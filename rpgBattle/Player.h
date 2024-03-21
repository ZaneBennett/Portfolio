#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Player : public Character
{
private:
	bool item;
public:
	Player();
	void Item(Player&);
	void Attack(Player&, Character&);
	void Defend(Player&);
	void EnemyCheck(Character);
	void StatCheck(Player);
	void DefCooldownCycle(Player&);
};