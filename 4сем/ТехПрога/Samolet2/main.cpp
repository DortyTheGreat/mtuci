#include "TitleForm.h"

using namespace TechProg4Kuleshov;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TechProg4Kuleshov::TitleForm form;
	Application::Run(% form);
	return (0);
}