#include "venus.h"
#include <iostream>

void venus::usePotion(){
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
void venus::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void venus::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

venus::venus(string n)
{
    my_name = n;
    my_health=20;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string venus::getName() const
{
    return my_name;
}
string venus::getDescription() const
{
    return "The venus is both fluffy and friendly.";
}
void venus::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(2);
}
string venus::basicName() const
{
    return "uses a gravitational wave.";
}
void venus::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string venus::defenseName() const
{
    return "Hide";
}
void venus::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(3);
}
string venus::specialName() const
{
    return "uses an overlying gravitational wave.";
}
int venus::getHealth() const
{
    return my_health;
}
void venus::doDamage(int damage)
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
void venus::resetHealth()
{
    my_health=20;
}