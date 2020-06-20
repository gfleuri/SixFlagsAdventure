#include <stdio.h>
#include <stdlib.h>
#include <items.h>


/*
	Room Structure
*/

struct Room {
  char * description;
  struct Item * items;
  struct Room * north;
  struct Room * south;
  struct Room * east;
  struct Room * west;
  struct Room * up;
  struct Room * down;
};



/*
	Room Structure Creation
*/

struct Room * room(char* description, struct Item* items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down) {
  struct Room * r = NULL;

  // allocating memory
  r = (struct Room *) malloc(sizeof(struct Room));

  // setting default values given parameters
  r->description = description;
  r->items = items;
  r->north = north;
  r->south = south;
  r->east = east;
  r->west = west;
  r->up = up;
  r->down = down;

  return r;
}



/*
	Returns random room throughout whole map
	given specified parameters
*/

struct Room * fetchROOM(int floor, int room, struct Room * floor1, struct Room * floor2, struct Room * floor3, struct Room * floor4) {

	// prototypes
	struct Room * getNorth(struct Room * current);
	struct Room * getSouth(struct Room * current);
	struct Room * getEast(struct Room * current);
	struct Room * getWest(struct Room * current);

	/*
		Goal: Convert numbers 1-4 into rooms / floors
			Floor: 1=1, 2=2, 3=3, 4=4
			Room: 1=N, 2=S, 3=E, 4=W
	*/

	if (floor == 1) {	// if floor 1

		if (room==1)
			return getNorth(floor1);
		if (room==2)
			return getSouth(floor1);
		if (room==3)
			return getEast(floor1);
		if (room==4)
			return getWest(floor1);

	} else if (floor == 2) {	// if floor 2

		if (room==1)
			return getNorth(floor2);
		if (room==2)
			return getSouth(floor2);
		if (room==3)
			return getEast(floor2);
		if (room==4)
			return getWest(floor2);
		
	} else if (floor == 3) { // if floor 3

		if (room==1)
			return getNorth(floor3);
		if (room==2)
			return getSouth(floor3);
		if (room==3)
			return getEast(floor3);
		if (room==4)
			return getWest(floor3);
		
	} else if (floor == 4) { // if floor 4

		if (room==1)
			return getNorth(floor4);
		if (room==2)
			return getSouth(floor4);
		if (room==3)
			return getEast(floor4);
		if (room==4)
			return getWest(floor4);
		
	}

	return getNorth(floor1);
}


/*
	Freeing Room and Items in room
*/
void room_free(struct Room * c) {
    
    struct Item * it = c->items;
    item_free(it); // freeing items
    
    free(c);	// freeing room
}


/*
	Get Room Description
*/

char * room_description(struct Room * room) {
	return room->description;
}


/*
	Get North Room
*/

struct Room * getNorth(struct Room * current) {
	return current->north;
}

/*
	Get South Romo
*/

struct Room * getSouth(struct Room * current) {
	return current->south;
}


/*
	Get East Room
*/

struct Room * getEast(struct Room * current) {
	return current->east;
}


/*
	Get West Room
*/

struct Room * getWest(struct Room * current) {
	return current->west;
}


/*
	Get Up Room
*/

struct Room * getUp(struct Room * current) {
	return current->up;
}


/*
	Get Down Room
*/

struct Room * getDown(struct Room * current) {
	return current->down;
}



/*
	Get items in room
*/

struct Item * getItems(struct Room * current) {
	return current->items;
}
