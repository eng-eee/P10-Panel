

/*
 *
 * Droid_Sans_16
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : droid_sans_16.h
 * Date                : 06.03.2013
 * Font size in bytes  : 10778
 * Font width          : 10
 * Font height         : 17
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined (ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

#ifndef DROID_SANS_16_H
#define DROID_SANS_16_H

#define DROID_SANS_16_WIDTH 10
#define DROID_SANS_16_HEIGHT 17

static const uint8_t Droid_Sans_16[] PROGMEM = {
    0x2A, 0x1A, // size
    0x0A, // width
    0x11, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x02, 0x05, 0x08, 0x07, 0x0B, 0x0A, 0x02, 0x04, 0x04, 
    0x08, 0x07, 0x03, 0x03, 0x01, 0x06, 0x07, 0x04, 0x07, 0x07, 
    0x09, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x03, 0x07, 0x07, 
    0x07, 0x06, 0x0C, 0x0A, 0x08, 0x09, 0x09, 0x06, 0x06, 0x0A, 
    0x08, 0x04, 0x02, 0x08, 0x07, 0x0B, 0x09, 0x0A, 0x07, 0x0A, 
    0x08, 0x07, 0x08, 0x08, 0x09, 0x0D, 0x08, 0x08, 0x08, 0x03, 
    0x06, 0x03, 0x09, 0x07, 0x03, 0x07, 0x07, 0x06, 0x07, 0x07, 
    0x04, 0x08, 0x07, 0x01, 0x02, 0x07, 0x01, 0x0C, 0x07, 0x07, 
    0x07, 0x07, 0x05, 0x05, 0x05, 0x07, 0x08, 0x0C, 0x08, 0x08, 
    0x06, 0x05, 0x01, 0x05, 0x07, 0x07, 
    
    // font data
    0xFE, 0xFE, 0x1B, 0x19, 0x00, 0x00, // 33
    0x1E, 0x02, 0x00, 0x1E, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x00, 0x20, 0xF0, 0x3E, 0x20, 0xF0, 0x2E, 0x20, 0x01, 0x1F, 0x03, 0x01, 0x1F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0x38, 0x6C, 0x44, 0xFF, 0x84, 0x84, 0x04, 0x0C, 0x08, 0x08, 0x3F, 0x08, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 36
    0x3C, 0x42, 0x42, 0x66, 0x3C, 0xC0, 0x30, 0x8C, 0x82, 0x80, 0x00, 0x00, 0x00, 0x10, 0x0C, 0x03, 0x00, 0x0F, 0x10, 0x10, 0x19, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
    0x00, 0x9C, 0xF6, 0xC2, 0xE2, 0x36, 0x1C, 0x00, 0x80, 0x80, 0x0F, 0x1D, 0x10, 0x10, 0x11, 0x1B, 0x0E, 0x0E, 0x1B, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
    0x1E, 0x02, 0x00, 0x00, 0x00, 0x00, // 39
    0xE0, 0xF8, 0x0E, 0x02, 0x0F, 0x7E, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, // 40
    0x02, 0x0E, 0xF8, 0xE0, 0x80, 0xC0, 0x7E, 0x0F, 0x00, 0x00, 0x00, 0x00, // 41
    0x0C, 0x0C, 0x78, 0x1F, 0x1F, 0x78, 0x4C, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x80, 0x80, 0x80, 0xF0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x40, 0x38, 0x08, 0x00, 0x00, 0x00, // 44
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, // 45
    0x00, 0x18, 0x00, // 46
    0x00, 0x00, 0xC0, 0x70, 0x1E, 0x02, 0x18, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0xF8, 0x3C, 0x06, 0x02, 0x06, 0x3C, 0xF8, 0x07, 0x0F, 0x18, 0x10, 0x18, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 48
    0x08, 0x04, 0x06, 0xFE, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, // 49
    0x04, 0x06, 0x02, 0x02, 0x82, 0xEE, 0x3C, 0x18, 0x1C, 0x16, 0x13, 0x11, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 50
    0x04, 0x06, 0x42, 0x42, 0xC2, 0xB6, 0x1C, 0x18, 0x10, 0x10, 0x10, 0x18, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 51
    0x00, 0x80, 0x60, 0x30, 0x18, 0x04, 0xFE, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x1F, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
    0x7E, 0x4E, 0x42, 0x42, 0xC2, 0x82, 0x00, 0x18, 0x10, 0x10, 0x10, 0x18, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 53
    0xF0, 0xFC, 0x44, 0x46, 0x42, 0xC2, 0x80, 0x07, 0x0D, 0x18, 0x10, 0x10, 0x0C, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 54
    0x02, 0x02, 0x02, 0x82, 0xE2, 0x3E, 0x06, 0x00, 0x18, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x1C, 0xA6, 0xC2, 0x42, 0xC2, 0xB6, 0x1C, 0x0F, 0x19, 0x10, 0x10, 0x10, 0x19, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 56
    0x78, 0xCE, 0x82, 0x82, 0x86, 0xEC, 0xF8, 0x00, 0x10, 0x10, 0x10, 0x08, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 57
    0x30, 0x18, 0x00, // 58
    0x00, 0x30, 0x00, 0x40, 0x38, 0x08, 0x00, 0x00, 0x00, // 59
    0xC0, 0xC0, 0x20, 0x20, 0x10, 0x10, 0x08, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x08, 0x10, 0x10, 0x20, 0x20, 0xC0, 0xC0, 0x06, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0x04, 0x06, 0x02, 0x82, 0x66, 0x3C, 0x00, 0x00, 0x1B, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0xE0, 0x38, 0x0C, 0xC4, 0x32, 0x12, 0x12, 0xF2, 0x06, 0x04, 0x18, 0xF0, 0x07, 0x0C, 0x10, 0x33, 0x26, 0x24, 0x26, 0x23, 0x34, 0x04, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 64
    0x00, 0x00, 0xC0, 0x78, 0x0E, 0x0E, 0x78, 0xC0, 0x00, 0x00, 0x18, 0x0F, 0x03, 0x01, 0x01, 0x01, 0x01, 0x03, 0x0F, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
    0xFE, 0x42, 0x42, 0x42, 0x42, 0xC2, 0xAE, 0x3C, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 66
    0xF0, 0xF8, 0x0C, 0x06, 0x02, 0x02, 0x02, 0x06, 0x06, 0x03, 0x07, 0x0C, 0x18, 0x10, 0x10, 0x10, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x06, 0x0C, 0xF8, 0xF0, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x18, 0x0C, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
    0xFE, 0x42, 0x42, 0x42, 0x42, 0x42, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 69
    0xFE, 0x42, 0x42, 0x42, 0x42, 0x42, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0xF0, 0xF8, 0x0C, 0x06, 0x02, 0x02, 0x82, 0x82, 0x86, 0x80, 0x03, 0x07, 0x0C, 0x18, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
    0xFE, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
    0x02, 0xFE, 0x02, 0x02, 0x10, 0x1F, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, // 73
    0x00, 0xFE, 0xC0, 0x7F, 0x00, 0x00, // 74
    0xFE, 0x80, 0x40, 0xE0, 0x98, 0x0C, 0x06, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x03, 0x06, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 75
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 76
    0xFE, 0x06, 0x3C, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x1C, 0x02, 0xFE, 0x1F, 0x00, 0x00, 0x01, 0x0F, 0x18, 0x07, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
    0xFE, 0x06, 0x1C, 0x30, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0E, 0x18, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
    0xF0, 0xFC, 0x04, 0x06, 0x02, 0x02, 0x02, 0x04, 0xFC, 0xF0, 0x03, 0x0F, 0x08, 0x10, 0x10, 0x10, 0x10, 0x08, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
    0xFE, 0x82, 0x82, 0x82, 0xC6, 0x7C, 0x3C, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0xF0, 0xFC, 0x04, 0x06, 0x02, 0x02, 0x02, 0x04, 0xFC, 0xF0, 0x03, 0x0F, 0x08, 0x10, 0x10, 0x10, 0x30, 0xE8, 0x8F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
    0xFE, 0x82, 0x82, 0x82, 0xC6, 0x7C, 0x3C, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x03, 0x06, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
    0x3C, 0x7E, 0x42, 0xC2, 0x82, 0x86, 0x02, 0x18, 0x10, 0x10, 0x10, 0x10, 0x0D, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 83
    0x02, 0x02, 0x02, 0xFE, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x0C, 0x18, 0x10, 0x10, 0x18, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 85
    0x06, 0x3C, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x3C, 0x06, 0x00, 0x00, 0x01, 0x0F, 0x10, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x0E, 0xFC, 0xC0, 0x00, 0xC0, 0x7C, 0x02, 0x7C, 0x80, 0x00, 0xC0, 0xFC, 0x0E, 0x00, 0x00, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x10, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
    0x02, 0x0E, 0x38, 0xE0, 0xE0, 0x38, 0x0E, 0x02, 0x10, 0x0C, 0x07, 0x01, 0x01, 0x07, 0x1C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
    0x0E, 0x38, 0xE0, 0x80, 0xE0, 0x38, 0x0E, 0x02, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0x02, 0x02, 0x02, 0x82, 0x62, 0x32, 0x0E, 0x06, 0x18, 0x1C, 0x13, 0x11, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 90
    0xFE, 0x02, 0x02, 0xFF, 0x80, 0x80, 0x00, 0x00, 0x00, // 91
    0x06, 0x1C, 0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0E, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 92
    0x02, 0x02, 0xFE, 0x80, 0x80, 0xFF, 0x00, 0x00, 0x00, // 93
    0x80, 0xE0, 0x30, 0x0C, 0x06, 0x0C, 0x30, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 95
    0x01, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x00, 0x30, 0x10, 0x10, 0x10, 0x30, 0xE0, 0x0E, 0x1B, 0x11, 0x11, 0x11, 0x0D, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 97
    0xFF, 0x60, 0x10, 0x10, 0x10, 0xE0, 0xC0, 0x1F, 0x0C, 0x10, 0x10, 0x10, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 98
    0xC0, 0xE0, 0x30, 0x10, 0x10, 0x30, 0x07, 0x0E, 0x18, 0x10, 0x10, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 99
    0xC0, 0xE0, 0x10, 0x10, 0x10, 0x60, 0xFF, 0x07, 0x0E, 0x10, 0x10, 0x10, 0x0C, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 100
    0xC0, 0xE0, 0x30, 0x10, 0x10, 0x60, 0xC0, 0x07, 0x0D, 0x19, 0x11, 0x11, 0x11, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 101
    0x10, 0xFE, 0x13, 0x11, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 102
    0x00, 0xE0, 0x30, 0x10, 0x10, 0x30, 0xF0, 0x10, 0xE0, 0xBD, 0x17, 0x12, 0x12, 0x13, 0xB1, 0xE0, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, // 103
    0xFF, 0x60, 0x10, 0x10, 0x10, 0x30, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 104
    0xF6, 0x1F, 0x00, // 105
    0x00, 0xF6, 0x00, 0xFF, 0x80, 0x80, // 106
    0xFF, 0x00, 0x80, 0xC0, 0x60, 0x30, 0x10, 0x1F, 0x03, 0x01, 0x03, 0x06, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 107
    0xFF, 0x1F, 0x00, // 108
    0xF0, 0x60, 0x10, 0x10, 0x10, 0xF0, 0xE0, 0x30, 0x10, 0x10, 0x30, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
    0xF0, 0x60, 0x10, 0x10, 0x10, 0x30, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 110
    0xC0, 0xE0, 0x10, 0x10, 0x10, 0xE0, 0xC0, 0x07, 0x0E, 0x10, 0x10, 0x10, 0x0E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 111
    0xF0, 0x60, 0x10, 0x10, 0x10, 0xE0, 0xC0, 0xFF, 0x0C, 0x10, 0x10, 0x10, 0x0E, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 112
    0xC0, 0xE0, 0x10, 0x10, 0x10, 0x60, 0xF0, 0x07, 0x0E, 0x10, 0x10, 0x10, 0x0C, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, // 113
    0xF0, 0x40, 0x30, 0x10, 0x10, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114
    0xE0, 0xB0, 0x10, 0x10, 0x30, 0x18, 0x11, 0x11, 0x1B, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, // 115
    0x10, 0xFC, 0x10, 0x10, 0x10, 0x00, 0x0F, 0x18, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, // 116
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x0F, 0x18, 0x10, 0x10, 0x10, 0x0C, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 117
    0x30, 0xE0, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x30, 0x00, 0x01, 0x07, 0x1C, 0x1C, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 118
    0x70, 0xE0, 0x00, 0x00, 0x80, 0x70, 0x70, 0xC0, 0x00, 0x00, 0xE0, 0x70, 0x00, 0x07, 0x1E, 0x1C, 0x07, 0x00, 0x00, 0x07, 0x1C, 0x1E, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
    0x10, 0x30, 0x60, 0x80, 0x80, 0x60, 0x30, 0x10, 0x10, 0x18, 0x0E, 0x03, 0x03, 0x0E, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 120
    0x30, 0xE0, 0x80, 0x00, 0x00, 0x80, 0xE0, 0x30, 0x00, 0x00, 0x87, 0xFC, 0x3C, 0x07, 0x01, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, // 121
    0x10, 0x10, 0x10, 0x90, 0x70, 0x30, 0x18, 0x1C, 0x17, 0x11, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 122
    0x00, 0x00, 0xFC, 0x06, 0x02, 0x01, 0x03, 0x7E, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, // 123
    0xFF, 0xFF, 0x80, // 124
    0x02, 0x06, 0xFC, 0x00, 0x00, 0x80, 0xC0, 0x7E, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // 125
    0x80, 0x40, 0x40, 0x80, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0xFE, 0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 127
    
};

#endif