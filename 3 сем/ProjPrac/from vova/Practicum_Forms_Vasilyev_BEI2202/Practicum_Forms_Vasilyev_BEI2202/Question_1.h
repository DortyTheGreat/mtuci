#pragma once
#include "Question_2.h"
namespace PracticumFormsVasilyevBEI2202 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace DLLPracticumVasilyevBEI2202;

	/// <summary>
	/// Сводка для Question_1
	/// </summary>
	public ref class Question_1 : public System::Windows::Forms::Form
	{
	public:
		Question_1(void)
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
		~Question_1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ r1;
	private: System::Windows::Forms::RadioButton^ r2;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ r3;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->r1 = (gcnew System::Windows::Forms::RadioButton());
			this->r2 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->r3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// r1
			// 
			this->r1->AutoSize = true;
			this->r1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->r1->Location = System::Drawing::Point(88, 111);
			this->r1->Name = L"r1";
			this->r1->Size = System::Drawing::Size(519, 29);
			this->r1->TabIndex = 0;
			this->r1->TabStop = true;
			this->r1->Text = L"Познакомить читателей с основами криптографии";
			this->r1->UseVisualStyleBackColor = true;
			// 
			// r2
			// 
			this->r2->AutoSize = true;
			this->r2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->r2->Location = System::Drawing::Point(88, 150);
			this->r2->Name = L"r2";
			this->r2->Size = System::Drawing::Size(547, 29);
			this->r2->TabIndex = 1;
			this->r2->TabStop = true;
			this->r2->Text = L"Познакомить читателей с основами деревообработки";
			this->r2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(153, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(356, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"В чём состоит цель данной работы\?";
			// 
			// r3
			// 
			this->r3->AutoSize = true;
			this->r3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->r3->Location = System::Drawing::Point(88, 189);
			this->r3->Name = L"r3";
			this->r3->Size = System::Drawing::Size(580, 29);
			this->r3->TabIndex = 3;
			this->r3->TabStop = true;
			this->r3->Text = L"Познакомить читателей с основами машинного обучения";
			this->r3->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(158, 247);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(351, 46);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Следующий вопрос";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Question_1::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(158, 318);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(351, 46);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Выйти из приложения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Question_1::button2_Click);
			// 
			// Question_1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 393);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->r3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->r2);
			this->Controls->Add(this->r1);
			this->Name = L"Question_1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Question_1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		bool flag = Class1::Radio_B(r1, r2, r3, 0);
		if (flag){
			Question_2^ f = gcnew Question_2();
			f->Owner = this;
			f->Show();
			this->Hide();
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
