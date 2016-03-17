#include "mars.h"
#include <iostream>

void mars::usePotion(){
    defense_mode=false;
    if(potion > 0){
        my_health += 10;
        potion -- ;
        if(my_health > 100) my_health = 100;
        else ;
        cout<<"You drank the potion."<<endl;
    }
    else cout <<"You do not have any potions."<<endl;
}
void mars::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void mars::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

mars::mars(string n)
{
    my_name = n;
    my_health=50;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string mars::getName() const
{
    return my_name;
}
string mars::getDescription() const
{
    return "The mars is both fluffy and friendly.";
}
void mars::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(5);
}
string mars::basicName() const
{
    return "uses the fire attack.";
}
void mars::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string mars::defenseName() const
{
    return "Hide";
}
void mars::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(6);
}
string mars::specialName() const
{
    return "uses the super fire attack.";
}
int mars::getHealth() const
{
    return my_health;
}
void mars::doDamage(int damage)
{
    if(defense_mode)
    {
        //Defense mode cuts damage in half
        my_health=my_health-(damage/2);
    }else
    {
        my_health=my_health-damage;
    }
}
void mars::resetHealth()
{
    my_health=50;
}
