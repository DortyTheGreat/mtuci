#pragma once
#include "Algorithms.h"
#include "MyForm1.h"



namespace rofl {

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
	private: System::Windows::Forms::Label^ label7;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(640, 484);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Время:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(20, 561);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(43, 13);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Время:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(689, 484);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 27;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(69, 558);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 26;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(720, 572);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 43);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Далее";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(646, 294);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(170, 26);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Результат решения с помощью \r\nалгорима Дейкстры:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 294);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(227, 26);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Результат решения с помощью алгоритма \r\nФлойда-Уоршелла:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(23, 324);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(580, 196);
			this->dataGridView1->TabIndex = 22;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(357, 223);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 21);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 226);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Выберите начальную вершину:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" });
			this->comboBox1->Location = System::Drawing::Point(183, 223);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 19;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(649, 324);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 147);
			this->listBox1->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(19, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(604, 105);
			this->label2->TabIndex = 17;
			this->label2->Text = resources->GetString(L"label2.Text");
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(18, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 21);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Задание:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(643, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(155, 173);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(831, 626);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №3(1)";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			// Получаем начальную вершину из формы
			int src = Convert::ToInt32(comboBox1->SelectedItem->ToString()) - 1;

			const int inf = 1001 * 1001;

			std::vector<std::vector<std::pair<int, int>>> graph_adj_list;
			graph_adj_list.resize(8);

			graph_adj_list[0].push_back({ 1, 4 });
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

			// Измерение времени выполнения алгоритма Дейкстры
			System::Diagnostics::Stopwatch^ stopwatchDijkstra = gcnew System::Diagnostics::Stopwatch();
			stopwatchDijkstra->Start();

			std::vector<int> resultDijkstra = dijkstra(graph, src);

			stopwatchDijkstra->Stop();
			// Вывод времени выполнения алгоритма Дейкстры
			textBox1->Text = stopwatchDijkstra->Elapsed.TotalMilliseconds.ToString() + " ms";

			// Вывод результатов в ListBox
			listBox1->Items->Clear();
			for (int i = 0; i < resultDijkstra.size(); ++i) {
				String^ result = "До вершины " + (i + 1) + ": ";
				result += (resultDijkstra[i] == inf) ? "∞" : resultDijkstra[i].ToString();
				listBox1->Items->Add(result);
			}

			// Измерение времени выполнения алгоритма Флойда-Уоршелла
			System::Diagnostics::Stopwatch^ stopwatchFloyd = gcnew System::Diagnostics::Stopwatch();
			stopwatchFloyd->Start();

			std::vector<std::vector<int>> resultFloydWarshall = floydWarshall(graph);

			stopwatchFloyd->Stop();
			// Вывод времени выполнения алгоритма Флойда-Уоршелла
			textBox2->Text = stopwatchFloyd->Elapsed.TotalMilliseconds.ToString() + " ms";

			// Настройка DataGridView
			dataGridView1->ColumnCount = resultFloydWarshall.size();
			dataGridView1->RowCount = resultFloydWarshall.size();

			// Заполнение DataGridView результатами алгоритма Флойда-Уоршелла
			for (int i = 0; i < resultFloydWarshall.size(); ++i) {
				for (int j = 0; j < resultFloydWarshall[i].size(); ++j) {
					dataGridView1->Rows[i]->Cells[j]->Value = (resultFloydWarshall[i][j] == inf) ? "∞" : resultFloydWarshall[i][j].ToString();
				}
			}
		}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ f = gcnew MyForm1();
	f->Owner = this;
	f->Show();
	this->Hide();
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

