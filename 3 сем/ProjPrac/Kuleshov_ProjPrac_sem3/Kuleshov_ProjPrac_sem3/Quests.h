#pragma once
//#include "Titul.h"
#include "Totals.h"
namespace KuleshovProjPracsem3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace dllkuleshovprojpracsem3;
	/// <summary>
	/// Сводка для Quests
	/// </summary>
	public ref class Quests : public System::Windows::Forms::Form
	{
	public:
		Quests(void)
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
		~Quests()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ CBQ1_4;

	private: System::Windows::Forms::CheckBox^ CBQ1_1;
	private: System::Windows::Forms::CheckBox^ CBQ1_3;







	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::GroupBox^ GB_Q1;

	private: System::Windows::Forms::CheckBox^ CBQ1_2;
	private: System::Windows::Forms::GroupBox^ GB_Q2;

	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::GroupBox^ GB_Q3;
	private: System::Windows::Forms::RadioButton^ RBQ3_3;

	private: System::Windows::Forms::RadioButton^ RBQ3_2;

	private: System::Windows::Forms::RadioButton^ RBQ3_1;


	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::GroupBox^ GB_Q4;
	private: System::Windows::Forms::CheckBox^ CBQ4_2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::CheckBox^ CBQ4_1;
	private: System::Windows::Forms::CheckBox^ CBQ4_3;
	private: System::Windows::Forms::GroupBox^ GB_Q5;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::GroupBox^ GB_Q6;
	private: System::Windows::Forms::TextBox^ TBQ6;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ GB_Q7;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RadioButton^ RBQ7_3;

	private: System::Windows::Forms::RadioButton^ RBQ7_2;

	private: System::Windows::Forms::RadioButton^ RBQ7_1;
	private: System::Windows::Forms::GroupBox^ GB_Q8;
	private: System::Windows::Forms::TextBox^ TBQ8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::GroupBox^ GB_Q9;






	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::GroupBox^ GB_Q10;







	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ ComBoxQ5;
	private: System::Windows::Forms::HScrollBar^ HBARQ9;
private: System::Windows::Forms::Label^ Q9_label;
private: System::Windows::Forms::CheckedListBox^ CLBQ2;
private: System::Windows::Forms::VScrollBar^ VSBARQ10;
private: System::Windows::Forms::Label^ Q10_label;







	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CBQ1_4 = (gcnew System::Windows::Forms::CheckBox());
			this->CBQ1_1 = (gcnew System::Windows::Forms::CheckBox());
			this->CBQ1_3 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->GB_Q1 = (gcnew System::Windows::Forms::GroupBox());
			this->CBQ1_2 = (gcnew System::Windows::Forms::CheckBox());
			this->GB_Q2 = (gcnew System::Windows::Forms::GroupBox());
			this->CLBQ2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->GB_Q3 = (gcnew System::Windows::Forms::GroupBox());
			this->RBQ3_3 = (gcnew System::Windows::Forms::RadioButton());
			this->RBQ3_2 = (gcnew System::Windows::Forms::RadioButton());
			this->RBQ3_1 = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->GB_Q4 = (gcnew System::Windows::Forms::GroupBox());
			this->CBQ4_2 = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CBQ4_1 = (gcnew System::Windows::Forms::CheckBox());
			this->CBQ4_3 = (gcnew System::Windows::Forms::CheckBox());
			this->GB_Q5 = (gcnew System::Windows::Forms::GroupBox());
			this->ComBoxQ5 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GB_Q6 = (gcnew System::Windows::Forms::GroupBox());
			this->TBQ6 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->GB_Q7 = (gcnew System::Windows::Forms::GroupBox());
			this->RBQ7_3 = (gcnew System::Windows::Forms::RadioButton());
			this->RBQ7_2 = (gcnew System::Windows::Forms::RadioButton());
			this->RBQ7_1 = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->GB_Q8 = (gcnew System::Windows::Forms::GroupBox());
			this->TBQ8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->GB_Q9 = (gcnew System::Windows::Forms::GroupBox());
			this->Q9_label = (gcnew System::Windows::Forms::Label());
			this->HBARQ9 = (gcnew System::Windows::Forms::HScrollBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->GB_Q10 = (gcnew System::Windows::Forms::GroupBox());
			this->VSBARQ10 = (gcnew System::Windows::Forms::VScrollBar());
			this->Q10_label = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->GB_Q1->SuspendLayout();
			this->GB_Q2->SuspendLayout();
			this->GB_Q3->SuspendLayout();
			this->GB_Q4->SuspendLayout();
			this->GB_Q5->SuspendLayout();
			this->GB_Q6->SuspendLayout();
			this->GB_Q7->SuspendLayout();
			this->GB_Q8->SuspendLayout();
			this->GB_Q9->SuspendLayout();
			this->GB_Q10->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(502, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1. Как классифицируют промышленные инновации для\r\nоценки их эффективности\?";
			this->label1->Click += gcnew System::EventHandler(this, &Quests::label1_Click);
			// 
			// CBQ1_4
			// 
			this->CBQ1_4->AutoSize = true;
			this->CBQ1_4->Checked = true;
			this->CBQ1_4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CBQ1_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ1_4->Location = System::Drawing::Point(6, 188);
			this->CBQ1_4->Name = L"CBQ1_4";
			this->CBQ1_4->Size = System::Drawing::Size(464, 28);
			this->CBQ1_4->TabIndex = 1;
			this->CBQ1_4->Text = L"В зависимости от технологических параметров";
			this->CBQ1_4->UseVisualStyleBackColor = true;
			// 
			// CBQ1_1
			// 
			this->CBQ1_1->AutoSize = true;
			this->CBQ1_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ1_1->Location = System::Drawing::Point(6, 86);
			this->CBQ1_1->Name = L"CBQ1_1";
			this->CBQ1_1->Size = System::Drawing::Size(344, 28);
			this->CBQ1_1->TabIndex = 2;
			this->CBQ1_1->Text = L"В зависимости от рентабельности";
			this->CBQ1_1->UseVisualStyleBackColor = true;
			// 
			// CBQ1_3
			// 
			this->CBQ1_3->AutoSize = true;
			this->CBQ1_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ1_3->Location = System::Drawing::Point(6, 154);
			this->CBQ1_3->Name = L"CBQ1_3";
			this->CBQ1_3->Size = System::Drawing::Size(401, 28);
			this->CBQ1_3->TabIndex = 3;
			this->CBQ1_3->Text = L"В заисимости от исторического периода";
			this->CBQ1_3->UseVisualStyleBackColor = true;
			this->CBQ1_3->CheckedChanged += gcnew System::EventHandler(this, &Quests::checkBox2_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(500, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 75);
			this->button1->TabIndex = 8;
			this->button1->Text = L"В главное меню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Quests::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(0, 350);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 75);
			this->button2->TabIndex = 9;
			this->button2->Text = L"К следующему вопросу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Quests::button2_Click);
			// 
			// GB_Q1
			// 
			this->GB_Q1->Controls->Add(this->CBQ1_2);
			this->GB_Q1->Controls->Add(this->label1);
			this->GB_Q1->Controls->Add(this->CBQ1_4);
			this->GB_Q1->Controls->Add(this->CBQ1_1);
			this->GB_Q1->Controls->Add(this->CBQ1_3);
			this->GB_Q1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q1->Location = System::Drawing::Point(12, 12);
			this->GB_Q1->Name = L"GB_Q1";
			this->GB_Q1->Size = System::Drawing::Size(600, 400);
			this->GB_Q1->TabIndex = 13;
			this->GB_Q1->TabStop = false;
			this->GB_Q1->Text = L"Вопрос 1";
			// 
			// CBQ1_2
			// 
			this->CBQ1_2->AutoSize = true;
			this->CBQ1_2->Checked = true;
			this->CBQ1_2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CBQ1_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ1_2->Location = System::Drawing::Point(6, 120);
			this->CBQ1_2->Name = L"CBQ1_2";
			this->CBQ1_2->Size = System::Drawing::Size(357, 28);
			this->CBQ1_2->TabIndex = 4;
			this->CBQ1_2->Text = L"В зависимости от сфер приложения";
			this->CBQ1_2->UseVisualStyleBackColor = true;
			// 
			// GB_Q2
			// 
			this->GB_Q2->Controls->Add(this->CLBQ2);
			this->GB_Q2->Controls->Add(this->label3);
			this->GB_Q2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q2->Location = System::Drawing::Point(629, 12);
			this->GB_Q2->Name = L"GB_Q2";
			this->GB_Q2->Size = System::Drawing::Size(600, 400);
			this->GB_Q2->TabIndex = 14;
			this->GB_Q2->TabStop = false;
			this->GB_Q2->Text = L"Вопрос 2";
			// 
			// CLBQ2
			// 
			this->CLBQ2->FormattingEnabled = true;
			this->CLBQ2->HorizontalExtent = 1000;
			this->CLBQ2->HorizontalScrollbar = true;
			this->CLBQ2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"предполагает сложные  вычисления.", L"Метод решает  проблемы множественности внутренней ставки рентабельности",
					L"Не  всегда  выделяется  самый  прибыльный проект"
			});
			this->CLBQ2->Location = System::Drawing::Point(20, 106);
			this->CLBQ2->Name = L"CLBQ2";
			this->CLBQ2->Size = System::Drawing::Size(563, 100);
			this->CLBQ2->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(16, 35);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(348, 48);
			this->label3->TabIndex = 0;
			this->label3->Text = L"2. Что верно для метода  внутренней\r\nставки  доходности\?";
			// 
			// GB_Q3
			// 
			this->GB_Q3->Controls->Add(this->RBQ3_3);
			this->GB_Q3->Controls->Add(this->RBQ3_2);
			this->GB_Q3->Controls->Add(this->RBQ3_1);
			this->GB_Q3->Controls->Add(this->label5);
			this->GB_Q3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q3->Location = System::Drawing::Point(6, 266);
			this->GB_Q3->Name = L"GB_Q3";
			this->GB_Q3->Size = System::Drawing::Size(600, 400);
			this->GB_Q3->TabIndex = 14;
			this->GB_Q3->TabStop = false;
			this->GB_Q3->Text = L"Вопрос 3";
			// 
			// RBQ3_3
			// 
			this->RBQ3_3->AutoSize = true;
			this->RBQ3_3->Location = System::Drawing::Point(20, 208);
			this->RBQ3_3->Name = L"RBQ3_3";
			this->RBQ3_3->Size = System::Drawing::Size(568, 52);
			this->RBQ3_3->TabIndex = 4;
			this->RBQ3_3->Text = L"Характеризует соотношение  экономического  эффекта  до\r\n и  после  внедрения инно"
				L"вации";
			this->RBQ3_3->UseVisualStyleBackColor = true;
			// 
			// RBQ3_2
			// 
			this->RBQ3_2->AutoSize = true;
			this->RBQ3_2->Location = System::Drawing::Point(20, 147);
			this->RBQ3_2->Name = L"RBQ3_2";
			this->RBQ3_2->Size = System::Drawing::Size(437, 52);
			this->RBQ3_2->TabIndex = 3;
			this->RBQ3_2->Text = L"Характеризует  изменение  рентабельности \r\nпо  основной  деятельности за период";
			this->RBQ3_2->UseVisualStyleBackColor = true;
			// 
			// RBQ3_1
			// 
			this->RBQ3_1->AutoSize = true;
			this->RBQ3_1->Checked = true;
			this->RBQ3_1->Location = System::Drawing::Point(20, 84);
			this->RBQ3_1->Name = L"RBQ3_1";
			this->RBQ3_1->Size = System::Drawing::Size(533, 52);
			this->RBQ3_1->TabIndex = 1;
			this->RBQ3_1->TabStop = true;
			this->RBQ3_1->Text = L"Характеризует  изменение  прибыли  от операционной \r\nдеятельности за определенный"
				L" период";
			this->RBQ3_1->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(16, 35);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(406, 24);
			this->label5->TabIndex = 0;
			this->label5->Text = L"3. Что характеризует \"Динамика  прибыли\"\?";
			// 
			// GB_Q4
			// 
			this->GB_Q4->Controls->Add(this->CBQ4_2);
			this->GB_Q4->Controls->Add(this->label6);
			this->GB_Q4->Controls->Add(this->CBQ4_1);
			this->GB_Q4->Controls->Add(this->CBQ4_3);
			this->GB_Q4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q4->Location = System::Drawing::Point(618, 237);
			this->GB_Q4->Name = L"GB_Q4";
			this->GB_Q4->Size = System::Drawing::Size(600, 400);
			this->GB_Q4->TabIndex = 17;
			this->GB_Q4->TabStop = false;
			this->GB_Q4->Text = L"Вопрос 4";
			// 
			// CBQ4_2
			// 
			this->CBQ4_2->AutoSize = true;
			this->CBQ4_2->Checked = true;
			this->CBQ4_2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CBQ4_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ4_2->Location = System::Drawing::Point(6, 168);
			this->CBQ4_2->Name = L"CBQ4_2";
			this->CBQ4_2->Size = System::Drawing::Size(346, 52);
			this->CBQ4_2->TabIndex = 4;
			this->CBQ4_2->Text = L"колебания рыночной конъюнктуры,\r\nцен, валютных курсов и т.п";
			this->CBQ4_2->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(16, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(481, 72);
			this->label6->TabIndex = 0;
			this->label6->Text = L"4. точность оценки зависит  от  неопределенности \r\nдоходов-расходов и  инвестицио"
				L"нных рисков. \r\nКакие наиболее встречающиеся риски\?";
			// 
			// CBQ4_1
			// 
			this->CBQ4_1->AutoSize = true;
			this->CBQ4_1->Checked = true;
			this->CBQ4_1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CBQ4_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ4_1->Location = System::Drawing::Point(6, 110);
			this->CBQ4_1->Name = L"CBQ4_1";
			this->CBQ4_1->Size = System::Drawing::Size(556, 52);
			this->CBQ4_1->TabIndex = 2;
			this->CBQ4_1->Text = L"риск,   связанный   с   нестабильностью   экономического \r\nзаконодательстваи  тек"
				L"ущей  экономической  ситуации";
			this->CBQ4_1->UseVisualStyleBackColor = true;
			// 
			// CBQ4_3
			// 
			this->CBQ4_3->AutoSize = true;
			this->CBQ4_3->Checked = true;
			this->CBQ4_3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->CBQ4_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CBQ4_3->Location = System::Drawing::Point(6, 226);
			this->CBQ4_3->Name = L"CBQ4_3";
			this->CBQ4_3->Size = System::Drawing::Size(415, 28);
			this->CBQ4_3->TabIndex = 3;
			this->CBQ4_3->Text = L"производственно-технологический  риск  ";
			this->CBQ4_3->UseVisualStyleBackColor = true;
			// 
			// GB_Q5
			// 
			this->GB_Q5->Controls->Add(this->ComBoxQ5);
			this->GB_Q5->Controls->Add(this->label2);
			this->GB_Q5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q5->Location = System::Drawing::Point(1248, 12);
			this->GB_Q5->Name = L"GB_Q5";
			this->GB_Q5->Size = System::Drawing::Size(600, 400);
			this->GB_Q5->TabIndex = 18;
			this->GB_Q5->TabStop = false;
			this->GB_Q5->Text = L"Вопрос 5";
			// 
			// ComBoxQ5
			// 
			this->ComBoxQ5->FormattingEnabled = true;
			this->ComBoxQ5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"промышленный сектор", L"сектор инноваций", L"коллекционный сектор" });
			this->ComBoxQ5->Location = System::Drawing::Point(20, 160);
			this->ComBoxQ5->Name = L"ComBoxQ5";
			this->ComBoxQ5->Size = System::Drawing::Size(422, 32);
			this->ComBoxQ5->TabIndex = 2;
			this->ComBoxQ5->SelectedIndexChanged += gcnew System::EventHandler(this, &Quests::ComBoxQ5_SelectedIndexChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(392, 72);
			this->label2->TabIndex = 0;
			this->label2->Text = L"5. В сфере промышленных инноваций\r\nосновным источником все же  является ...\r\nЗако"
				L"нчите предложение";
			// 
			// GB_Q6
			// 
			this->GB_Q6->Controls->Add(this->TBQ6);
			this->GB_Q6->Controls->Add(this->label4);
			this->GB_Q6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q6->Location = System::Drawing::Point(1242, 215);
			this->GB_Q6->Name = L"GB_Q6";
			this->GB_Q6->Size = System::Drawing::Size(600, 400);
			this->GB_Q6->TabIndex = 19;
			this->GB_Q6->TabStop = false;
			this->GB_Q6->Text = L"Вопрос 6";
			// 
			// TBQ6
			// 
			this->TBQ6->Location = System::Drawing::Point(20, 145);
			this->TBQ6->Name = L"TBQ6";
			this->TBQ6->Size = System::Drawing::Size(422, 29);
			this->TBQ6->TabIndex = 1;
			this->TBQ6->Text = L"дисконтирования";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(16, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(566, 96);
			this->label4->TabIndex = 0;
			this->label4->Text = L"6. Для оценки эффективности инноваций целесообразно \r\nприменять не только методы "
				L"дисконтирования, но и методы\r\n... и аннуитета.\r\nЧто должно стоять на месте троет"
				L"очия\?";
			// 
			// GB_Q7
			// 
			this->GB_Q7->Controls->Add(this->RBQ7_3);
			this->GB_Q7->Controls->Add(this->RBQ7_2);
			this->GB_Q7->Controls->Add(this->RBQ7_1);
			this->GB_Q7->Controls->Add(this->label7);
			this->GB_Q7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q7->Location = System::Drawing::Point(1235, 429);
			this->GB_Q7->Name = L"GB_Q7";
			this->GB_Q7->Size = System::Drawing::Size(600, 400);
			this->GB_Q7->TabIndex = 20;
			this->GB_Q7->TabStop = false;
			this->GB_Q7->Text = L"Вопрос 7";
			// 
			// RBQ7_3
			// 
			this->RBQ7_3->AutoSize = true;
			this->RBQ7_3->Location = System::Drawing::Point(20, 250);
			this->RBQ7_3->Name = L"RBQ7_3";
			this->RBQ7_3->Size = System::Drawing::Size(48, 28);
			this->RBQ7_3->TabIndex = 7;
			this->RBQ7_3->Text = L"90";
			this->RBQ7_3->UseVisualStyleBackColor = true;
			// 
			// RBQ7_2
			// 
			this->RBQ7_2->AutoSize = true;
			this->RBQ7_2->Checked = true;
			this->RBQ7_2->Location = System::Drawing::Point(16, 193);
			this->RBQ7_2->Name = L"RBQ7_2";
			this->RBQ7_2->Size = System::Drawing::Size(48, 28);
			this->RBQ7_2->TabIndex = 6;
			this->RBQ7_2->TabStop = true;
			this->RBQ7_2->Text = L"60";
			this->RBQ7_2->UseVisualStyleBackColor = true;
			// 
			// RBQ7_1
			// 
			this->RBQ7_1->AutoSize = true;
			this->RBQ7_1->Location = System::Drawing::Point(16, 141);
			this->RBQ7_1->Name = L"RBQ7_1";
			this->RBQ7_1->Size = System::Drawing::Size(48, 28);
			this->RBQ7_1->TabIndex = 5;
			this->RBQ7_1->Text = L"20";
			this->RBQ7_1->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(16, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(569, 96);
			this->label7->TabIndex = 0;
			this->label7->Text = L"7.Сколько процентов всех инноваций  по данным \r\nМинистерства обороны США, во втор"
				L"ой половине\r\nXX века в США, получивших повсеместное распространение,\r\nбыли комме"
				L"рциализированные проекты\?";
			// 
			// GB_Q8
			// 
			this->GB_Q8->Controls->Add(this->TBQ8);
			this->GB_Q8->Controls->Add(this->label8);
			this->GB_Q8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q8->Location = System::Drawing::Point(1229, 713);
			this->GB_Q8->Name = L"GB_Q8";
			this->GB_Q8->Size = System::Drawing::Size(600, 400);
			this->GB_Q8->TabIndex = 21;
			this->GB_Q8->TabStop = false;
			this->GB_Q8->Text = L"Вопрос 8";
			// 
			// TBQ8
			// 
			this->TBQ8->Location = System::Drawing::Point(19, 102);
			this->TBQ8->Name = L"TBQ8";
			this->TBQ8->Size = System::Drawing::Size(422, 29);
			this->TBQ8->TabIndex = 2;
			this->TBQ8->Text = L"денежные поступления";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(16, 35);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(472, 48);
			this->label8->TabIndex = 0;
			this->label8->Text = L"8.Что игнорирует простой (бездисконтный) метод \r\nокупаемости инвестиций\?";
			// 
			// GB_Q9
			// 
			this->GB_Q9->Controls->Add(this->Q9_label);
			this->GB_Q9->Controls->Add(this->HBARQ9);
			this->GB_Q9->Controls->Add(this->label9);
			this->GB_Q9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q9->Location = System::Drawing::Point(612, 497);
			this->GB_Q9->Name = L"GB_Q9";
			this->GB_Q9->Size = System::Drawing::Size(600, 400);
			this->GB_Q9->TabIndex = 21;
			this->GB_Q9->TabStop = false;
			this->GB_Q9->Text = L"Вопрос 9";
			// 
			// Q9_label
			// 
			this->Q9_label->AutoSize = true;
			this->Q9_label->Location = System::Drawing::Point(6, 186);
			this->Q9_label->Name = L"Q9_label";
			this->Q9_label->Size = System::Drawing::Size(118, 24);
			this->Q9_label->TabIndex = 9;
			this->Q9_label->Text = L"Ваш Ответ: ";
			// 
			// HBARQ9
			// 
			this->HBARQ9->Location = System::Drawing::Point(62, 109);
			this->HBARQ9->Name = L"HBARQ9";
			this->HBARQ9->Size = System::Drawing::Size(463, 50);
			this->HBARQ9->TabIndex = 8;
			this->HBARQ9->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Quests::HBARQ9_Scroll);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(16, 35);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(500, 48);
			this->label9->TabIndex = 0;
			this->label9->Text = L"9.Метод оценки эффективности инноваций \r\nдолжен базироваться на системе каких пок"
				L"азателей\?";
			// 
			// GB_Q10
			// 
			this->GB_Q10->Controls->Add(this->VSBARQ10);
			this->GB_Q10->Controls->Add(this->Q10_label);
			this->GB_Q10->Controls->Add(this->label10);
			this->GB_Q10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GB_Q10->Location = System::Drawing::Point(0, 541);
			this->GB_Q10->Name = L"GB_Q10";
			this->GB_Q10->Size = System::Drawing::Size(600, 400);
			this->GB_Q10->TabIndex = 22;
			this->GB_Q10->TabStop = false;
			this->GB_Q10->Text = L"Вопрос 10";
			// 
			// VSBARQ10
			// 
			this->VSBARQ10->Location = System::Drawing::Point(26, 107);
			this->VSBARQ10->Name = L"VSBARQ10";
			this->VSBARQ10->Size = System::Drawing::Size(83, 124);
			this->VSBARQ10->TabIndex = 11;
			this->VSBARQ10->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Quests::VSBARQ10_Scroll);
			// 
			// Q10_label
			// 
			this->Q10_label->AutoSize = true;
			this->Q10_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Q10_label->Location = System::Drawing::Point(8, 264);
			this->Q10_label->Name = L"Q10_label";
			this->Q10_label->Size = System::Drawing::Size(91, 18);
			this->Q10_label->TabIndex = 10;
			this->Q10_label->Text = L"Ваш Ответ: ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(16, 35);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(442, 48);
			this->label10->TabIndex = 0;
			this->label10->Text = L"10. Какая задача является основной проблемой\r\nметода ВСА\?";
			// 
			// Quests
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1061);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->GB_Q10);
			this->Controls->Add(this->GB_Q9);
			this->Controls->Add(this->GB_Q8);
			this->Controls->Add(this->GB_Q7);
			this->Controls->Add(this->GB_Q6);
			this->Controls->Add(this->GB_Q5);
			this->Controls->Add(this->GB_Q4);
			this->Controls->Add(this->GB_Q3);
			this->Controls->Add(this->GB_Q2);
			this->Controls->Add(this->GB_Q1);
			this->Name = L"Quests";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Вопросы к материалу";
			this->Load += gcnew System::EventHandler(this, &Quests::Quests_Load);
			this->GB_Q1->ResumeLayout(false);
			this->GB_Q1->PerformLayout();
			this->GB_Q2->ResumeLayout(false);
			this->GB_Q2->PerformLayout();
			this->GB_Q3->ResumeLayout(false);
			this->GB_Q3->PerformLayout();
			this->GB_Q4->ResumeLayout(false);
			this->GB_Q4->PerformLayout();
			this->GB_Q5->ResumeLayout(false);
			this->GB_Q5->PerformLayout();
			this->GB_Q6->ResumeLayout(false);
			this->GB_Q6->PerformLayout();
			this->GB_Q7->ResumeLayout(false);
			this->GB_Q7->PerformLayout();
			this->GB_Q8->ResumeLayout(false);
			this->GB_Q8->PerformLayout();
			this->GB_Q9->ResumeLayout(false);
			this->GB_Q9->PerformLayout();
			this->GB_Q10->ResumeLayout(false);
			this->GB_Q10->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Owner->Show();
		this->Close();
	}
	List<GroupBox^>^ groups = gcnew List<GroupBox^>();
	
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		label4->Visible = true;
		

		switch (Functions::question)
		{
		case 1: Functions::validate(Functions::GetCheckBoxScore4(CBQ1_1, CBQ1_2, CBQ1_3, CBQ1_4, 0, 1, 0, 1), groups); break;
			case 2: Functions::validate(Functions::GetCheckedListBoxScore(CLBQ2, 1, 0, 1), groups); break;
			case 3: Functions::validate(Functions::GetRadioButtonScore3(RBQ3_1, RBQ3_2, RBQ3_3, 1, 0, 0), groups); break;
			case 4: Functions::validate(Functions::GetCheckBoxScore3(CBQ4_1, CBQ4_2, CBQ4_3, 1, 1, 1), groups); break;
			case 5: Functions::validate(Functions::GetComboBoxScore(ComBoxQ5), groups); break; 
			case 6: Functions::validate(Functions::GetTextBoxScore(TBQ6, "дисконтирования"), groups); break;
			case 7: Functions::validate(Functions::GetRadioButtonScore3(RBQ7_1, RBQ7_2, RBQ7_3, 0, 1, 0), groups); break;
			case 8: Functions::validate(Functions::GetTextBoxScore(TBQ8, "денежные поступления"), groups); break;
			case 9: Functions::validate(Functions::GetHBARScore(HBARQ9), groups);
				button2->Text = "Закончить тестирование";
				break;
			case 10: Functions::validate(Functions::GetVBARScore(VSBARQ10), groups);
				groups[0]->Visible = true;
				
				Totals^ f = gcnew Totals();
				f->Owner = this;
				f->Show();
				this->Hide();
				
				break;
			
		}
		


		

		
		///label4->Text = "Результат: " + (CheckBoxScore + RadioBoxScore).ToString() + "/6";
	}
	private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Quests_Load(System::Object^ sender, System::EventArgs^ e) {
	
	
	

	
	groups->Add(GB_Q1);
	groups->Add(GB_Q2);
	groups->Add(GB_Q3);
	groups->Add(GB_Q4);
	groups->Add(GB_Q5);
	groups->Add(GB_Q6);
	groups->Add(GB_Q7);
	groups->Add(GB_Q8);
	groups->Add(GB_Q9);
	groups->Add(GB_Q10);

	for (int i = 0; i < 10; ++i) {
		groups[i]->Location = Point(10, 10);
		groups[i]->Visible = false;
	}

	groups[0]->Visible = true;
	this->Size = System::Drawing::Size(700, 500);
}
private: System::Void ComBoxQ5_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void HBARQ9_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	Functions::HSBar_output(HBARQ9, Q9_label);
}
private: System::Void VSBARQ10_Scroll(System::Object^ sender, System::Windows::Forms::ScrollEventArgs^ e) {
	Functions::VSBar_output(VSBARQ10, Q10_label);
}
};
}
