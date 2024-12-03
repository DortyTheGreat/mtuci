#include "MyForm1.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace visual;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	visual::MyForm1 form;
	Application::Run(% form);
}

