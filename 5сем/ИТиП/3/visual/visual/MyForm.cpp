#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace visual;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	visual::MyForm form;
	Application::Run(% form);
}

