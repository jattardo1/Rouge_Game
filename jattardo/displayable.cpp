#include "displayable.hpp"
#include <string>
#include <iostream>

Displayable::Displayable( ){

}

void Displayable::setInvisible( )
{

}

void Displayable::setVisible( )
{

}

void Displayable::setMaxHit(int maxHit)
{

}

void Displayable::setHpMove(int hpMoves)
{

}

void Displayable::setHp(int Hp)
{

}

void Displayable::setType(char t)
{

}

void Displayable::setIntValue(int v)
{

}

void Displayable::SetPosX(int x)
{

}

void Displayable::setPosY(int y)
{

}

void Displayable::SetWidth(int x)
{

}

void Displayable::setHeight(int y)
{

}

Room::Room(std::string room, int roomnum)
{
    std::cout<<"Room Created"<<std::endl;
    std::cout<<"Room: " + room <<std::endl;
    
}

void Room::setId(int room)
{

}

void Room::setCreature(Creature Monster)
{

}

Passage::Passage(){
    std::cout<<"Passage Object Created"<<std::endl;
}

void Passage::setName(std::string)
{
}

void Passage::setID(int room1, int room2)
{
    std::cout<<"Room1: " + std::to_string(room1) + " to room2: " + std::to_string(room2)<<std::endl;
}

Creature::Creature(){

}

void Creature::setHp(int h){

}

void Creature::setHpMoves(int hpm){

}

//void Creature::setDeathAction(CreatureAction da){

//}

//void Creature::setHitAcion(ha){

//}
Player::Player()
{
 
}
Player::Player(std::string name, int room, int serial)
{
    std::cout<<"Player Object Created"<<std::endl;
    std::cout<<"Name: "+ name<<std::endl;
    std::cout<<"Room: "+ std::to_string(room)<<std::endl;
    std::cout<<"Serial: "+ std::to_string(serial)<<std::endl;
}

void Player::setWeapon(Item sword){

}

void Player::setArmor(Item armor)
{

}

Monster::Monster(){

}

void Monster::setName(std::string name)
{
    std::cout<<"Monster Object Created"<<std::endl;
    std::cout<<"Name: "+ name<<std::endl;
}

void Monster::setID(int room, int serial)
{
    std::cout<<"Room: " + std::to_string(room) + "serial: " + std::to_string(serial)<<std::endl;
}

void Item::setOwner(Creature owner){

}

Scroll::Scroll(std::string name){
    std::cout<<"Scroll Object Created"<<std::endl;
    std::cout<<"Name: "+ name<<std::endl;
}

void Scroll::setID(int room, int serial){
std::cout<<"Room: " + std::to_string(room) + "serial: " + std::to_string(serial)<<std::endl;
}

Armor::Armor(std::string name){
    std::cout<<"Armor Object Created"<<std::endl;
    std::cout<<"Name: "+ name<<std::endl;
}

void Armor::setID(int room, int serial){
    std::cout<<"Room: " + std::to_string(room) + "serial: " + std::to_string(serial)<<std::endl;
}

void Armor::setName(std::string)
{

}

Sword::Sword(std::string name){

}

void Sword::setID(int room, int serial){

}
