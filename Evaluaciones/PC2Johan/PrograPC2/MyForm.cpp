#include "MyForm.h"  
#include <ctime>
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	srand(time(0));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PrograPC2::MyForm()); //Project 1 es el nombre del proyecto
}
