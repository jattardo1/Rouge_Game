#ifndef STUDENTXMLHANDLER_H_
#define STUDENTXMLHANDLER_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "action.hpp"
#include "displayable.hpp"
#include "dungeon.hpp"
#include "ObjectDisplayGrid.hpp"
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/Attributes.hpp>

class badXMLHandler : public xercesc::DefaultHandler{
private:
    int DEBUG = 1;
    std::string CLASSID = "badXMLHandler";
    std::string data ;
    bool bVisible = false;
    bool bposX = false;
    bool bposY = false;
    bool bWidth = false;
    bool bHeight = false;
    bool bActionMessage = false;
    bool bActionIntValue = false;
    bool bActionCharValue = false;
    bool bHp = false;
    bool bHpMoves = false;
    bool bMaxHit = false;
    bool bItemIntValue = false;
    bool bType = false;
    Item latestItem;
    Player latestPlayer;
    Dungeon *currDungeon;

public:
    badXMLHandler();
    void startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes) ;
    void endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName) ;
    void fatalError(const xercesc::SAXParseException&);
    void characters(const XMLCh * const ch, const XMLSize_t length ) ;
};

#endif /* STUDENTXMLHANDLER_H_ */
