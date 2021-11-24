#ifndef MENU
#define MENU
#include "var.h"
#include "c_func.c"
#include "fun.h"

void insert_ascii_art_phone()
{
		wmove(win, 2, 4);
		mvwprintw(win, 2, 4, "   _\n");
		mvwprintw(win, 3, 4, "  | |\n");
		mvwprintw(win, 4, 4,"  |_|\n");
 		mvwprintw(win, 5, 4,"/_\\   \\ | /");
		mvwprintw(win, 6, 4, ".-\"\"\"------.----.\n");
		mvwprintw(win, 7, 4, "|          U    |\n");
		mvwprintw(win, 8, 4, "|               |\n");
		mvwprintw(win, 9, 4, "| ====o======== |\n");
		mvwprintw(win, 10, 4,"| ============= |\n");
		mvwprintw(win, 11, 4,"|               |\n");
		mvwprintw(win, 12,4,"|_______________|\n");
		mvwprintw(win, 13,4,"| ________GF337 |\n");
		mvwprintw(win, 14,4,"||   Welcome   ||\n");
		mvwprintw(win, 15,4,"||             ||\n");
		mvwprintw(win, 16,4,"||_____________||\n");
		mvwprintw(win, 17,4,"|__.---\"\"\"---.__|\n");
		mvwprintw(win, 18,4,"|---------------|\n");
		mvwprintw(win, 19,4,"|[Yes][(|)][ No]|\n");
		mvwprintw(win, 20,4,"| ___  ___  ___ |\n");
		mvwprintw(win, 21,4,"|[<-'][CLR][.->]|\n");
		mvwprintw(win, 22,4," ___  ___  ___ |\n");
		mvwprintw(win, 23,4,"|[1__][2__][3__]|\n");
		mvwprintw(win, 24,4,"| ___  ___  ___ |\n");
		mvwprintw(win, 25,4,"|[4__][5__][6__]|\n");
		mvwprintw(win, 26,4,"| ___  ___  ___ |\n");
		mvwprintw(win, 27,4,"|[7__][8__][9__]|\n");
		mvwprintw(win, 28,4,"| ___  ___  ___ |\n");
		mvwprintw(win, 29,4,"|[*__][0__][#__]|\n");
		mvwprintw(win, 30,4,"`--------------'\n");
		mvwprintw(win, 31,4,"\{__|""|_______'-\n");
		mvwprintw(win, 32,4,"`---------------'\n");
		wrefresh(win);
		refresh();
}

void	insert_menu_options()
{
 		int i
		int highlight = 0;
		int choice;
		keypad(win, TRUE);
		struct options op[5] = {{"List all contacts"}, {"Create a new contact"}, {"Delete a contact"}, {"Edit a contact"}, {"Exit"}};
		while (1)
		{
				for (i = 0; i < 5; i++)
				{
						if (i == highlight)
						wattron(win, A_REVERSE);
						mvwprintw(win, i + 1, 30, op[i].s);
						wattroff(win, A_REVERSE);
				}
				choice = wgetch(win);
				switch (choice)
				{
					case KEY_UP:
					highlight--;
					if (highlight < 0)
					highlight = 3;
					break;
					case KEY_DOWN:
					highlight++;
					if (highlight > 4)
					highlight = 0;
					break;
				}
				if (choice == 10)
				{
					operation(highlight + 1);
						break;
				}
		}
		refresh();
		wrefresh(win);

}

void	create_menu(void)
{
		box(win, 0, 0); // creates a border for the window
		refresh();
		wrefresh(win);
		insert_ascii_art_phone();
		refresh();
		wrefresh(win);
		insert_menu_options();
		refresh();
		wrefresh(win);
}
void	create_window(void)
{
		initscr();   // initiates the window
		refresh();
		move(3, 10);
		//printw("Verification");// verifies where the text is

		win = newwin(40, 100, 3, 10); // initialises the window and creates it
			
		refresh();
		wrefresh(win);
		create_menu(); // creates the menu in the win window
		mvwprintw(win, 10, 30, "Press any key to continue");
		wmove(win, 11, 30);
		refresh();
		wrefresh(win);

		//wgetch(win);
		getch(); 
		endwin();
}
#endif
