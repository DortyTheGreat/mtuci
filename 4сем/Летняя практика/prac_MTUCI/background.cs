using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static dll_for_prac.Class1;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace prac_MTUCI
{
    public partial class task1 : Form
    {
        public task1()
        {
            InitializeComponent();
        }

        public void output_mas(double[] mas, int len, DataGridView grid, double h)
        {
            grid.RowCount = 2;
            grid.ColumnCount = len;

            for (int i = 0; i < len; i++)
            {
                grid.Rows[0].Cells[i].Value = (i * h).ToString("F3");
                grid.Rows[1].Cells[i].Value = mas[i].ToString("F3");
            }
        }

        const double g = 9.8;

        double s1 = 8;
        double s0 = 10;
        double t_last = 2.767;

        double s(double t)
        {
            double b = (s0 + s1) / 2;

            double c_1 = (s0 - b) / 2, c_2 = (s0 - b) / 2;

            return c_1 * Math.Pow(Math.E, Math.Sqrt(g) * t / Math.Sqrt(b)) + c_2 * Math.Pow(Math.E, -Math.Sqrt(g) * t / Math.Sqrt(b)) + b;
        }

        double s_deriv(double t)
        {
            double eps = 0.00001;
            return (s(t + eps) - s(t))/ eps;
        }

        public unsafe double[] diff_solve_arr(double t0, double h, int it, double s0, double s1)
        {
            double[] arr = new double[it];
            for(int i =0; i < it; ++i)
            {
                arr[i] = s(t0);
                t0 += h;
            }
            return arr;
        }

        double binary_search(double eps = 0.0001)
        {
            double l = 0; // f(l)=0
            double r = 1e10; // f(r)=1
            while (r - l > eps)
            {
                double m = (r + l) / 2;
                if (s(m) > (s0 + s1)) // target = s0 + s1
                    r = m;
                else
                    l = m;
            }
            return (r + l)/ 2;
        }
        String final_content = "Не было произведено расчёта";
        private void Calculate_Click(object sender, EventArgs e)
        {

            double t0;

            double h, it;

            double ans1, ans2, ans3 = 0;
            final_content = "Задание №1\n\n";
            if (Input(t0_txtBox, out t0, errorProvider1, "В поля для ввода данных допускается лишь ввод числовых значений с плавающей точкой"))
            {  
                final_content += "t0 = " + t0 + '\n';
            }

            if (Input(s0_txtBox, out s0, errorProvider1, "В поля для ввода данных допускается лишь ввод числовых значений с плавающей точкой"))
            {
                final_content += "s0 = " + s0 + '\n';
            }

            if (Input(s1_txtBox, out s1, errorProvider1, "В поля для ввода данных допускается лишь ввод числовых значений с плавающей точкой"))
            {
                final_content += "s1 = " + s1 + '\n' + '\n';
            }

            if (Input(h_txtBox, out h, errorProvider1, "В поля для ввода данных допускается лишь ввод числовых значений с плавающей точкой"))
            {
                final_content += "h = " + h + '\n';
            }

            if (Input(it_txtBox, out it, errorProvider1, "В поля для ввода данных допускается лишь ввод числовых значений с плавающей точкой"))
            {
                final_content += "it = " + it + '\n' + '\n';
            }

            animate();

            output_mas(diff_solve_arr(t0, h, Int32.Parse(it.ToString()), s0, s1), Int32.Parse(it.ToString()), dataGridView2, h);

            t_last = binary_search();

            t_fall_txtBox.Text = t_last.ToString("F3");

            final_content += "t_падения = " + t_fall_txtBox.Text + '\n';

            v_fall_txtBox.Text = s_deriv(binary_search(0.00001)).ToString("F3");

            final_content += "v_падения = " + v_fall_txtBox.Text + '\n';
        }

        private void task1_Load(object sender, EventArgs e)
        {
            animate();
        }

        private void to_statement_Click(object sender, EventArgs e)
        {
            task1_statement f = new task1_statement();
            this.Hide();
            f.ShowDialog();
        }

        private void textBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            NumberLimiter(e, s0_txtBox);
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            NumberLimiter(e, t0_txtBox);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (animation_tb.Value == 100)
            {
                animation_tb.Value = 0;
                timer1.Enabled = true;
                return;
            }
            timer1.Enabled ^= true;
            if (timer1.Enabled)
            {
                button2.Text = "Пауза";
            }
            else
            {
                button2.Text = "Аимировать";
            }
        }

        void animate()
        {
            double cur_time = (animation_tb.Value / 100.0) * t_last;

            double new_s0 = 10 * s(cur_time);
            double new_s1 = 10 * ((s1+s0)- s(cur_time)); 

            picture_s1.Size = new Size(picture_s1.Size.Width, Convert.ToInt32(Math.Ceiling(new_s1)));
            picture_s0.Size = new Size(picture_s0.Size.Width, Convert.ToInt32(Math.Ceiling(new_s0)));
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (animation_tb.Value >= 99)
            {
                animation_tb.Value = 100;
                button2.Text = "Анимировать";
                timer1.Enabled = false;
                animate();
                return;
            }
            animation_tb.Value += 1;
            animate();
        }

        private void animation_tb_Scroll(object sender, EventArgs e)
        {
            animate();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.IO.File.WriteAllText("task1.txt", final_content);
        }
    }
}
