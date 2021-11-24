#ifndef LIST
#define LIST
#include "var.h"
#include "fun.h"
#include "c_func.c"
void	edit_node(char *fn, char *ln, char *pn)
{
		clear();
		wclear(win);
		box(win, 0, 0);
		refresh();
		wrefresh(win);
		int ok = 0;
		char s[30];
		struct node *temp = head;
		while (temp)
		{
				if (strcmp(fn, temp->first_name) == 0 && strcmp(ln, temp->last_name) == 0 && strcmp(pn, temp->phone_number) == 0)
				{
						ok = 1;
						mvwprintw(win, 2, 2, "Answer by yes or no:\n");
						mvwprintw(win, 3, 2, "Do you want to edit the first name?\n");
						wmove(win, 4, 2);
						wgetstr(win, s);
						if (strcmp(s, "yes") == 0)
						{mvwprintw(win, 6, 2, "Introduce the new first name\n");
								s[0] = '\0';
								wmove(win, 7, 2);
								wgetstr(win, s);
								strcpy(temp->first_name, s);
								s[0] = '\0';

						}
						mvwprintw(win, 8, 2, "Do you want to edit the last name\n");
						wmove(win, 9, 2);
						wgetstr(win, s);
						if (strcmp(s, "yes") == 0)
						{
								mvwprintw(win, 10, 2, "Introduce the new last name\n");
								wmove(win, 11, 2);
								s[0] = '\0';
								wgetstr(win, s);
								strcpy(temp->last_name, s);
								s[0] = '\0';

						}
						mvwprintw(win, 12, 2, "Do you want to edit the phone number\n");
						wmove(win, 13, 2);
						wgetstr(win, s);
						if (strcmp(s, "yes") == 0)
						{
								s[0] = '\0';
								mvwprintw(win, 13, 2, "Introduce the new phone number\n");
								wmove(win, 14, 2);
								wgetstr(win, s);
								strcpy(temp->phone_number, s);
						}
				}
				temp = temp->link;
		}
		if (ok == 0)
		{mvwprintw(win, 3, 2, "The introduced data couldn't match any contact, do you want to try again?\n");
				mvwprintw(win, 4, 2, "Answer by yes or no");
				wmove(win, 5, 2);
				wgetstr(win, s);
				if (strcmp(s, "yes") == 0)
				{
						edit_contact();
						return;
				}
				else
				{
						wclear(win);
						create_menu();
						return;
				}}
		clear();
		wclear(win);
		box(win, 0, 0);
		refresh();
		wrefresh(win);

		mvwprintw(win, 15, 2, "Your contact has been edited\n");
		mvwprintw(win, 9, 2, "Do you want to return to the main menu? Answer by yes or no");
		wmove(win, 10, 2);
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

void	insert_node(char *fn, char *ln, char *pn)
{
		struct node *temp = NULL;

		temp = malloc(sizeof(struct node));
		strcpy(temp->first_name, fn);
		strcpy(temp->last_name, ln);
		strcpy(temp->phone_number, pn);
		temp->link = NULL;
		if (head == NULL)
				head = temp;
		else
		{
				temp->link = head;
				head = temp;
		}

}

int		delete_node(char *fn, char *ln, char *pn)
{
		struct node *temp = NULL;
		struct node *temp1 = NULL;
		int ok = 0;
		temp = head;
		if (head == NULL)
				return(ok);
		if (strcmp(temp->first_name, fn) == 0 && strcmp(temp->last_name, ln) == 0 && strcmp(temp->phone_number, pn) == 0)
				{		ok = 1;
						head = temp->link;
						free(temp);
				}
				else
				{
						while (temp)
						{
								ok = 1;
								if (strcmp(temp->first_name, fn) == 0 && strcmp(temp->last_name, ln) == 0)
										if (strcmp(temp->phone_number, pn) == 0)
										{
												temp1->link = temp->link;
												free(temp);
												break;
										}
								temp1 = temp;
								temp = temp->link;
						}
				}

		return (ok);		
}
#endif
