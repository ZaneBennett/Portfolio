#include <iostream>
#include "Character.h"
using namespace std;

Character::Character()
{
	maxHP = 12;
	HP = maxHP;
	att = 5;
	baseDef = 5;
	defCooldown = 0;
	def = baseDef;
	spd = 5;
	turn = 0;
};

void Character::SpeedTest(Character& user, Character& enemy)
{
	if (user.spd >= enemy.spd)
		user.turn = 1;
	else
		enemy.turn = 1;
}

void Character::Attack(Character& attacker, Character& defender)
{
	int damage;
	damage = attacker.att - (defender.def / 2);
	if (damage == 0)
		damage = 1;
	defender.HP -= damage;
	if (defender.HP < 0)
		defender.HP = 0;
	cout << "\nThe enemy attacked!\nYou took " << damage << " damage.\nYou have " << defender.HP << " HP left.\n";
}

void Character::Defend(Character& enemy)
{
	enemy.def += 3;
	enemy.defCooldown += 3;
	cout << "\nThe enemy is defending!\n";
}

void Character::DefCooldownCycle(Character& enemy)
{
	if (enemy.defCooldown > 0)
	{
		enemy.defCooldown -= 1;

		if (enemy.defCooldown == 0)
		{
			cout << "\nThe enemy's guard relaxed.\n";
			enemy.def = enemy.baseDef;
		}
	}
}

void Character::End(Character user, Character enemy)
{
	if (user.HP > enemy.HP)
	{
		cout << "\nYou won the battle! The enemy hurries back into the shadows from whence it came.\n";
		cout << "The End.\n";
	}
	else
	{
		cout << "You were defeated...\n";
		cout << "GAME OVER\n";
	}
}