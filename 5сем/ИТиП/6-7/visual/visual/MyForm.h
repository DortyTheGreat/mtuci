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


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->DATA_CB = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
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
			this->groupBox3->Location = System::Drawing::Point(530, 139);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(353, 218);
			this->groupBox3->TabIndex = 39;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Добавление Элемента";
			// 
			// EA_L4
			// 
			this->EA_L4->AutoSize = true;
			this->EA_L4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L4->Location = System::Drawing::Point(161, 95);
			this->EA_L4->Name = L"EA_L4";
			this->EA_L4->Size = System::Drawing::Size(70, 18);
			this->EA_L4->TabIndex = 45;
			this->EA_L4->Text = L"Порода4";
			// 
			// EA_L3
			// 
			this->EA_L3->AutoSize = true;
			this->EA_L3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L3->Location = System::Drawing::Point(161, 33);
			this->EA_L3->Name = L"EA_L3";
			this->EA_L3->Size = System::Drawing::Size(70, 18);
			this->EA_L3->TabIndex = 44;
			this->EA_L3->Text = L"Порода3";
			// 
			// EA_L2
			// 
			this->EA_L2->AutoSize = true;
			this->EA_L2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L2->Location = System::Drawing::Point(5, 95);
			this->EA_L2->Name = L"EA_L2";
			this->EA_L2->Size = System::Drawing::Size(70, 18);
			this->EA_L2->TabIndex = 43;
			this->EA_L2->Text = L"Порода2";
			// 
			// EA_L1
			// 
			this->EA_L1->AutoSize = true;
			this->EA_L1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->EA_L1->Location = System::Drawing::Point(5, 33);
			this->EA_L1->Name = L"EA_L1";
			this->EA_L1->Size = System::Drawing::Size(70, 18);
			this->EA_L1->TabIndex = 42;
			this->EA_L1->Text = L"Порода1";
			// 
			// EA_TB4
			// 
			this->EA_TB4->Location = System::Drawing::Point(161, 116);
			this->EA_TB4->Name = L"EA_TB4";
			this->EA_TB4->Size = System::Drawing::Size(187, 24);
			this->EA_TB4->TabIndex = 39;
			// 
			// EA_TB3
			// 
			this->EA_TB3->Location = System::Drawing::Point(161, 54);
			this->EA_TB3->Name = L"EA_TB3";
			this->EA_TB3->Size = System::Drawing::Size(187, 24);
			this->EA_TB3->TabIndex = 38;
			// 
			// EA_TB2
			// 
			this->EA_TB2->Location = System::Drawing::Point(5, 116);
			this->EA_TB2->Name = L"EA_TB2";
			this->EA_TB2->Size = System::Drawing::Size(150, 24);
			this->EA_TB2->TabIndex = 37;
			// 
			// EA_TB1
			// 
			this->EA_TB1->Location = System::Drawing::Point(5, 54);
			this->EA_TB1->Name = L"EA_TB1";
			this->EA_TB1->Size = System::Drawing::Size(150, 24);
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
			this->EA_CB->Location = System::Drawing::Point(131, 183);
			this->EA_CB->Name = L"EA_CB";
			this->EA_CB->Size = System::Drawing::Size(121, 26);
			this->EA_CB->TabIndex = 34;
			this->EA_CB->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::EA_CB_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 186);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(111, 18);
			this->label5->TabIndex = 35;
			this->label5->Text = L"Тип Элемента:";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(253, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 29);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox2->Location = System::Drawing::Point(530, 376);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(286, 149);
			this->groupBox2->TabIndex = 38;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Задача Распределения";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(49, 87);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 18);
			this->label6->TabIndex = 28;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(14, 29);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(441, 322);
			this->dataGridView1->TabIndex = 29;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Controls->Add(this->DATA_CB);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox1->Location = System::Drawing::Point(25, 129);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(485, 437);
			this->groupBox1->TabIndex = 37;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button4->Location = System::Drawing::Point(285, 362);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 29);
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
			this->DATA_CB->Location = System::Drawing::Point(158, 365);
			this->DATA_CB->Name = L"DATA_CB";
			this->DATA_CB->Size = System::Drawing::Size(121, 26);
			this->DATA_CB->TabIndex = 33;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->Location = System::Drawing::Point(11, 368);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 18);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Выберите таблицу:";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button3->Location = System::Drawing::Point(19, 592);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 36;
			this->button3->Text = L"Назад";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button2->Location = System::Drawing::Point(739, 592);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 23);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label4->Location = System::Drawing::Point(15, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(198, 18);
			this->label4->TabIndex = 40;
			this->label4->Text = L"Выберите конечный город:";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9"
			});
			this->comboBox2->Location = System::Drawing::Point(231, 46);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 26);
			this->comboBox2->TabIndex = 41;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1135, 626);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
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
			this->ResumeLayout(false);
			this->PerformLayout();

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
	
	std::vector<DBObject*> vc;
	std::string table = 0;

	XMLDocument doc;
	std::string fileName = "db.xml";

	checkFile(fileName, doc);

	

	


	switch (DATA_CB->SelectedIndex) {
	case 0:
		
		XMLElement* root = doc.FirstChildElement("Pets");
		XMLElement* petElement = root->FirstChildElement("Object");

		while (petElement) {
			Pet* pet = new Pet();
			petElement->QueryIntAttribute("id", &pet->id);
			petElement->QueryIntAttribute("breedCode", &pet->breedCode);
			pet->name = petElement->Attribute("name");
			pet->birthDate = petElement->Attribute("birthDate");
			petElement->QueryIntAttribute("ownerCode", &pet->ownerCode);

			vc.push_back(pet);

			petElement = petElement->NextSiblingElement("Object");
		}
		break;
	case 1:
		XMLElement * root1 = doc.FirstChildElement("Owners");
		XMLElement* petElement1 = root1->FirstChildElement("Object");

		while (petElement1) {
			Ownerw* pet = new Ownerw();
			petElement1->QueryIntAttribute("id", &pet->id);
			pet->fullName = petElement1->Attribute("fullName");
			pet->address = petElement1->Attribute("address");


			vc.push_back(pet);

			petElement1 = petElement1->NextSiblingElement("Object");
		}

		break;
	
	}

	if (vc.size() < 1) return;

	dataGridView1->ColumnCount = 2;
	dataGridView1->RowCount = vc[0]->get_description().size();

	/*
	for (int i = 0; i < ff.second.size(); ++i) {
		for (int j = 0; j < ff.second.size(); ++j) {
			dataGridView1->Rows[i]->Cells[j]->Value = (ff.second[i][j] == inf) ? "∞" : ff.second[i][j].ToString();
		}
	}
	*/
}
};
}

