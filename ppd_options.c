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

#include "ppd_options.h"
#include "ppd_utility.h"

/**
 * @file ppd_options.c this is where you need to implement the main 
 * options for your program. You may however have the actual work done
 * in functions defined elsewhere. 
 * @note if there is an error you should handle it within the function
 * and not simply return FALSE unless it is a fatal error for the 
 * task at hand. You want people to use your software, afterall, and
 * badly behaving software doesn't get used.
 **/

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true as this particular function should never fail.
 **/
BOOLEAN display_items(struct ppd_system * system) {
	/* display the detail of items */
	int my_name_line = getNameLength(system->item_list);

	printf("Items Menu\n");
	PUT_LINE(strlen("Items Menu"));

	printf("%-*s|", IDLEN, "ID");
	printf("%-*s|", my_name_line, " Name");
	printf("%s|", " Available ");
	printf("%s\n", " Price ");

	PUT_LINE(
			IDLEN + my_name_line + strlen(" Available ") + strlen (" Price ") + 4);

	display_stock(system->item_list);

	printf("\n");

	return TRUE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true when a purchase succeeds and false when it does not
 **/
BOOLEAN purchase_item(struct ppd_system * system) {
	char prompt[100];
	char* itemId = NULL;
	struct ppd_stock *search_stock;
	int temp_money = 0;
	int input_money = 0;
	int refunds = 0;
	int item_price = 0;

	if ((itemId = malloc(sizeof(char) * (IDLEN + OTHER_CHARS))) == NULL) {
		perror("failed to allocate memory in purchase_item");
		return FALSE;
	}

	/* display all the heading details */
	printf("Purchase Item\n");
	PUT_LINE(strlen("Purchase Item"));

	/* TO DO */
	printf("Please enter the id of the item you wish to purchase: ");

	fgets(itemId, IDLEN + OTHER_CHARS, stdin);

	if (itemId[strlen(itemId) - 1] != '\n') {
		read_rest_of_line();
	} else {
		itemId[strlen(itemId) - 1] = '\0';
	}

	search_stock = findStockById(itemId, system);
	if (search_stock == NULL) {
		return FALSE;
	}
	else
	{
		if(search_stock->on_hand ==0)
		{
			printf("Sorry, this item is sold out.\n");
			printf("\n");
			return FALSE;
		}


		item_price = (search_stock->price.dollars * 100)
				+ (search_stock->price.cents);
	}

	printf("You have selected \"%s - %s\". This will cost you "
			"$%2d.%02d.\n", search_stock->name, search_stock->desc,
			search_stock->price.dollars, search_stock->price.cents);
	printf("Please hand over the money - type in the value of each "
			"note/coin in cents.\n");
	printf("Press enter on a new and empty line to cancel "
			"this purchase:\n");

	refunds = input_money - item_price;

	while (refunds < 0) {
		sprintf(prompt, "You still need to give us $%d.%02d: ",
				abs(refunds / 100), abs(refunds % 100));

		getInteger(&temp_money, 4, prompt, 0, 1000);

		if (temp_money == 0) {
			break;
		}

		if (check_money(temp_money) == FALSE) {
			continue;
		}

		input_money = input_money + temp_money;

		refunds = input_money - item_price;

	}
	if (refunds < 0) {

		printf("Refund your change of $%d.%02d\n", abs(input_money / 100),
				abs(input_money % 100));
	} else {

		printf("Thank you. Here is your %s\n", search_stock->name);
	}

	if (refunds > 0) {

		printf(" and your change of $%d.%02d\n", abs(refunds / 100),
				abs(refunds % 100));
	}

	free(itemId);

	return TRUE;

}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true when a save succeeds and false when it does not
 **/
BOOLEAN save_system(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */

	return TRUE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true when adding an item succeeds and false when it does not
 **/
BOOLEAN add_item(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true when removing an item succeeds and false when it does not
 **/
BOOLEAN remove_item(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true as this function cannot fail.
 **/
BOOLEAN reset_stock(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true as this function cannot fail.
 **/
BOOLEAN reset_coins(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;
}

/**
 * @param system a pointer to a  ppd_system struct that contains 
 * all the information for managing the system.
 * @return true as this function cannot fail
 **/
BOOLEAN display_coins(struct ppd_system * system) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;
}
