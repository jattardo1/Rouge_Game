#include "action.hpp"
#include <string>
#include <iostream>
void Action::setMessage(std::string msg)
{

}

void Action::setIntValue(int v)
{

}

void Action::setCharValue(char c)
{

}

CreatureAction::CreatureAction(Creature owner)
{
    std::cout<<"CreatureAction Object Created"<<std::endl;
}

ItemAction::ItemAction(Item owner){
    std::cout<<"ItemAction Object Created"<<std::endl;
}

BlessCurseOwner::BlessCurseOwner(Item owner): ItemAction::ItemAction(owner){

}

Hallucinate:: Hallucinate(Item owner): ItemAction::ItemAction(owner){

}
