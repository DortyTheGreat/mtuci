#pragma once
#include "Algorithms.h"
#include <iostream>
#include <iomanip>

namespace visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox3;





	private: System::Windows::Forms::GroupBox^ groupBox2;






	private: System::Windows::Forms::Label^ label6;







	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ DATA_CB;

	private: System::Windows::Forms::Label^ label3;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ EA_CB;

	private: System::Windows::Forms::TextBox^ EA_TB4;

	private: System::Windows::Forms::TextBox^ EA_TB3;

	private: System::Windows::Forms::TextBox^ EA_TB2;

	private: System::Windows::Forms::TextBox^ EA_TB1;

	private: System::Windows::Forms::Label^ EA_L4;
	private: System::Windows::Forms::Label^ EA_L3;
	private: System::Windows::Forms::Label^ EA_L2;
	private: System::Windows::Forms::Label^ EA_L1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox2;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;











	protected:















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->EA_L4 = (gcnew System::Windows::Forms::Label());
			this->EA_L3 = (gcnew System::Windows::Forms::Label());
			this->EA_L2 = (gcnew System::Windows::Forms::Label());
			this->EA_L1 = (gcnew System::Windows::Forms::Label());
			this->EA_TB4 = (gcnew System::Windows::Forms::TextBox());
			this->EA_TB3 = (gcnew System::Windows::Forms::TextBox());
			this->EA_TB2 = (gcnew System::Windows::Forms::TextBox());
			this->EA_TB1 = (gcnew System::Windows::Forms::TextBox());
			this->EA_CB = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->DATA_CB = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->EA_L4);
			this->groupBox3->Controls->Add(this->EA_L3);
			this->groupBox3->Controls->Add(this->EA_L2);
			this->groupBox3->Controls->Add(this->EA_L1);
			this->groupBox3->Controls->Add(this->EA_TB4);
			this->groupBox3->Controls->Add(this->EA_TB3);
			this->groupBox3->Controls->Add(this->EA_TB2);
			this->groupBox3->Controls->Add(this->EA_TB1);
			this->groupBox3->Controls->Add(this->EA_CB);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox3->Location = System::Drawing::Point(795, 21);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(530, 335);
			this->groupBox3->TabIndex = 39;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Добавление Элемента";
			// 
			// EA_L4
			// 
			this->EA_L4->AutoSize = true;
			this->EA_L4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L4->Location = System::Drawing::Point(242, 146);
			this->EA_L4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EA_L4->Name = L"EA_L4";
			this->EA_L4->Size = System::Drawing::Size(101, 26);
			this->EA_L4->TabIndex = 45;
			this->EA_L4->Text = L"Порода4";
			// 
			// EA_L3
			// 
			this->EA_L3->AutoSize = true;
			this->EA_L3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L3->Location = System::Drawing::Point(242, 51);
			this->EA_L3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EA_L3->Name = L"EA_L3";
			this->EA_L3->Size = System::Drawing::Size(101, 26);
			this->EA_L3->TabIndex = 44;
			this->EA_L3->Text = L"Порода3";
			// 
			// EA_L2
			// 
			this->EA_L2->AutoSize = true;
			this->EA_L2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L2->Location = System::Drawing::Point(8, 146);
			this->EA_L2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EA_L2->Name = L"EA_L2";
			this->EA_L2->Size = System::Drawing::Size(101, 26);
			this->EA_L2->TabIndex = 43;
			this->EA_L2->Text = L"Порода2";
			// 
			// EA_L1
			// 
			this->EA_L1->AutoSize = true;
			this->EA_L1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L1->Location = System::Drawing::Point(8, 51);
			this->EA_L1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->EA_L1->Name = L"EA_L1";
			this->EA_L1->Size = System::Drawing::Size(101, 26);
			this->EA_L1->TabIndex = 42;
			this->EA_L1->Text = L"Порода1";
			// 
			// EA_TB4
			// 
			this->EA_TB4->Location = System::Drawing::Point(242, 178);
			this->EA_TB4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->EA_TB4->Name = L"EA_TB4";
			this->EA_TB4->Size = System::Drawing::Size(278, 32);
			this->EA_TB4->TabIndex = 39;
			// 
			// EA_TB3
			// 
			this->EA_TB3->Location = System::Drawing::Point(242, 83);
			this->EA_TB3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->EA_TB3->Name = L"EA_TB3";
			this->EA_TB3->Size = System::Drawing::Size(278, 32);
			this->EA_TB3->TabIndex = 38;
			// 
			// EA_TB2
			// 
			this->EA_TB2->Location = System::Drawing::Point(8, 178);
			this->EA_TB2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->EA_TB2->Name = L"EA_TB2";
			this->EA_TB2->Size = System::Drawing::Size(223, 32);
			this->EA_TB2->TabIndex = 37;
			// 
			// EA_TB1
			// 
			this->EA_TB1->Location = System::Drawing::Point(8, 83);
			this->EA_TB1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->EA_TB1->Name = L"EA_TB1";
			this->EA_TB1->Size = System::Drawing::Size(223, 32);
			this->EA_TB1->TabIndex = 36;
			// 
			// EA_CB
			// 
			this->EA_CB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_CB->FormattingEnabled = true;
			this->EA_CB->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Животные", L"Владельцы", L"Породы", L"Прививки",
					L"Выставление"
			});
			this->EA_CB->Location = System::Drawing::Point(196, 282);
			this->EA_CB->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->EA_CB->Name = L"EA_CB";
			this->EA_CB->Size = System::Drawing::Size(180, 34);
			this->EA_CB->TabIndex = 34;
			this->EA_CB->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::EA_CB_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 286);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 26);
			this->label5->TabIndex = 35;
			this->label5->Text = L"Тип Элемента:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(380, 278);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 45);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->comboBox1);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox2->Location = System::Drawing::Point(795, 372);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(429, 229);
			this->groupBox2->TabIndex = 38;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Удаление Элемента";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button5->Location = System::Drawing::Point(261, 167);
			this->button5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 45);
			this->button5->TabIndex = 46;
			this->button5->Text = L"Удалить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(134, 84);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 32);
			this->textBox1->TabIndex = 46;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 84);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 26);
			this->label2->TabIndex = 47;
			this->label2->Text = L"Номер:";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Животные", L"Владельцы", L"Породы", L"Прививки",
					L"Выставление"
			});
			this->comboBox1->Location = System::Drawing::Point(134, 39);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(180, 34);
			this->comboBox1->TabIndex = 46;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 42);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 26);
			this->label1->TabIndex = 46;
			this->label1->Text = L"Таблица:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(74, 134);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 26);
			this->label6->TabIndex = 28;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(21, 45);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(662, 495);
			this->dataGridView1->TabIndex = 29;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Controls->Add(this->DATA_CB);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox1->Location = System::Drawing::Point(38, 198);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(728, 672);
			this->groupBox1->TabIndex = 37;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button4->Location = System::Drawing::Point(428, 557);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 45);
			this->button4->TabIndex = 46;
			this->button4->Text = L"Обновить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// DATA_CB
			// 
			this->DATA_CB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->DATA_CB->FormattingEnabled = true;
			this->DATA_CB->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Животные", L"Владельцы", L"Породы", L"Прививки",
					L"Выставление"
			});
			this->DATA_CB->Location = System::Drawing::Point(237, 562);
			this->DATA_CB->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->DATA_CB->Name = L"DATA_CB";
			this->DATA_CB->Size = System::Drawing::Size(180, 34);
			this->DATA_CB->TabIndex = 33;
			this->DATA_CB->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::DATA_CB_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->Location = System::Drawing::Point(16, 566);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(210, 26);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Выберите таблицу:";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button3->Location = System::Drawing::Point(28, 911);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 35);
			this->button3->TabIndex = 36;
			this->button3->Text = L"Назад";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button2->Location = System::Drawing::Point(1108, 911);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 35);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox4->Location = System::Drawing::Point(795, 628);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(429, 229);
			this->groupBox4->TabIndex = 40;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"SQL Запросы";
			this->groupBox4->Enter += gcnew System::EventHandler(this, &MyForm::groupBox4_Enter);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button6->Location = System::Drawing::Point(261, 72);
			this->button6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 45);
			this->button6->TabIndex = 46;
			this->button6->Text = L"Загрузить";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(26, 78);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(223, 32);
			this->textBox2->TabIndex = 46;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 42);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(189, 26);
			this->label7->TabIndex = 46;
			this->label7->Text = L"Название схемы:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(74, 134);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 26);
			this->label8->TabIndex = 28;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1702, 963);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №4(выполнение)";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			// Получаем начальную вершину из формы
			
		}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Owner->Show();
	this->Close();
}

