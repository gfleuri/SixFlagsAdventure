#ifndef HEADER_ROOMS
#define HEADER_ROOMS

#include <stdio.h>
#include <items.h>


/*
	Room Structure Creation
*/

struct Room * room(char* description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down);



/*
	Returns random room throughout whole map
	given specified parameters
*/

struct Room * fetchROOM(int floor, int room, struct Room * floor1, struct Room * floor2, struct Room * floor3, struct Room * floor4);



/*
	Freeing Room and Items in room
*/
void room_free(struct Room * c);



/*
	Get Room Description
*/

char * room_description(struct Room * room);



/*
	Get North Room
*/

struct Room * getNorth(struct Room * current);



/*
	Get South Romo
*/

struct Room * getSouth(struct Room * current);



/*
	Get East Room
*/

struct Room * getEast(struct Room * current);



/*
	Get West Room
*/

struct Room * getWest(struct Room * current);



/*
	Get Up Room
*/

struct Room * getUp(struct Room * current);



/*
	Get Down Room
*/

struct Room * getDown(struct Room * current);



/*
	Get items in room
*/

struct Item * getItems(struct Room * current);





#endif