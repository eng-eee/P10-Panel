#include <Arduino.h>
#include "DMD2.h"
#include <SPI.h>
#include "MyFont.h"
#include <Ethernet.h>

const int WIDTH = 3;

const uint8_t *FONT = mytest_font;

SoftDMD dmd(WIDTH, 1);

byte mac[] = {
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 0, 19);

IPAddress server(192, 168, 0, 54);

EthernetClient client;

char Panel[12] = {0};
bool flag = false;

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("connecting...");

  if (client.connect(server, 80))
  {
    Serial.println("connected");
    client.println("Succesfull...");
  }
  else
  {
    Serial.println("connection failed");
  }

  if (!client.connected())
  {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for (;;)
      ;
  }

  dmd.setBrightness(85);
  dmd.begin();
  dmd.selectFont(mytest_font);
}
int i = 0;
void loop()
{
  while (client.available())
  {
    char c = client.read();
    Panel[i++] = c;
  }
  dmd.drawChar(1, 0, Panel[0], GRAPHICS_ON, mytest_font);
  dmd.drawChar(9, 0, Panel[1], GRAPHICS_ON, mytest_font);
  dmd.drawChar(17, 0, Panel[2], GRAPHICS_ON, mytest_font);
  dmd.drawChar(25, 0, Panel[3], GRAPHICS_ON, mytest_font);

  dmd.drawChar(33, 0, Panel[4], GRAPHICS_ON, mytest_font);
  dmd.drawChar(41, 0, Panel[5], GRAPHICS_ON, mytest_font);
  dmd.drawChar(49, 0, Panel[6], GRAPHICS_ON, mytest_font);
  dmd.drawChar(57, 0, Panel[7], GRAPHICS_ON, mytest_font);

  dmd.drawChar(65, 0, Panel[8], GRAPHICS_ON, mytest_font);
  dmd.drawChar(73, 0, Panel[9], GRAPHICS_ON, mytest_font);
  dmd.drawChar(81, 0, Panel[10], GRAPHICS_ON, mytest_font);
  dmd.drawChar(89, 0, Panel[11], GRAPHICS_ON, mytest_font);
  i=0;
  delay(450);
}
// void func()
// {
//   for (size_t i = 0; i < 12; i++)
//   {
//     Serial.print(Panel[i]);
//   }
//   Serial.println();

//   // flag = false;
// }



// Port registers are same size as a pointer (16-bit on AVR, 32-bit on ARM)
typedef intptr_t port_reg_t;
// 9 - enable 6 - A  7 - B   13 - CLK  8 SCLK  DATA 11  GND
SPIDMD::SPIDMD(byte panelsWide, byte panelsHigh)
#ifdef ESP8266
    : BaseDMD(panelsWide, panelsHigh, 15, 16, 12, 0)
#else
    : BaseDMD(panelsWide, panelsHigh, 35, 53, 34, 43)
#endif
{
}

/* Create a DMD display using a custom pinout for all the non-SPI pins (SPI pins set by hardware) */
SPIDMD::SPIDMD(byte panelsWide, byte panelsHigh, byte pin_noe, byte pin_a, byte pin_b, byte pin_sck)
    : BaseDMD(panelsWide, panelsHigh, pin_noe, pin_a, pin_b, pin_sck)
{
}

void SPIDMD::beginNoTimer()
{
  // Configure SPI before initialising the base DMD
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0); // CPOL=0, CPHA=0
#ifdef __AVR__
  SPI.setClockDivider(SPI_CLOCK_DIV4); // 4MHz clock. 8MHz (DIV2 not DIV4) is possible if you have short cables. Longer cables may need DIV8/DIV16.
#elif defined(ESP8266)
  SPI.setFrequency(4000000); // ESP can run at 80mhz or 160mhz, setting frequency directly is easier, set to 4MHz.
#else
  SPI.setClockDivider(20); // 4.2MHz on Due. Same comment as above applies (lower numbers = less divider = faster speeds.)
#endif
  BaseDMD::beginNoTimer();
}

void SPIDMD::writeSPIData(volatile uint8_t *rows[4], const int rowsize)
{
  /* We send out interleaved data for 4 rows at a time */
  for (int i = 0; i < rowsize; i++)
  {
    SPI.transfer(*(rows[3]++));
    SPI.transfer(*(rows[2]++));
    SPI.transfer(*(rows[1]++));
    SPI.transfer(*(rows[0]++));
  }
}

