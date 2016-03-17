#include "mercucy.h"
#include <iostream>

void mercucy::usePotion(){
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
void mercucy::useFireBall(enemy * enemy){
    defense_mode=false;
    if(fireball > 0){
        enemy->doDamage(15);
        fireball --;
        cout << "Fireball Attack Successful."<<endl;
    }
    else cout << "You do not have any fireballs."<<endl;
}
void mercucy::printState(){
    cout<<my_name<<":"<<my_health<<"/100 health"<<endl;
    cout<<"remaining "<< fireball <<" Fireballs, "<<potion <<" Potions"<<endl;
}

mercucy::mercucy(string n)
{
    my_name = n;
    my_health=40;
    defense_mode=false;
    fireball = 10;
    potion = 6;
}

string mercucy::getName() const
{
    return my_name;
}
string mercucy::getDescription() const
{
    return "The mercucy is both fluffy and friendly.";
}
void mercucy::basicAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(3);
}
string mercucy::basicName() const
{
    return "uses a light wave.";
}
void mercucy::defenseAttack(enemy * enemy)
{
    defense_mode=true;
}
string mercucy::defenseName() const
{
    return "Hide";
}
void mercucy::specialAttack(enemy * enemy)
{
    defense_mode=false;//Can't defend and attack
    enemy->doDamage(5);
}
string mercucy::specialName() const
{
    return "uses a overlying light wave.";
}
int mercucy::getHealth() const
{
    return my_health;
}
void mercucy::doDamage(int damage)
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
void mercucy::resetHealth()
{
    my_health=40;
}
