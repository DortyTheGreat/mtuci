#pragma once
#include "Algorithms.h"
#include "MyForm.h"
#include <string>
namespace visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;





	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(752, 338);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(278, 320);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(16, 401);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(843, 198);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Написать программу для:\r\nа) поиска оптимального назначения,\r\nминимизирующее сумма"
				L"рную\r\nстоимость назначений.\r\nб) поиска оптимального назначение, максимизирующее "
				L"суммарную\r\nэффективность назначений.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(16, 368);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 33);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Задание 2:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1088, 589);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 69);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Далее";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(16, 85);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(935, 264);
			this->label3->TabIndex = 28;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(15, 35);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 33);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Задание:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(716, 96);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(531, 150);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 29;
			this->pictureBox2->TabStop = false;
			// 
			// MyForm1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1260, 705);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №4(условие)";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm^ f = gcnew MyForm();
	f->Owner = this;
	f->Show();
	this->Hide();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	MyForm^ f = gcnew MyForm();
	f->Owner = this;
	f->Show();
	this->Hide();
	
	/*
	const int inf = 1001 * 1001;

	std::vector<std::vector<std::pair<int, int>>> graph_adj_list;
	graph_adj_list.resize(8);

	graph_adj_list[0].push_back({ 1, 4 }); // Закоментируй для увлечения!
	graph_adj_list[0].push_back({ 7, 2 });

	graph_adj_list[1].push_back({ 6, 5 });
	graph_adj_list[1].push_back({ 4, 4 });
	graph_adj_list[1].push_back({ 2, 3 });

	graph_adj_list[2].push_back({ 6, 6 });
	graph_adj_list[2].push_back({ 4, 5 });
	graph_adj_list[2].push_back({ 3, 4 });

	graph_adj_list[3].push_back({ 7, 2 });
	graph_adj_list[3].push_back({ 5, 4 });
	graph_adj_list[3].push_back({ 4, 1 });

	graph_adj_list[4].push_back({ 5, 3 });

	graph_adj_list[5].push_back({ 6, 2 });
	graph_adj_list[5].push_back({ 7, 1 });

	graph_adj_list[6].push_back({ 7, 3 });

	std::vector<std::vector<int>> graph = to_adjacency_matrix(graph_adj_list);


	int start_city = Convert::ToInt32(comboBox1->SelectedItem->ToString()) - 1;


	auto masha_ans = masha(start_city, graph);

	long long min_distance = masha_ans.first;
	std::vector<int> path = masha_ans.second;

	// Отображаем минимальное расстояние
	textBox1->Text = Convert::ToString(min_distance);

	// Отображаем путь
	if (!path.empty()) {
		System::String^ path_string = "";
		for (int i = 0; i < path.size(); i++) {
			path_string += (path[i] + 1).ToString(); // Преобразуем индексы в города (нумерация с 1)
			if (i < path.size() - 1) {
				path_string += " -> ";
			}
		}
		label6->Text = path_string; // Отображаем путь в лейбле
	}
	else {
		label6->Text = "Путь не найден";
	}
	*/
}



private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
