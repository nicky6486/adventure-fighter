#include "hero.h"
#include <iostream>


void hero::usePotion(){
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
void hero::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void hero::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

hero::hero(string n)
{
    my_name = n;
    my_health=100;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string hero::getName() const
{
    return my_name;
}
string hero::getDescription() const
{
    return "The hero is both fluffy and friendly.";
}
void hero::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(5);
}
string hero::basicName() const
{
    return "Sword Flash Attack Successful.";
}
void hero::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string hero::defenseName() const
{
    return "Hide";
}
void hero::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(10);
}
string hero::specialName() const
{
    return "Double Sword Flash Attack Successful.";
}
int hero::getHealth() const
{
    return my_health;
}
void hero::doDamage(int damage)
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
void hero::resetHealth()
{
    my_health=100;
}


