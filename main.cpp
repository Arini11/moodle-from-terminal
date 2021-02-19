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

	vector<string> titols = carregar_dades();

	int length = titols.size();

	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	int height, width, start_y, start_x;
	start_y = start_x = 0;

	getmaxyx(stdscr, height, width);
	WINDOW * win1 = newwin(height, width, start_y, start_x); 
	WINDOW * win2 = newwin(height, width, start_y, start_x); 
	box(win1, 0, 0);

	// ARRAY MENUS1
	Menu menus1[length] = {Menu()};
	for(int i=0;i<length;i++){
		menus1[i] = Menu(titols[i]);
	}
	Menu menus2[length] = {Menu()};
	for(int i=0;i<length;i++){
		menus1[i] = Menu(titols[i]);
	}
	// ARRAY MENUS2

	MenuBar menu1 = MenuBar(win1, menus1, length);
	MenuBar menu2 = MenuBar(win2, menus2, length);
	menu1.draw();

	int c;
	while(c = wgetch(win1)){
		menu1.handleTrigger(c);
		menu1.draw();
	}

	endwin();

	return 0;
}
