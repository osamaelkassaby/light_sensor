using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace light_sensor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public string data;
        public bool status ;
        public int mode = 1;
        public int mode_2 = 0;
        public bool hide;
        public Alert_dark form = new Alert_dark();
        public Light light = new Light();

        public void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            status = true;
            data = serialPort1.ReadExisting();
          
        }

        private void conn_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = comboBox1.Text;
                serialPort1.BaudRate = Convert.ToInt32(9600);
                serialPort1.Open();

            }catch(Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            comboBox1.Items.Clear();
            comboBox1.Items.AddRange(ports);
        }
   

        public void timer1_Tick(object sender, EventArgs e)
        {
            if(status == true)
            {
                if (Int32.Parse(data) == 1)
                {
                   
               //     this.BackColor = System.Drawing.Color.White;
                   // this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(217)))), ((int)(((byte)(4)))), ((int)(((byte)(41)))));
                  //  this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(217)))), ((int)(((byte)(4)))), ((int)(((byte)(41)))));
                  //  this.comboBox1.BackColor = System.Drawing.Color.White;
                  //  this.comboBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(217)))), ((int)(((byte)(4)))), ((int)(((byte)(41)))));
                   
                    label2.Text = "DARK";

                    if(mode == 1)
                    {
                        string Desktop_path = @"C:\Users\" + Environment.UserName + @"\OneDrive\Desktop\sensor.log";

                        StreamReader sr = new StreamReader(Desktop_path, false);
                        string sr_r = sr.ReadToEnd();
                        sr.Close();
                        StreamWriter sw = new StreamWriter(Desktop_path);
                        sw.WriteLine("TIME : (" + DateTime.Now + ")" + " ===>  Dark");
                        sw.Write(sr_r);
                        sw.Close();
                        mode = 0;
                        mode_2 = 1;
                        if(hide == true)
                        {
                          
                            form.msg = "Dark";
                            form.ShowDialog();
                        }
                      

                    }
                

                }
                else if (Int32.Parse(data) == 0)
                {
              //      this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(2)))), ((int)(((byte)(48)))), ((int)(((byte)(71)))));
                //    this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(190)))), ((int)(((byte)(11)))));
                 //   this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(190)))), ((int)(((byte)(11)))));
                  //  this.comboBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(2)))), ((int)(((byte)(48)))), ((int)(((byte)(71)))));
                  //  this.comboBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(190)))), ((int)(((byte)(11)))));
                    label2.Text = "LIGHT";

                    if (mode_2 == 1)
                    {
                        string Desktop_path = @"C:\Users\" + Environment.UserName + @"\OneDrive\Desktop\sensor.log";

                        StreamReader sr = new StreamReader(Desktop_path, false);
                        string sr_r = sr.ReadToEnd();
                        sr.Close();
                        StreamWriter sw = new StreamWriter(Desktop_path);
                        sw.WriteLine("TIME : (" + DateTime.Now + ")" + " ===>  Light");
                        sw.WriteLine(sr_r);
                        sw.Close();
                        mode_2 = 0;
                        mode = 1;
                        if (hide == true)
                        {
                            light.msg = "LIGHT";
                            light.ShowDialog();
                        }
                    }
                   
                    
                  

                }
            }
           
          
        }

        private void close_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            hide = true;

            this.Hide();
        }
    }
}
