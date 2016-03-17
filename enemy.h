#ifndef _BATTLE_enemy_
#define _BATTLE_enemy_

#include <string>
using namespace std;

//This class defines a generic enemy
//It doesn't actually DO anything.
//It just gives you a template for how a enemy works.

//We can make any number of enemys and have them fight
//they just all need to INHERIT from this one so that work the same way

//Since this class is not intended to be used
//none of the methods do anything
//The virtual command means we want the children to override these.
//The =0 part means these function's won't even work if you tried.
//This class is impossible to use by itself.

class enemy
{
	public:
		enemy();
		//Name the enemy we are fighting
		//The description is printed at the start to give
		//additional details
		virtual string getName() const=0;
		virtual string getDescription() const=0;
	
		//Basic Attack Move
		//This will be the most common attack the enemy makes
		//You are passed a pointer to the enemy you are fighting
		virtual void basicAttack(enemy * enemy)=0;
		//Print the name of the attack used
		virtual string basicName() const=0;
	
		//Defense Move
		//This move is used less frequently to
		//let the enemy defend itself
		virtual void defenseAttack(enemy * enemy)=0;
		//Print out the name of the attack used
		virtual string defenseName() const=0;
	
		//Special Attack
		//This move is used less frequently
		//but is the most powerful move the enemy has
		virtual void specialAttack(enemy * enemy)=0;
		virtual string specialName() const=0;
	
		//Health Management
		//A enemy at health <= 0 is unconscious
		//This returns the current health level
		virtual int getHealth() const=0;
		//This function is used by the other enemy to
		//either do damage (positive int) or heal (negative int)
		virtual void doDamage(int damage) =0;
		//Reset Health for next match
		virtual void resetHealth() = 0;
        /*virtual void usePotion()=0;
        virtual void printInformation()const=0;*/
        virtual void useFireBall(enemy * enemy) = 0;
        virtual void printState() = 0;
        virtual void usePotion()=0;
};

#endif
