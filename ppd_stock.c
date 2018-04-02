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
#include "ppd_stock.h"

/**
 * @file ppd_stock.c this is the file where you will implement the
 * interface functions for managing the stock list.
 **/

/* check ID is valid or not */
BOOLEAN valid_id(const char *string) {
	return TRUE;
}

/* check NAME is valid or not */
BOOLEAN valid_name(const char *string) {
	return TRUE;
}

/* check DESCRIPTION is valid or not */
BOOLEAN valid_desc(const char *string) {
	return TRUE;
}

BOOLEAN strtoprice(const char * input, struct price* price) {
	long result;
	const char * start = input;
	char * end;
	/*dollar*/
	result = strtol(input, &end, 10);
	if (*end != '.') {
		printf("Error: the price is not valid.\n");
		return FALSE;
	}
	if (result < 0 || result > 99) {
		fprintf(stderr, "Error: the dollars are out of range.\n");
		return FALSE;
	}

	/*cents*/
	price->dollars = result;
	start = end + 1;
	result = strtol(start, &end, 10);

	if (*end != '\0') {
		fprintf(stderr, "Error: the cents are not numeric.\n");
		return FALSE;
	}
	if (result < 0 || result > 95) {
		fprintf(stderr, "Error: the cents are out of range.\n");
		return FALSE;
	}
	price->cents = result;
	return TRUE;
}

struct ppd_stock * create_stock(const char * id, const char * name,
        const char * desc, struct price price, unsigned on_hand)
{
    struct ppd_stock * new = NULL;
    /* allocate space for the new stock */
    new = malloc(sizeof(struct ppd_stock));
    if(!new)
    {
        perror("failed to allocate memory");
        return NULL;
    }
    /* copy the values in */
    strcpy(new->id, id);
    strcpy(new->name, name);
    strcpy(new->desc, desc);
    new->price = price;
    new->on_hand = on_hand;
    return new;
}

struct ppd_stock * strtostock(char * mystring)
{
	char * end;
	char * tok;
	char *s = "|";
	char *id, *name, *desc;
	struct price price;
	unsigned on_hand;
	struct ppd_stock * newstock;
	unsigned fieldIndex = 1;

	tok = strtok(mystring, s);

	while (tok) {
		switch (fieldIndex) {
		case 1:
			id = tok;
			break;
		case 2:
			name = tok;
			break;
		case 3:
			desc = tok;
			break;
		case 4:
			if (!strtoprice(tok, &price)) {
				return NULL;
			}
			break;
		case 5:
			on_hand = strtol(tok, &end, 10);
			break;
		default:
			fprintf(stderr, "Error in stock file : "
					"invalid number of tokens.\n");
			return NULL;
		}
		/* grab the next token */
		tok = strtok(NULL, s);
		fieldIndex++;
	}

	newstock = create_stock(id, name, desc, price, on_hand);

	return newstock;
}


BOOLEAN insert_stock(struct ppd_list* list, struct ppd_stock* newstock)
{
    struct ppd_node * current, *prev = NULL;
    struct ppd_node * new = malloc(sizeof(struct ppd_node));
    if(!new)
    {
        perror("failed to allocate memory.\n");
        return FALSE;
    }

    new->next = NULL;
    new->data = newstock;
    current = list->head;
    while(current)
    {
        prev = current;
        current = current -> next;
    }
	
    if(!prev)
    {
        new->next = list->head;
        list->head = new;
    }
    else if(!current)
    {
        prev->next = new;
    }
    else
    {

        new->next = current;
        prev->next = new;
    }

    ++list->count;
    return TRUE;
}


BOOLEAN stock_list_init(struct ppd_list ** list)
{
    void * memory = malloc(sizeof(struct ppd_list));
    if(!memory)
    {
        perror("Failed to allocate memory");
        return FALSE;
    }
    memset(memory, 0, sizeof(struct ppd_list));
    *list = (struct ppd_list*)memory;

    return TRUE;
}


void display_stock(struct ppd_list* list)
{
	int my_name_line = 0;
	my_name_line = getNameLength(list);

    struct ppd_node * current = list -> head;
    while(current)
    {
        /* print the item menu */
        struct ppd_stock * data = current -> data;
        struct price price = data->price;
        printf("%-*s|",IDLEN, data->id);
        printf("%-*s|",my_name_line,data->name);
        printf("%-*d|",(int)strlen(" Available "),data->on_hand);
        printf("$%2d.%02d\n",price.dollars, price.cents);
        /* next node list */
        current = current->next;
    }

}


struct ppd_stock * findStockById(char * itemId,struct ppd_system * system)
{
	char *findItemId;
	struct ppd_stock *current_stock;
	struct ppd_node  *currentNode;
	struct ppd_list  *lst = system->item_list;
	currentNode = lst->head;
	while(currentNode != NULL)
	{
		current_stock = currentNode->data;
		findItemId = current_stock->id;
		if (strcmp(itemId,findItemId) == 0)
		{
			break;
		}else
		{
			current_stock = NULL;
		}
		currentNode = currentNode->next;
	}
	return current_stock;

}


BOOLEAN check_money(int money)
{
	if(money == 5 || money == 10 || money == 20 ||
			money == 50 || money == 100 || money == 200 ||
			money == 500 || money == 1000)
	{
		return TRUE;
	}
	else
	{
		printf("Error: no valid money. Please try again!\n");
		return FALSE;
	}
}
