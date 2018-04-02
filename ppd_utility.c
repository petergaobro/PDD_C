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

#include "ppd_utility.h"
/**
 * @file ppd_utility.c contains implementations of important functions for
 * the system. If you are not sure where to implement a new function, 
 * here is probably a good spot.
 **/

BOOLEAN getInteger(int* integer, const unsigned length, const char* prompt,
		const int min, const int max) {
	BOOLEAN finished = FALSE;
	char* input;
	long long_result;
	int int_result = 0;

	/* a pointer to the next character after what has been successfully processed */
	char* end;

	/* Allocate temporary memory. */
	if ((input = malloc(sizeof(char) * (length + OTHER_CHARS))) == NULL) {
		/* displays this message followed by a system defined error message */
		perror("failed to allocate memory in getInteger");
		return FALSE;
	}

	/* Continue to interact with the user until the input is valid. */
	do {
		/* Provide a custom prompt. */
		printf("%s", prompt);

		/* Accept input. "EXTRACHARS" is for the \n and \0
		 * characters. */
		fgets(input, length + OTHER_CHARS, stdin);

		/* A string that doesn't have a newline character is too
		 * long (has leftover input in the buffer). */
		if (input[strlen(input) - 1] != '\n') {
			printf("Input was too long.\n");
			read_rest_of_line();
		} else {
			/* Overwrite the \n character with \0 as we now
			 * know we have gotten all the data from the buffer
			 */
			input[strlen(input) - 1] = '\0';
			/* Convert string to an integer. */
			long_result = strtol(input, &end, 10);
			/* Validate integer result. */
			if (*end != '\0') {
				/* there were leftover characters that were
				 * no processed so it was not a valid
				 * integer
				 */
				fprintf(stderr, "Input was not numeric.\n");
				return FALSE;
				/* continue; */

			}
			/* validate the range of the integer */
			if (long_result < min || long_result > max) {
				printf("Input was not within range %d - %d.\n", min, max);
				return FALSE;
			} else {
				/* all good so assign the value to its
				 * integer variable
				 */
				int_result = long_result;
				finished = TRUE;
			}
		}
	} while (finished == FALSE);

	/* Make the result integer available to calling function. */
	*integer = int_result;

	/* Deallocate temporary memory. */
	free(input);

	return TRUE;
}

void read_rest_of_line(void) {
	int ch;
	/* keep retrieving characters from stdin until we
	 * are at the end of the buffer
	 */
	while (ch = getc(stdin), ch != '\n' && ch != EOF)
		;
	/* reset error flags on stdin */
	clearerr(stdin);
}

/**
 * @param system a pointer to a @ref ppd_system struct that holds all 
 * the data for the system we are creating
 **/
BOOLEAN system_init(struct ppd_system * system)
{
	memset(system, 0, sizeof(struct ppd_system));
	if (stock_list_init(&system->item_list))
	{
		return TRUE;
	}
	return FALSE;
}

/**
 * loads the stock file's data into the system. This needs to be 
 * implemented as part of requirement 2 of the assignment specification.
 **/
BOOLEAN load_stock(struct ppd_system * system, const char * filename)
{
	FILE * f_stock = NULL;
	char line[STOCK_LEN + OTHER_CHARS];
	struct pdd_stock * newstock = NULL;

	/* open the stock file and verify that it is within the
	 * allowed length */
	f_stock = fopen(filename, "r");
	if (!f_stock) {
		perror("Please try again! You cannot open stock file.");
		return FALSE;
	}

	while (fgets(line, STOCK_LEN + OTHER_CHARS, f_stock) != NULL)
	{
		if (line[strlen(line) - 1] != '\n') {
			printf("Error: the line is too long!\n");
			fclose(f_stock);
			return FALSE;
		}
		line[strlen(line) - 1] = '\0';

		newstock = strtostock(line);

		if (!newstock) {
			fclose(f_stock);
			return FALSE;
		}
		if (!insert_stock(system->item_list, newstock)) {
			fprintf(stderr, "Error: failed to insert stock into the "
					"system.\n");
			fclose(f_stock);
			return FALSE;
		}

	}
	fclose(f_stock);

	return TRUE;
}

/**
 * loads the contents of the coins file into the system. This needs to
 * be implemented as part 1 of requirement 18.
 **/
BOOLEAN load_coins(struct ppd_system * system, const char * filename) {
	/*
	 * Please delete this default return value once this function has
	 * been implemented. Please note that it is convention that until
	 * a function has been implemented it should return FALSE
	 */
	return FALSE;

}

/**
 * @param system a pointer to a @ref ppd_system struct that holds all 
 * the data for the system we are creating
 **/
void system_free(struct ppd_system * system)
{

}

BOOLEAN save_stock(struct ppd_system *system)
{
	return FALSE;
}

BOOLEAN save_coins(struct ppd_system *system)
{
	return FALSE;
}


int getNameLength(struct ppd_list * item_list)
{
	struct ppd_node * current_node = NULL;
	current_node = item_list->head;
	int len = 0;
	int maxlen = 0;

	while(current_node != NULL)
	{
		len = strlen(current_node->data->name);
		if(len > maxlen)
		{
			maxlen = len;
		}
		current_node = current_node->next;
	}
	return maxlen;
}

