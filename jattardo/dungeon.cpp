#include "dungeon.hpp"
#include "scrolly.hpp"
#include <string>
#include <iostream>
Dungeon::Dungeon(std::string name, int width, int topHeight, int gameHeight, int bottomHeight)
{
    int dunwidth = width;
    int dunheight = gameHeight;
    int topheight = topHeight;
    int botheight = bottomHeight;
    std::cout<<"Dungeon Object Created"<<std::endl;
    std::cout<<"name: " + name + " width: " + std::to_string(width) +" topHeight: " + std::to_string(topHeight) +" gameHeight: " + std::to_string(gameHeight) +" bottomHeight: " + std::to_string(bottomHeight)<<std::endl;
}

void Dungeon::getDungeon(std::string name, int width, int gameHeight){

}

void getDungeon(std::string name, int width, int gameHeight){

}

void addRoom(Room){

    
}
void addCreature(Creature){

    
}
    
void addPassage(Passage passage){

}

void addItem(Item){

}
