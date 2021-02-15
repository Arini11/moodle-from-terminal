#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ncurses.h>
#include <vector>
#include "menu.h"
#include "json_parse.h"
#include "json_parse.cpp"

using namespace std;

int main(){

	vector<Json::Value> titols = carregar_dades();

	initscr();
	noecho();
	curs_set(0);

	int height, width, start_y, start_x;
	start_y = start_x = 0;

	getmaxyx(stdscr, height, width);
	WINDOW * index = newwin(height, width, start_y, start_x); 
	box(index, 0, 0);

	Menu menus[4] = {
		Menu(titols[0], '1'),
		Menu(titols[1], '2'),
		Menu(titols[2], '3'),
		Menu(titols[3], '4')
	};

	MenuBar menubar = MenuBar(index, menus, 4);
	menubar.draw();

	char ch;
	while(ch = wgetch(index)){
		menubar.handleTrigger(ch);
		menubar.draw();
	}

	endwin();

	return 0;
}
