#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace rofl;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	rofl::MyForm form;
	Application::Run(% form);
}