void BaseDMD::scanDisplay()
{
  if (pin_other_cs >= 0 && digitalRead(pin_other_cs) != HIGH)
    return;
  // Rows are send out in 4 blocks of 4 (interleaved), across all panels

  int rowsize = unified_width_bytes();

  volatile uint8_t *rows[4] = {
      // Scanning out 4 interleaved rows
      bitmap + (scan_row + 0) * rowsize,
      bitmap + (scan_row + 4) * rowsize,
      bitmap + (scan_row + 8) * rowsize,
      bitmap + (scan_row + 12) * rowsize,
  };

  writeSPIData(rows, rowsize);

  digitalWrite(pin_noe, LOW);
  digitalWrite(pin_sck, HIGH); // Latch DMD shift register output
  digitalWrite(pin_sck, LOW);  // (Deliberately left as digitalWrite to ensure decent latching time)

  // Digital outputs A, B are a 2-bit selector output, set from the scan_row variable (loops over 0-3),
  // that determines which set of interleaved rows we are outputting during this pass.
  // BA 0 (00) = 1,5,9,13
  // BA 1 (01) = 2,6,10,14
  // BA 2 (10) = 3,7,11,15
  // BA 3 (11) = 4,8,12,16
  digitalWrite(pin_a, scan_row & 0x01);
  digitalWrite(pin_b, scan_row & 0x02);
  scan_row = (scan_row + 1) % 4;

  // Output enable pin is either fixed on, or PWMed for a variable brightness display
  if (brightness < 255)
    digitalWrite(pin_noe, HIGH);
  else
    analogWrite(pin_noe, brightness);
}

#ifdef ESP8266
// No SoftDMD for ESP8266 for now
#else
// oe,a,b,sclk,clk,data
SoftDMD::SoftDMD(byte panelsWide, byte panelsHigh)
    : BaseDMD(panelsWide, panelsHigh, 35, 53, 34, 43),
      pin_clk(41),
      pin_r_data(28)
{
}

SoftDMD::SoftDMD(byte panelsWide, byte panelsHigh, byte pin_noe, byte pin_a, byte pin_b, byte pin_sck,
                 byte pin_clk, byte pin_r_data)
    : BaseDMD(panelsWide, panelsHigh, pin_noe, pin_a, pin_b, pin_sck),
      pin_clk(pin_clk),
      pin_r_data(pin_r_data)
{
}

void SoftDMD::beginNoTimer()
{
  digitalWrite(pin_clk, LOW);
  pinMode(pin_clk, OUTPUT);

  digitalWrite(pin_r_data, LOW);
  pinMode(pin_r_data, OUTPUT);
  BaseDMD::beginNoTimer();
}

static inline __attribute__((always_inline)) void softSPITransfer(uint8_t data, volatile port_reg_t *data_port, port_reg_t data_mask, volatile port_reg_t *clk_port, port_reg_t clk_mask)
{
  // Emulate a single byte SPI transfer using software GPIO. Overall this is actually only marginally slower than normal SPI on AVR.
  //
  // MSB first, data captured on rising edge
  for (uint8_t bit = 0; bit < 8; bit++)
  {
    if (data & (1 << 7))
      *data_port |= data_mask;
    else
      *data_port &= ~data_mask;
    *clk_port |= clk_mask;
    data <<= 1;
    *clk_port &= ~clk_mask;
  }
}

void SoftDMD::writeSPIData(volatile uint8_t *rows[4], const int rowsize)
{
  /* Write out 4 interleaved rows of data using software GPIO rather than SPI. */
  volatile port_reg_t *port_clk = (volatile port_reg_t *)portOutputRegister(digitalPinToPort(pin_clk));
  port_reg_t mask_clk = digitalPinToBitMask(pin_clk);
  volatile port_reg_t *port_r_data = (volatile port_reg_t *)portOutputRegister(digitalPinToPort(pin_r_data));
  port_reg_t mask_r_data = digitalPinToBitMask(pin_r_data);

  for (int i = 0; i < rowsize; i++)
  {
    softSPITransfer(*(rows[3]++), port_r_data, mask_r_data, port_clk, mask_clk);
    softSPITransfer(*(rows[2]++), port_r_data, mask_r_data, port_clk, mask_clk);
    softSPITransfer(*(rows[1]++), port_r_data, mask_r_data, port_clk, mask_clk);
    softSPITransfer(*(rows[0]++), port_r_data, mask_r_data, port_clk, mask_clk);
  }
}
#endif

BaseDMD::BaseDMD(byte panelsWide, byte panelsHigh, byte pin_noe, byte pin_a, byte pin_b, byte pin_sck)
    : DMDFrame(panelsWide * PANEL_WIDTH, panelsHigh * PANEL_HEIGHT),
      scan_row(0),
      pin_noe(pin_noe),
      pin_a(pin_a),
      pin_b(pin_b),
      pin_sck(pin_sck),
#ifdef ESP8266
      default_pins(pin_noe == 15 && pin_a == 16 && pin_b == 12 && pin_sck == 0),
#else
      default_pins(pin_noe == 40 && pin_a == 34 && pin_b == 36 && pin_sck == 38),
#endif
      pin_other_cs(-1),
      brightness(255)
{
}

void BaseDMD::beginNoTimer()
{
  digitalWrite(pin_noe, LOW);
  pinMode(pin_noe, OUTPUT);

  digitalWrite(pin_a, LOW);
  pinMode(pin_a, OUTPUT);

  digitalWrite(pin_b, LOW);
  pinMode(pin_b, OUTPUT);

  digitalWrite(pin_sck, LOW);
  pinMode(pin_sck, OUTPUT);

  clearScreen();
  scanDisplay();
}

