using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Microsoft.Win32;
using System.IO;
using static System.Windows.Forms.AxHost;

namespace light_sensor
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        public bool state = true;
        public  Form1 frm = new Form1();

        private void timer1_Tick(object sender, EventArgs e)
        {
            progress.Width += 2;
            label2.Text = progress.Width / 10 + 20 + "%";

            if (progress.Width >= 300)
            {
                label1.Text = "Created by NuclearMind Team";
              
                this.Name = "Strat";
                //for (int i = 350; i < 450; i++)
                //{

                //    if (state == true)
                //    {
                //        this.Location = new System.Drawing.Point(i, progress.Width - 100);

                //        this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;

                //    }




                //}
            }
            if (progress.Width >= 600)
            {
                state = false;
              //  this.Location = new System.Drawing.Point(400, 500);

             //   this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
                label1.Text = "  Prof. Hesham Arafat  ";
              //  Font font = new Font("Segoe UI", 24);
              //  this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;

               label1.Font = new System.Drawing.Font("Segoe UI", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
                label1.Location = new System.Drawing.Point(250, 6);
            }

            if (progress.Width >= 800)
            {
                timer1.Stop();
                frm.Show();
                this.Hide();
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            //string path = "sensor.log";
            //if (!File.Exists(path))
            //{
            //    StreamWriter sw = new StreamWriter(path, false);

            //    StratUp();
            //}
            //string Desktop_path = @"C:\Users\" + Environment.UserName + @"\OneDrive\Desktop\sensor.log";

            //if (!File.Exists(Desktop_path))
            //{
            //    StreamWriter sw = new StreamWriter(Desktop_path, false);

            //}
        }

        //public void StratUp()
        //{

        //   RegistryKey registryKey = Registry.CurrentUser.OpenSubKey("Computer\\HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run");
        //   registryKey.SetValue("light sensor", Application.ExecutablePath.ToString());
        //}
    }
}
