#ifndef DIS_H
#define DIS_H
#include <string>

class Displayable{
private:
    
public:
    Displayable( );
    void setInvisible( );
    void setVisible( );
    void setMaxHit(int maxHit);
    void setHpMove(int hpMoves);
    void setHp(int Hp);
    void setType(char t);
    void setIntValue(int v);
    void SetPosX(int x);
    void setPosY(int y);
    void SetWidth(int x);
    void setHeight(int y);
};

class Structure: public Displayable
{

};

class Creature: public Displayable
{
        public:
        Creature();
        void setHp(int h);
        void setHpMoves(int hpm);
        //void setDeathAction(CreatureAction da);
        //void setHitAcion(ha);
};

class Item: public Displayable
{
        public:
        void setOwner(Creature owner);
};

class Player: public Creature
{
    public:
    Player();
    Player(std::string, int room, int serial);
    void setWeapon(Item sword);
    void setArmor(Item armor);
};

class Monster: public Creature
{
    public:
    Monster();
    void setName(std::string);
    void setID(int room, int serial);

};

class Scroll: public Item
{
    public:
    Scroll(std::string name);
    void setID(int room, int serial);
};

class Armor: public Item
{
    public:
    Armor(std::string name);
    void setName(std::string);
    void setID(int room, int serial);
};

class Sword: public Item
{
    public:
    Sword(std::string name);
    void setID(int room, int serial);
};


class Magic: public Displayable
{
    
};

class Room: public Structure{
    public:
        Room(std::string, int);
        void setId(int room);
        void setCreature(Creature Monster);
};

class Passage: public Structure{
    public:
        Passage();
        void setName(std::string);
        void setID(int room1, int room2);
};

#endif