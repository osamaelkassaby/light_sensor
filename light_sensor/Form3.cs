using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace light_sensor
{
    public partial class Alert_dark : Form
    {
        public Alert_dark()
        {
            InitializeComponent();
        }
        public string msg;

        public int x, y;

        private void close_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Alert_dark_Click(object sender, EventArgs e)
        {
            Light light = new Light();
            light.Light_Click(sender , e);
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            label1.Text = msg;
          
            
                    this.x = Screen.PrimaryScreen.WorkingArea.Width - this.Width + 5;
                    this.y = Screen.PrimaryScreen.WorkingArea.Height - this.Height * 2;
                    this.Location = new Point(this.x, this.y);
                


        }
    }
}
