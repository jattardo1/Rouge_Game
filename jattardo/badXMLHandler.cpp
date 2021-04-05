#include "badXMLHandler.hpp"

int case_insensitive_match(std::string s1, std::string s2) {
    //convert s1 and s2 into lower case strings
    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower); //std overloads tolower, ::tolower is the definition in the global namespace
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    if(s1.compare(s2) == 0)
        return 1;
    return 0;
}

inline std::string boolToString(bool booleanValue){
    return booleanValue ? "true": "false";
}

badXMLHandler::badXMLHandler(){

}


std::string xmlChToString(const XMLCh* xmlChName, int length = -1){
    //Xerces Parses file into XMLCh* string. So use Transcode to allocate a char* buffer
    char * chStarName = xercesc::XMLString::transcode(xmlChName); 
    if(length == -1){
        std::string StrName(chStarName);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }
    else{
        std::string StrName(chStarName,0,length);
        xercesc::XMLString::release(&chStarName);
        return StrName;
    }

}

const XMLCh* getXMLChAttributeFromString(const xercesc::Attributes& attributes, const char * strGet){
    XMLCh * xmlChGet = xercesc::XMLString::transcode(strGet);
    const XMLCh * xmlChAttr = attributes.getValue(xmlChGet);
    xercesc::XMLString::release((&xmlChGet));
    return xmlChAttr;
}


void badXMLHandler::startElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName, const xercesc::Attributes& attributes){

        char * qNameStr = xercesc::XMLString::transcode(qName);
        if (DEBUG > 1) {
            std::cout << CLASSID << ".startElement qName: " << qNameStr << std::endl;
        }
        if (case_insensitive_match(qNameStr,"Dungeon")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int width = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"width"))); 
            int topHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"topHeight"))); 
            int gameHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"gameHeight"))); 
            int bottomHeight = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"bottomHeight"))); 
            Dungeon dungeon = Dungeon(name, width, topHeight, gameHeight, bottomHeight);
            currDungeon = &dungeon; 
        }else if (case_insensitive_match(qNameStr,"Room")) {
			std::string room= xmlChToString(getXMLChAttributeFromString(attributes,"room"));
            int roomnum= std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room")));
            Room roomy = Room(room, roomnum);
        } 
        else if (case_insensitive_match(qNameStr,"Rooms")) {
        }
        else if (case_insensitive_match(qNameStr,"Passages")) {
        }
        else if (case_insensitive_match(qNameStr,"Scroll")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));
            Scroll scroll = Scroll(name);
            scroll.setID(room, serial);
            latestItem = (Item) scroll;
            }
            else if (case_insensitive_match(qNameStr,"ItemAction")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string room = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
            ItemAction itemaction = ItemAction(latestItem);
            }
            else if (case_insensitive_match(qNameStr,"CreatureAction")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            std::string type = xmlChToString(getXMLChAttributeFromString(attributes,"type"));
            CreatureAction creatureaction = CreatureAction(latestPlayer);
            }
            else if (case_insensitive_match(qNameStr,"Player")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial"))); 
            Player player = Player(name, room, serial);
            latestPlayer = (Player) player;

            }
            else if (case_insensitive_match(qNameStr,"Sword")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));
            Sword sword = Sword(name);
            sword.setID(room, serial);

            }
            else if (case_insensitive_match(qNameStr,"Armor")) {
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));                 
            Armor armor = Armor(name);
            armor.setID(room, serial);
            }
            else if (case_insensitive_match(qNameStr,"Monster")) {   
            std::string name = xmlChToString(getXMLChAttributeFromString(attributes,"name"));
            int room = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room"))); 
            int serial = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"serial")));                 
            Monster mon = Monster();
            mon.setName(name);
            mon.setID(room, serial);              
            }
            else if (case_insensitive_match(qNameStr,"Passage")) {   
            int room1 = std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room1"))); 
            int room2= std::stoi(xmlChToString(getXMLChAttributeFromString(attributes,"room2")));                 
            Passage pass = Passage();
            pass.setID(room1, room2);              
            }
         else if (case_insensitive_match(qNameStr,"ItemIntValue")) {
             bItemIntValue = true;                 
        }
         else if (case_insensitive_match(qNameStr,"type")) {  
             bType = true;               
        }
         else if (case_insensitive_match(qNameStr,"visible")) {
            bVisible = true;
        } else if (case_insensitive_match(qNameStr,"posX")) {
            bposX = true;
        } else if (case_insensitive_match(qNameStr,"posY")) {
            bposY = true;
        } else if (case_insensitive_match(qNameStr,"width")) {
            bWidth = true;
        } else if (case_insensitive_match(qNameStr,"height")) {
            bHeight = true;
        } else if (case_insensitive_match(qNameStr,"actionMessage")) {
            bActionMessage = true;
        } else if (case_insensitive_match(qNameStr,"actionIntValue")) {
            bActionIntValue = true;
        } else if (case_insensitive_match(qNameStr,"actionCharValue")) {
            bActionCharValue = true;
        } else if (case_insensitive_match(qNameStr,"hp")) {
            bHp = true;
        } else if (case_insensitive_match(qNameStr,"hpMoves")) {
            bHpMoves = true;
        } else if (case_insensitive_match(qNameStr,"maxhit")) {
            bMaxHit = true;
        } else {
            std::cout <<"Unknown qname: " << qNameStr << std::endl;
        }
        xercesc::XMLString::release(&qNameStr);
}

void badXMLHandler::endElement(const XMLCh* uri, const XMLCh* localName, const XMLCh* qName)  {


}

void badXMLHandler::characters(const XMLCh * const ch, const XMLSize_t length) {
        data = xmlChToString(ch,(int)length) ;   
        if (DEBUG > 1) {
			std::cout << CLASSID + ".characters: " << data << std::endl;
            std::cout.flush();
        }
}

void badXMLHandler::fatalError(const xercesc::SAXParseException& exception)
{
    char* message = xercesc::XMLString::transcode(exception.getMessage());
    std::cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << std::endl;
    xercesc::XMLString::release(&message);
}
