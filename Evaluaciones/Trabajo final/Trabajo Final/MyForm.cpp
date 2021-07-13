#include "MyForm.h"
#include "MyMenu.h"
#include<iostream>
#include<time.h>
using namespace TrabajoFinal;
void main()
{
	srand(time(0));
	Application::Run(gcnew TrabajoFinal::MyMenu);
}
