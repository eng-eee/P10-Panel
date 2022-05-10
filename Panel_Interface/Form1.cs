using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;      //required
using System.Net.Sockets;    //required

namespace Panel_Interface
{
    public partial class Form1 : Form
    {
        TcpListener server;
        TcpClient client;
        public delegate void AddListItem();
        public AddListItem ConnectStatus;
        public AddListItem AddList;
        EndPoint ipaddr;
        bool flag = true;
        byte[] buff;
        public Form1()
        {
            InitializeComponent();
            AddList = new AddListItem(AddListDeviceFunc);
            ConnectStatus = new AddListItem(ReceiveStatusFunc);
        }

        private void buttonConnect_Click(object sender, EventArgs e)
        {
            IPAddress adres = IPAddress.Parse(textboxServer.Text);
            server = new TcpListener(adres, Convert.ToInt32(textBoxPort.Text));
            try
            {
                buttonStop.Enabled = true;
                buttonConnect.Enabled = false;
                server.Start();
                progressBar1.Value = 100;
            }
            catch { }

            new Task(() =>
            {
                client = server.AcceptTcpClient();
                ipaddr = client.Client.RemoteEndPoint;
                listBoxConnectDevices.Invoke(AddList);
                while (flag)
                {
                    
                    if (client.Client.Available>0)
                    {
                        buff = new byte[client.Client.Available];
                        client.Client.Receive(buff);
                        listBoxReceivedata.Invoke(ConnectStatus);

                    }
                    if (!client.Client.Poll(0, SelectMode.SelectRead))
                        flag = false;
                }
            }).Start();

        }

        void ReceiveStatusFunc() //Delegate
        {
            listBoxReceivedata.Text = Encoding.UTF8.GetString(buff);
        }

       void AddListDeviceFunc() //Delegatefunc
        {
            listBoxConnectDevices.Items.Add(ipaddr.ToString());
        }


        private void buttonStop_Click(object sender, EventArgs e)
        {

                buttonConnect.Enabled = true;
                buttonStop.Enabled = false;
                server.Stop();
                progressBar1.Value = 0;
                
        }

        private void button_sendPanel1_Click(object sender, EventArgs e)
        {
            byte[] recivedata=Encoding.ASCII.GetBytes(textBox_Panel1Data.Text);
            client.Client.Send(recivedata);

        }

        private void button_sendPanel2_Click(object sender, EventArgs e)
        {
            byte[] recivedata = Encoding.ASCII.GetBytes(textBox_Panel2Data.Text);
            client.Client.Send(recivedata);
        }

        private void button_sendPanel3_Click(object sender, EventArgs e)
        {
            byte[] recivedata = Encoding.ASCII.GetBytes(textBox_Panel3Data.Text);
            client.Client.Send(recivedata);
        }
    }
}
