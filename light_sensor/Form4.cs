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
    public partial class Light : Form
    {
        public Light()
        {
            InitializeComponent();
        }
        public string msg;
        public int x ,y ;
        private void Light_Load(object sender, EventArgs e)
        {
            label1.Text = msg;

            this.x = Screen.PrimaryScreen.WorkingArea.Width - this.Width + 5;
            this.y = Screen.PrimaryScreen.WorkingArea.Height - this.Height * 3;
            this.Location = new Point(this.x, this.y);
        }

        private void close_Click(object sender, EventArgs e)
        {
            this.Close();

        }

        public void Light_Click(object sender, EventArgs e)
        {
            Form2 form = new Form2();
            form.frm.ShowDialog();
        }
    }
}
