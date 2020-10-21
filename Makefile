g++ -Wall -g -std=c++11 -I /usr/local/Cellar/xerces-c/3.2.3/include/ -L /usr/local/Cellar/xerces-c/3.2.3/lib/ ./*cpp -o XMLExample -lxerces-c
./XMLExample badScroll.xml

g++ -std=c++11 *.cpp