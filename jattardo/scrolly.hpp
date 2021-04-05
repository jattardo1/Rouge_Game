#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H
#include <string>

// This is a declaration of your variable, which tells the linker this value
// is found elsewhere.  Anyone who wishes to use it must include global.h,
// either directly or indirectly.
extern int dunwidth;
extern int dunheight;
extern int topheight;
extern int botheight;
extern int rooms;
extern int handlerDoorY[];
extern int handlerDoorX[];
extern int handlerDoor2Y[];
extern int handlerDoor2X[];
extern int handlerWidth[];
extern int handlerHeight[];
extern int HandlerobjX[];
extern int HandlerobjY[];
extern int HandlerplayerX;
extern int HandlerplayerY;
extern int HandlerstartX[];
extern int HandlerstartY[];
extern int HandlerHP;
extern int HandlerHit;
extern int HandlerswordX[];
extern int HandlerswordY[];
extern int HandlerarmorX[];
extern int HandlerarmorY[];
extern int HandlerarmorX2[];
extern int HandlerarmorY2[];
extern int HandlersnakeX[];
extern int HandlersnakeY[];
extern int HandlerhobX[];
extern int HandlerhobY[];
extern int HandlertrollX[];
extern int HandlertrollY[];
extern int startRoom;
extern int HandlertrollHP[];
extern int HandlersnakeHP[];
extern int HandlerhobHP[];
extern int HandlertrollHit[];
extern int HandlersnakeHit[];
extern int HandlerhobHit[];
extern int pathX[];
extern int pathY[];
extern std::string armorname;
extern std::string narmorname;
extern std::string armor2name;
extern std::string swordname;
extern std::string objname;
extern std::string Darmorname;
extern std::string Darmor2name;
extern std::string Dswordname;
extern std::string Dobjname;
extern std::string Dobjread;
extern int hpmoves;
extern int movecount;
extern int Handlerarmor;
extern int Handlersword;
extern int armorVal;
extern int swordVal;
extern char scrollChar;
extern int scrollVal;
extern char playerac;
extern int HPline;
extern int infoline;
extern int actionline;
extern int sizeofX;
extern int sizeofY;
extern int HandlersnakeX2[];
extern int HandlersnakeY2[];
extern int HandlerhobX2[];
extern int HandlerhobY2[];
extern int HandlertrollX2[];
extern int HandlertrollY2[];
extern int trip;

#endif