#ifndef _venus_
#define _venus_

#include <string>
#include "enemy.h"

using namespace std;

//This is a venus.
//It is a very weak enemy.

class venus : public enemy
{
	private:
		string my_name;
		int my_health;
		bool defense_mode;
        int potion;
        int fireball;
	public:
		venus(string n="No Name");
		//redefine all the Methods of enemy
		//Note: we can make more methods if we want, but
		//we need to redfine the methods of enemy
		//because those are the ones that will be used in the game.
		string getName() const;
		string getDescription() const;
		void basicAttack(enemy * enemy);
		string basicName() const;
		void defenseAttack(enemy * enemy);
		string defenseName() const;
		void specialAttack(enemy * enemy);
		string specialName() const;
		int getHealth() const;
		void doDamage(int damage);
		void resetHealth();
        void useFireBall(enemy * enemy);
        void printState();
        void usePotion();
   
    
};

#endif