void DMDFrame::selectFont(const uint8_t *font)
{
  this->font = (uint8_t *)font;
}

int DMDFrame::drawChar(const int x, const int y, const char letter, DMDGraphicsMode mode, const uint8_t *font)
{
  if (!font)
    font = this->font;
  if (x >= (int)width || y >= height)
    return -1;

  struct FontHeader header;
  memcpy_P(&header, (void *)font, sizeof(FontHeader));

  DMDGraphicsMode invertedMode = inverseMode(mode);

  char c = letter;
  if (c == ' ')
  {
    int charWide = charWidth(' ');
    this->drawFilledBox(x, y, x + charWide, y + header.height, invertedMode);
    return charWide;
  }
  uint8_t width = 0;
  uint8_t bytes = (header.height + 7) / 8;
  uint16_t index = 0;

  if (c < header.firstChar || c >= (header.firstChar + header.charCount))
    return 0;
  c -= header.firstChar;

  if (header.size == 0)
  {
    // zero length is flag indicating fixed width font (array does not contain width data entries)
    width = header.fixedWidth;
    index = sizeof(FontHeader) + c * bytes * width;
  }
  else
  {
    // variable width font, read width data, to get the index
    for (uint8_t i = 0; i < c; i++)
    {
      index += pgm_read_byte(font + sizeof(FontHeader) + i);
    }
    index = index * bytes + header.charCount + sizeof(FontHeader);
    width = pgm_read_byte(font + sizeof(FontHeader) + c);
  }
  if (x < -width || y < -header.height)
    return width;

  bool inverse = false;
  if (mode == GRAPHICS_INVERSE)
  {
    inverse = true;
  }

  // last but not least, draw the character
  for (uint8_t j = 0; j < width; j++)
  { // Width
    for (uint8_t i = bytes - 1; i < 254; i--)
    { // Vertical Bytes
      uint8_t data = pgm_read_byte(font + index + j + (i * width));
      int offset = (i * 8);
      if ((i == bytes - 1) && bytes > 1)
      {
        offset = header.height - 8;
      }
      for (uint8_t k = 0; k < 8; k++)
      { // Vertical bits
        if ((offset + k >= i * 8) && (offset + k <= header.height))
        {
          if (data & (1 << k))
          {
            if (inverse)
            {
              setPixel(x + j, y + offset + k, GRAPHICS_OFF);
            }
            else
            {
              setPixel(x + j, y + offset + k, GRAPHICS_ON);
            }
          }
          else
          {
            if (inverse)
            {
              setPixel(x + j, y + offset + k, GRAPHICS_ON);
            }
            else
            {
              setPixel(x + j, y + offset + k, GRAPHICS_OFF);
            }
          }
        }
      }
    }
  }
  return width;
}

// Generic drawString implementation for various kinds of strings
template <class StrType>
__attribute__((always_inline)) inline void _drawString(DMDFrame *dmd, int x, int y, StrType str, DMDGraphicsMode mode, const uint8_t *font)
{
  struct FontHeader header;
  memcpy_P(&header, font, sizeof(FontHeader));

  if (y + header.height < 0)
    return;

  DMDGraphicsMode invertedMode = inverseMode(mode);
  int strWidth = 0;
  if (x > 0)
    dmd->drawLine(x - 1, y, x - 1, y + header.height - 1, invertedMode);

  char c;
  for (int idx = 0; c = str[idx], c != 0; idx++)
  {
    if (c == '\n')
    { // Newline
      strWidth = 0;
      y = y - header.height - 1;
    }
    else
    {
      int charWide = dmd->drawChar(x + strWidth, y, c, mode);
      if (charWide > 0)
      {
        strWidth += charWide;
        dmd->drawLine(x + strWidth, y, x + strWidth, y + header.height - 1, invertedMode);
        strWidth++;
      }
      else if (charWide < 0)
      {
        return;
      }
    }
  }
}

// Generic stringWidth implementation for various kinds of strings
template <class StrType>
__attribute__((always_inline)) inline unsigned int _stringWidth(DMDFrame *dmd, const uint8_t *font, StrType str)
{
  unsigned int width = 0;
  char c;
  int idx;
  for (idx = 0; c = str[idx], c != 0; idx++)
  {
    int cwidth = dmd->charWidth(c);
    if (cwidth > 0)
      width += cwidth + 1;
  }
  if (width)
  {
    width--;
  }
  return width;
}

#if defined(__AVR__) || defined(ESP8266)
// Small wrapper class to allow indexing of progmem strings via [] (should be inlined out of the actual implementation)
class _FlashStringWrapper
{
  const char *str;

public:
  _FlashStringWrapper(const char *flstr) : str(flstr) {}
  inline char operator[](unsigned int index)
  {
    return pgm_read_byte(str + index);
  }
};

void DMDFrame::drawString_P(int x, int y, const char *flashStr, DMDGraphicsMode mode, const uint8_t *font)
{
  if (!font)
    font = this->font;
  if (x >= (int)width || y >= height)
    return;
  _FlashStringWrapper wrapper(flashStr);
  _drawString(this, x, y, wrapper, mode, font);
}

