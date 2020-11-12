#include <iostream>
#include <string>
#include "Player.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"

void Player::setWeapon(Item _sword){
    sword = _sword;
  //  std::cout << "setWeapon: " << sword << std::endl;
    //std::cout<< "sword" << sword << std::endl;

}

void Player::setArmor(Item _armor){
    armor = _armor;
  //  std::cout << "setArmor: " << armor << std::endl;
    //std::cout<< "armor" << armor << std::endl;
}

void Player::setName(std::string _playerName){
    playerName = _playerName;
    std::cout << "Player::setName :   " << playerName << std::endl;
}

void Player::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
    std::cout << "Player::setID  room: " << room << "serial:  "<< serial << std::endl;
}

int Player::getRoomID(){
    return room;
}

std::string Player::toString(){
    std::string str;

    str = "   Player: " + playerName + " room: " + std::to_string(room) + " serial: " +  std::to_string(serial) + "\n";
    //Print all Info, same as all print in .cpp classes    
    str += "   Visible: " + std::to_string(visible) + "\n";
    str += "   Posx: \n";
    for (int posx : posX) {
        str += "   ";
        str += std::to_string(posx) + "\n";
    }
    str += "   Posy: \n";
    for (int posy : posY) {
        str += "   ";
        str += std::to_string(posy) + "\n";
    }
    str += "   ItemIntValue: " + std::to_string(v) + "\n";
    std::string type_string{t};
    str += "   Type: " + type_string + "\n";
    str += "   Hp: " + std::to_string(Hp) + "\n";
    str += "   Hpmoves: " + std::to_string(hpMoves) + "\n";
    str += "   Maxhit: " + std::to_string(maxHit) + "\n";
    /* Not useful, but could still be accessed
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
    */
    //End of print all Info, same as all print in .cpp classes
    
    //COULDN'T PRINT OUT CREATURE!!!!!
    return str;
}
/*
std::string Student::toString( ) {
    std::string str = "Student: \n";
    str += "   name: "+name + "\n";
    str += "   numActivities "+std::to_string(numActivities) + "\n";
    for (Activity* activity: activities) {
        str += activity->toString( ) + "\n";
    }
    return str;
}   
*/
