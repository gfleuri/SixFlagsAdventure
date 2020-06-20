#ifndef HEADER_ITEMS
#define HEADER_ITEMS

#include <stdio.h>


/*
	Item Creator
*/

struct Item * item(char * name, char * description, struct Item * next);



/*
	Returns Item name
*/

char * item_name(struct Item * x);



/*
	Returns Item Description
*/

char * item_description(struct Item * x);



/*
	Returns next Item list
*/

struct Item * item_next(struct Item * x);



/*
	Prints out item names
*/

void item_display(struct Item * list);



/*
	Prints out item descriptions
*/

void item_displayDESC(struct Item * list);



/*
	Adds item to another item list
*/

void item_add(struct Item * item, struct Item * list);



/*
	Return found item
	Returns same list if not found
	Remove found item from list
*/

struct Item * item_take(char * findName, struct Item * list);



/*
	Returns number of items in list
*/

int itemsInList(struct Item * list);



/*
	Frees item list
*/

void item_free(struct Item * c);



#endif