unsigned int DMDFrame::stringWidth_P(const char *flashStr, const uint8_t *font)
{
  if (!font)
    font = this->font;
  _FlashStringWrapper wrapper(flashStr);
  return _stringWidth(this, font, wrapper);
}

#endif

void DMDFrame::drawString(int x, int y, const char *bChars, DMDGraphicsMode mode, const uint8_t *font)
{
  if (!font)
    font = this->font;
  if (x >= (int)width || y >= height)
    return;
  _drawString(this, x, y, bChars, mode, font);
}

void DMDFrame::drawString(int x, int y, const String &str, DMDGraphicsMode mode, const uint8_t *font)
{
  if (!font)
    font = this->font;
  if (x >= (int)width || y >= height)
    return;
  _drawString(this, x, y, str, mode, font);
}

// Find the width of a character
int DMDFrame::charWidth(const char letter, const uint8_t *font)
{
  struct FontHeader header;
  memcpy_P(&header, (void *)this->font, sizeof(FontHeader));

  if (!font)
    font = this->font;

  if (letter == ' ')
  {
    // if the letter is a space then return the font's fixedWidth
    // (set as the 'width' field in New Font dialog in GLCDCreator.)
    return header.fixedWidth;
  }

  if ((uint8_t)letter < header.firstChar || (uint8_t)letter >= (header.firstChar + header.charCount))
  {
    return 0;
  }

  if (header.size == 0)
  {
    // zero length is flag indicating fixed width font (array does not contain width data entries)
    return header.fixedWidth;
  }

  // variable width font, read width data for character
  return pgm_read_byte(this->font + sizeof(FontHeader) + letter - header.firstChar);
}

unsigned int DMDFrame::stringWidth(const char *bChars, const uint8_t *font)
{
  if (!font)
    font = this->font;
  return _stringWidth(this, font, bChars);
}

unsigned int DMDFrame::stringWidth(const String &str, const uint8_t *font)
{
  if (!font)
    font = this->font;
  return _stringWidth(this, font, str);
}

DMD_TextBox::DMD_TextBox(DMDFrame &dmd, int left, int top, int width, int height) : dmd(dmd),
                                                                                    inverted(false),
                                                                                    left(left),
                                                                                    top(top),
                                                                                    width(width),
                                                                                    height(height),
                                                                                    cur_x(0),
                                                                                    cur_y(0),
                                                                                    pending_newline(false)
{
}

size_t DMD_TextBox::write(uint8_t character)
{
  struct FontHeader header;
  memcpy_P(&header, (void *)this->dmd.font, sizeof(FontHeader));
  uint8_t rowHeight = header.height + 1;

  if (width == 0)
    width = dmd.width - left;
  if (height == 0)
    height = dmd.height - top;

  uint8_t char_width = dmd.charWidth(character) + 1;
  while ((cur_x > 0 && cur_x + char_width >= this->width) || pending_newline)
  { // Need to wrap to new line
    if (height >= rowHeight * 2)
    { // Can scroll
      cur_y += rowHeight;
      cur_x = 0;
      if (cur_y + rowHeight > height)
      {                                         // Scroll
        int delta = cur_y + rowHeight - height; // the amount that it's over by
        delta = delta + 0;
      }
    }
    else if (pending_newline)
    { // No room, so just clear display
      clear();
    }
    else
    { // Scroll characters horizontally
      int scroll_by = char_width - (this->width - cur_x - 1);
      scrollX(-scroll_by);
    }
    pending_newline = false;
  }

  if (character == '\n')
  {
    pending_newline = true;
    // clear the rest of the line after the current cursor position,
    // this allows you to then use reset() and do a flicker-free redraw
    dmd.drawFilledBox(cur_x + left, cur_y + top, left + width, cur_y + top + rowHeight, inverted ? GRAPHICS_ON : GRAPHICS_OFF);
  }

  dmd.drawChar(cur_x + left, cur_y + top, character, inverted ? GRAPHICS_OFF : GRAPHICS_ON);
  cur_x += char_width;
  return 1;
}

void DMD_TextBox::scrollY(int scrollBy)
{
  if (abs(scrollBy) >= height)
  { // scrolling over the whole display
    // scrolling will erase everything
    dmd.drawFilledBox(left, top, left + width - 1, top + height - 1, inverted ? GRAPHICS_ON : GRAPHICS_OFF);
  }
  else if (scrollBy < 0)
  { // Scroll up
    dmd.movePixels(left, top - scrollBy, left, top, width, height + scrollBy);
  }
  else if (scrollBy > 0)
  { // Scroll down
    dmd.movePixels(left, top, left, top + scrollBy, width, height - scrollBy);
  }

  cur_y += scrollBy;
  while (cur_y < 0)
    cur_y += height;
  while (cur_y > height)
    cur_y -= height;
}

