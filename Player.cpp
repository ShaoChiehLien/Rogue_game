#include <iostream>
#include <string>
#include "Player.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"

void Player::setWeapon(Item _sword){
    sword = _sword;
  //  std::cout << "setWeapon: " << sword << std::endl;
    std::cout<< "sword" << sword << std::endl;

}

void Player::setArmor(Item _armor){
    armor = _armor;
  //  std::cout << "setArmor: " << armor << std::endl;
    std::cout<< "armor" << armor << std::endl;
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

std::string Player::toString(){
    std::string str;

    str = "Player: " + playerName + " room: " + std::to_string(room) + " serial: " +  std::to_string(serial) + "\n";
    //Print all Info, same as all print in .cpp classes
    str += "   Maxhit: " + std::to_string(maxHit) + "\n";
    str += "   Hpmoves: " + std::to_string(hpMoves) + "\n";
    str += "   Hp: " + std::to_string(Hp) + "\n";
    //str += "   Type: " + t + "\n";
    //str += "   ActionIntValue: " + boolToString(bActionIntValue) + "\n";
    //str += "   actionCharValue: " + boolToString(bActionCharValue) + "\n";
    //str += "   ActionMessage: " + boolToString(bActionMessage) + "\n";
    str += "   Posx: " + std::to_string(x) + "\n";
    str += "   Posy: " + std::to_string(y) + "\n";
    str += "   Width: " + std::to_string(width) + "\n";
    str += "   Height: " + std::to_string(height) + "\n";
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
