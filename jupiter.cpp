#include "jupiter.h"
#include <iostream>

void jupiter::usePotion(){
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
void jupiter::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void jupiter::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

jupiter::jupiter(string n)
{
    my_name = n;
    my_health=30;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string jupiter::getName() const
{
    return my_name;
}
string jupiter::getDescription() const
{
    return "The jupiter is both fluffy and friendly.";
}
void jupiter::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(2);
}
string jupiter::basicName() const
{
    return "shoots an arrow.";
}
void jupiter::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string jupiter::defenseName() const
{
    return "Hide";
}
void jupiter::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(4);
}
string jupiter::specialName() const
{
    return "shoots double arrows.";
}
int jupiter::getHealth() const
{
    return my_health;
}
void jupiter::doDamage(int damage)
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
void jupiter::resetHealth()
{
    my_health=20;
}