void DMD_TextBox::scrollX(int scrollBy)
{
  if (abs(scrollBy) >= width)
  { // scrolling over the whole display!
    // scrolling will erase everything
    dmd.drawFilledBox(left, top, left + width - 1, top + height - 1, inverted ? GRAPHICS_ON : GRAPHICS_OFF);
  }
  else if (scrollBy < 0)
  { // Scroll left
    dmd.movePixels(left - scrollBy, top, left, top, width + scrollBy, height);
  }
  else
  { // Scroll right
    dmd.movePixels(left, top, left + scrollBy, top, width - scrollBy, height);
  }

  cur_x += scrollBy;
  while (cur_x < 0)
    cur_x += width;
  while (cur_x > width)
    cur_x -= width;
}

void DMD_TextBox::clear()
{
  this->reset();

  dmd.drawFilledBox(left, top, left + width, top + height, inverted ? GRAPHICS_ON : GRAPHICS_OFF);
}

void DMD_TextBox::reset()
{
  cur_x = 0;
  cur_y = 0;
  pending_newline = false;
}

//#define NO_TIMERS

#define ESP8266_TIMER0_TICKS microsecondsToClockCycles(250) // 250 microseconds between calls to scan_running_dmds seems to works better than 1000.

#ifdef NO_TIMERS

// Timer-free stub code which gets compiled in only if NO_TIMERS is set
void BaseDMD::begin()
{
  beginNoTimer();
}

void BaseDMD::end()
{
}

#else // Use timers

// Forward declarations for tracking currently running DMDs
static void register_running_dmd(BaseDMD *dmd);
static bool unregister_running_dmd(BaseDMD *dmd);
static void inline scan_running_dmds();

#ifdef ESP8266
static void ICACHE_RAM_ATTR esp8266_ISR_wrapper();
#endif

#ifdef __AVR__

/* This AVR timer ISR uses the standard /64 timing used by Timer1 in the Arduino core,
   so none of those registers (or normal PWM timing) is changed. We do skip 50% of ISRs
   as 50% timer overflows is approximately every 4ms, which is fine for flicker-free
   updating.
*/
ISR(TIMER1_OVF_vect)
{
  static uint8_t skip_isrs = 0;
  skip_isrs = (skip_isrs + 1) % 2;
  if (skip_isrs)
    return;
  scan_running_dmds();
}

void BaseDMD::begin()
{
  beginNoTimer(); // Do any generic setup

  char oldSREG = SREG;
  cli();
  register_running_dmd(this);
  TIMSK1 = _BV(TOIE1); // set overflow interrupt
  SREG = oldSREG;
}

void BaseDMD::end()
{
  char oldSREG = SREG;
  cli();
  bool still_running = unregister_running_dmd(this);
  if (!still_running)
    TIMSK1 &= ~_BV(TOIE1); // disable timer interrupt, no more DMDs are running
  SREG = oldSREG;
  // One final (manual) scan to turn off all LEDs
  clearScreen();
  scanDisplay();
}

#elif defined(__arm__) // __ARM__, Due assumed for now

/* ARM timer callback (ISR context), checks timer status then scans all running DMDs */
void TC7_Handler()
{
  TC_GetStatus(TC2, 1);
  scan_running_dmds();
}

void BaseDMD::begin()
{
  beginNoTimer(); // Do any generic setup

  NVIC_DisableIRQ(TC7_IRQn);
  register_running_dmd(this);
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk(TC7_IRQn);
  // Timer 7 is TC2, channel 1
  TC_Configure(TC2, 1, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4); // counter up, /128 divisor
  TC_SetRC(TC2, 1, 2500);                                                               // approx 4ms at /128 divisor
  TC2->TC_CHANNEL[1].TC_IER = TC_IER_CPCS;

  NVIC_ClearPendingIRQ(TC7_IRQn);
  NVIC_EnableIRQ(TC7_IRQn);
  TC_Start(TC2, 1);
}

void BaseDMD::end()
{
  NVIC_DisableIRQ(TC7_IRQn);
  bool still_running = unregister_running_dmd(this);
  if (still_running)
    NVIC_EnableIRQ(TC7_IRQn); // Still some DMDs running
  else
    TC_Stop(TC2, 1);
  clearScreen();
  scanDisplay();
}

#elif defined(ESP8266)

void BaseDMD::begin()
{
  beginNoTimer();
  timer0_detachInterrupt();

  register_running_dmd(this);

  timer0_isr_init();
  timer0_attachInterrupt(esp8266_ISR_wrapper);
  timer0_write(ESP.getCycleCount() + ESP8266_TIMER0_TICKS);
}

void BaseDMD::end()
{
  bool still_running = unregister_running_dmd(this);
  if (!still_running)
  {
    timer0_detachInterrupt(); // timer0 disables itself when the CPU cycle count reaches its own value, hence ESP.getCycleCount()
  }
  clearScreen();
  scanDisplay();
}

#endif // ifdef __AVR__

/* Following functions are static non-architecture-specific functions
   to manage a global array that tracks all known DMD instances.

   This is so a global C code interrupt can call all of the DMDs on
   timer interrupt.

   The array is grown with realloc. If a DMD is destroyed then it
   shrink the array, it just NULLs out the entry (presuming there
   isn't a lot of dynamic growth/shrinkage of DMDs within a sketch!)
*/
static volatile BaseDMD **running_dmds = 0;
static volatile int running_dmd_len = 0;

