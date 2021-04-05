#ifndef DUN_H
#define DUN_H

#include <string>
#include "displayable.hpp"

class Dungeon{
private:

public:
    Dungeon(std::string name, int width, int topHeight, int gameHeight, int bottomHeight);
    void getDungeon(std::string name, int width, int gameHeight);
    void addRoom(Room);
    void addCreature(Creature);
    void addPassage(Passage passage);
    void addItem(Item);

};

#endif