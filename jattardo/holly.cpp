#include "scrolly.hpp"
#include <stdio.h>
int rooms = 1;
int startRoom = 0;
int handlerDoorY[1] = {0};
int handlerDoorX[1] = {0};
int handlerDoor2Y[1] = {0};
int handlerDoor2X[1] = {0};
int handlerWidth[1] = {8};
int handlerHeight[1] = {5};
int HandlerobjX[1] = {1};
int HandlerobjY[1] = {3};
int HandlerplayerX = 2;
int HandlerplayerY = 3;
int HandlerstartX[1] = {0};
int HandlerstartY[1] = {0};
int HandlerHP = 1;
int HandlerHit = 6;
int HandlerswordX[1] = {} ;
int HandlerswordY[1] = {} ;
int HandlerarmorX[1] = {} ;
int HandlerarmorY[1] = {} ;
int HandlersnakeX[1] = {3} ;
int HandlersnakeY[1] = {1} ;
int HandlerhobX[1] = {2} ;
int HandlerhobY[1] = {1} ;
int HandlertrollX[1] = {1} ;
int HandlertrollY[1] = {1} ;
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
std::string armorname = "";
std::string armor2name = "";
std::string swordname = "";
std::string objname= "Hallucinate";
std::string Darmorname = "";
std::string Darmor2name = "";
std::string Dswordname = "";
std::string Dobjname= "";
std::string Dobjread= "You have picked up a scroll of hallucination!";
std::string narmorname = "";
int hpmoves = 5;
int movecount = 0;
int Handlerarmor = 0;
int Handlersword = 0;
int armorVal = 0;
int swordVal = 0;
int scrollVal = 0;
char scrollChar = 'h';
char playerac = 'h';
int HPline = -40;
int infoline = -1;
int actionline =-3;
int sizeofX = 80;
int sizeofY = 40;
int HandlersnakeX2[1] = {6} ;
int HandlersnakeY2[1] = {3} ;
int HandlerhobX2[1] = {5} ;
int HandlerhobY2[1] = {3} ;
int HandlertrollX2[1] = {4} ;
int HandlertrollY2[1] = {3} ;