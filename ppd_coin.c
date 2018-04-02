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
#include "ppd_coin.h"
#include "ppd_utility.h"

 /**
  * @file ppd_coin.c implement functions here for managing coins in the
  * "cash register" contained in the @ref ppd_system struct.
  **/

/* initialize coins */
void coins_init(struct userstore* ust)
{
    memset(ust, 0, sizeof(struct userstore));
}


/* Valid denomination */
/*BOOLEAN valid_denom(int denom)
{
    switch(denom)
    {
        case CV_FIVE_CENTS:
        case CV_TEN_CENTS:
        case CV_TWENTY_CENTS:
        case CV_FIFTY_CENTS:
        case CV_ONE_DOLLAR:
        case CV_TWO_DOLLARS:
        case CV_FIVE_DOLLARS:
        case CV_TEN_DOLLARS:
            return TRUE;
        default:
            return FALSE;
    }
}*/


void coins(struct coin c)
{

}

/* display the coins change */
/*void coinchange(struct userstore * ust)
{
    struct coin * c = NULL;
    char * coinstr;
    if(ust -> tos == 0)
    {
        return;
    }
    c = stack_pop(ust);
    display_change(ust);
    coinstr = cointostr(c);
    printf("%s ", coinstr);
}
*/


/*void refunds(struct userstore * ust)
{
    struct coin * c = NULL;
    char * coinstr;
    if(ust -> tos == 0)
    {
        return;
    }
    c = stack_pop(ust);
    display_change(ust);
    coinstr = cointostr(c);
    printf("%s ", coinstr);
    --c->count;

}
*/

/*BOOLEAN change_calculator(struct userstore* ust, int owing, struct coin * coins)
{

}
*/
