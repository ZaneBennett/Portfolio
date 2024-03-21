#include <iostream>
#include <cstdlib>
#include "Player.h"
using namespace std;

Player::Player()
{
	srand((unsigned)time(NULL));
	maxHP = 9 + (rand() % 3);
	HP = maxHP;
	att = 4 + (rand() % 3);
	baseDef = 4 + (rand() % 3);
	def = baseDef;
	defCooldown = 0;
	spd = 4 + (rand() % 3);
	turn = 0;
	item = true;
};

void Player::Item(Player& pla)
{
	if (pla.item == true)
	{
		cout << "\nYou ate the Medicinal Herb.\n";
		pla.HP += 10;
		if (pla.HP > pla.maxHP)
			pla.HP = pla.maxHP;
		cout << "You now have " << pla.HP << " HP.\n";
		pla.item = false;
	}
	else
	{
		cout << "\nYou have no items left!\n";
		pla.turn = 1;
	}
}

void Player::Attack(Player& attacker, Character& defender)
{
	int damage;
	damage = attacker.att - (defender.def / 2);
	if (damage == 0)
		damage = 1;
	defender.HP -= damage;
	cout << "\nYou attacked!\nThe enemy took " << damage << " damage.\n\n";
}

void Player::Defend(Player& pla)
{
	if (pla.defCooldown == 0)
	{
		pla.defCooldown += 3;
		pla.def += 3;
		cout << "\nYou hold your arms up in defence!\nYour defence temporarily increases.\n";
	}
	else
	{
		cout << "\nYou are already defending!\n\n";
		pla.turn = 1;
	}
}

void Player::EnemyCheck(Character enemy)
{
	int opt;
	opt = 1 + (rand() % 3);

	switch (opt)
	{
	case 1:
		cout << "\nThe enemy appears to be some sort of bandit, who make his living taking the gold from unwary travelers.\n";
		break;
	case 2:
		cout << "\nThe opponent is glaring at you menacingly.\n";
		break;
	case 3:
		cout << "\nThe enemy seems to have no affiliation with a rival guild, meaning that he is probably just a random attacker.\n";
		break;
	}
	
	cout << "\nStats:\nHP:   " << enemy.HP << "\nAtt:  " << enemy.att << "\nDef:  " << enemy.def << "\nSpd:  " << enemy.spd << endl;

}

void Player::StatCheck(Player pla)
{
	cout << "\nYour stats:\nMax HP: " << pla.maxHP << "\nHP:     " << pla.HP << "\nAtt:    " << pla.att << "\nDef:    " << pla.def;
	cout << "\nSpd:    " << pla.spd << endl << endl;
}

void Player::DefCooldownCycle(Player& pla)
{
	if (pla.defCooldown > 0)
	{
		pla.defCooldown -= 1;

		if (pla.defCooldown == 0)
		{
			cout << "\nYour guard relaxed.\n";
			pla.def = pla.baseDef;
		}
	}
}