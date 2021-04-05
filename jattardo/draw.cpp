#include "scrolly.hpp"
#include <stdio.h>
int rooms = 4;
int handlerRooms = 4;
int startRoom = 2;


int handlerDoorY[4] = {4, 3, 16, 16};
int handlerDoorX[4] = {3, 15, 17, 26};
int handlerDoor2Y[4] = {2, 2, 13, 16};
int handlerDoor2X[4] = {5, 18, 22, 29};



int handlerWidth[4] = {6, 7, 10, 3};
int handlerHeight[4] = {5, 4, 7, 3};
int HandlerstartX[4] = {0, 12, 17, 29};
int HandlerstartY[4] = {0, 0, 13, 15};
int HandlerobjX[1];
int HandlerobjY[1];
int HandlerplayerX = 7;
int HandlerplayerY = 3;
int HandlerHP = 20;
int HandlerHit = 6;
int HandlerswordX[4] = {0,0,0,0};
int HandlerswordY[4] = {0,0,0,0};
int HandlerarmorX[4] = {0,0,0,0};
int HandlerarmorY[4] = {0,0,0,0};
int HandlersnakeX[4] = {0,2,5,0};
int HandlersnakeY[4] = {0,1,2,0};
int HandlerhobX[4] = {0,0,2,0};
int HandlerhobY[4] = {0,0,3,0};
int HandlertrollX[4] = {2, 4, 5, 0};
int HandlertrollY[4] = {2, 1, 5, 0};
int HandlertrollHP[4] = {7, 7, 7, 0};
int HandlersnakeHit[4] = {0, 1, 1, 0};
int HandlersnakeHP[4] = {0, 3, 3, 0};
int HandlerhobHit[4] = {0, 0, 3, 0};
int HandlerhobHP[4] = {0, 0, 10, 0};
int HandlertrollHit[4] = {5, 5, 5, 0};
int HandlerarmorX2[1] = {0};
int HandlerarmorY2[1] = {0};
std::string armorname = "";
std::string armor2name = "";
std::string swordname = "";
std::string objname = "";
int pathX[] = {6,7,8,9,9,9,9,10,11,12,13,14,15,15,19,20,21,22,22,22,22,22,22,22,22,22,22,22,27,28,3,3,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0};
int pathY[] = {4,4,4,4,5,6,7, 7, 7, 7, 7, 7, 7, 6, 4, 4, 4, 4, 5, 6, 7, 8, 9,10,11,12,13,14,18,18,7,8,9,10,11,12,13,14,15,16,17,18,18,18,18,18,18,18,18,18,18,18,18,18,18, 0};
int hpmoves = 5;
int movecount = 0;
std::string Darmorname = "";
std::string Darmor2name = "";
std::string Dswordname = "";
std::string Dobjname= "";
std::string Dobjread= "";
std::string narmorname = "";
int Handlerarmor = 0;
int Handlersword = 0;
int armorVal = 0;
int swordVal = 0;
int scrollVal = 0;
char scrollChar = 'i';
char playerac = 't';
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