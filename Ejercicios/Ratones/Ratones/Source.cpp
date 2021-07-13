#include "CJuego.h"
int main()
{
	srand(time(NULL));
	const int MAXW = 140;
	const int MAXH = 40;
	Console::SetWindowSize(MAXW, MAXH);
	Console::CursorVisible = false;
	CJuego* obj = new CJuego();
	obj->jugar(MAXW, MAXH);
	system("pause");
	return 0;
}