// Add a running_dmd to the list (caller must have disabled interrupts)
static void register_running_dmd(BaseDMD *dmd)
{
  int empty = -1;
  for (int i = 0; i < running_dmd_len; i++)
  {
    if (running_dmds[i] == dmd)
      return; // Already running and registered
    if (!running_dmds[i])
      empty = i; // Found an unused slot in the array
  }

  if (empty == -1)
  { // Grow array to fit new entry
    running_dmd_len++;
    BaseDMD **resized = (BaseDMD **)realloc(running_dmds, sizeof(BaseDMD *) * running_dmd_len);
    if (!resized)
    {
      // Allocation failed, bail out

      running_dmd_len--;
      return;
    }
    empty = running_dmd_len - 1;
    running_dmds = (volatile BaseDMD **)resized;
  }
  running_dmds[empty] = dmd;
}

// Null out a running_dmd from the list (caller must have disabled interrupts)
static bool unregister_running_dmd(BaseDMD *dmd)
{
  bool still_running = false;
  for (int i = 0; i < running_dmd_len; i++)
  {
    if (running_dmds[i] == dmd)
      running_dmds[i] = NULL;
    else if (running_dmds[i])
      still_running = true;
  }
  return still_running;
}

// ESP8266 ISR Wrapper
#ifdef ESP8266
static void inline ICACHE_RAM_ATTR esp8266_ISR_wrapper()
{
  if (((int)0x40200000))
  { // Make sure flash isn't being accessed.
    scan_running_dmds();
  }
  timer0_write(ESP.getCycleCount() + ESP8266_TIMER0_TICKS);
}
#endif

// This method is called from timer ISR to scan all the DMD instances present in the running sketch
static void inline __attribute__((always_inline)) scan_running_dmds()
{
  for (int i = 0; i < running_dmd_len; i++)
  {
    BaseDMD *next = (BaseDMD *)running_dmds[i];
    if (next)
    {
      next->scanDisplay();
    }
  }
}

#endif // ifdef NO_TIMERS
DMDFrame::DMDFrame(byte pixelsWide, byte pixelsHigh)
    : width(pixelsWide),
      height(pixelsHigh),
      font(0)
{
  row_width_bytes = (pixelsWide + 7) / 8; // on full panels pixelsWide is a multiple of 8, but for sub-regions may not be
  height_in_panels = (pixelsHigh + PANEL_HEIGHT - 1) / PANEL_HEIGHT;
  bitmap = (uint8_t *)malloc(bitmap_bytes());
  memset((void *)bitmap, 0xFF, bitmap_bytes());
}

DMDFrame::DMDFrame(const DMDFrame &source) : width(source.width),
                                             height(source.height),
                                             row_width_bytes(source.row_width_bytes),
                                             height_in_panels(source.height_in_panels),
                                             font(source.font)
{
  bitmap = (uint8_t *)malloc(bitmap_bytes());
  memcpy((void *)bitmap, (void *)source.bitmap, bitmap_bytes());
}

DMDFrame::~DMDFrame()
{
  free((void *)bitmap);
}

void DMDFrame::swapBuffers(DMDFrame &other)
{
#ifdef __AVR__
  // AVR can't write pointers atomically, so need to disable interrupts
  char oldSREG = SREG;
  cli();
#endif
  volatile uint8_t *temp = other.bitmap;
  other.bitmap = this->bitmap;
  this->bitmap = temp;
#ifdef __AVR__
  SREG = oldSREG;
#endif
}

// Set a single LED on or off. Remember that the pixel array is inverted (bit set = LED off)
void DMDFrame::setPixel(unsigned int x, unsigned int y, DMDGraphicsMode mode)
{
  if (x >= width || y >= height)
    return;

  int byte_idx = pixelToBitmapIndex(x, y);
  uint8_t bit = pixelToBitmask(x);
  switch (mode)
  {
  case GRAPHICS_ON:
    bitmap[byte_idx] &= ~bit; // and with the inverse of the bit - so
    break;
  case GRAPHICS_OFF:
    bitmap[byte_idx] |= bit; // set bit (which turns it off)
    break;
  case GRAPHICS_OR:
    bitmap[byte_idx] = ~(~bitmap[byte_idx] | bit);
    break;
  case GRAPHICS_NOR:
    bitmap[byte_idx] = (~bitmap[byte_idx] | bit);
    break;
  case GRAPHICS_XOR:
    bitmap[byte_idx] ^= bit;
    break;
  case GRAPHICS_INVERSE:
  case GRAPHICS_NOOP:
    break;
  }
}

bool DMDFrame::getPixel(unsigned int x, unsigned int y)
{
  if (x >= width || y >= height)
    return false;
  int byte_idx = pixelToBitmapIndex(x, y);
  uint8_t bit = pixelToBitmask(x);
  bool res = !(bitmap[byte_idx] & bit);
  return res;
}

