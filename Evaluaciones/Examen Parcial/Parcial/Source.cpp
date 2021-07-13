#include "CControladora.h"
int main()
{
	srand(time(NULL));
	const int MAXW = 100;
	const int MAXH = 40;
	Console::SetWindowSize(MAXW, MAXH);
	Console::CursorVisible = false;
	CControladora* obj = new CControladora();
	obj->empezar(MAXW, MAXH);
	_getch();
	return 0;
}