private: std::string toStdStr(System::String^ string)
{
	using System::Runtime::InteropServices::Marshal;
	System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
	char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
	std::string returnString(charPointer, string->Length);
	Marshal::FreeHGlobal(pointer);
	return returnString;
}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	using namespace tinyxml2;

	std::cout << "index: " << EA_CB->SelectedIndex << std::endl;

	XMLDocument doc;
	std::string fileName = "db.xml";

	checkFile(fileName, doc);

	switch (EA_CB->SelectedIndex) {
	case 0:
		//Животные

		AddObject(doc, new Pet(toStdStr(EA_TB1->Text), toStdStr(EA_TB2->Text), toStdStr(EA_TB3->Text), toStdStr(EA_TB4->Text)), "Pets");

		break;

	case 1:
		//Владельцы
		
		AddObject(doc, new Ownerw(toStdStr(EA_TB1->Text), toStdStr(EA_TB2->Text)), "Owners");
		break;
	case 2:
		//Породы

		AddObject(doc, new Breed(toStdStr(EA_TB1->Text)), "Breeds");
		break;
	case 3:
		//Прививки
		AddObject(doc, new Vaccine(toStdStr(EA_TB1->Text), toStdStr(EA_TB2->Text)), "Vaccines");
		break;
	case 4:
		//Выставление
		AddObject(doc, new PetVaccine(toStdStr(EA_TB1->Text), toStdStr(EA_TB2->Text), toStdStr(EA_TB3->Text)), "PetVaccines");
		break;
	}

	SaveXML(fileName, doc);



	/*
	XMLDocument doc;
	std::string fileName = "db.xml";

	checkFile(fileName, doc);

	Pet pet = Pet();
	DBObject* dbo = &pet;

	AddObject(doc, dbo);
	
	*/
	
}
private: System::Void EA_CB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
	/*
		Животные
		Владельцы
		Породы
		Прививки
		Выставление
	*/
	
	switch (EA_CB->SelectedIndex) {
	case 0:
		//Животные
		EA_L1->Text = "Номер породы";
		EA_L2->Text = "Имя";
		EA_L3->Text = "Дата Рождения";
		EA_L4->Text = "Номер Владельца";

		EA_L1->Visible = true;
		EA_L2->Visible = true;
		EA_L3->Visible = true;
		EA_L4->Visible = true;

		EA_TB1->Visible = true;
		EA_TB2->Visible = true;
		EA_TB3->Visible = true;
		EA_TB4->Visible = true;
		break;

	case 1:
		//Владельцы
		EA_L1->Text = "Имя";
		EA_L2->Text = "Адрес";
		EA_L3->Text = "";
		EA_L4->Text = "";

		EA_L1->Visible = true;
		EA_L2->Visible = true;
		EA_L3->Visible = false;
		EA_L4->Visible = false;

		EA_TB1->Visible = true;
		EA_TB2->Visible = true;
		EA_TB3->Visible = false;
		EA_TB4->Visible = false;
		break;
	case 2:
		//Породы
		EA_L1->Text = "Название";
		EA_L2->Text = "";
		EA_L3->Text = "";
		EA_L4->Text = "";

		EA_L1->Visible = true;
		EA_L2->Visible = false;
		EA_L3->Visible = false;
		EA_L4->Visible = false;

		EA_TB1->Visible = true;
		EA_TB2->Visible = false;
		EA_TB3->Visible = false;
		EA_TB4->Visible = false;
		break;
	case 3:
		//Прививки
		EA_L1->Text = "Название";
		EA_L2->Text = "Комментарий";
		EA_L3->Text = "";
		EA_L4->Text = "";

		EA_L1->Visible = true;
		EA_L2->Visible = true;
		EA_L3->Visible = false;
		EA_L4->Visible = false;

		EA_TB1->Visible = true;
		EA_TB2->Visible = true;
		EA_TB3->Visible = false;
		EA_TB4->Visible = false;
		break;
	case 4:
		//Выставление
		EA_L1->Text = "Номер животного";
		EA_L2->Text = "Номер вакцины";
		EA_L3->Text = "Дата";
		EA_L4->Text = "";

		EA_L1->Visible = true;
		EA_L2->Visible = true;
		EA_L3->Visible = true;
		EA_L4->Visible = false;

		EA_TB1->Visible = true;
		EA_TB2->Visible = true;
		EA_TB3->Visible = true;
		EA_TB4->Visible = false;
		break;
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::vector< std::vector< std::string > > vc;

	XMLDocument doc;
	std::string fileName = "db.xml";

	checkFile(fileName, doc);

	if (DATA_CB->SelectedIndex == -1) return;

	std::string table_name = get_table_name(DATA_CB->SelectedIndex);
	std::vector<std::string> fields_to_read = get_class(DATA_CB->SelectedIndex)->get_description();
	fields_to_read.insert(fields_to_read.begin(), "id");
	


	
		
	XMLElement* root = doc.FirstChildElement(table_name.c_str());
	XMLElement* petElement = root->FirstChildElement("Object");

	while (petElement) {
		
		std::vector< std::string > element;

		for (auto field : fields_to_read) {
			element.push_back(petElement->Attribute(field.c_str()));
			std::cout << petElement->Attribute(field.c_str()) << " " << field.c_str() << std::endl;
		}
		

		vc.push_back(element);

		petElement = petElement->NextSiblingElement("Object");
	}
	

	if (vc.size() < 1) return;

	dataGridView1->ColumnCount = fields_to_read.size();
	dataGridView1->RowCount = vc.size() + 1;


	for (int j = 0; j < fields_to_read.size(); ++j) {
		dataGridView1->Rows[0]->Cells[j]->Value = gcnew String(fields_to_read[j].c_str());
	}
	
	
	for (int i = 1; i < vc.size() + 1; ++i) {
		for (int j = 0; j < fields_to_read.size(); ++j) {
			dataGridView1->Rows[i]->Cells[j]->Value = gcnew String( vc[i-1][j].c_str()) ;
		}
	}
	
}
private: System::Void DATA_CB_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	
	XMLDocument doc;
	std::string fileName = "db.xml";

	checkFile(fileName, doc);

	std::string targetId = toStdStr(textBox1->Text);
	std::cout << toStdStr(textBox1->Text) << " <- to_delete" << std::endl;

	XMLElement* rootElement = doc.FirstChildElement( get_table_name(comboBox1->SelectedIndex).c_str() );
	
	
	for (XMLElement* element = rootElement->FirstChildElement("Object"); element != nullptr; element = element->NextSiblingElement("Object")) {
		std::string idValue = element->Attribute("id");
		std::cout << idValue << " " << targetId << std::endl;
		if (targetId == idValue) {
			// Удаление элемента
			rootElement->DeleteChild(element);

			break;  // Если нашли и удалили, выходим из цикла
		}
	}

	SaveXML(fileName, doc);
}
private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	LoadSQL("itip");
}
};
}

