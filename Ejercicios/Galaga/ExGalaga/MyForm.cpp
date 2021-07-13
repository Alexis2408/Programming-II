#include "MyForm.h"
#include <ctime>
using namespace ExGalaga;
int main()
{
	srand(time(NULL));
	Application::Run(gcnew MyForm());
	return 0;
}
