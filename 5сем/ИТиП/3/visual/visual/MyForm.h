#pragma once
#include "Algorithms.h"



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
	private: System::Windows::Forms::Label^ label7;
	protected:
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ djikstra_time;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ olya_time;

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ olya_dist_label;
	private: System::Windows::Forms::TextBox^ olya_dist;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ olya_path_label;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ floyd_time;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ olya_path;


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
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->djikstra_time = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->olya_time = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->olya_path = (gcnew System::Windows::Forms::TextBox());
			this->olya_dist_label = (gcnew System::Windows::Forms::Label());
			this->olya_dist = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->olya_path_label = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->floyd_time = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(56, 282);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(85, 26);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Время:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 26;
			this->listBox1->Location = System::Drawing::Point(89, 32);
			this->listBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(178, 212);
			this->listBox1->TabIndex = 30;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->djikstra_time);
			this->groupBox3->Controls->Add(this->listBox1);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox3->Location = System::Drawing::Point(795, 214);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(404, 335);
			this->groupBox3->TabIndex = 39;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Дейкстра";
			// 
			// djikstra_time
			// 
			this->djikstra_time->Location = System::Drawing::Point(149, 279);
			this->djikstra_time->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->djikstra_time->Name = L"djikstra_time";
			this->djikstra_time->Size = System::Drawing::Size(148, 32);
			this->djikstra_time->TabIndex = 31;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 184);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 26);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Время:";
			// 
			// olya_time
			// 
			this->olya_time->Location = System::Drawing::Point(118, 184);
			this->olya_time->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->olya_time->Name = L"olya_time";
			this->olya_time->Size = System::Drawing::Size(144, 32);
			this->olya_time->TabIndex = 33;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->olya_path);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->olya_time);
			this->groupBox2->Controls->Add(this->olya_dist_label);
			this->groupBox2->Controls->Add(this->olya_dist);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->olya_path_label);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox2->Location = System::Drawing::Point(795, 578);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(429, 229);
			this->groupBox2->TabIndex = 38;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Задача Оли";
			// 
			// olya_path
			// 
			this->olya_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->olya_path->Location = System::Drawing::Point(100, 134);
			this->olya_path->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->olya_path->Name = L"olya_path";
			this->olya_path->Size = System::Drawing::Size(322, 26);
			this->olya_path->TabIndex = 35;
			// 
			// olya_dist_label
			// 
			this->olya_dist_label->AutoSize = true;
			this->olya_dist_label->Location = System::Drawing::Point(25, 57);
			this->olya_dist_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->olya_dist_label->Name = L"olya_dist_label";
			this->olya_dist_label->Size = System::Drawing::Size(135, 26);
			this->olya_dist_label->TabIndex = 23;
			this->olya_dist_label->Text = L"Длина пути:";
			// 
			// olya_dist
			// 
			this->olya_dist->Location = System::Drawing::Point(196, 54);
			this->olya_dist->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->olya_dist->Name = L"olya_dist";
			this->olya_dist->Size = System::Drawing::Size(148, 32);
			this->olya_dist->TabIndex = 24;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(73, 134);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 26);
			this->label6->TabIndex = 28;
			// 
			// olya_path_label
			// 
			this->olya_path_label->AutoSize = true;
			this->olya_path_label->Location = System::Drawing::Point(25, 134);
			this->olya_path_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->olya_path_label->Name = L"olya_path_label";
			this->olya_path_label->Size = System::Drawing::Size(67, 26);
			this->olya_path_label->TabIndex = 27;
			this->olya_path_label->Text = L"Путь:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 564);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 26);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Время:";
			// 
			// floyd_time
			// 
			this->floyd_time->Location = System::Drawing::Point(100, 561);
			this->floyd_time->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->floyd_time->Name = L"floyd_time";
			this->floyd_time->Size = System::Drawing::Size(144, 32);
			this->floyd_time->TabIndex = 31;
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
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->floyd_time);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->groupBox1->Location = System::Drawing::Point(38, 198);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(727, 609);
			this->groupBox1->TabIndex = 37;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Флойд-Уоршелл";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button3->Location = System::Drawing::Point(28, 910);
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
			this->button2->Location = System::Drawing::Point(1112, 910);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 35);
			this->button2->TabIndex = 35;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->button1->Location = System::Drawing::Point(555, 18);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 35);
			this->button1->TabIndex = 34;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8" });
			this->comboBox1->Location = System::Drawing::Point(346, 19);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(180, 34);
			this->comboBox1->TabIndex = 33;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->label3->Location = System::Drawing::Point(23, 19);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(302, 26);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Выберите начальный город:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1246, 963);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №3(выполнение)";
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
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	int src = Convert::ToInt32(comboBox1->SelectedItem->ToString()) - 1;

	const int inf = 1001 * 1001;

	std::vector<std::vector<std::pair<int, int>>> graph_adj_list;
	graph_adj_list.resize(8);

	//graph_adj_list[0].push_back({ 1, 4 });
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
	djikstra_time->Text = stopwatchDijkstra->Elapsed.TotalMilliseconds.ToString() + " ms";

	// Вывод результатов в ListBox
	listBox1->Items->Clear();
	for (int i = 0; i < resultDijkstra.size(); ++i) {
		String^ result = (src + 1) + " -> " + (i + 1) + ": ";
		result += (resultDijkstra[i] == inf) ? "∞" : resultDijkstra[i].ToString();
		listBox1->Items->Add(result);
	}

	System::Diagnostics::Stopwatch^ stopwatchFloyd = gcnew System::Diagnostics::Stopwatch();
	stopwatchFloyd->Start();

	std::vector<std::vector<int>> resultFloydWarshall = floydWarshall(graph);

	stopwatchFloyd->Stop();

	floyd_time->Text = stopwatchFloyd->Elapsed.TotalMilliseconds.ToString() + " ms";


	dataGridView1->ColumnCount = resultFloydWarshall.size();
	dataGridView1->RowCount = resultFloydWarshall.size();

	for (int i = 0; i < resultFloydWarshall.size(); ++i) {
		for (int j = 0; j < resultFloydWarshall[i].size(); ++j) {
			dataGridView1->Rows[i]->Cells[j]->Value = (resultFloydWarshall[i][j] == inf) ? "∞" : resultFloydWarshall[i][j].ToString();
		}
	}

	


	System::Diagnostics::Stopwatch^ stopwatchOlya = gcnew System::Diagnostics::Stopwatch();
	stopwatchOlya->Start();

	auto olya_ans = olya(src, graph);

	stopwatchOlya->Stop();

	long long min_distance = olya_ans.first;
	std::vector<int> path = olya_ans.second;

	// Отображаем минимальное расстояние
	olya_dist->Text = Convert::ToString(min_distance);

	// Отображаем путь
	if (!path.empty()) {
		System::String^ path_string = "";
		for (int i = 0; i < path.size(); i++) {
			path_string += (path[i] + 1).ToString(); // Преобразуем индексы в города (нумерация с 1)
			if (i < path.size() - 1) {
				path_string += " -> ";
			}
		}
		olya_path->Text = path_string; // Отображаем путь в лейбле
	}
	else {
		olya_path->Text = "Путь не найден";
	}
	

	olya_time->Text = stopwatchOlya->Elapsed.TotalMilliseconds.ToString() + " ms";;
	
}
};
}

