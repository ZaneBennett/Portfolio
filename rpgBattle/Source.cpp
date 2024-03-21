#include <iostream>
#include <cstdlib>
#include "Character.h"
#include "Player.h"
using namespace std;

int main()
{
	int choice;
	int enemyChoice;
	Character enemy;
	Player user;

	cout << "As you are walking through the forest one day, a brigand suddenly jumps into the trail and looks ready to attack!\n\n";

	enemy.SpeedTest(user, enemy);

	while (user.HP > 0 && enemy.HP > 0)
	{
		if (user.turn == 1)
		{
			user.DefCooldownCycle(user);
			cout << "\nWhat do you do?\n1 : Attack\n2 : Defend\n3 : Item\n4 : Stats\n5 : Check\n";
			cin >> choice;
			user.turn = 0;
			switch (choice)
			{
			case 1:
				user.Attack(user, enemy);
				break;
			case 2:
				user.Defend(user);
				break;
			case 3:
				user.Item(user);
				break;
			case 4:
				user.StatCheck(user);
				break;
			case 5:
				user.EnemyCheck(enemy);
				break;
			}
			if (user.turn == 0)
				enemy.turn = 1;
		}

		if (enemy.turn == 1 && enemy.HP > 0
			)
		{
			enemy.DefCooldownCycle(enemy);
			enemy.turn = 0;
			if (enemy.defCooldown == 0)
				enemyChoice = 1 + (rand() % 3);
			else
				enemyChoice = 1;

			if (enemyChoice == 3)
				enemy.Defend(enemy);
			else
				enemy.Attack(enemy, user);

			user.turn = 1;
		}
	}

	enemy.End(user, enemy);

	return 0;

}