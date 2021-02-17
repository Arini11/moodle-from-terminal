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

	int height, width, start_y, start_x;
	start_y = start_x = 0;

	getmaxyx(stdscr, height, width);
	WINDOW * index = newwin(height, width, start_y, start_x); 
	box(index, 0, 0);

	Menu menus[length] = {Menu()};
	
	for(int i=0;i<length;i++){
		menus[i] = Menu(titols[i]);
	}

	MenuBar menubar = MenuBar(index, menus, length);
	menubar.draw();

	int c;
	while(c = wgetch(index)){
		//menubar.handleTrigger(c);
		menubar.draw();
	}

	endwin();

	return 0;
}
