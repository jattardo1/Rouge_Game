#include "scrolly.hpp"
#include <stdio.h>
#include <string>
int rooms = 1;
int handlerRooms = 1;
int startRoom = 0;


int handlerDoorY[1] = {0};
int handlerDoorX[1] = {0};
int handlerDoor2Y[1] = {0};
int handlerDoor2X[1] = {0};



int handlerWidth[1] = {8};
int handlerHeight[1] = {8};
int HandlerstartX[1] = {0};
int HandlerstartY[1] = {0};
int HandlerobjX[1]={0};
int HandlerobjY[1]={0};
int HandlerplayerX = 1;
int HandlerplayerY = 1;
int HandlerHP = 100;
int HandlerHit = 1;
int HandlerswordX[1] = {5};
int HandlerswordY[1] = {2};
int HandlerarmorX[1] = {3};
int HandlerarmorY[1] = {2};
int HandlerarmorX2[1] = {4};
int HandlerarmorY2[1] = {2};
int HandlersnakeX[1] = {0};
int HandlersnakeY[1] = {0};
int HandlerhobX[1] = {0};
int HandlerhobY[1] = {0};
int HandlertrollX[1] = {2};
int HandlertrollY[1] = {2};
int HandlertrollHP[1] = {1};
int HandlersnakeHit[1] = {0};
int HandlersnakeHP[1] = {0};
int HandlerhobHit[1] = {0};
int HandlerhobHP[1] = {0};
int HandlertrollHit[1] = {50};
int pathX[1] = {0};
int pathY[1] = {0};
std::string armorname = "+10 Armor";
std::string armor2name = "+5 Armor";
std::string swordname = "+5 Sword";
std::string objname = "";
std::string Darmorname = "";
std::string Darmor2name = "";
std::string Dswordname = "";
std::string Dobjname= "";
std::string Dobjread= "";
std::string narmorname = "";
int hpmoves = 5;
int movecount = 0;
int Handlerarmor = 0;
int Handlersword = 0;
int armorVal = 10;
int swordVal = 5;
int scrollVal = 0;
char scrollChar = 'a';
char playerac = 'd';
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