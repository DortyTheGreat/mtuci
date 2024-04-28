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
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ left_VPP;
	private: System::Windows::Forms::Button^ right_VPP;
	private: System::Windows::Forms::Button^ left_down;
	private: System::Windows::Forms::Button^ hung_cross1;
	private: System::Windows::Forms::Button^ hung_cross2;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label1;



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
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->left_VPP = (gcnew System::Windows::Forms::Button());
			this->right_VPP = (gcnew System::Windows::Forms::Button());
			this->left_down = (gcnew System::Windows::Forms::Button());
			this->hung_cross1 = (gcnew System::Windows::Forms::Button());
			this->hung_cross2 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1036, 535);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 54);
			this->button1->TabIndex = 1;
			this->button1->Text = L"start test";
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
			this->button2->Location = System::Drawing::Point(-41, 115);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(1249, 50);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSlateGray;
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(80, 115);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 258);
			this->button3->TabIndex = 3;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSlateGray;
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(80, 323);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(1249, 50);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSlateGray;
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(1136, 246);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 204);
			this->button5->TabIndex = 5;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightSlateGray;
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(967, 246);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 204);
			this->button6->TabIndex = 6;
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::LightSlateGray;
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(199, 323);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 302);
			this->button7->TabIndex = 7;
			this->button7->UseVisualStyleBackColor = false;
			// 
			// left_VPP
			// 
			this->left_VPP->Location = System::Drawing::Point(101, 135);
			this->left_VPP->Name = L"left_VPP";
			this->left_VPP->Size = System::Drawing::Size(10, 10);
			this->left_VPP->TabIndex = 8;
			this->left_VPP->Text = L"left_VPP";
			this->left_VPP->UseVisualStyleBackColor = true;
			this->left_VPP->Visible = false;
			// 
			// right_VPP
			// 
			this->right_VPP->Location = System::Drawing::Point(1176, 135);
			this->right_VPP->Name = L"right_VPP";
			this->right_VPP->Size = System::Drawing::Size(10, 10);
			this->right_VPP->TabIndex = 9;
			this->right_VPP->Text = L"button8";
			this->right_VPP->UseVisualStyleBackColor = true;
			this->right_VPP->Visible = false;
			// 
			// left_down
			// 
			this->left_down->Location = System::Drawing::Point(101, 343);
			this->left_down->Name = L"left_down";
			this->left_down->Size = System::Drawing::Size(10, 10);
			this->left_down->TabIndex = 10;
			this->left_down->Text = L"button8";
			this->left_down->UseVisualStyleBackColor = true;
			this->left_down->Visible = false;
			// 
			// hung_cross1
			// 
			this->hung_cross1->Location = System::Drawing::Point(985, 343);
			this->hung_cross1->Name = L"hung_cross1";
			this->hung_cross1->Size = System::Drawing::Size(10, 10);
			this->hung_cross1->TabIndex = 11;
			this->hung_cross1->Text = L"button8";
			this->hung_cross1->UseVisualStyleBackColor = true;
			this->hung_cross1->Visible = false;
			// 
			// hung_cross2
			// 
			this->hung_cross2->Location = System::Drawing::Point(1155, 343);
			this->hung_cross2->Name = L"hung_cross2";
			this->hung_cross2->Size = System::Drawing::Size(10, 10);
			this->hung_cross2->TabIndex = 12;
			this->hung_cross2->Text = L"button8";
			this->hung_cross2->UseVisualStyleBackColor = true;
			this->hung_cross2->Visible = false;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(305, 463);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 13;
			this->button8->Text = L"+";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &BeeBehaviourTestForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(305, 535);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 14;
			this->button9->Text = L"-";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &BeeBehaviourTestForm::button9_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(321, 506);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"label1";
			// 
			// BeeBehaviourTestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1220, 677);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->hung_cross2);
			this->Controls->Add(this->hung_cross1);
			this->Controls->Add(this->left_down);
			this->Controls->Add(this->right_VPP);
			this->Controls->Add(this->left_VPP);
			this->Controls->Add(this->button7);
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
	private: System::Void BeeBehaviourTestForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		clock_intervals[0] = 10;
		clock_intervals[1] = 20;
		clock_intervals[2] = 40;
		clock_intervals[3] = 80;
		clock_intervals[4] = 100;
		clock_intervals[5] = 200;
		
		//bees = gcnew List<Bee^>();
		int Qx = 100;
		int Qy = 200;
		//button8->Location.X;
		p = gcnew Plane(this, hung_cross1->Location, 100);
		p->Rotate(RotationalObject::Direction::Right);
		p->BringToFront();

		List<Point>^ Movement_path = gcnew List<Point>;
		Movement_path->Add(hung_cross1->Location);
		Movement_path->Add(left_down->Location);
		Movement_path->Add(left_VPP->Location);

		p->prepare_to_fly(Movement_path);

		p->FlewAway += gcnew FlewAwayHandler(this, &BeeBehaviourTestForm::NextPlane);
	}

	void NextPlane() {
		Console::WriteLine("next_plane");
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		p->tick();
		

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = !timer1->Enabled;
	}
	private: System::Void BeeBehaviourTestForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		//queen->Location = e->Location;
	}

	
	
	
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

		if (++clock_carr > 5) clock_carr = 5;
		timer1->Interval = clock_intervals[clock_carr];
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (--clock_carr < 0) clock_carr = 0;
		timer1->Interval = clock_intervals[clock_carr];
	}
};
}
