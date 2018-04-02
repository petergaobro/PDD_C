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
#include "ppd_shared.h"
/**
 * @file ppd_coin.h defines the coin structure for managing currency in the
 * system. You should declare function prototypes for managing coins here
 * and implement them in ppd_coin.c
 **/
#ifndef PPD_COIN
#define PPD_COIN
#define COIN_DELIM ","
struct ppd_system;

/* in one dollar, there are 100 cents in it */
#define DOLLAR 100

/**
 * enumeration representing the various types of currency available in
 * the system. 
 **/
enum denomination
{
    FIVE_CENTS, TEN_CENTS, TWENTY_CENTS, FIFTY_CENTS, ONE_DOLLAR, 
    TWO_DOLLARS, FIVE_DOLLARS, TEN_DOLLARS
};

/* The maximum of userstore coins */
#define MAX_USERSTORE 50


/* each values represent current value about money */
enum coin_value
{
    CV_FIVE_CENTS=5, CV_TEN_CENTS=10, CV_TWENTY_CENTS=20,
    CV_FIFTY_CENTS=50, CV_ONE_DOLLAR=100, CV_TWO_DOLLARS=200,
    CV_FIVE_DOLLARS=500, CV_TEN_DOLLARS=1000,
    /**
     * an invalid coin value
     **/
    CV_INVALID=-1
};


/**
 * represents a coin type stored in the cash register. Each demonination
 * will have exactly one of these in the cash register.
 **/
struct coin
{
    /**
     * the denomination type
     **/
    enum denomination denom;
    /**
     * the count of how many of these are in the cash register
     **/
    unsigned count;
};

/* userstore---store their coins when user input them */
struct userstore
{
	/* this is coins array of pointers
	 * when the user input coins into system
	 * the array will be generated. */
	struct coins * array[MAX_USERSTORE];

	int tos;
};


void coins(struct coin);

void coinchange(struct userstore *);

void refunds(struct userstore *);

BOOLEAN coins_calculator(struct userstore*, int, struct coin*);
#endif
