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

#include "ppd_main.h"
#include "ppd_menu.h"
#include "ppd_options.h"
#include "ppd_utility.h"

/**
 * @file ppd_main.c contains the main function implementation and any 
 * helper functions for main such as a display_usage() function.
 **/

/**
 * manages the running of the program, initialises data structures, loads
 * data and handles the processing of options. The bulk of this function
 * should simply be calling other functions to get the job done.
 **/
int main(int argc, char **argv)
{
    /* uncomment this menu structure when you are ready to work on the 
     * menu system with function pointers */
    struct menu_item menu[NUM_MENU_ITEMS];

    /* represents the data structures to manage the system */
    struct ppd_system system;

    BOOLEAN init_tmp, load_tmp;
    BOOLEAN quit = FALSE;

    /* validate command line arguments */
    if(argc != 2)
    {
        printf("Error: invalid arguments passed in.\n");
        return EXIT_FAILURE;
    }

    /* init the system */
    init_tmp = system_init(&system);

    /* load data */
    load_tmp = load_stock(&system, argv[1]);

    /* test if everything has been initialised correctly */
    if(!init_tmp || !load_tmp)
    {
        return EXIT_FAILURE;
    }

    /* initialise the menu system */
    init_menu(menu);
    /* loop, asking for options from the menu */

    /* run each option selected */

    /* until the user quits */
    while(!	quit )
    {
    	menu_function task;
    	/* display the main menu and get the choice */
    	task = get_menu_choice(menu);
    	task(&system);
    }
    /* make sure you always free all memory and close all files 
     * before you exit the program
     */
    return EXIT_SUCCESS;
}

/*
void display_usage(void)
{
    fprintf(stderr, "Correct arguments are: \n");
    fprintf(stderr, "\t./ppd <stockfile> <coinfile>\n");
    fprintf(stderr, "Where <stockfile> and <coinfile> are two valid "
            "files in the expected format.\n");
}
*/
