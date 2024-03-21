#pragma once

class Character
{
public:
	int maxHP;
	int HP;
	int att;
	int baseDef;
	int def;
	int defCooldown;
	int spd;
	bool turn;
	Character();
	void SpeedTest(Character&, Character&);
	void Attack(Character&, Character&);
	void Defend(Character&);
	void DefCooldownCycle(Character&);
	void End(Character, Character);
};