# Commands

Help: ‘?’: show the different commands in the info section of the display

Help ‘H’ <command>give more detailed information about the specified command in the info section of
the display.

End game ‘E’ <Y | y>: end the game

### Basic Command

Move commands are the vi/vim navigation keys.

h: move left 1 space.

l: move right 1 space. Note that this is a lower case el, l, not an upper case i.

k: move up 1 space

j: move down 1 space

### Move commands, processed by the Player

i: inventory -- show pack contents

c: take off/change armor

d: drop <item number> item from pack"
  
p: pick up item under player and put into the pack"

r <item in pack number>: read the scroll which is item number <item in pack number> in pack
  
t: take out weapon from pack

w: take out the armor which is item number <item number in pack> in the pack and put it on

## Representing Keys of the Characters

### Creatures

We will have 3 kinds of monsters and a player. 

‘T’: Trolls

‘S’: Snakes

‘H’: Hobgoblins

‘@’: Player

### Items

")": A weapon (i.e, a sword in our game)

"]": An armor

"?": A scroll

### Dungeon

The dungeon consists of Rooms and Passages. Rooms consist of 

‘X’: walls (which are not traversable) 

‘.’: Floors (which are traversabl)

‘#’: Passages consist of passage floors

‘+’: Passages junctions, which is where the passage floor runs into a room wall

## Run the Program

To compile the code: 
g++ -Wall -g -std=c++11 -I /usr/local/Cellar/xerces-c/3.2.3/include/ -L /usr/local/Cellar/xerces-c/3.2.3/lib/ ./*cpp -o XMLExample -lxerces-c -lcurses

To execute the code:
./XMLExample "name of file"
