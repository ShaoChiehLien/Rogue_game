#include <iostream>
#include <string>
#include "Player.hpp"
#include "Creature.hpp"
#include "Item.hpp"
#include "Sword.hpp"

Player::Player(){
    for(int i = 0; i < 10; i++){
        pack.push_back(nullptr);
    }
}

void Player::setWeapon(Item _sword){
    sword = _sword;

}

void Player::setArmor(Item _armor){
    armor = _armor;

}

void Player::addItemintoPack(int _placeToAdd, Item* _item){
    pack.at(_placeToAdd) = _item;
}

Item* Player::dropItemfromPack(int _placeToThrow){
    //std::cout << "hello" << std::endl;
    Item* tempItem = pack.at(_placeToThrow);
    
    if (tempItem == nullptr){
        std::cout << "trying to drop something null" << std::endl;
    }
    pack.at(_placeToThrow) = nullptr;
       // std::cout << "hello" << std::endl;
    
    return tempItem;
}

Item* Player::getItemfromPack(int _placeToThrow){
    //std::cout << "hello" << std::endl;
    Item* tempItem = pack.at(_placeToThrow);
    if (tempItem == nullptr){
        std::cout << "trying to get something null" << std::endl;
    }
    
    return tempItem;
}

std::vector<Item*> Player::getIteminPack(){
    return pack;
}


void Player::setName(std::string _playerName){
    playerName = _playerName;
}

void Player::setID(int _room, int _serial){
    room = _room;
    serial = _serial;
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
