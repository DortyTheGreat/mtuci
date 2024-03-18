#pragma once
#include "AllClasses.h"
#include "BeeBehaviourTestForm.h"

namespace TechProg4Kuleshov {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Creatures;

	/// <summary>
	/// Summary for TitleForm
	/// </summary>
	public ref class TitleForm : public System::Windows::Forms::Form
	{
	public:
		TitleForm(void)
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
		~TitleForm()
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
			this->button1->Location = System::Drawing::Point(1202, 518);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 67);
			this->button1->TabIndex = 0;
			this->button1->Text = L"start test";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &TitleForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 200;
			this->timer1->Tick += gcnew System::EventHandler(this, &TitleForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1202, 609);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 67);
			this->button2->TabIndex = 1;
			this->button2->Text = L"next test";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &TitleForm::button2_Click);
			// 
			// TitleForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1529, 968);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"TitleForm";
			this->Text = L"MovementTest";
			this->Load += gcnew System::EventHandler(this, &TitleForm::TitleForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TitleForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//bug->Fly(Insect::Direction::Up);
		//this->Show();
		//bug->Fly(Insect::Direction(2));
		timer1->Enabled = !timer1->Enabled;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		(gcnew BeeBehaviourTestForm())->Show();
	}
};
}
