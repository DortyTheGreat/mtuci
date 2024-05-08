#pragma once
#include "AllClasses.h"

namespace TechProg4Kuleshov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Creatures;
	using namespace System::Threading;
	//using namespace Ran;

	/// <summary>
	/// Summary for BeeBehaviourTestForm
	/// </summary>
	public ref class BeeBehaviourTestForm : public System::Windows::Forms::Form
	{
	public:
		BeeBehaviourTestForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BeeBehaviourTestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Button^ left_VPP;
	private: System::Windows::Forms::Button^ right_VPP;
	private: System::Windows::Forms::Button^ left_down;
	private: System::Windows::Forms::Button^ hung_cross1;
	private: System::Windows::Forms::Button^ hung_cross2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ hung_0;
	private: System::Windows::Forms::Button^ hung_1;
	private: System::Windows::Forms::Button^ hung_2;
	private: System::Windows::Forms::Button^ hung_3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ human_cross;
	private: System::Windows::Forms::Button^ cargo_cross;
	private: System::Windows::Forms::Button^ bus_stop;
	private: System::Windows::Forms::Button^ bus_plane_stop;





	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->left_VPP = (gcnew System::Windows::Forms::Button());
			this->right_VPP = (gcnew System::Windows::Forms::Button());
			this->left_down = (gcnew System::Windows::Forms::Button());
			this->hung_cross1 = (gcnew System::Windows::Forms::Button());
			this->hung_cross2 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->hung_0 = (gcnew System::Windows::Forms::Button());
			this->hung_1 = (gcnew System::Windows::Forms::Button());
			this->hung_2 = (gcnew System::Windows::Forms::Button());
			this->hung_3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->human_cross = (gcnew System::Windows::Forms::Button());
			this->cargo_cross = (gcnew System::Windows::Forms::Button());
			this->bus_stop = (gcnew System::Windows::Forms::Button());
			this->bus_plane_stop = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(931, 638);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 70);
			this->button1->TabIndex = 1;
			this->button1->Text = L"«апустить симул€цию";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BeeBehaviourTestForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &BeeBehaviourTestForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSlateGray;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(-39, 169);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(1379, 50);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSlateGray;
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(80, 169);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 281);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSlateGray;
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(80, 404);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(1249, 50);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSlateGray;
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(1132, 326);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 204);
			this->button5->TabIndex = 5;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightSlateGray;
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(931, 327);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 204);
			this->button6->TabIndex = 6;
			this->button6->UseVisualStyleBackColor = false;
			// 
			// left_VPP
			// 
			this->left_VPP->Location = System::Drawing::Point(101, 189);
			this->left_VPP->Name = L"left_VPP";
			this->left_VPP->Size = System::Drawing::Size(10, 10);
			this->left_VPP->TabIndex = 8;
			this->left_VPP->Text = L"left_VPP";
			this->left_VPP->UseVisualStyleBackColor = true;
			this->left_VPP->Visible = false;
			// 
			// right_VPP
			// 
			this->right_VPP->Location = System::Drawing::Point(1274, 189);
			this->right_VPP->Name = L"right_VPP";
			this->right_VPP->Size = System::Drawing::Size(10, 10);
			this->right_VPP->TabIndex = 9;
			this->right_VPP->Text = L"button8";
			this->right_VPP->UseVisualStyleBackColor = true;
			this->right_VPP->Visible = false;
			// 
			// left_down
			// 
			this->left_down->Location = System::Drawing::Point(101, 423);
			this->left_down->Name = L"left_down";
			this->left_down->Size = System::Drawing::Size(10, 10);
			this->left_down->TabIndex = 10;
			this->left_down->Text = L"button8";
			this->left_down->UseVisualStyleBackColor = true;
			this->left_down->Visible = false;
			// 
			// hung_cross1
			// 
			this->hung_cross1->Location = System::Drawing::Point(949, 424);
			this->hung_cross1->Name = L"hung_cross1";
			this->hung_cross1->Size = System::Drawing::Size(10, 10);
			this->hung_cross1->TabIndex = 11;
			this->hung_cross1->Text = L"button8";
			this->hung_cross1->UseVisualStyleBackColor = true;
			this->hung_cross1->Visible = false;
			// 
			// hung_cross2
			// 
			this->hung_cross2->Location = System::Drawing::Point(1151, 423);
			this->hung_cross2->Name = L"hung_cross2";
			this->hung_cross2->Size = System::Drawing::Size(10, 10);
			this->hung_cross2->TabIndex = 12;
			this->hung_cross2->Text = L"button8";
			this->hung_cross2->UseVisualStyleBackColor = true;
			this->hung_cross2->Visible = false;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(801, 616);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 29);
			this->button8->TabIndex = 13;
			this->button8->Text = L"-";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &BeeBehaviourTestForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(801, 675);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 33);
			this->button9->TabIndex = 14;
			this->button9->Text = L"+";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &BeeBehaviourTestForm::button9_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(831, 648);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 24);
			this->label1->TabIndex = 15;
			this->label1->Text = L"3";
			// 
			// hung_0
			// 
			this->hung_0->Location = System::Drawing::Point(949, 350);
			this->hung_0->Name = L"hung_0";
			this->hung_0->Size = System::Drawing::Size(10, 10);
			this->hung_0->TabIndex = 16;
			this->hung_0->Text = L"button8";
			this->hung_0->UseVisualStyleBackColor = true;
			this->hung_0->Visible = false;
			// 
			// hung_1
			// 
			this->hung_1->Location = System::Drawing::Point(949, 504);
			this->hung_1->Name = L"hung_1";
			this->hung_1->Size = System::Drawing::Size(10, 10);
			this->hung_1->TabIndex = 17;
			this->hung_1->Text = L"button8";
			this->hung_1->UseVisualStyleBackColor = true;
			this->hung_1->Visible = false;
			// 
			// hung_2
			// 
			this->hung_2->Location = System::Drawing::Point(1151, 349);
			this->hung_2->Name = L"hung_2";
			this->hung_2->Size = System::Drawing::Size(10, 10);
			this->hung_2->TabIndex = 18;
			this->hung_2->Text = L"button8";
			this->hung_2->UseVisualStyleBackColor = true;
			this->hung_2->Visible = false;
			// 
			// hung_3
			// 
			this->hung_3->Location = System::Drawing::Point(1151, 503);
			this->hung_3->Name = L"hung_3";
			this->hung_3->Size = System::Drawing::Size(10, 10);
			this->hung_3->TabIndex = 19;
			this->hung_3->Text = L"button8";
			this->hung_3->UseVisualStyleBackColor = true;
			this->hung_3->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(759, 589);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(200, 24);
			this->label2->TabIndex = 20;
			this->label2->Text = L"—корость —имул€ции";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::LightSlateGray;
			this->button10->Enabled = false;
			this->button10->Location = System::Drawing::Point(-26, 552);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(383, 50);
			this->button10->TabIndex = 21;
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::LightSlateGray;
			this->button11->Enabled = false;
			this->button11->Location = System::Drawing::Point(307, 404);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(50, 430);
			this->button11->TabIndex = 22;
			this->button11->UseVisualStyleBackColor = false;
			// 
			// human_cross
			// 
			this->human_cross->Location = System::Drawing::Point(325, 424);
			this->human_cross->Name = L"human_cross";
			this->human_cross->Size = System::Drawing::Size(10, 10);
			this->human_cross->TabIndex = 23;
			this->human_cross->Text = L"button8";
			this->human_cross->UseVisualStyleBackColor = true;
			this->human_cross->Visible = false;
			// 
			// cargo_cross
			// 
			this->cargo_cross->Location = System::Drawing::Point(325, 572);
			this->cargo_cross->Name = L"cargo_cross";
			this->cargo_cross->Size = System::Drawing::Size(10, 10);
			this->cargo_cross->TabIndex = 24;
			this->cargo_cross->Text = L"button8";
			this->cargo_cross->UseVisualStyleBackColor = true;
			this->cargo_cross->Visible = false;
			// 
			// bus_stop
			// 
			this->bus_stop->Location = System::Drawing::Point(325, 800);
			this->bus_stop->Name = L"bus_stop";
			this->bus_stop->Size = System::Drawing::Size(10, 10);
			this->bus_stop->TabIndex = 25;
			this->bus_stop->Text = L"button8";
			this->bus_stop->UseVisualStyleBackColor = true;
			this->bus_stop->Visible = false;
			// 
			// bus_plane_stop
			// 
			this->bus_plane_stop->Location = System::Drawing::Point(325, 488);
			this->bus_plane_stop->Name = L"bus_plane_stop";
			this->bus_plane_stop->Size = System::Drawing::Size(10, 10);
			this->bus_plane_stop->TabIndex = 26;
			this->bus_plane_stop->Text = L"button8";
			this->bus_plane_stop->UseVisualStyleBackColor = true;
			this->bus_plane_stop->Visible = false;
			// 
			// BeeBehaviourTestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1296, 703);
			this->Controls->Add(this->bus_plane_stop);
			this->Controls->Add(this->bus_stop);
			this->Controls->Add(this->cargo_cross);
			this->Controls->Add(this->human_cross);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->hung_3);
			this->Controls->Add(this->hung_2);
			this->Controls->Add(this->hung_1);
			this->Controls->Add(this->hung_0);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->hung_cross2);
			this->Controls->Add(this->hung_cross1);
			this->Controls->Add(this->left_down);
			this->Controls->Add(this->right_VPP);
			this->Controls->Add(this->left_VPP);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"BeeBehaviourTestForm";
			this->Text = L"BeeBehaviourTestForm";
			this->Load += gcnew System::EventHandler(this, &BeeBehaviourTestForm::BeeBehaviourTestForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BeeBehaviourTestForm::BeeBehaviourTestForm_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		int* clock_intervals = new int[6];
		int clock_carr = 3;

		Plane^ p;

		List<Plane^> planes;
		int current_plane = -1;
		int waiting_plane = -1;

		List<Point>^ Movement_path0 = gcnew List<Point>;
		List<Point>^ Movement_path1 = gcnew List<Point>;
		List<Point>^ Movement_path2 = gcnew List<Point>;
		List<Point>^ Movement_path3 = gcnew List<Point>;

		List<Point>^ Movement_path_bus = gcnew List<Point>;

		List<Point>^ Elipse = gcnew List<Point>;

		Random^ rnd = gcnew Random();

		Bus^ Buss;

		Point in_sky;

	private: System::Void BeeBehaviourTestForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		clock_intervals[0] = 5;
		clock_intervals[1] = 10;
		clock_intervals[2] = 20;
		clock_intervals[3] = 50;
		clock_intervals[4] = 100;
		clock_intervals[5] = 200;
		
		in_sky = left_VPP->Location;
		in_sky.X += 1300;
		in_sky.Y -= 100;

		const int points_discretion = 60;
		const int radius = 300;
		for (int i = 0; i < points_discretion; ++i) {
			Math::Cos(10);
			Elipse->Add(Point(radius + radius * Math::Cos(i * 2 * Math::PI / points_discretion), radius + radius * Math::Sin(i * 2 * Math::PI / points_discretion)));
		}

		Buss = gcnew Bus(this, bus_stop->Location, 600);
		Buss->BringToFront();

		Movement_path_bus->Add(bus_stop->Location); 
		Movement_path_bus->Add(bus_plane_stop->Location);
		Buss->Movement_path = Movement_path_bus;

		Movement_path0->Add(hung_0->Location);
		Movement_path0->Add(hung_cross1->Location);

		Movement_path1->Add(hung_1->Location);
		Movement_path1->Add(hung_cross1->Location);

		Movement_path2->Add(hung_2->Location);
		Movement_path2->Add(hung_cross2->Location);

		Movement_path3->Add(hung_3->Location);
		Movement_path3->Add(hung_cross2->Location);

		Movement_path0->Add(human_cross->Location);
		Movement_path0->Add(left_down->Location);
		Movement_path0->Add(left_VPP->Location);

		Movement_path1->Add(human_cross->Location);
		Movement_path1->Add(left_down->Location);
		Movement_path1->Add(left_VPP->Location);
		

		Movement_path2->Add(human_cross->Location);
		Movement_path2->Add(left_down->Location);
		Movement_path2->Add(left_VPP->Location);
		
		Movement_path3->Add(human_cross->Location);
		Movement_path3->Add(left_down->Location);
		Movement_path3->Add(left_VPP->Location);
		
		planes.Add(nullptr);
		planes.Add(nullptr);
		planes.Add(nullptr);
		planes.Add(nullptr);

		NextPlane();
		add_to_wait();
	}
	

	
	List<Point>^ Movement_path;

	List<Point>^ generate_path(int index) {
		if (index == 0) return Movement_path = Movement_path0;
		if (index == 1) return Movement_path = Movement_path1;
		if (index == 2) return Movement_path = Movement_path2;
		if (index == 3) return Movement_path = Movement_path3;
	}

	void LandPlane() {
		Console::WriteLine("LandPlane");
		current_plane = -1;

		for (int i = 0; i < 4; ++i) {
			if (planes[i] == nullptr) {
				current_plane = i;

				planes[i] = (gcnew Plane(this, in_sky, 100));

				break;
			}
		}


		planes[current_plane]->Rotate(RotationalObject::Direction::Left);
		planes[current_plane]->BringToFront();

		planes[current_plane]->prepare_to_land(generate_path(current_plane));
		planes[current_plane]->Landed += gcnew LandedHandler(this, &BeeBehaviourTestForm::NextPlane);

	}

	void FlyPlane() {
		Console::WriteLine("FlyPlane");

		current_plane = -1;
		int there_is_plane = -1;
		for (int i = 0; i < 4; ++i) {
			if (planes[i] == nullptr) continue;
			there_is_plane = i;
			if (rnd->Next() < 0.3) current_plane = i;
		}

		if (current_plane == -1) current_plane = there_is_plane;
		Console::WriteLine(current_plane);
		planes[current_plane]->prepare_to_fly();
		Console::WriteLine(planes[current_plane]->state);
		planes[current_plane]->FlewAway += gcnew FlewAwayHandler(this, &BeeBehaviourTestForm::NextPlane);
	}

	void NextPlane() {
		Thread::Sleep(100);
		Console::WriteLine("NextPlane");
		clear_missing_planes();

		int real_count = 0;

		for (int i = 0; i < 4; ++i) {
			if (planes[i] != nullptr) ++real_count;
		}

		if (real_count == 0) { LandPlane(); return; }
		if (real_count == 4) { FlyPlane(); return; }

		if (waiting_plane != -1) {
			
			current_plane = waiting_plane;
			waiting_plane = -1;
			planes[current_plane]->airport_is_busy = false;

			/// current plane -> land

			return;
		}

		if (rnd->NextDouble() < 0.5) {
			LandPlane();
		}
		else {
			FlyPlane();
		}

	}

	void add_to_wait() {
		if (waiting_plane != -1) return; 


		int there_is_plane = -1;
		for (int i = 0; i < 4; ++i) {
			if (planes[i] != nullptr) continue;
			there_is_plane = i;
			if (rnd->Next() < 0.3) waiting_plane = i;
		}

		if (waiting_plane == -1) waiting_plane = there_is_plane;
		if (waiting_plane == -1) return;

		
		

		planes[waiting_plane] = gcnew Plane(this, in_sky, 100);
		planes[waiting_plane]->Rotate(RotationalObject::Direction::Left);
		planes[waiting_plane]->BringToFront();

		planes[waiting_plane]->prepare_to_wait(Elipse);
		planes[waiting_plane]->LandingMovement_path = generate_path(waiting_plane);
		planes[waiting_plane]->Landed += gcnew LandedHandler(this, &BeeBehaviourTestForm::NextPlane);
	}

	void clear_missing_planes() {
		for (int i = 0; i < 4; ++i) {
			if (planes[i] == nullptr) continue;

			if (planes[i]->state == "flewaway") {
				planes[i] = nullptr;
			}
			
		}

	}

	void main_tick() {
		Plane::Callback clb = planes[current_plane]->tick();
		if (clb == Plane::Callback::Default) return;
		if (clb == Plane::Callback::Bus) {

			Bus::Callback clbb = Buss->tick();
			if (clbb == Bus::Callback::Delivered) planes[current_plane]->loaded ^= 1;
		}
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		main_tick();


		if (waiting_plane != -1) planes[waiting_plane]->tick();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = !timer1->Enabled;
		if (timer1->Enabled) button1->Text = "«апустить симул€цию";
		else button1->Text = "ќстановить симул€цию";
	}
	private: System::Void BeeBehaviourTestForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//queen->Location = e->Location;
	}

	
	
	
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

		if (++clock_carr > 5) clock_carr = 5;
		timer1->Interval = clock_intervals[clock_carr];
		label1->Text = ( 6 - clock_carr).ToString();
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (--clock_carr < 0) clock_carr = 0;
		timer1->Interval = clock_intervals[clock_carr];
		label1->Text = ( 6 - clock_carr).ToString();
	}

};
}