void DMDFrame::debugPixelLine(unsigned int y, char *buf)
{ // buf must be large enough (2x pixels+EOL+nul), or we'll overrun
  char *currentPixel = buf;
  for (int x = 0; x < width; x++)
  {
    bool set = getPixel(x, y);
    if (set)
    {
      *currentPixel = '[';
      currentPixel++;
      *currentPixel = ']';
    }
    else
    {
      *currentPixel = '_';
      currentPixel++;
      *currentPixel = '_';
    }
    currentPixel++;
  }
  *currentPixel = '\n';
  currentPixel++;
  *currentPixel = 0; // nul terminator
}

void DMDFrame::movePixels(unsigned int from_x, unsigned int from_y,
                          unsigned int to_x, unsigned int to_y,
                          unsigned int width, unsigned int height)
{
  // NB: This implementation is actually a copy-erase so
  // it uses more RAM than a real move implementation would
  // do (however bypasses issues around overlapping regions.)

  if (from_x >= this->width || from_y >= this->height || to_x >= this->width || to_y >= this->height)
    return;

  DMDFrame to_move = this->subFrame(from_x, from_y, width, height);
  this->drawFilledBox(from_x, from_y, from_x + width - 1, from_y + height - 1, GRAPHICS_OFF);
  this->copyFrame(to_move, to_x, to_y);
}

// Set the entire screen
void DMDFrame::fillScreen(bool on)
{
  memset((void *)bitmap, on ? 0 : 0xFF, bitmap_bytes());
}

void DMDFrame::drawLine(int x1, int y1, int x2, int y2, DMDGraphicsMode mode)
{
  int dy = y2 - y1;
  int dx = x2 - x1;
  int stepx, stepy;

  if (dy < 0)
  {
    dy = -dy;
    stepy = -1;
  }
  else
  {
    stepy = 1;
  }
  if (dx < 0)
  {
    dx = -dx;
    stepx = -1;
  }
  else
  {
    stepx = 1;
  }
  dy = dy * 2;
  dx = dx * 2;

  setPixel(x1, y1, mode);
  if (dx > dy)
  {
    int fraction = dy - (dx / 2); // same as 2*dy - dx
    while (x1 != x2)
    {
      if (fraction >= 0)
      {
        y1 += stepy;
        fraction -= dx; // same as fraction -= 2*dx
      }
      x1 += stepx;
      fraction += dy; // same as fraction -= 2*dy
      setPixel(x1, y1, mode);
    }
  }
  else
  {
    int fraction = dx - (dy / 2);
    while (y1 != y2)
    {
      if (fraction >= 0)
      {
        x1 += stepx;
        fraction -= dy;
      }
      y1 += stepy;
      fraction += dx;
      setPixel(x1, y1, mode);
    }
  }
}

void DMDFrame::drawCircle(unsigned int xCenter, unsigned int yCenter, int radius, DMDGraphicsMode mode)
{
  // Bresenham's circle drawing algorithm
  int x = -radius;
  int y = 0;
  int error = 2 - 2 * radius;
  while (x < 0)
  {
    setPixel(xCenter - x, yCenter + y, mode);
    setPixel(xCenter - y, yCenter - x, mode);
    setPixel(xCenter + x, yCenter - y, mode);
    setPixel(xCenter + y, yCenter + x, mode);
    radius = error;
    if (radius <= y)
      error += ++y * 2 + 1;
    if (radius > x || error > y)
      error += ++x * 2 + 1;
  }
}

void DMDFrame::drawBox(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, DMDGraphicsMode mode)
{
  drawLine(x1, y1, x2, y1, mode);
  drawLine(x2, y1, x2, y2, mode);
  drawLine(x2, y2, x1, y2, mode);
  drawLine(x1, y2, x1, y1, mode);
}

void DMDFrame::drawFilledBox(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, DMDGraphicsMode mode)
{
  for (unsigned int b = x1; b <= x2; b++)
  {
    drawLine(b, y1, b, y2, mode);
  }
}

void DMDFrame::scrollY(int scrollBy)
{
  if (abs(scrollBy) >= height)
  { // scrolling over the whole display
    // scrolling will erase everything
    drawFilledBox(0, 0, width - 1, height - 1, GRAPHICS_OFF);
  }
  else if (scrollBy < 0)
  { // Scroll up
    movePixels(0, -scrollBy, 0, 0, width, height + scrollBy);
    drawFilledBox(0, height + scrollBy, width, height, GRAPHICS_OFF);
  }
  else if (scrollBy > 0)
  { // Scroll down
    movePixels(0, 0, 0, scrollBy, width, height - scrollBy);
    drawFilledBox(0, 0, width, scrollBy, GRAPHICS_OFF);
  }
}

void DMDFrame::scrollX(int scrollBy)
{
  if (abs(scrollBy) >= width)
  { // scrolling over the whole display!
    // scrolling will erase everything
    drawFilledBox(0, 0, width - 1, height - 1, GRAPHICS_OFF);
  }
  else if (scrollBy < 0)
  { // Scroll left
    movePixels(-scrollBy, 0, 0, 0, width + scrollBy, height);
    drawFilledBox(width + scrollBy, 0, width, height, GRAPHICS_OFF);
  }
  else
  { // Scroll right
    movePixels(0, 0, scrollBy, 0, width - scrollBy, height);
    drawFilledBox(0, 0, scrollBy, height, GRAPHICS_OFF);
  }
}

