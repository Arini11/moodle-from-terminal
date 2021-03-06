#include <curses.h>
#include <string>

#ifndef _MENU_H_
#define _MENU_H_

class Menu{
//treure public i posar getters i setters
public:

	int start_y;
	std::string text;

	Menu(){
	}

	Menu(std::string text){
		this->text = text;
	}

};

class MenuBar{
//treure public i posar getters i setters
public:

	WINDOW *win;
	Menu * menus;
	int num_menus;
	int selected_menu;

	MenuBar(WINDOW *win, Menu* menus, int num_menus){
		this->win = win;
		this->menus = menus;
		this->num_menus = num_menus;
		this->selected_menu = 0;

		int curr_pos = 1;

		for(int i=0;i<num_menus;i++){
			this->menus[i].start_y = curr_pos;
			curr_pos++;
		}
	}

	void draw(){
		for(int i=0;i<num_menus;i++){
			int start_y = this->menus[i].start_y;
			std::string text = this->menus[i].text;
			if(selected_menu == i)
				//només cal posar dins del loop l'attribute ON, en cas que la opcio sigui la seleccionada
				wattron(win,A_REVERSE);
			mvwprintw(win, start_y, 2, text.c_str());
			//encara que attroff s'executi sempre, no passa res, no dona error.
			//Més val així que repetir mvwprintw i fer un else
			wattroff(win,A_REVERSE);
		}
	}


	void handleTrigger(int trigger){
			if(trigger == 107){		// 107 = j
				selected_menu--;
				if(selected_menu < 0) // Si surt del límit superior, es restableix la posició a 0
					selected_menu = 0;
			}

			if(trigger ==106 && trigger){ //106 = k
				selected_menu++;
				if(selected_menu > num_menus-1) // Si surt del límit inferior, es restableix a l'última posició
					selected_menu = num_menus-1;
			}
	}

};
#endif
