#ifndef ACTION_H
#define ACTION_H

#include <string>
#include "displayable.hpp"

class Action : public Creature, public Item{
    public:
        void setMessage(std::string msg);
        void setIntValue(int v);
        void setCharValue(char c);
};

class CreatureAction: public Action{
    public:
    CreatureAction(Creature owner);
};

class ItemAction: public Creature
{
    public:
    ItemAction(Item owner);
};

class BlessCurseOwner: public ItemAction{
    BlessCurseOwner(Item owner);
};

class Hallucinate: public ItemAction{
    Hallucinate(Item owner);

};

class Remove: public CreatureAction
{
    Remove(std::string name, Creature owner);
};

class YouWin: public CreatureAction
{
    YouWin(std::string name, Creature owner);
};

class UpdateDisplay: public CreatureAction
{
    UpdateDisplay(std::string name, Creature owner);
};

class Teleport: public CreatureAction
{
    Teleport(std::string name, Creature owner);
};

class EndGame: public CreatureAction
{
    EndGame(std::string name, Creature owner);
};

class ChangeDisplayedType: public CreatureAction
{
    ChangeDisplayedType(std::string name, Creature owner);
};

class DropPack: public CreatureAction
{
    DropPack(std::string name, Creature owner);
};

#endif