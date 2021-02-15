#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ncurses.h>
#include "menu.h"
#include "json_parse.h"

using namespace std;

int main(){

	initscr();
	noecho();
	curs_set(0);

	int height, width, start_y, start_x;
	start_y = start_x = 0;

	getmaxyx(stdscr, height, width);
	WINDOW * index = newwin(height, width, start_y, start_x); 
	box(index, 0, 0);

	Menu menus[4] = {
		Menu("ÑAÑ", '1'),
		Menu("ÑAÑ", '2'),
		Menu("ÑAÑ", '3'),
		Menu("ÑAÑ", '4'),
	};

	MenuBar menubar = MenuBar(index, menus, 4);
	menubar.draw();

	char ch;
	while(ch = wgetch(index)){
		menubar.handleTrigger(ch);
		menubar.draw();
	}

	endwin();

	carregar_dades();

	return 0;
}
