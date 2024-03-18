#include "main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//KuleshovProjPracsem3::Questions^ f = gcnew KuleshovProjPracsem3::Questions();

	SamoletKuleshov::main form;

	Application::Run(% form);

}