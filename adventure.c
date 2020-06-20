#include <stdio.h>
#include <rooms.h>
#include <items.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

int main() {


	/*
		Creating all the rooms.
		Created with items that are empty at first
	*/

  	struct Room * north1 = room("1909 Illions Grand Carousel", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * south1 = room("Thunderbolt", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * east1 = room("Scream", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * west1 = room("Whistlestop Water Works", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * up1 = room("Staircase 1", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * down1 = room("Basement", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  	struct Room * north2 = room("Superman The Ride", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * south2 = room("Kryptonite Kollider", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * east2 = room("Catwoman Whip", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * west2 = room("Gotham City Gauntlet Escape From Arkham Asylum", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * up2 = room("Staircase 2", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * down2 = room("Staircase 1", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  	struct Room * north3 = room("Gotham City Crime Wave", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * south3 = room("Harley Quinn Spinsanity", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * east3 = room("The Riddler Revenge", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * west3 = room("Batman The Dark Knight", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * up3 = room("Staircase 3", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * down3 = room("Staircase 2", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);

  	struct Room * north4 = room("Monsoon Lagoon", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * south4 = room("Hurricane Falls", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * east4 = room("Gernimo Falls/Zooma Falls", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * west4 = room("Typhoon Water Coaster", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * up4 = room("Staircase 4", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);
  	struct Room * down4 = room("Staircase 3", item("dummy","dummy",NULL), NULL, NULL, NULL, NULL, NULL, NULL);


  	/*
  		Creating the seperate floors
  	*/
  	struct Room * floor1 = room("Main Street Plaza", item("dummy","dummy",NULL), north1, south1, east1, west1, up1, down1);
  	struct Room * floor2 = room("DC Super Adventures", item("dummy","dummy",NULL), north2, south2, east2, west2, up2, down2);
  	struct Room * floor3 = room("Gotham City", item("dummy","dummy",NULL), north3, south3, east3, west3, up3, down3);
  	struct Room * floor4 = room("Hurricane Harbor", item("dummy","dummy",NULL), north4, south4, east4, west4, up4, down4);


  	/*
  		Player inventory that will story all their items
  	*/
  	struct Item * inventory = item("dummy", "dummy",NULL);


  	item_add(item("JOURNAL", "!emag ym yojne uoy epoh", NULL), inventory); // random item


  	/*
		Game  Opening Message
	*/
  	printf("======================================================================\n\n");
  	printf("\t      --- THE SECRET SILVER OF SIX FLAGS --- \n");
  	printf("\n\tSTORY\n\tAre you ready to have the time of your life?\n");
  	printf("\tYes?.. Well Good! Because your about to enter\n");
  	printf("\tan amusment park with hidden riches!\n\n");
  	printf("\tGOAL\n\tUse commands provided by 'help' to locate the hidden\n");
  	printf("\tshard in one of the rooms. This 'key' will open a chest\n");
  	printf("\tin one of the rooms with loads of treasure. You must\n");
  	printf("\thurry to find it! Your tour guides Peter Parker, Bruce\n");
  	printf("\tBanner, and Tony Stark will assist you with advice.\n");
  	printf("\tGood Luck! But first, you must select a code to generate\n");
  	printf("\tthe map! Have fun!\n\n");



  	/*
		Entering Username
  	*/

  	int selected = FALSE;	// if username has been selected


	char * username = malloc(256);	// username storing
	    if (username == NULL)		// memory space check
	        return 1;
  	do {
  	printf("\n\n\t-> Pick a different username to generate a game ID!\n\t\tUsername:  ");

	fgets(username, 256, stdin); // getting line input

  	if (strlen(username) < 28 && strlen(username) > 2) // Checking usrname is between 3-27 characters
  		selected = TRUE;
  	else
  		printf("Please enter an appropriate value. Less than 28 letters. Must have atleast 3.\n");
  	} while (selected == FALSE);






  	/*
		Generating a Game ID:
		Game ID's are used to randomize the
		positioning of shards/orbs/chest around
		the map per different username
  	*/

  	int gameID = 0;	// the id value

  	int cntr = 1; // used as array parameter
  	while (username[cntr] != '\0') { // looping through name
  		// multiplying char val by 13131 *cntr to generate unique values
  		gameID+=(username[cntr]*(cntr*13131));
  		cntr++;	// increasing cntr
  	}

  	int codes[7] = {0,0,0,0,0,0,0};	// values taken from generated number
  	int codeCount = 0;				// generates vals 0-9

	int seed = gameID;
  	for (int i=0; i<7; i++){
	  	
  		int val = seed % 10;	// getting the last value in int
  		seed/=10;				// removing last value in int

  		if (val >= 7) {				// vals 7-9, become 4
  			val = 4;
  		} else if (val >= 5) {		// vals 5-6, become 3
  			val = 3;
  		} else if (val >= 3) {		// vals 3-4, become 2
  			val = 2;
  		} else {					// vals 0-2, become 1
  			val = 1;
  		}

  		// changing to ints 1-4, since there are 4 floors,
  		// and 4 different rooms per floor(N/S/E/W), not including up/down rooms

	  	codes[codeCount] = val; // storing these 1-4 vals in an int[]
	  	codeCount++; // incrementer

  	}

  	/*
		Placing items accross the map:
		fetchRoom() allows for the random vals of int codes[]
		to be used to return random rooms throughout each floor
		item_add used to add items to the room.
		getItems() returns the items for that room.
  	*/

  	item_add(item("ORB 1", "travel somewhere quick", NULL), getItems(fetchROOM(codes[1], codes[2], floor1, floor2, floor3, floor4)));
  	item_add(item("ORB 2", "travel somewhere quick", NULL), getItems(fetchROOM(codes[3], codes[4], floor1, floor2, floor3, floor4)));
  	item_add(item("ORB 3", "travel somewhere quick", NULL), getItems(fetchROOM(codes[5], codes[0], floor1, floor2, floor3, floor4)));

  	item_add(item("EGG", "not an easter egg...", NULL), getItems(fetchROOM(codes[5], codes[3], floor1, floor2, floor3, floor4)));

  	item_add(item("SHARD 1", "a purple diamond key", NULL), getItems(fetchROOM(codes[0], codes[1], floor1, floor2, floor3, floor4)));
  	item_add(item("SHARD 2", "a red ruby shard", NULL), getItems(fetchROOM(codes[2], codes[3], floor1, floor2, floor3, floor4)));
  	item_add(item("SHARD 3", "a silvery shiny secret shard", NULL), getItems(fetchROOM(codes[5], codes[4], floor1, floor2, floor3, floor4)));
  	item_add(item("$ TREASURE CHEST $", "so much gold you could buy six flags", NULL), getItems(fetchROOM(codes[6], codes[1], floor1, floor2, floor3, floor4)));


  	/*
		ADMIN Command:
		If username contains '~!' then upon commencment,
		the user will see where all the items are located.
  	*/

	if (strstr(username, "~!") != NULL) {
	  	printf("\n  ORB 1 IS HERE: %s\n", room_description(fetchROOM(codes[1], codes[2], floor1, floor2, floor3, floor4)));
	  	printf("\n  ORB 2 IS HERE: %s\n", room_description(fetchROOM(codes[3], codes[4], floor1, floor2, floor3, floor4)));
	  	printf("\n  ORB 3 IS HERE: %s\n", room_description(fetchROOM(codes[5], codes[0], floor1, floor2, floor3, floor4)));
	  	printf("\n\n\n  SHARD 1 IS HERE: %s\n", room_description(fetchROOM(codes[0], codes[1], floor1, floor2, floor3, floor4)));
	  	printf("\n  SHARD 2 IS HERE: %s\n", room_description(fetchROOM(codes[2], codes[3], floor1, floor2, floor3, floor4)));
	  	printf("\n  SHARD 3 IS HERE: %s\n", room_description(fetchROOM(codes[5], codes[4], floor1, floor2, floor3, floor4)));

	  	printf("\n  TREASURE CHEST IS HERE: %s\n", room_description(fetchROOM(codes[6], codes[1], floor1, floor2, floor3, floor4)));
  	}


  	/*
  		Room Where the Treasure Chest is located
  	*/
  	struct Room * winRoom = fetchROOM(codes[6], codes[1], floor1, floor2, floor3, floor4);


  	/*
		Game "booleans"
  	*/

  	int gameOver = FALSE;		//	game status
  	int foundShard1 = FALSE;	// found shard
  	int foundShard2 = FALSE; 	// found shard
  	int foundShard3 = FALSE;	// found shard
  	int runs = 0;				// # of Cmd's run

  	/*
		Avatar Positioning
  	*/

  	struct Room * floorPosition = floor1;	// their current floor
  	struct Room * roomPosition = north1;	// their current room
  	char * guide;							// tour guide name


	char * cmd = malloc(256);	// allocating memory for input
	if (cmd == NULL)			// memory space check
	    return 1;

  	/*
		Game's Main Operations:
		Where CMD's are executed
  	*/
  	while (gameOver == FALSE) {

  		runs++;	// increasing runs

  		if (runs % 3 == 0) {
			guide = "PETER PARKER";		// tour guide name selector
  		} else if (runs % 4 == 0) {
			guide = "BRUCE BANNER";
  		} else {
  			guide = "TONY STARK";
  		}

  		printf("\n");
  		printf("\n");

		if (runs > 1) {
			printf("   INVENTORY (%i): ",itemsInList(inventory)); 	// displaying
		  	item_display(inventory);								// printing out the avatars inventory
		} 
  		

  		printf("\n\n======================================================================\n");
  		printf("\n THE SECRET SILVER OF SIX FLAGS: \t%s\tGAME ID: #%i\n\n   RUNNING CMD: ",username,gameID);



  		/*
			USER COMMAND INPUT
  		*/

	    fgets(cmd, 256, stdin);		// taking input
	  


  		printf("\n   TOUR GUIDE, %s SAYS: \n\n\t", guide); 		// printing




  		/*
			TAKE COMMAND
  		*/

  		if (strcmp(cmd,"take\n") == 0 || strcmp(cmd,"TAKE\n") == 0) {			// only input 'take'
  			printf("Specify what you want to take. 'take <item>'.\n");			// help msg
  			continue;
  		}

  		if (strstr(cmd, "take ") != NULL || strstr(cmd, "TAKE ") != NULL ) {	// if cmd contains 'take'

  			if (strstr(cmd, "$") != NULL){										// cannot take chest since
  				printf("You need all 3 shards to open the treasure chest!\n");	// it contains '$'
  				continue;
  			}

  			if (itemsInList(getItems(roomPosition)) == 0) {						// no items in room check
  				printf("There are no items here! Are you blind?? :'(\n");
  				continue;
  			}


  			/*
				Getting intended item name:
				ex: "take DOG"
				cmd = "take DOG"
				Goal: char[] with only "DOG"
  			*/

  			int counter = 5;				// getting 5 item in array
  			int length = 0;					// counter variable
  			while (cmd[counter] != '\0') {	// looping through all cmd
  				length++;					// getting length
  				counter++;
  			}
  			length--;						// space for null character later

  			if (length > 36) {				// character length check
  				printf("Too long of an input! Must be less than 36 characters!\n");
  			}

  			char value[length];				// new char[] that will hold item name only

  			int count = 5;						// neglecting 'take' in cmd
  			while (cmd[count] != '\0') {		// looping through all of cmd
  				value[(count-5)]=cmd[count];	// copy char variables
  				count++;
  			}
  			value[length] = '\0';				// adding null character






  			if (count == 6) {	// entering only 'take ' check
  				printf("Specify what you want to take. 'take <item>'.\n");
  			} else {
  				char * takeThis = value;	// char[] turned into pointer
  				printf("Processing a take on: %s\n",takeThis);

  				// Trying to find the item specified
  				struct Item * find = item_take(takeThis, getItems(roomPosition));

  				// Item not found message
  				if (strcmp(item_name(find),"dummy") == 0) {
  					printf("\n\tThe item: '%s', was NOT FOUND in the room.\n",takeThis);
  					printf("\t  Use cmd 'look' to see the available items in a room.\n");
  					continue;
  				}

  				// Item Description
			    printf("\n\tTAKING ITEM: %s\n",item_name(find));
			    printf("\t       DESC: %s\n",item_description(find));

			    item_add(find, inventory); // adding Item avatar to inventory

  			}

  			continue;
		}


		/*
			DROP COMMAND
  		*/
		if (strcmp(cmd,"drop\n") == 0 || strcmp(cmd,"DROP\n") == 0) {			// only input 'drop'
  			printf("Specify what you want to drop. 'drop <item>'.\n");			// help msg
  			continue;
  		}

  		if (strstr(cmd, "drop ") != NULL || strstr(cmd, "DROP ") != NULL ) {	// if cmd contains 'drop'

  			if (itemsInList(inventory) == 0) {									// no items in inventory check
  				printf("There are no items in your inventory to drop!\n");
  				continue;
  			}


			/*
				Getting intended item name:
				ex: "drop CAT"
				cmd = "drop CAT"
				Goal: char[] with only "CAT"
  			*/
  			int counter = 5;				// getting 5 item in array
  			int length = 0;					// counter variable
  			while (cmd[counter] != '\0') {	// looping through all cmd
  				length++;					// getting length
  				counter++;
  			}
  			length--;						// space for null character later

  			if (length > 36) {				// character length check
  				printf("Too long of an input! Must be less than 36 characters!\n");
  			}

  			char value[length];					// new char[] that will hold item name only

  			int count = 5;						// neglecting 'drop' in cmd
  			while (cmd[count] != '\0') {		// looping through all of cmd
  				value[(count-5)]=cmd[count];	// copy char variables
  				count++;
  			}
  			value[length] = '\0';				// adding null character


  			if (count == 6) {	// entering only 'drop ' check
  				printf("Specify what you want to drop. 'drop <item>'.\n");
  			} else {
  				char * takeThis = value;	// char[] turned into pointer
  				printf("Processing a drop on: %s\n",takeThis);
  				
  				// Trying to find the item specified
  				struct Item * find = item_take(takeThis, inventory);

  				// Item not found message
  				if (strcmp(item_name(find),"dummy") == 0) {
  					printf("\n\tThe item: '%s', was NOT FOUND in your inventory.\n",takeThis);
  					printf("\t  Use cmd 'look' to see the available items in your inventory.\n");
  					continue;
  				}

  				// Item Description
			    printf("\n\tDROPPING ITEM: %s\n",item_name(find));
			    printf("\t       DESC: %s\n",item_description(find));

			    item_add(find, getItems(roomPosition)); // adding Item back to room

  			}

  			continue;
		}






		/*
			USE COMMAND
		*/

		if (strcmp(cmd,"use\n") == 0 || strcmp(cmd,"use\n") == 0) {				// only input 'use'
  			printf("Specify what you want to use. 'use <item>'.\n");			// help msg
  			continue;
  		}

		if (strstr(cmd, "use ") != NULL || strstr(cmd, "USE ") != NULL ) {		// contains input 'use'

  			if (itemsInList(inventory) == 0) {									// no items in inventory check
  				printf("There are no items in your inventory to use!\n");
  				continue;
  			}


  			/*
				Getting intended item name:
				ex: "use SHARK"
				cmd = "use SHARK"
				Goal: char[] with only "SHARK"
  			*/

  			int counter = 4;				// getting 4 item in array
  			int length = 0;					// counter variable
  			while (cmd[counter] != '\0') {	// looping through all cmd
  				length++;					// getting length
  				counter++;
  			}
  			length--;						// space for null character later

  			if (length > 36) {				// character length check
  				printf("Too long of an input! Must be less than 36 characters!\n");
  			}

  			char value[length];				// new char[] that will hold item name only

  			int count = 4;						// neglecting 'use' in cmd
  			while (cmd[count] != '\0') {		// looping through all of cmd
  				value[(count-4)]=cmd[count];	// copy char variables
  				count++;
  			}
  			value[length] = '\0';				// adding null character

  			if (count == 5) {	// entering only 'use ' check
  				printf("Specify what you want to use. 'use <item>'.\n");
  			} else {
  				char * takeThis = value;	// char[] turned into pointer
  				printf("\tProcessing a use on: %s\n",takeThis);

  				// Trying to find the item specified
  				struct Item * find = item_take(takeThis, inventory);

  				// Item not found message
  				if (strcmp(item_name(find),"dummy") == 0) {
  					printf("\n\tThe item: '%s', was NOT FOUND in your inventory.\n",takeThis);
  					printf("\t  Use cmd 'look' to see the available items in your inventory.\n");
  					continue;
  				}

  				char * found = item_name(find);

  				// Item Description
			    printf("\n\tUSING ITEM: %s\n",found);
			    printf("\t       DESC: %s\n",item_description(find));

			    
			    /*
					SPECIAL ITEM CONDITIONS AND USES
					BY NAME, FOUND IN INVENTORY
				*/

				// if you in this room, and item has this name, then ....


			    if (winRoom == roomPosition && (strcmp(found,"SHARD 1") == 0 || strcmp(found,"SHARD 2") == 0 || strcmp(found,"SHARD 3") == 0)) { // in room with chest

			    	int s = 0; // shard counter

					if (strcmp(found,"SHARD 1") == 0) {		// used shard 1
	  					if (foundShard1 == FALSE) 
	  						foundShard1 = TRUE;
	  				}

					if (strcmp(found,"SHARD 2") == 0) {		// used shard 2
	  					if (foundShard2 == FALSE) 
	  						foundShard2 = TRUE;
	  				}

					if (strcmp(found,"SHARD 3") == 0) {		// used shard 3
	  					if (foundShard3 == FALSE) 
	  						foundShard3 = TRUE;
	  				}

	  				if (foundShard1 == TRUE) 	// counting shards
	  					s++;
					if (foundShard2 == TRUE)	// counting shards
	  					s++;
					if (foundShard3 == TRUE) 	// counting shards
	  					s++;

				    if (s != 3) {	// Display Shard Amount
				    	printf("\n\tYOU HAVE COLLECTED %i/3 SHARDS!\n", s);
				    	printf("\tYOU ONLY NEED %i MORE TO OPEN THE CHEST!\n", (3-s));
			    	} else {

			    		/*
							3 Shards used in Chest Room
							Game = OVER
			    		*/

			    		gameOver = TRUE;

			    		printf("\n\t... YOU HAVE FOUND AND USED ALL 3 SHARDS TO\n");
			    		printf("\t... OPEN THE CHEST! CONGRATS YOU WON!\n");

			    	}


			    	continue;
			    }


			    if (strcmp(found,"ORB 1") == 0) { // using orb

			    	printf("\n\tTraveling somwhere... ?\n");

			    	// Using fetchROOM to change users room position
			    	
			    	roomPosition = fetchROOM(codes[3], codes[1], floor1, floor2, floor3, floor4);

			    	// Updating their floor position as well

				    if (codes[3] == 1) {
				    	floorPosition = floor1;
					} else if (codes[3] == 2) {
				    	floorPosition = floor2;
					} else if (codes[3] == 3) {
				    	floorPosition = floor3;
					} else if (codes[3] == 4) {
				    	floorPosition = floor4;
					}

			    	continue;
			    }

			    if (strcmp(found,"ORB 2") == 0) { // using orb

			    	printf("\nTraveling somwhere... ?\n");

			    	// Using fetchROOM to change users room position

			    	roomPosition = fetchROOM(codes[4], codes[1], floor1, floor2, floor3, floor4);

			    	// Updating their floor position as well

				    if (codes[4] == 1) {
				    	floorPosition = floor1;
					} else if (codes[4] == 2) {
				    	floorPosition = floor2;
					} else if (codes[4] == 3) {
				    	floorPosition = floor3;
					} else if (codes[4] == 4) {
				    	floorPosition = floor4;
					}

			    	continue;
			    }

			    if (strcmp(found,"ORB 3") == 0) { // using orb

			    	printf("\nTraveling somwhere... ?\n");

			    	// Using fetchROOM to change users room position

			    	roomPosition = fetchROOM(codes[1], codes[1], floor1, floor2, floor3, floor4);

			    	// Updating their floor position as well

				    if (codes[1] == 1) {
				    	floorPosition = floor1;
					} else if (codes[1] == 2) {
				    	floorPosition = floor2;
					} else if (codes[1] == 3) {
				    	floorPosition = floor3;
					} else if (codes[1] == 4) {
				    	floorPosition = floor4;
					}

			    	continue;
			    }




			    // Usage had no effects

			    printf("\n\tRESULT: No effects :(\n");
			    item_add(find, inventory);

  			}

  			continue;
		}



		/*
			Description Command
		*/

		if (strcmp(cmd,"desc\n") == 0 || strcmp(cmd,"DESC\n") == 0 || strcmp(cmd,"d\n") == 0) {
  			printf("Inventory Item Descriptions (%i):   \n\t",itemsInList(inventory));
  			item_displayDESC(inventory); // displays description of items
  			printf("\n");
  			continue;
  		}

  		/*
			Go North Command
  		*/

  		if (strcmp(cmd,"go north\n") == 0 || strcmp(cmd,"go NORTH\n") == 0 || strcmp(cmd,"gn\n") == 0) {
  			char * rName = "north"; // name
  			printf("Traveling to Room:   %s",rName);
  			printf("\n\n\tYour are now in room %s,\n\t   on the floor...   %s",rName,room_description(floorPosition));
  			roomPosition = getNorth(floorPosition);		// updating room position
  			printf("\n");
  			continue;
  		}
  		

  		/*
			Go South Command
  		*/
  		
  		if (strcmp(cmd,"go south\n") == 0 || strcmp(cmd,"go SOUTH\n") == 0 || strcmp(cmd,"gs\n") == 0) {
  			char * rName = "south"; // name
  			printf("Traveling to Room:   %s",rName);
  			printf("\n\n\tYour are now in room %s,\n\t   on the floor...   %s",rName,room_description(floorPosition));
  			roomPosition = getSouth(floorPosition);		// updating room position
  			printf("\n");
  			continue;
  		}
  		

  		/*
			Go West Command
  		*/
  		
  		if (strcmp(cmd,"go west\n") == 0 || strcmp(cmd,"go WEST\n") == 0 || strcmp(cmd,"gw\n") == 0) {
  			char * rName = "west"; // name
  			printf("Traveling to Room:   %s",rName);
  			printf("\n\n\tYour are now in room %s,\n\t   on the floor...   %s",rName,room_description(floorPosition));
  			roomPosition = getWest(floorPosition);		// updating room position
  			printf("\n");
  			continue;
  		}
  		

  		/*
			Go East Command
  		*/
  		
  		if (strcmp(cmd,"go east\n") == 0 || strcmp(cmd,"go east\n") == 0 || strcmp(cmd,"ge\n") == 0) {
  			char * rName = "east"; // name
  			printf("Traveling to Room:   %s",rName);
  			printf("\n\n\tYour are now in room %s,\n\t   on the floor...   %s",rName,room_description(floorPosition));
  			roomPosition = getEast(floorPosition);		// updating room position
  			printf("\n");
  			continue;
  		}



  		/*
			Go Up Command
  		*/

  		if (strcmp(cmd,"go up\n") == 0 || strcmp(cmd,"go UP\n") == 0 || strcmp(cmd,"gu\n") == 0) {
  			
  			if (roomPosition == up1 || roomPosition == up2 || roomPosition == up3 || roomPosition == up4) {	// if in staircase
	  			if (floorPosition == floor4) { // highest floor check
	  				printf("You are on the highest floor. Roof is staff only!\n");
	  				continue;
	  			}

	  			// Going to next floor up

				if (floorPosition == floor3)
	  				floorPosition = floor4;

				if (floorPosition == floor2)
	  				floorPosition = floor3;

	  			if (floorPosition == floor1)
	  				floorPosition = floor2;

	  			char * rName = "up"; // name
	  			printf("Traveling to a new floor...");
	  			printf("\n\n\tYour are now,\n\t   on the floor...   %s",room_description(floorPosition));
	  			roomPosition = getNorth(floorPosition); // updating room position
	  			printf("\n");
  			} else {

  				// Going 'Up' room = Staircase

	  			char * rName = "up"; // name
	  			printf("Traveling to Room:   %s",rName);
	  			printf("\n\n\tYour are now in a staircase,\n\t   on the floor...   %s",room_description(floorPosition));
	  			printf("\n\n\tIf you want to go UP the steps, run the 'go up' cmd again!");
	  			roomPosition = getUp(floorPosition); // updating room position
	  			printf("\n");
  			}


  			continue;
  		}

  		/*
			Go Down Command
  		*/

		if (strcmp(cmd,"go down\n") == 0 || strcmp(cmd,"go DOWN\n") == 0 || strcmp(cmd,"gd\n") == 0) {
	  			
	  			if (roomPosition == down1 || roomPosition == down2 || roomPosition == down3 || roomPosition == down4) {
		  			if (floorPosition == floor1) { // lowest floor check
		  				printf("You are on the lowest floor. Basement is staff only!\n");
		  				continue;
		  			}

		  			// Going to next floor down

					if (floorPosition == floor2)
		  				floorPosition = floor1;

					if (floorPosition == floor3)
		  				floorPosition = floor2;

					if (floorPosition == floor4)
		  				floorPosition = floor3;

		  			

		  			char * rName = "down"; // name
		  			printf("Traveling to a new floor...");
		  			printf("\n\n\tYour are now,\n\t   on the floor...   %s",room_description(floorPosition));
		  			roomPosition = getNorth(floorPosition); // updating floor position
		  			printf("\n");
	  			} else {

	  				// Going 'Down' room = Staircase

		  			char * rName = "down"; // name
		  			printf("Traveling to Room:   %s",rName);
		  			printf("\n\n\tYour are now in a staircase,\n\t   on the floor...   %s",room_description(floorPosition));
		  			printf("\n\n\tIf you want to go DOWN the steps, run the 'go down' cmd again!");
		  			roomPosition = getDown(floorPosition); // updating floor position
		  			printf("\n");
	  			}


	  			continue;
	  		}



	  	/*
			Look Command
	  	*/

  		if (strcmp(cmd,"look\n") == 0 || strcmp(cmd,"LOOK\n") == 0 || strcmp(cmd,"l\n") == 0) {
  			// displaying room information
  			printf("ROOM NAME:   %s", room_description(roomPosition));
  			printf("\n\n\tFLOOR NAME:  %s", room_description(floorPosition));
  			printf("\n\n\tITEMS (%i):   ",itemsInList(getItems(roomPosition)));
  			item_display(getItems(roomPosition)); // displaying items in room
  			printf("\n\t   ** Case Sensitive **");
  			printf("\n");
  			continue;
  		}

  		/*
			Help Command
  		*/

  		if (strcmp(cmd,"help\n") == 0 || strcmp(cmd,"HELP\n") == 0 || strcmp(cmd,"h\n") == 0) {
  			// displaying commands
  			printf("ALL CMDS: take <item>\t- take items from room");
  			printf("\n\t\t  drop <item>\t- drop items from inventory");
  			printf("\n\t\t  use <item>\t- use item from inventory");
  			printf("\n\t\t  look,l\t- look inside room");
  			printf("\n\t\t  quit,q\t- quit the game");
  			printf("\n\t\t  help,h\t- shows commands");
  			printf("\n\t\t  desc,d\t- view description of inventory items");
  			printf("\n\t\t  go (north/south/east/west/up/down) - move cmd");
  			printf("\n\t\t    ** shrt cut -> gn, gs, ge, gw, gu, gd");
  			printf("\n");
  			continue;
  		}

  		/*
			Quit Command
  		*/

  		if (strcmp(cmd,"quit\n") == 0 || strcmp(cmd,"QUIT\n") == 0 || strcmp(cmd,"q\n") == 0) {
  			// quitting
  			printf("C you again.... no pun intended... :(\n\n");
  			gameOver = TRUE; // ending game/loop
  			break;
  		}

  		// Not a command msg
  		printf("That's not a command! You silly goose! ;(\n");
  		printf("\tEnter the command 'help' to see all available commands.\n");


  	}

  	printf("\n");

  	free(cmd);
  	free(username);


/* 
	NOTE:

	items in room are free'd in the room_free method in rooms.c

*/

  	room_free(north1);
  	room_free(south1);
  	room_free(east1);
  	room_free(west1);
  	room_free(up1);
  	room_free(down1);

  	room_free(north2);
  	room_free(south2);
  	room_free(east2);
  	room_free(west2);
  	room_free(up2);
  	room_free(down2);

  	room_free(north3);
  	room_free(south3);
  	room_free(east3);
  	room_free(west3);
  	room_free(up3);
  	room_free(down3);

  	room_free(north4);
  	room_free(south4);
  	room_free(east4);
  	room_free(west4);
  	room_free(up4);
  	room_free(down4);

  	room_free(floor1);
  	room_free(floor2);
	room_free(floor3);
  	room_free(floor4);

	return 0;
}
