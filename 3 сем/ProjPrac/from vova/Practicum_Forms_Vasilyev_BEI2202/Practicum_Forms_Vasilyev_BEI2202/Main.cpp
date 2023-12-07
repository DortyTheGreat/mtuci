#include "Main.h"
#include "Question_1.h"
#include "Question_2.h"
#include "Question3.h"
#include "Question4.h"
#include "Question5.h"
#include "Question6.h"
#include "Question7.h"
#include "Question8.h"
#include "Question9.h"
#include "Question10.h"
#include "Results.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	PracticumFormsVasilyevBEI2202::Main form;
	Application::Run(% form);
}