void DMDFrame::marqueeScrollX(int scrollBy)
{
  // Scrolling is basically the same as normal scrolling, but we save/restore the overlapping
  // area in between to create the marquee effect
  scrollBy = scrollBy % width;

  if (scrollBy < 0)
  {                                                           // Scroll left
    DMDFrame frame = subFrame(0, 0, -scrollBy, height);       // save leftmost
    movePixels(-scrollBy, 0, 0, 0, width + scrollBy, height); // move
    copyFrame(frame, width + scrollBy, 0);                    // drop back at right edge
  }
  else
  {                                                                   // Scroll right
    DMDFrame frame = subFrame(width - scrollBy, 0, scrollBy, height); // save rightmost
    movePixels(0, 0, scrollBy, 0, width - scrollBy, height);          // move
    copyFrame(frame, 0, 0);                                           // drop back at left edge
  }
}

void DMDFrame::marqueeScrollY(int scrollBy)
{
  scrollBy = scrollBy % height;

  if (scrollBy < 0)
  {                                                           // Scroll up
    DMDFrame frame = subFrame(0, 0, width, -scrollBy);        // save topmost
    movePixels(0, -scrollBy, 0, 0, width, height + scrollBy); // move
    copyFrame(frame, 0, height + scrollBy);                   // drop back at bottom edge
  }
  else
  {                                                                   // Scroll down
    DMDFrame frame = subFrame(0, height - scrollBy, width, scrollBy); // save bottommost
    movePixels(0, 0, 0, scrollBy, width, height - scrollBy);          // move
    copyFrame(frame, 0, 0);                                           // drop back at top edge
  }
}

DMDFrame DMDFrame::subFrame(unsigned int left, unsigned int top, unsigned int width, unsigned int height)
{
  DMDFrame result(width, height);

  if ((left % 8) == 0 && (width % 8) == 0)
  {
    // Copying from/to byte boundaries, can do simple/efficient copies
    for (unsigned int to_y = 0; to_y < height; to_y++)
    {
      unsigned int from_y = top + to_y;
      unsigned int from_end = pixelToBitmapIndex(left + width, from_y);
      unsigned int to_byte = result.pixelToBitmapIndex(0, to_y);
      for (unsigned int from_byte = pixelToBitmapIndex(left, from_y); from_byte < from_end; from_byte++)
      {
        result.bitmap[to_byte++] = this->bitmap[from_byte];
      }
    }
  }
  else
  {
    // Copying not from a byte boundary. Slow pixel-by-pixel for now.
    for (unsigned int to_y = 0; to_y < height; to_y++)
    {
      for (unsigned int to_x = 0; to_x < width; to_x++)
      {
        bool val = this->getPixel(to_x + left, to_y + top);
        result.setPixel(to_x, to_y, val ? GRAPHICS_ON : GRAPHICS_OFF);
      }
    }
  }

  return result;
}

void DMDFrame::copyFrame(DMDFrame &from, unsigned int left, unsigned int top)
{
  if ((left % 8) == 0 && (from.width % 8) == 0)
  {
    // Copying rows on byte boundaries, can do simple/efficient copies
    unsigned int to_bottom = top + from.height;
    if (to_bottom > this->height)
      to_bottom = this->height;
    unsigned int to_right = left + from.width;
    if (to_right > this->width)
      to_right = this->width;
    unsigned int from_y = 0;
    for (unsigned int to_y = top; to_y < to_bottom; to_y++)
    {
      unsigned int to_end = pixelToBitmapIndex(to_right, to_y);
      unsigned int from_byte = from.pixelToBitmapIndex(0, from_y);
      for (unsigned int to_byte = pixelToBitmapIndex(left, to_y); to_byte < to_end; to_byte++)
      {
        this->bitmap[to_byte] = from.bitmap[from_byte++];
      }
      from_y++;
    }
  }
  else
  {
    // Copying not to a byte boundary. Slow pixel-by-pixel for now.
    for (unsigned int from_y = 0; from_y < from.height; from_y++)
    {
      for (unsigned int from_x = 0; from_x < from.width; from_x++)
      {
        bool val = from.getPixel(from_x, from_y);
        this->setPixel(from_x + left, from_y + top, val ? GRAPHICS_ON : GRAPHICS_OFF);
      }
    }
  }
}

/* Lookup table for DMD pixel locations, marginally faster than bitshifting */
const PROGMEM uint8_t DMD_Pixel_Lut[] = {
    0x80, // 0, bit 7
    0x40, // 1, bit 6
    0x20, // 2. bit 5
    0x10, // 3, bit 4
    0x08, // 4, bit 3
    0x04, // 5, bit 2
    0x02, // 6, bit 1
    0x01  // 7, bit 0
};