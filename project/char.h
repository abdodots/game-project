#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
private:
    int health;
    int attack;
    int defense;

public:
    Character();

    // Setters
    void setHealth(int h);
    void setAttack(int a);
    void setDefense(int d);

    // Getters
    int getHealth();
    int getAttack();
    int getDefense();

    // Functions
    void Basic_Attack();
    void Special_Power();
    void Display_Stats();
};

#endif