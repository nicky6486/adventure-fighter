#include "saturn.h"
#include <iostream>

void saturn::usePotion(){
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
void saturn::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void saturn::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

saturn::saturn(string n)
{
    my_name = n;
    my_health=60;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string saturn::getName() const
{
    return my_name;
}
string saturn::getDescription() const
{
    return "The saturn is both fluffy and friendly.";
}
void saturn::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(10);
}
string saturn::basicName() const
{
    return "uses the hurricane attack.";
}
void saturn::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string saturn::defenseName() const
{
    return "Hide";
}
void saturn::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(12);
}
string saturn::specialName() const
{
    return "uses the storm attack.";
}
int saturn::getHealth() const
{
    return my_health;
}
void saturn::doDamage(int damage)
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
void saturn::resetHealth()
{
    my_health=60;
}
