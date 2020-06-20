# How To Use
Run "./adventure"

Enter a username to play with and follow the directions.

Enter command 'help' or 'h' to see all CMDS, and 'look' or 'l' to see the 
room name, floor name, items in the room, and the items in  your inventory.

take <item>   - take items from room
drop <item>   - drop items from inventory
use <item>    - use item from inventory
look,l        - look inside room
quit,q        - quit the game
help,h        - shows commands
desc,d        - view description of inventory items
go (north/south/east/west/up/down) - move cmd
** shrt cut -> gn, gs, ge, gw, gu, gd

# How It Works


## THE SECRET SILVER OF SIX FLAGS
A Mini Adventure Game exploring areas of Six Flags in search for treasure!

The game has 28 different locations to explore. Each location may or may not contain items. 
This is done through the item_add method in items.c. The default item list are specified 
when initializing the locations. You can see the area you're in with the command look 
and you can see the description of the items with the command desc. You can move through each 
room with 'go *direction*'. You can pickup items with the command 'take *item*'. You can use 
items with 'use *item*'. Using the item ORB's in my game will alter the state of the room you're 
in and randomly teleport you to another location. You can also use 'drop *item*' to drop items 
back into the room/location. You can win the game by using all 3 shards in the room with the 
Treasure chest item.

The game will recognize all occurences of inproper inputs and responded with a help message
like 'wrong command' or specify what was needed to have a succesful input.

I also used short-cut commands that can be viewed with command "help" or "h". 
But the regular commands work as well. Just more user friendly.
