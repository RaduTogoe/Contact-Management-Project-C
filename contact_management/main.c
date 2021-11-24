#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node *head = 0;
int kk= 0;
#include "ncurses.h"
WINDOW *win;
#include "fun.h"
#include "menu_functions.c"
#include "var.h"
#include "c_func.c"
#include "list_functions.c"

//struct node *head = NULL;
//WINDOW *win;

int		main(void)
{
		import_contacts();
		create_window();
		export_contacts();
}
