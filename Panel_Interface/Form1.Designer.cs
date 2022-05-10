
namespace Panel_Interface
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonConnect = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.textboxServer = new System.Windows.Forms.TextBox();
            this.textBoxPort = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button_sendPanel1 = new System.Windows.Forms.Button();
            this.textBox_Panel1Data = new System.Windows.Forms.TextBox();
            this.textBox_Panel2Data = new System.Windows.Forms.TextBox();
            this.button_sendPanel2 = new System.Windows.Forms.Button();
            this.textBox_Panel3Data = new System.Windows.Forms.TextBox();
            this.button_sendPanel3 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.buttonStop = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.listBoxConnectDevices = new System.Windows.Forms.ListBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.listBoxReceivedata = new System.Windows.Forms.ListBox();
            this.label4 = new System.Windows.Forms.Label();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonConnect
            // 
            this.buttonConnect.Location = new System.Drawing.Point(41, 103);
            this.buttonConnect.Name = "buttonConnect";
            this.buttonConnect.Size = new System.Drawing.Size(279, 23);
            this.buttonConnect.TabIndex = 0;
            this.buttonConnect.Text = "Start";
            this.buttonConnect.UseVisualStyleBackColor = true;
            this.buttonConnect.Click += new System.EventHandler(this.buttonConnect_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(53, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "SERVER IP";
            // 
            // textboxServer
            // 
            this.textboxServer.Location = new System.Drawing.Point(149, 30);
            this.textboxServer.Multiline = true;
            this.textboxServer.Name = "textboxServer";
            this.textboxServer.Size = new System.Drawing.Size(171, 20);
            this.textboxServer.TabIndex = 2;
            // 
            // textBoxPort
            // 
            this.textBoxPort.Location = new System.Drawing.Point(149, 70);
            this.textBoxPort.Name = "textBoxPort";
            this.textBoxPort.Size = new System.Drawing.Size(171, 22);
            this.textBoxPort.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(53, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "PORT";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(38, 162);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(111, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Connect Status";
            // 
            // button_sendPanel1
            // 
            this.button_sendPanel1.Location = new System.Drawing.Point(41, 22);
            this.button_sendPanel1.Name = "button_sendPanel1";
            this.button_sendPanel1.Size = new System.Drawing.Size(128, 23);
            this.button_sendPanel1.TabIndex = 6;
            this.button_sendPanel1.Text = "Send Data";
            this.button_sendPanel1.UseVisualStyleBackColor = true;
            this.button_sendPanel1.Click += new System.EventHandler(this.button_sendPanel1_Click);
            // 
            // textBox_Panel1Data
            // 
            this.textBox_Panel1Data.Location = new System.Drawing.Point(189, 23);
            this.textBox_Panel1Data.Name = "textBox_Panel1Data";
            this.textBox_Panel1Data.Size = new System.Drawing.Size(131, 22);
            this.textBox_Panel1Data.TabIndex = 7;
            // 
            // textBox_Panel2Data
            // 
            this.textBox_Panel2Data.Location = new System.Drawing.Point(189, 89);
            this.textBox_Panel2Data.Name = "textBox_Panel2Data";
            this.textBox_Panel2Data.Size = new System.Drawing.Size(131, 22);
            this.textBox_Panel2Data.TabIndex = 9;
            // 
            // button_sendPanel2
            // 
            this.button_sendPanel2.Location = new System.Drawing.Point(41, 89);
            this.button_sendPanel2.Name = "button_sendPanel2";
            this.button_sendPanel2.Size = new System.Drawing.Size(128, 23);
            this.button_sendPanel2.TabIndex = 8;
            this.button_sendPanel2.Text = "Send Data";
            this.button_sendPanel2.UseVisualStyleBackColor = true;
            this.button_sendPanel2.Click += new System.EventHandler(this.button_sendPanel2_Click);
            // 
            // textBox_Panel3Data
            // 
            this.textBox_Panel3Data.Location = new System.Drawing.Point(189, 162);
            this.textBox_Panel3Data.Name = "textBox_Panel3Data";
            this.textBox_Panel3Data.Size = new System.Drawing.Size(131, 22);
            this.textBox_Panel3Data.TabIndex = 11;
            // 
            // button_sendPanel3
            // 
            this.button_sendPanel3.Location = new System.Drawing.Point(41, 162);
            this.button_sendPanel3.Name = "button_sendPanel3";
            this.button_sendPanel3.Size = new System.Drawing.Size(128, 23);
            this.button_sendPanel3.TabIndex = 10;
            this.button_sendPanel3.Text = "Send Data";
            this.button_sendPanel3.UseVisualStyleBackColor = true;
            this.button_sendPanel3.Click += new System.EventHandler(this.button_sendPanel3_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.progressBar1);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.listBoxReceivedata);
            this.groupBox1.Controls.Add(this.buttonStop);
            this.groupBox1.Controls.Add(this.label11);
            this.groupBox1.Controls.Add(this.listBoxConnectDevices);
            this.groupBox1.Controls.Add(this.textBoxPort);
            this.groupBox1.Controls.Add(this.buttonConnect);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.textboxServer);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(610, 215);
            this.groupBox1.TabIndex = 15;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "SETUP";
            // 
            // buttonStop
            // 
            this.buttonStop.Location = new System.Drawing.Point(41, 132);
            this.buttonStop.Name = "buttonStop";
            this.buttonStop.Size = new System.Drawing.Size(279, 23);
            this.buttonStop.TabIndex = 14;
            this.buttonStop.Text = "Stop";
            this.buttonStop.UseVisualStyleBackColor = true;
            this.buttonStop.Click += new System.EventHandler(this.buttonStop_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(403, 30);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(143, 16);
            this.label11.TabIndex = 13;
            this.label11.Text = "Connected Devices";
            // 
            // listBoxConnectDevices
            // 
            this.listBoxConnectDevices.FormattingEnabled = true;
            this.listBoxConnectDevices.ItemHeight = 16;
            this.listBoxConnectDevices.Location = new System.Drawing.Point(400, 55);
            this.listBoxConnectDevices.Name = "listBoxConnectDevices";
            this.listBoxConnectDevices.Size = new System.Drawing.Size(179, 20);
            this.listBoxConnectDevices.TabIndex = 7;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.button_sendPanel1);
            this.groupBox2.Controls.Add(this.textBox_Panel1Data);
            this.groupBox2.Controls.Add(this.button_sendPanel2);
            this.groupBox2.Controls.Add(this.textBox_Panel2Data);
            this.groupBox2.Controls.Add(this.button_sendPanel3);
            this.groupBox2.Controls.Add(this.textBox_Panel3Data);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(12, 223);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(610, 218);
            this.groupBox2.TabIndex = 16;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "SEND DATA";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(397, 169);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(65, 16);
            this.label9.TabIndex = 14;
            this.label9.Text = "PANEL3";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(397, 95);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(65, 16);
            this.label8.TabIndex = 13;
            this.label8.Text = "PANEL2";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(397, 30);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(65, 16);
            this.label7.TabIndex = 12;
            this.label7.Text = "PANEL1";
            // 
            // listBoxReceivedata
            // 
            this.listBoxReceivedata.FormattingEnabled = true;
            this.listBoxReceivedata.ItemHeight = 16;
            this.listBoxReceivedata.Location = new System.Drawing.Point(400, 129);
            this.listBoxReceivedata.Name = "listBoxReceivedata";
            this.listBoxReceivedata.Size = new System.Drawing.Size(179, 20);
            this.listBoxReceivedata.TabIndex = 15;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(403, 100);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(99, 16);
            this.label4.TabIndex = 16;
            this.label4.Text = "ReceiveData";
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(41, 182);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(279, 23);
            this.progressBar1.TabIndex = 17;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(634, 450);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonConnect;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textboxServer;
        private System.Windows.Forms.TextBox textBoxPort;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button_sendPanel1;
        private System.Windows.Forms.TextBox textBox_Panel1Data;
        private System.Windows.Forms.TextBox textBox_Panel2Data;
        private System.Windows.Forms.Button button_sendPanel2;
        private System.Windows.Forms.TextBox textBox_Panel3Data;
        private System.Windows.Forms.Button button_sendPanel3;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.ListBox listBoxConnectDevices;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button buttonStop;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox listBoxReceivedata;
        private System.Windows.Forms.ProgressBar progressBar1;
    }
}

