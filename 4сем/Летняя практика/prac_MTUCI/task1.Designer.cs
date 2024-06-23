namespace prac_MTUCI
{
    partial class task1
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            this.to_statement = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.t0_txtBox = new System.Windows.Forms.TextBox();
            this.Calculate = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.s0_txtBox = new System.Windows.Forms.TextBox();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.it_txtBox = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.h_txtBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.label7 = new System.Windows.Forms.Label();
            this.s1_txtBox = new System.Windows.Forms.TextBox();
            this.v_fall_txtBox = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.t_fall_txtBox = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // to_statement
            // 
            this.to_statement.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.to_statement.Location = new System.Drawing.Point(330, 12);
            this.to_statement.Name = "to_statement";
            this.to_statement.Size = new System.Drawing.Size(101, 41);
            this.to_statement.TabIndex = 2;
            this.to_statement.Text = "К условию";
            this.to_statement.UseVisualStyleBackColor = true;
            this.to_statement.Click += new System.EventHandler(this.to_statement_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label1.Location = new System.Drawing.Point(10, 92);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(20, 18);
            this.label1.TabIndex = 3;
            this.label1.Text = "t0";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // t0_txtBox
            // 
            this.t0_txtBox.Enabled = false;
            this.t0_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.t0_txtBox.Location = new System.Drawing.Point(36, 92);
            this.t0_txtBox.Name = "t0_txtBox";
            this.t0_txtBox.Size = new System.Drawing.Size(149, 24);
            this.t0_txtBox.TabIndex = 4;
            this.t0_txtBox.Text = "0";
            this.t0_txtBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox1_KeyPress);
            // 
            // Calculate
            // 
            this.Calculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.Calculate.Location = new System.Drawing.Point(330, 408);
            this.Calculate.Name = "Calculate";
            this.Calculate.Size = new System.Drawing.Size(101, 41);
            this.Calculate.TabIndex = 7;
            this.Calculate.Text = "Высчитать";
            this.Calculate.UseVisualStyleBackColor = true;
            this.Calculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label3.Location = new System.Drawing.Point(10, 128);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(24, 18);
            this.label3.TabIndex = 8;
            this.label3.Text = "s0";
            // 
            // s0_txtBox
            // 
            this.s0_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.s0_txtBox.Location = new System.Drawing.Point(36, 128);
            this.s0_txtBox.Name = "s0_txtBox";
            this.s0_txtBox.Size = new System.Drawing.Size(149, 24);
            this.s0_txtBox.TabIndex = 10;
            this.s0_txtBox.Text = "10";
            this.s0_txtBox.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox2_KeyPress);
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label2.Location = new System.Drawing.Point(10, 61);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(148, 18);
            this.label2.TabIndex = 11;
            this.label2.Text = "Начальные условия";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label4.Location = new System.Drawing.Point(10, 205);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(188, 18);
            this.label4.TabIndex = 12;
            this.label4.Text = "Значения интегрирования";
            // 
            // it_txtBox
            // 
            this.it_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.it_txtBox.Location = new System.Drawing.Point(36, 276);
            this.it_txtBox.Name = "it_txtBox";
            this.it_txtBox.Size = new System.Drawing.Size(149, 24);
            this.it_txtBox.TabIndex = 16;
            this.it_txtBox.Text = "30";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label5.Location = new System.Drawing.Point(10, 276);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(15, 18);
            this.label5.TabIndex = 15;
            this.label5.Text = "it";
            // 
            // h_txtBox
            // 
            this.h_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.h_txtBox.Location = new System.Drawing.Point(36, 240);
            this.h_txtBox.Name = "h_txtBox";
            this.h_txtBox.Size = new System.Drawing.Size(149, 24);
            this.h_txtBox.TabIndex = 14;
            this.h_txtBox.Text = "0,1";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label6.Location = new System.Drawing.Point(10, 240);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(16, 18);
            this.label6.TabIndex = 13;
            this.label6.Text = "h";
            // 
            // dataGridView2
            // 
            this.dataGridView2.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.dataGridView2.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.ColumnHeadersVisible = false;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridView2.DefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridView2.Location = new System.Drawing.Point(244, 128);
            this.dataGridView2.Margin = new System.Windows.Forms.Padding(2);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowHeadersVisible = false;
            this.dataGridView2.RowHeadersWidth = 51;
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(436, 114);
            this.dataGridView2.TabIndex = 17;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label7.Location = new System.Drawing.Point(10, 167);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(24, 18);
            this.label7.TabIndex = 18;
            this.label7.Text = "s1";
            // 
            // s1_txtBox
            // 
            this.s1_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.s1_txtBox.Location = new System.Drawing.Point(36, 167);
            this.s1_txtBox.Name = "s1_txtBox";
            this.s1_txtBox.Size = new System.Drawing.Size(149, 24);
            this.s1_txtBox.TabIndex = 19;
            this.s1_txtBox.Text = "8";
            // 
            // v_fall_txtBox
            // 
            this.v_fall_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.v_fall_txtBox.Location = new System.Drawing.Point(93, 398);
            this.v_fall_txtBox.Name = "v_fall_txtBox";
            this.v_fall_txtBox.Size = new System.Drawing.Size(149, 24);
            this.v_fall_txtBox.TabIndex = 24;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label8.Location = new System.Drawing.Point(10, 398);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(80, 18);
            this.label8.TabIndex = 23;
            this.label8.Text = "v_падения";
            // 
            // t_fall_txtBox
            // 
            this.t_fall_txtBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.t_fall_txtBox.Location = new System.Drawing.Point(93, 362);
            this.t_fall_txtBox.Name = "t_fall_txtBox";
            this.t_fall_txtBox.Size = new System.Drawing.Size(149, 24);
            this.t_fall_txtBox.TabIndex = 22;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label9.Location = new System.Drawing.Point(10, 362);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(77, 18);
            this.label9.TabIndex = 21;
            this.label9.Text = "t_падения";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.label10.Location = new System.Drawing.Point(10, 327);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(61, 18);
            this.label10.TabIndex = 20;
            this.label10.Text = "Ответы";
            // 
            // task1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 461);
            this.Controls.Add(this.v_fall_txtBox);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.t_fall_txtBox);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.s1_txtBox);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.dataGridView2);
            this.Controls.Add(this.it_txtBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.h_txtBox);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.s0_txtBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Calculate);
            this.Controls.Add(this.t0_txtBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.to_statement);
            this.Name = "task1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Задание №1";
            this.Load += new System.EventHandler(this.task1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button to_statement;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox t0_txtBox;
        private System.Windows.Forms.Button Calculate;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox s0_txtBox;
        private System.Windows.Forms.ErrorProvider errorProvider1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox it_txtBox;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox h_txtBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.TextBox s1_txtBox;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox v_fall_txtBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.TextBox t_fall_txtBox;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
    }
}