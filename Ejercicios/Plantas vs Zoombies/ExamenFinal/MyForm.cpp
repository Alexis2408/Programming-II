#include "MyForm.h"
#include <ctime>
using namespace ExamenFinal;
int main()
{
	srand(time(NULL));
	Application::Run(gcnew MyForm());
	return 0;
}
