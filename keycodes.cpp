//http://www.youtube.com/user/thecplusplusguy
//Thanks for the typed in code to Tapit85
#include <ncurses.h>

int main()
{
	initscr();
	noecho();
	raw();
	int c;
	while((c = getch()) != 27)
	{
		move(10,0);
		printw("Keycode: %d, and the character: %c", c, c);
		move(0,0);
		printw("Write something (ESC to escape): ");
		refresh();
	}
	endwin();
	return 0;
}