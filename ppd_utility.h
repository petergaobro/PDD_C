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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ppd_main.h"
#include "ppd_stock.h"
#ifndef PPD_UTILITY
#define PPD_UTILITY
/**
 * @file ppd_utility.h defines some helper functions for the rest of your
 * program. In particular, it declares three of the most important 
 * functions for your application: @ref load_data which loads the data
 * in from files, @ref system_init which initialises the system to a 
 * known safe state and @ref system_free which frees all memory when you
 * are going to quit the application.
 **/


/**
 * the maximum length of a line read in from the console
 **/
#define LINE_LEN 80

#define OTHER_CHARS 2

/**
 * the maximum length of a line in the coin file
 **/
#define COIN_LINE_LEN 20


/* show the judgement of user input */
enum user_input
{
	/* when the user's input is incorrect---failure */
	FAILURE,
	/* when the user's input is right---success */
	SUCCESS,
	/* payment */
	PAY
};

#define PUT_LINE(N) { \
    unsigned n; \
    for(n = 0; n < N; ++n) \
    { \
        putchar('-'); \
    } \
    putchar('\n');\
}


/**
 * the function to call for buffer clearing. This was discussed extensively
 * for assignment 1
 **/
void read_rest_of_line(void);

/**
 * Initialise the system to a known safe state. Before you post on the
 * discussion board about this, have a look at the structures as defined
 * in ppd_stock.h, ppd_coin.h and ppd_main.h. Given that nothing is 
 * initialized by the system if it
 * is a local variable, what would be good starting values for each of 
 * these. You already have some experience with this from assignment 
 * 1 to help you.
 **/
BOOLEAN system_init(struct ppd_system *);

/**
 * loads the stock file's data into the system. This needs to be 
 * implemented as part of requirement 2 of the assignment specification.
 **/
BOOLEAN load_stock(struct ppd_system *, const char *);

/**
 * loads the contents of the coins file into the system. This needs to
 * be implemented as part 1 of requirement 18.
 **/
BOOLEAN load_coins(struct ppd_system *, const char *);

/**
 * free all memory that has been allocated. If you are struggling to
 * find all your memory leaks, compile your program with the -g flag
 * and run it through valgrind. An important thing to think about here:
 * as malloc() returns a memory address to the first byte allocated, you
 * must pass each of these memory addresses to free, and no other 
 * memory addresses.
 **/
void system_free(struct ppd_system *);


BOOLEAN save_stock(struct ppd_system*);

BOOLEAN save_coins(struct ppd_system*);



int getNameLength(struct ppd_list * item_list);


BOOLEAN getInteger(int* integer, const unsigned length, const char* prompt,
		const int min, const int max);



#endif
