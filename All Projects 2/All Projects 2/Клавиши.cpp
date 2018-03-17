/*#include "Header.h"
using namespace std;
void draw(int x, int y, int color)
{
	setfillstyle(1, color);
	bar(x, y, x + 20, y + 20);
}
main()
{
	int x, y,dx,dy;
	initwindow(400, 400);
	setfillstyle(1, COLOR(0, 0, 255));
	bar(0, 0, 399, 399);
	x = 0; y = 240;
	dx = 1; dy = 0;
	while (1)
	{
		if (kbhit())
		{
			code = getch();
			if (code == 27) break;
			switch(code)
			{
				case 75:dx = -1; dy = 0; break;
				case 77:dx = 1; dy = 0; break;
				case 72:dx = 0; dy = -1; break;
				case 80:dx = 0; dy = -1;
			}
		}
		Draw(x, y, COLOR(255, 255, 0));
		delay(10);
		Draw(x, y, COLOR(0, 0, 255));
		x += dx;
		y += dy;
	}
	closegraph;
}
*/