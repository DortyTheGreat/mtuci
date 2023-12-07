#pragma once
#include "Question3.h"

namespace PracticumFormsVasilyevBEI2202 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace DLLPracticumVasilyevBEI2202;

	/// <summary>
	/// Сводка для Question_2
	/// </summary>
	public ref class Question_2 : public System::Windows::Forms::Form
	{
	public:
		Question_2(void)
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
		~Question_2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(193, 332);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(351, 46);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Выйти из приложения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Question_2::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(193, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(351, 46);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Следующий вопрос";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Question_2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(34, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(653, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"На чем основан стегано графический способ защиты информации\?";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"На попытке сообщить противнику интересующую информацию",
					L"На попытке скрыть от противника сам факт наличия интересующей его информации", L"На попытке скрыть информацию в стеганой куртке",
					L"На попытке скрыть источник информации"
			});
			this->comboBox1->Location = System::Drawing::Point(39, 66);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(648, 26);
			this->comboBox1->TabIndex = 13;
			this->comboBox1->Text = L"Выберите ответ";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Question_2::comboBox1_SelectedIndexChanged);
			// 
			// Question_2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(772, 408);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Question_2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Question_2";
			this->Load += gcnew System::EventHandler(this, &Question_2::Question_2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		bool flag = Class1::ComboBox_check(comboBox1, 1);
		if (flag) {
			Question3^ f = gcnew Question3();
			f->Owner = this;
			f->Show();
			this->Hide();
		}

	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Question_2_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
