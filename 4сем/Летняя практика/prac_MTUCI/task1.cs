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

        double s(double t, double s0, double s1)
        {
            double b = (s0 + s1) / 2;

            double c_1 = (s0 - b) / 2, c_2 = (s0 - b) / 2;

            return c_1 * Math.Pow(Math.E, Math.Sqrt(g) * t / Math.Sqrt(b)) + c_2 * Math.Pow(Math.E, -Math.Sqrt(g) * t / Math.Sqrt(b)) + b;
        }

        double s_deriv(double t, double s0, double s1)
        {
            double eps = 0.00001;
            return (s(t + eps, s0, s1) - s(t, s0, s1))/ eps;
        }

        public unsafe double[] diff_solve_arr(double t0, double h, int it, double s0, double s1)
        {
            double[] arr = new double[it];
            for(int i =0; i < it; ++i)
            {
                arr[i] = s(t0, s0, s1);
                t0 += h;
            }
            return arr;
        }

        double binary_search(double s0, double s1, double eps)
        {
            double l = 0; // f(l)=0
            double r = 1e10; // f(r)=1
            while (r - l > eps)
            {
                double m = (r + l) / 2;
                if (s(m, s0, s1) > (s0 + s1)) // target = s0 + s1
                    r = m;
                else
                    l = m;
            }
            return (r + l)/ 2;
        }

        private void Calculate_Click(object sender, EventArgs e)
        {

            double t0, s0, s1;

            double h, it;

            double ans1, ans2, ans3 = 0;
            String final_content = "Задание №1\n\n";
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


            output_mas(diff_solve_arr(t0, h, Int32.Parse(it.ToString()), s0, s1), Int32.Parse(it.ToString()), dataGridView2, h);

            t_fall_txtBox.Text = binary_search(s0, s1, 0.00001).ToString("F3");

            final_content += "t_падения = " + t_fall_txtBox.Text + '\n';

            v_fall_txtBox.Text = s_deriv(binary_search(s0, s1, 0.00001), s0, s1).ToString("F3");

            final_content += "v_падения = " + v_fall_txtBox.Text + '\n';

            System.IO.File.WriteAllText("task1.txt", final_content);
        }

        private void task1_Load(object sender, EventArgs e)
        {

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
    }
}
