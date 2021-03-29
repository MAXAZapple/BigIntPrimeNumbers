using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace THE_CALCULATOR
{
    public partial class Form1 : Form
    {
        byte Fun;
        double a, b;
        string s = "";

        private void button0_Click(object sender, EventArgs e)
        {
            textBox1.Text += button0.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text += button1.Text;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text += button2.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text += button3.Text;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text += button4.Text;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox1.Text += button5.Text;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox1.Text += button6.Text;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Text += button7.Text;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text += button8.Text;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.Text += button9.Text;
        }

        private void buttonD_Click(object sender, EventArgs e)
        {
            textBox1.Text += buttonD.Text;
                buttonD.Enabled = false;
        }

        private void button14_Click(object sender, EventArgs e) //кнопка РАВНО
        {            
                b = Convert.ToDouble(textBox1.Text);
                switch (Fun)
                {
                    case 0:
                        textBox1.Text = Convert.ToString(a + b);
                        break;
                    case 1:
                        textBox1.Text = Convert.ToString(a - b);
                        break;
                    case 2:
                        textBox1.Text = Convert.ToString(a * b);
                        break;
                    case 3:
                        try { textBox1.Text = Convert.ToString(a / b); }
                        catch { }
                        break;
                    default:
                        break;
                }
                buttonD.Enabled = true;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            Fun = 0;
            a = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            Fun = 1;
            a = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            Fun = 2;
            a = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
        }

        private void button13_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            Fun = 3;
            a = Convert.ToDouble(textBox1.Text);
            textBox1.Text = "";
        }

        private void buttonSqrt_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            textBox1.Text = Convert.ToString(Math.Sqrt(Convert.ToDouble(textBox1.Text)));
        }

        private void buttonSign_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            textBox1.Text = Convert.ToString(0 - Convert.ToDouble(textBox1.Text));
        }

        private void buttonReverse_Click(object sender, EventArgs e)
        {
            buttonD.Enabled = true;
            textBox1.Text = Convert.ToString(1 / Convert.ToDouble(textBox1.Text));
        }

        private void button99_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }

        public Form1()
        {
            InitializeComponent();
        }
    }
}
