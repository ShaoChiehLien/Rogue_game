# Commands

## Move Command 

Help: ‘?’: show the different commands in the info section of the display

Help ‘H’ <command>give more detailed information about the specified command in the info section of
the display.

End game ‘E’ <Y | y>: end the game

# Creatures

We will have 3 kinds of monsters and a player. 
‘T’: Trolls
‘S’: Snakes
‘H’: Hobgoblins
‘@’: Player


Move (left, right, up, down): move to a new location. The move can only occur if the new location is
traversable, i.e., is a dungeon floor or passageway. If the location to be moved to is occupied by another
creature, the other creature is hit but the creature moving does not occupy that location. If the location 
to be moved to is occupied by an item (armor, a sword or a scroll) the creature moves to that location.
A separate command is used to actually pick up the item, and only the player creature pics up items.
After the player moves, the location it leaves should show the dungeon floor or passage, if empty, or the
item that is laying on that spot, if not empty.
As well, the XML file can specify move actions that are performed at each move.
Show or display the inventory ‘I’: show the contents of the pack, printing the name for each item in the
pack. Each item is preceded by an integer 1 … max items in the pack that is used to refer to the item
when removing or dopping items in the pack.
Change, or take off armor ‘c’: armor that is being worn is taken off and placed in the pack. If not armor
is being worn a message should be shown in the info area of the game display.
Drop ‘d’ <integer>: drop item <integer> from the pack. If the <integer> does not refer to an item in the
pack and informational message is printed on the game display in the info area.
Read an item ‘r’ <integer>: the item specified by the integer must be a scroll that is in the pack. It causes
the scroll to perform its actions.
Pick up an item from the dungeon floor ‘p’: pick up the visible item on the dungeon floor location that
the player is standing on. If multiple items are in the location, only the top item is picked up.
Take out a weapon ‘T’ <integer>: take the sword identified by <integer> from the pack. If the identified
item is not a sword, or no such item exists, show a message in the info area of the game display.
Wear item ‘w’ <integer>: take the armor identified by <integer> from the pack and make it the armor
being worn. If the identified item is not armor, or no such item exists, show a message in the info area
of the game display.

The following characters are used to represent items: A weapon (i.e, a sword in our game) is ")", armor
is "]", and a scroll is "?"

The dungeon consists of Rooms and Passages. Rooms consist of walls (which are not traversable and are
represented by an ‘X’) and floors (which are traversable and represented by a ‘.’). Passages consist of
passage floors, which are represented by a ‘#’ and junctions, which is where the passage floor runs into
a room wall, and are represented as a ‘+’. Passage floors and junctions are traversable. Items and
creatures may be placed on room floors, passage floors and passage junctions. They may not be placed
on room walls. 

Move commands, processed by the Player and code needing to count moves.
Move commands are the vi/vim navigation keys.
h: move left 1 space.
l: move right 1 space. Note that this is a lower case el, l, not an upper case i.
k: move up 1 space
j: move down 1 space
Move commands, processed by the Player
i: inventory -- show pack contents
c: take off/change armor
d: drop <item number> item from pack";
p: pick up item under player and put into the pack";
r <item in pack number>: read the scroll which is item number <item in pack number> in pack
t: take out weapon from pack
w: take out the armor which is item number <item number in pack> in the pack and put it on



To compile the code: 
g++ -Wall -g -std=c++11 -I /usr/local/Cellar/xerces-c/3.2.3/include/ -L /usr/local/Cellar/xerces-c/3.2.3/lib/ ./*cpp -o XMLExample -lxerces-c -lcurses


To execute the code:
./XMLExample "name of file"
