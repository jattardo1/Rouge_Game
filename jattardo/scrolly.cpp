#include "scrolly.hpp"
#include <stdio.h>
int rooms = 1;
int startRoom = 0;
int handlerDoorY[1] = {0};
int handlerDoorX[1] = {0};
int handlerDoor2Y[1] = {0};
int handlerDoor2X[1] = {0};
int handlerWidth[1] = {6};
int handlerHeight[1] = {5};
int HandlerobjX[1] = {3};
int HandlerobjY[1] = {3};
int HandlerplayerX = 1;
int HandlerplayerY = 2;
int HandlerstartX[1] = {0};
int HandlerstartY[1] = {0};
int HandlerHP = 20;
int HandlerHit = 6;
int HandlerswordX[1] = {} ;
int HandlerswordY[1] = {} ;
int HandlerarmorX[1] = {} ;
int HandlerarmorY[1] = {} ;
int HandlersnakeX[1] = {0} ;
int HandlersnakeY[1] = {0} ;
int HandlerhobX[1] = {0} ;
int HandlerhobY[1] = {0} ;
int HandlertrollX[1] = {0} ;
int HandlertrollY[1] = {0} ;
int HandlerhobHit[1] = {0};
int HandlersnakeHit[1] = {0};
int HandlertrollHit[1] = {0};
int HandlertrollHP[1] = {0};
int HandlerhobHP[1] = {0};
int HandlersnakeHP[1] = {0};
int HandlerarmorX2[1] = {0};
int HandlerarmorY2[1] = {0};
int pathY[] = {0} ;
int pathX[] = {0} ;
std::string armorname = "+5 Armor";
std::string armor2name = "";
std::string swordname = "+10 Sword";
std::string objname= "BlessArmor";
std::string Darmorname = "+5 Armor";
std::string Darmor2name = "";
std::string Dswordname = "+10 Sword";
std::string Dobjname= "";
std::string Dobjread= "You have picked up a scroll of weakened armor";
std::string narmorname = "+0 Armor";
int hpmoves = 5;
int movecount = 0;
int Handlerarmor = 0;
int Handlersword = 0;
int armorVal = 5;
int swordVal = 10;
int scrollVal = -5;
char scrollChar = 'a';
char playerac = '@';
int HPline = -40;
int infoline = -1;
int actionline =-3;
int sizeofX = 80;
int sizeofY = 40;

int HandlersnakeX2[1] = {0} ;
int HandlersnakeY2[1] = {0} ;
int HandlerhobX2[1] = {0} ;
int HandlerhobY2[1] = {0} ;
int HandlertrollX2[1] = {0} ;
int HandlertrollY2[1] = {0} ;
