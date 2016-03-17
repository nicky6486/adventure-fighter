#include <iostream>
#include <string>
#include <stdlib.h> //This is where random numbers live
#include <time.h> //To set the random number generator
//#include "enemy.h"
#include "venus.h"
#include "jupiter.h"
#include "mercucy.h"
#include "mars.h"
#include "saturn.h"
#include "hero.h"
#include <vector>


enemy* enemy_battle(enemy* m1, enemy* m2);
void print_results(enemy* attacker, enemy* defender, string attack,int hchange);

int main()
{
    cout<<"Welcome to Adventure Battle!"<<endl;
    cout<<"What is the name of your hero?"<<endl;
    string hero_name;
    cin>>hero_name;
	enemy* h = new hero( hero_name );
	enemy* m0 = new venus("Venus");
    enemy* m1 = new jupiter("Jupiter");
    enemy* m2 = new mercucy("Mercucy");
    enemy* m3 = new mars("Mars");
    enemy* m4 = new saturn("Saturn");

    
    enemy* winner = enemy_battle(h,m0);
    if (winner != h) cout<< "Hero is defeated."<<endl;
    else { cout<<"Enemy is defeated."<<endl;
        winner = enemy_battle(h,m1);}
    if (winner != h) cout<< "Hero is defeated."<<endl;
    else { cout<<"Enemy is defeated."<<endl;
        winner = enemy_battle(h,m2);}

    if (winner != h) cout<< "Hero is defeated."<<endl;
    else { cout<<"Enemy is defeated."<<endl;
        winner = enemy_battle(h,m3);}

    if (winner != h) cout<< "Hero is defeated."<<endl;
    else { cout<<"Enemy is defeated."<<endl;
        winner = enemy_battle(h,m4);}

    if (winner != h) cout<< "Hero is defeated."<<endl;
    else { cout<<"Enemy is defeated."<<endl;
        cout << "Hero has defeated all the enemys!";}
}

//enemy Battle Happens below here
//DO NOT make any changes below this line
//---------------------------------------------------

//This function has two enemys fight
//it returns the winner
//or NULL on a tie
enemy* enemy_battle(enemy* m1, enemy* m2)
{
    cout << "You have encountered the enemy "<<m2->getName()<<endl;
    //Loop until either 1 is unconscious
    while(m1->getHealth() > 0 && m2->getHealth() > 0 )
    {   // hero's turn
        string command;
        cout<<"Enter Command: sword shield fireball potion exit"<<endl;
        cin>> command;
        if(command == "shield"){
            m1->defenseAttack(m2);
            cout << m1->defenseName()<<endl;
        }
        else if (command == "fireball"){
            m1->useFireBall(m2);
        }
        else if (command == "potion"){
            m1->usePotion();
        }
        else if (command =="sword")
        {
            
            int angry = rand() % 100 + 1;
            if(angry>=1 && angry <= 80)
            {
                m1->basicAttack(m2);
                cout << m1->basicName()<<endl;
            }
            if(angry>=80 && angry <= 100)
            {
                m1->specialAttack(m2);
                cout << m1->specialName()<<endl;
            }
        }
        
        try {
            if (command == "exit"){
                throw 1;}
        }
            catch( int e )
            {
                cout<<"Thanks for playing."<<endl;
                exit(0);
            }
        
        //Determine what move the enemy makes
        //Probabilities:
        //	60% chance of standard attack
        //	20% chance of defense move
        //	20% chance of special attack move
        //Pick a number between 1 and 100
        int move = rand() % 100 + 1;
        if(move>=1 && move <= 60)
        {
            //Attack!
            m2->basicAttack(m1);
            cout<< m2->getName() <<" "<< m2->basicName() <<endl;
        }
        
        if(move>=61 && move <= 80)
        {
            //Defend!
           m2->defenseAttack(m1);
           cout<< m2->getName() <<" "<< m2->defenseName() << endl;
        }
        if(move>=81 && move <= 100)
        {
            //Special attack
            m2->specialAttack(m1);
            cout<< m2->getName() <<" "<< m2->basicName() <<endl;
        }
        
        //who wins
        if(m1->getHealth() < 1 && m2->getHealth() < 1)
        {
            return NULL;
        }
        if(m1->getHealth()<1)
        {
            cout << m2->getName() << " is victorious!" << endl;
            return m2;
        }
        if(m2->getHealth()<1)
        {
            cout << m1->getName() << " is victorious!" << endl;
            return m1;
        }
        
        m1->printState();
    }
    
    cout << "A tie but not sure why??" << endl;
    return NULL;
}
