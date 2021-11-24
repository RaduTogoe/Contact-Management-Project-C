#ifndef con
#define con

#include "list_functions.c"
#include "menu_functions.c"
#include "fun.h"
void	verify_list(void);

void	import_contacts(void)
{
		
		char c[75];
		//char s[30];
		char fn[30], ln[30], nr[15];
		char *p;
		FILE *f = fopen("contacts.csv", "r");
		int k = 0;
		int a = 0;
		//FILE *f1 = fopen("a.txt", "w");
		a = fscanf(f, "%s", c);

		while (a == 1)
		{
			p = strtok(c, ",");
			while (p)
			{
					if (k == 0)
					{
							strcpy(fn, p);
					}
					if (k == 1)
					{
							strcpy(ln, p);
					}
					if (k == 2)
					{
							strcpy(nr, p);
							k = -1;
					}
					k++;
					p = strtok(NULL, ",");
			}
			//fprintf(f1, "%s,%s,%s\n", fn, ln, nr);
			insert_node(fn, ln, nr);
			a = fscanf(f, "%s", c);
		}
		//verify_list();
}

void	export_contacts(void)
{
		FILE *f = fopen("contacts.csv", "w");
		struct node *temp = head;
		while (temp)
		{
				fprintf(f, "%s,%s,%s\n", temp->first_name, temp->last_name, temp->phone_number);
				temp = temp->link;
		}
}

void	list_all_contacts(void)
{
	wclear(win);
	box(win, 0, 0);
	wrefresh(win);
	refresh();
	struct node *temp = head;
	int i = 2;
	FILE *f1 = fopen("a.txt", "w");
	while (temp)
	{
		fprintf(f1, "%s %s %s\n", temp->first_name, temp->last_name, temp->phone_number);
		mvwprintw(win, i, 10, "%s %s %s\n", temp->first_name, temp->last_name, temp->phone_number);
		temp = temp->link;
		i++;
	}
	wrefresh(win);
	refresh();
		mvwprintw(win, i+2, 2, "Do you want to return to the main menu? Answer by yes or no");
		wmove(win, 10, 2);
		char op[5];
		wgetstr(win, op);
		if (strcmp(op, "yes") == 0 || strcmp(op, "YES") == 0	)
		{
				wclear(win);
				create_menu();
		}
		else
		return;

}

void	verify_list(void)
{
		struct node *temp = head;
		FILE *f1 = fopen("a.txt", "w");
		while (temp)
		{
				fprintf(f1, "%s %s %s\n", temp->first_name, temp->last_name, temp->phone_number);
				temp = temp->link;
		}
}

void	create_contact(void)
{
		clear();
		box(win, 0, 0);
		wrefresh(win);
		refresh();
		char fn[30], ln[30], pn[30];
		echo();
		mvwprintw(win, 2, 2, "Please introduce the first name\n");
		wmove(win, 3, 2);
		wgetstr(win, fn);
		mvwprintw(win, 4, 2, "Please introduce the last name\n");
		wmove(win, 5, 2);
		wgetstr(win, ln);
		mvwprintw(win, 6, 2, "Please introduce the phone number\n");
		wmove(win, 7, 2);
		wgetstr(win, pn);
		insert_node(fn, ln, pn);
		mvwprintw(win, 8, 2, "Your contact was successfully created\n");
		refresh();
		wrefresh(win);
		//export_contacts();
		mvwprintw(win, 9, 2, "Do you want to return to the main menu? Answer by yes or no");
		wmove(win, 10, 2);
		char op[5];
		wgetstr(win, op);
		if (strcmp(op, "yes") == 0 || strcmp(op, "YES") == 0	)
		{
				wclear(win);
				create_menu();
		}
		else
		return;
}

void	delete_contact(void)
{
		wclear(win);
		box(win, 0, 0);
		refresh();
		wrefresh(win);
		char fn[30], ln[30], pn[30], s[5];
		echo();
		mvwprintw(win, 2, 2, "Please introduce the first name of the contact you want to delete\n");
		wmove(win, 3, 2);
		wgetstr(win, fn);
		mvwprintw(win, 4, 2, "Please introduce the last name of the contact you want to delete\n");
		wmove(win, 5, 2);
		wgetstr(win, ln);
		mvwprintw(win, 6, 2, "Please introduce the phone number of the contact you want to delete\n");
		wmove(win, 7, 2);
		wgetstr(win, pn);
		int ok = delete_node(fn, ln, pn);
		if (ok == 0)
		{
		mvwprintw(win, 10, 2, "The introduced data couldn't match any contact, do you want to try again?\n");
		mvwprintw(win, 11, 2, "Answer by yes or no");
		wmove(win, 12, 2);
		wgetstr(win, s);
		if (strcmp(s, "yes") == 0)
		{
			edit_contact();
			return;
		}
		else
		{
				wclear(win);
				kk = 1;
				create_menu();
				return;
		}
		}

		mvwprintw(win, 12, 2, "Your contact has been delected\n");
		//export_contacts();
		mvwprintw(win, 13, 2, "Do you want to return to the main menu? Answer by yes or no");
		wmove(win, 14, 2);
		char op[5];
		wgetstr(win, op);
		if (strcmp(op, "yes") == 0 || strcmp(op, "YES") == 0)
		{
				wclear(win);
				create_menu();
		}
		else
		return;

}

void	edit_contact(void)
{
	clear();
	wclear(win);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
	char fn[30], ln[30], pn[30];
	echo();
	mvwprintw(win, 2, 2, "Please introduce the first name of the contact you want to edit\n");
	wmove(win, 3, 2);
	wgetstr(win, fn);
	mvwprintw(win, 4, 2, "Please introduce the last name of the contact you want to edit\n");
	wmove(win, 5, 2);
	wgetstr(win, ln);
	mvwprintw(win, 6, 2, "Please introduce the phone number of the contact you want to edit\n");
	wmove(win, 7, 2);
	wgetstr(win, pn);
	edit_node(fn, ln, pn);
	/*mvwprintw(win, 9, 2, "Do you want to return to the main menu? Answer by yes or np\n");
		wmove(win, 10, 2);
		char op[5];
		wgetstr(win, op);
		if (strcmp(op, "yes") == 0 || strcmp(op, "YES") == 0	)
		{
				wclear(win);
				create_menu();
		}
		else
		return;*/


}

void	operation(int option)
{
	if (option == 1)
		list_all_contacts();
	if (option == 2)
		create_contact();
	if (option == 3)
		delete_contact();
	if (option == 4)
		edit_contact();
	if (option == 5)
	{
			export_contacts();
			return;
	}
}

#endif
