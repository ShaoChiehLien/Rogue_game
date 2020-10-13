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
