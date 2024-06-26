using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Media;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using static prac_MTUCI.main;

namespace prac_MTUCI
{
    public partial class task2_statement : Form
    {
        static SoundPlayer simpleSound = new SoundPlayer("p_craft.wav");
        public task2_statement()
        {
            InitializeComponent();
        }

        private void to_main_Click(object sender, EventArgs e)
        {
            main f = new main();
            this.Hide();
            f.ShowDialog();
        }

        private void to_task_Click(object sender, EventArgs e)
        {
            task2 f = new task2();
            this.Hide();
            f.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.Text == "Белый")
            {
                prac_MTUCI.main.Back_Color = SystemColors.Control;
            }
            
            if (comboBox1.Text == "Голубой")
            {
                prac_MTUCI.main.Back_Color = SystemColors.ActiveCaption;
            }

            if (comboBox1.Text == "Серый")
            {
                prac_MTUCI.main.Back_Color = SystemColors.InactiveCaption;
            }

            this.BackColor = prac_MTUCI.main.Back_Color;
        }

        private void task2_statement_Load(object sender, EventArgs e)
        {
            this.BackColor = prac_MTUCI.main.Back_Color;

            if (isActive)
            {
                button2.Text = "Пауза";
            }
            else
            {
                button2.Text = "Включить Музыку";
            }
        }

        static bool isActive = false;

        private void button2_Click(object sender, EventArgs e)
        {
            isActive ^= true;
            if (isActive)
            {
                button2.Text = "Пауза";
                simpleSound.PlayLooping();
            }
            else
            {
                button2.Text = "Включить Музыку";
                simpleSound.Stop();
            }
        }
    }
}
