#include <iostream>
#include <string>
#include <atomic> 
#include <thread>
#include <sstream>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include "badXMLHandler.hpp"
#include "ObjectDisplayGrid.hpp"
#include "GridChar.hpp"
#include "KeyboardListener.hpp"
#include <exception>
#include "scrolly.hpp"


std::atomic_bool isRunning(true);

int HP = HandlerHP;

void runDisplay(ObjectDisplayGrid* grid) {
    grid->writeLine(HPline, "HP: "+ std::to_string(HP) + "  core: 0");
    grid->writeLine(actionline, "Pack: ");
    grid->writeLine(infoline, "Info: " );
    for(int q = 0; q < rooms; q++){
        int doorX = handlerDoorX[q];
        int doorY = handlerDoorY[q];
        int door2X = handlerDoor2X[q];
        int door2Y = handlerDoor2Y[q];
        int WIDTH = handlerWidth[q];
        int HEIGHT = handlerHeight[q];
        int MESSAGES = 0;
        int objX = HandlerobjX[q];
        int objY = HandlerobjY[q];
        int playerX = HandlerplayerX;
        int playerY = HandlerplayerY;
        int startX = HandlerstartX[q];
        int startY = HandlerstartY[q];
        int swordX = HandlerswordX[q];
        int swordY = HandlerswordY[q];
        int armorX = HandlerarmorX[q];
        int armorY = HandlerarmorY[q];
        int snakeX = HandlersnakeX[q];
        int snakeY = HandlersnakeY[q];
        int hobX = HandlerhobX[q];
        int hobY = HandlerhobY[q];
        int trollX = HandlertrollX[q];
        int trollY = HandlertrollY[q];
        int snakeX2 = HandlersnakeX2[q];
        int snakeY2 = HandlersnakeY2[q];
        int hobX2 = HandlerhobX2[q];
        int hobY2 = HandlerhobY2[q];
        int trollX2 = HandlertrollX2[q];
        int trollY2 = HandlertrollY2[q];
        int armX2 = HandlerarmorX2[q];
        int armY2 = HandlerarmorY2[q];
        for (int i = startX; i < startX + WIDTH; i++) {
            for (int j = startY + 2; j < startY + HEIGHT + 2; j++) {
                char c;
                if (i == startX || j == startY + 2 || i == startX + WIDTH - 1 || j == startY + HEIGHT + 1) {
                    if((i == doorX && j == doorY + 2) || (i == door2X && j == door2Y + 2 )){
                    c = '+';
                }
                else{
                    c = 'X';
                }
                }
                else if(i == startX + objX && j == startY + objY + 2){
                    c = '?';
                }
                else if((i == startX + trollX && j == startY + trollY + 2 )|| (i == startX + trollX2 && j == startY + trollY2 + 2)){
                    c = 'T';
                }
                else if(i == startX + playerX && j == startY + playerY + 2){
                    c = '@';
                }
                else if((i == startX + armorX && j == startY + armorY + 2) || (i == startX + armX2 && j == startY + armY2 + 2)){
                    c = ']';
                }
                else if(i == startX + swordX && j == startY + swordY + 2){
                    c = ')';
                }
                else if((i == startX + snakeX && j == startY + snakeY + 2)|| (i == startX + snakeX2 && j == startY + snakeY2 + 2)){
                    c = 'S';
                }
                else if((i == startX + hobX && j == startY + hobY + 2)|| (i == startX + hobX2 && j == startY + hobY2 + 2)){
                    c = 'H';
                }
                else {
                    c = '.';
                }
                if(i == 0 && j == 2){
                    c = 'X';
                }
                grid->addObjectToDisplay(new GridChar(c), i, j);
            }
        // update the grid
        grid->update();
    
    }
    }
    for(int s = 0; pathX[s] != 0; s++){
        int i = pathX[s];
        int j = pathY[s];
        char c = '#';
        grid->addObjectToDisplay(new GridChar(c), i, j);
        grid->update();
    }
    if(rooms > 2){
        int i = 26;
        int j = 18;
        char c = '+';
        grid->addObjectToDisplay(new GridChar(c), i, j);
        grid->update();
        i = 24;
        j = 18;
        c = '@';
        grid->addObjectToDisplay(new GridChar(c), i, j);
        grid->update();
    }

}
int main(int argc, char* argv[]) {
    std::string fileName;
    try{
        xercesc::XMLPlatformUtils::Initialize();
    }
    catch (const xercesc::XMLException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Error during initialization! :\n";
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return 1;
    }
    switch (argc) {
        case 2:
            fileName = "xmlfiles/" + ((std::string) argv[1]);
            break;
        default:
            std::cout << "C++ Test <xmlfilename>" << std::endl;
    }
    xercesc::SAX2XMLReader* parser = xercesc::XMLReaderFactory::createXMLReader();

    try {
        badXMLHandler* handler = new badXMLHandler();
        parser->setContentHandler(handler);
        parser->setErrorHandler(handler);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
        XMLCh * fileNameXMLEnc = xercesc::XMLString::transcode(fileName.c_str()); //Encode string as UTF-16, but transcode needs casting as const char * (not std::string)
        parser->parse(fileNameXMLEnc);
        xercesc::XMLString::release(&fileNameXMLEnc);
        
        
		delete parser;
		delete handler;
     
    } catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cout << "Exception message is: \n"
                 << message << "\n";
            xercesc::XMLString::release(&message);
            return -1;
    }
    catch (const xercesc::SAXParseException& toCatch) {
        char* message = xercesc::XMLString::transcode(toCatch.getMessage());
        std::cout << "Exception message is: \n"
             << message << "\n";
        xercesc::XMLString::release(&message);
        return -1;
    }
	catch(std::exception& e){
	    std::cout << e.what() << '\n';
	}
	catch(...){
        std::cout << "Unexpected Exception \n" ;
        return -1;
	}
    xercesc::XMLPlatformUtils::Terminate(); //valgrind will say there's memory errors if not included
        ObjectDisplayGrid grid(sizeofX, sizeofY, 0);
    ObjectDisplayGrid* pGrid = &grid;

    // thread to wait for key press
    KeyboardListener listener(pGrid);
    std::thread keyboardThread(&KeyboardListener::run, &listener);

    // thread to update display
    std::thread displayThread(runDisplay, pGrid);
    // wait for the keyboard thread to finish, then notify the display to stop
    keyboardThread.join();
    isRunning = false;

    // wait for the display thread to finish
    displayThread.join();
	return 0;
}



