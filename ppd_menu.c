/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Semester 2 2016 Assignment #2
 * Full Name        : Peng Gao
 * Student Number   : s3457558
 * Course Code      : COSC1076
 * Program Code     : BP162
 * Start up code provided by Paul Miller
 * Some codes are adopted here with permission by an anonymous author
 ***********************************************************************/

#include "ppd_menu.h"
/**
 * @file ppd_menu.c handles the initialised and management of the menu 
 * array
 **/

/**
 * @param menu the menu item array to initialise
 **/
void init_menu(struct menu_item* menu) {
	/* array of the diaplay the Main Menu*/
	char * names[NUM_MENU_ITEMS] = { "Display Items", "Purchase Item",
			"Save and Exit", "Add Item", "Remove Item", "Display Coins",
			"Reset Stock", "Reset Coins", "Abort Program" };

	/* array of the menu function to perform program */
	menu_function func[NUM_MENU_ITEMS] = { display_items, purchase_item,
			save_system, add_item, remove_item, reset_stock, reset_coins,
			display_coins };

	/* simple counter */
	unsigned i;

	for (i = 0; i < NUM_MENU_ITEMS; ++i) {
		strcpy(menu[i].name, names[i]);
		menu[i].function = func[i];
	}

}

/**
 * @return a menu_function that defines how to perform the user's
 * selection
 **/
menu_function * get_menu_choice(struct menu_item * menu)
{

	int choice;
	/* print menu */
	unsigned i;
	BOOLEAN run = FALSE;
	char prompt[20];

	printf("Main Menu:\n");
	for (i = 0; i < NUM_MENU_ITEMS; ++i) {
		printf("%d. %s\n", i + 1, menu[i].name);
		if (i == BLANK_LINE) {
			printf("Administrator-Only Menu:\n");
		}
	}

	/* user get the input */
	sprintf(prompt,"Select your option (%d-%d):", 1, 9);

	do
	{
		run = getInteger(&choice,1,prompt,1,9);
		if (run==TRUE)
		{
			break;
		}
	}while(run==FALSE);


	return menu[choice - 1].function;


}
