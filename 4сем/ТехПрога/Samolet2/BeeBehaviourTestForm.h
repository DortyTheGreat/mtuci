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
			this->button2->Location = System::Drawing::Point(-22, 211);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(1249, 51);
			this->button2->TabIndex = 2;
			this->button2->UseVisualStyleBackColor = false;
			// 
			// BeeBehaviourTestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1220, 677);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"BeeBehaviourTestForm";
			this->Text = L"BeeBehaviourTestForm";
			this->Load += gcnew System::EventHandler(this, &BeeBehaviourTestForm::BeeBehaviourTestForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BeeBehaviourTestForm::BeeBehaviourTestForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion

		Plane^ p;
	private: System::Void BeeBehaviourTestForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		
		//bees = gcnew List<Bee^>();
		int Qx = 100;
		int Qy = 200;
		p = gcnew Plane(this, Point(Qx, Qy), 100);
		p->Rotate(RotationalObject::Direction::Right);
		p->BringToFront();

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
	private: System::Void pictureBox1_LocationChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
