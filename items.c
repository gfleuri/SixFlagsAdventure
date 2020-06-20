#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
	Item Structure
*/

struct Item {
  char * name;
  char * description;
  struct Item * next;
};


/*
	Item Creator
*/

struct Item * item(char * name, char * description, struct Item * next) {

  struct Item * newItem = NULL;

  // allocates memory
  newItem = (struct Item *) malloc(sizeof(struct Item));

  //assigns default values through parameters
  newItem->name = name;
  newItem->description = description;
  newItem->next = next;

  return newItem;
}

/*
	Returns Item name
*/

char * item_name(struct Item * x) {
  return x->name;
}

/*
	Returns Item Description
*/

char * item_description(struct Item * x) {
  return x->description;
}

/*
	Returns next Item list
*/

struct Item * item_next(struct Item * x) {
  return x->next;
}

/*
	Prints out item names
*/

void item_display(struct Item * list) {

	int itemsInList(struct Item * list); // prototype

	if (itemsInList(list) == 0) {	// item amount check
		printf("No items found");
		return;
	}

	struct Item * ptr = list->next; // pointer skipping dummy

	while (ptr != NULL) {	// looping throughout

		// displaying
		printf("[%s] ", ptr->name);

		ptr=ptr->next; // iterations
	}

}


/*
	Prints out item descriptions
*/

void item_displayDESC(struct Item * list) {

	int itemsInList(struct Item * list); // protoype

	if (itemsInList(list) == 0) {	// item amount check
		printf("No items found");
		return;
	}

	struct Item * ptr = list->next;	// pointer skipping dummy

	while (ptr != NULL) {	// looping throuhgout

		// display
		printf("\t%s - %s \n\t", ptr->name, ptr->description);

		ptr=ptr->next;	// iterations
	}

}



/*
	Adds item to another item list
*/

void item_add(struct Item * item, struct Item * list) {

  struct Item * ptr = list;

  while (ptr->next != NULL) { // going to last item
  	ptr=ptr->next;
  }

	ptr->next = item;	// setting next to new item
}


/*
	Return found item
	Returns same list if not found
	Remove found item from list
*/

struct Item * item_take(char * findName, struct Item * list) {

  struct Item * ptr = list;			// current pointer
  struct Item * prev_ptr = list;	// previous pointer
  int numNodes = 1;					// skipping dummy

  while (ptr != NULL) {				// looping throughout

    if (strcmp(ptr->name,findName) == 0) { // name=findName
      // Last in list
      if (ptr->next == NULL) {

        prev_ptr->next = NULL;			// setting previous next to null

      } else { // not last

        prev_ptr->next = ptr->next;
        ptr->next = NULL;				// setting to null

      }
      return ptr;
    }

    numNodes++;
    prev_ptr = ptr;
    ptr=ptr->next;
  }
  return list;
}


/*
	Returns number of items in list
*/

int itemsInList(struct Item * list) {

  int count = 0;	// storing count

  struct Item * ptr = list; // pointer

  while (ptr->next != NULL) { // looping through
      count++;			// counting
      ptr=ptr->next;	// going to next
  }

  return count;
}


/*
	Frees item list
*/

void item_free(struct Item * c) {

	if (c == NULL) return; // base case

	item_free(c->next);
	free(c); // freeing
}