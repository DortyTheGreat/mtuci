﻿namespace prac_MTUCI
{
    partial class task1_statement
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(task1_statement));
            this.to_main = new System.Windows.Forms.Button();
            this.to_task = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // to_main
            // 
            this.to_main.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.to_main.Location = new System.Drawing.Point(330, 12);
            this.to_main.Name = "to_main";
            this.to_main.Size = new System.Drawing.Size(101, 41);
            this.to_main.TabIndex = 1;
            this.to_main.Text = "На Главную";
            this.to_main.UseVisualStyleBackColor = true;
            this.to_main.Click += new System.EventHandler(this.to_main_Click);
            // 
            // to_task
            // 
            this.to_task.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.to_task.Location = new System.Drawing.Point(330, 397);
            this.to_task.Name = "to_task";
            this.to_task.Size = new System.Drawing.Size(101, 41);
            this.to_task.TabIndex = 2;
            this.to_task.Text = "К Заданию";
            this.to_task.UseVisualStyleBackColor = true;
            this.to_task.Click += new System.EventHandler(this.to_task_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.ImageLocation = "";
            this.pictureBox1.Location = new System.Drawing.Point(229, 59);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(312, 235);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 5;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F);
            this.label1.Location = new System.Drawing.Point(12, 308);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(593, 80);
            this.label1.TabIndex = 6;
            this.label1.Text = resources.GetString("label1.Text");
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // task1_statement
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 461);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.to_task);
            this.Controls.Add(this.to_main);
            this.Name = "task1_statement";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Условие";
            this.Load += new System.EventHandler(this.task1_statement_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button to_main;
        private System.Windows.Forms.Button to_task;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
    }
}