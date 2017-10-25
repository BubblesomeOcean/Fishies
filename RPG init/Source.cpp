#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

int Level = 1, Agi = 5, Att = 5, Def = 5, Hp = 20, Choice = 0, hard = 2, gold = 0;
unsigned int Exp = 0;
int at = (Att * 4), df = (Def * 4), eAt = (Att * hard), eDf = (Def * hard), hp = (Hp * 3), eHp = (Hp * hard), eType, pType;
std::string enemy, name;
int type[4] = { 4, 8, 16, 32 };
int escape = 0;

void whatDo();


/*
Types determind effectiveness against other types
Types are based on how simular they are to 4 fish types
type 0 are small fish
type 1 are jelly-like fish
type 2 are top of the food chain fish or big fish
type 3 are shelled or armoured
*/

void goldC(int a) // Works out gold
{
	gold += (a * hard);

}

void shop()
{
	std::cout << "You have " << gold << " gold.\n\n";
	std::cout << "What would you like to purchase?\nPress 1 for an attack booster(15)\nPress 2 for a defence booster(15)\nPress 3 for an agility boost(15)\nPress 4 for a HP boost(15)\n\nOR\n\nPress 5 to escape\n\n";
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
		if (gold >= 15)
		{
			gold -= 15;
			Att += 5;
			std::cout << "You purchased an attack booster!\n Attack + 5\n\n";
			shop();
		}
		else
		{
			std::cout << "You do not have enough money";
			whatDo();
		}
	case 2:
		if (gold >= 15)
		{
			gold -= 15;
			Def += 5;
			std::cout << "You purchased a defence booster!\n Defence + 5\n\n";
			shop();
		}
		else
		{
			std::cout << "You do not have enough money";
			whatDo();
		}
	case 3:
		if (gold >= 15)
		{
			gold -= 15;
			Agi += 5;
			std::cout << "You purchased an agility booster!\n Agility + 5\n\n";
			shop();
		}
		else
		{
			std::cout << "You do not have enough money";
			whatDo();
		}
	case 4:
		if (gold >= 15)
		{
			gold -= 15;
			Hp += 5;
			std::cout << "You purchased a HP booster!\n HP + 5\n\n";
			shop();
		}
		else
		{
			std::cout << "You do not have enough money";
			whatDo();
		}
	case 5:
		whatDo();
	}
}

void pAdvantage() // Checks if player is effective
{
	if (pType == (eType * 2))
	{
		std::cout << "You are effective against the " << enemy << "!" << std::endl;
		at = at + (at / 2);
	}
	if (pType == (eType / 8))
	{
		std::cout << "You are effective against the " << enemy << "!" << std::endl;
		at = at + (at / 2);
	}

}

void eAdvantage() // Checks if enemy is effective
{
	if (eType == (pType * 2))
	{
		std::cout << "The " << enemy << " is effective against " << name << "!" << std::endl;
		eAt = at + (eAt / 2);
	}
	if (eType == (pType / 8))
	{
		std::cout << "The " << enemy << " is effective against " << name << "!" << std::endl;
		eAt = at + (eAt / 2);
	}

}

void levelUp() // Adds to stats when levelling up
{
	srand(time(0));
	std::cout << "\nYou levelled up to level " << Level << "!";
	switch (rand() % 4)
	{
	case 1:
		Agi += 5;
		Def += 2;
		Hp += 2;
		Att += 2;
		Exp -= 100;
		std::cout << "\n Agility + 5\n Defence + 2\n HP + 2\n Attack + 2\n";
		if (Exp >= 100)
		{
			levelUp();
		}
		break;

	case 2:
		Agi += 2;
		Def += 5;
		Hp += 2;
		Att += 2;
		Exp -= 100;
		std::cout << "\n Agility + 2\n Defence + 5\n HP + 2\n Attack + 2\n";
		if (Exp >= 100)
		{
			levelUp();
		}
		break;

	case 3:
		Agi += 2;
		Def += 2;
		Hp += 5;
		Att += 2;
		Exp -= 100;
		std::cout << "\n Agility + 2\n Defence + 2\n HP + 5\n Attack + 2\n";
		if (Exp >= 100)
		{
			levelUp();
		}
		break;

	case 4:
		Agi += 2;
		Def += 2;
		Hp += 2;
		Att += 5;
		std::cout << "\n Agility + 2\n Defence + 2\n HP + 2\n Attack + 5\n";
		Exp -= 100;
		if (Exp >= 100)
		{
			levelUp();
		}
		break;

	}
}

int attack() // To decide and show what happens when you attack
{
	std::cin >> Choice;
	srand(time(0));
	switch (Choice)
	{
	case 1:
		eHp -= ((rand() % Att) + at);
		hp -= ((rand() % (eAt / 5) + eAt));
		if (hp > 0)
			std::cout << std::endl << name << " has " << hp << "HP left \n" << std::flush;
		else
			std::cout << "You died!\n";
		if (eHp > 0)
			std::cout << std::endl << "The " << enemy << "has " << eHp << "HP left \n\n" << std::flush;
		else
			std::cout << "\nThe enemy is defeated!\nYou won!\n\n";
		if (Agi >= (hard + 3) && (rand() % 100) > 80 && eHp > 0 && hp > 0)
		{
			eHp -= ((rand() % Att) + at);
			std::cout << name << " attacked twice!\nEnemy now has " << eHp << " HP\n\n";
		}
		break;
	case 2:
		hp -= ((rand() % (eAt / 5) + eAt));
		at = at + (at / 2);
		std::cout << name << " charged it's power! \nYour attack is increased!\n\n";
		hp -= ((rand() % (eAt / 5) + eAt));
		std::cout << name << " has " << hp << "HP left \n" << std::flush;
		break;
	case 3:
		if ((rand() % 100) < 50)
		{
			std::cout << "You escaped successfully!\n" << std::flush;
			escape += 1;
			return 0;
		}
		else
		{
			std::cout << "Escape failed!\n";
			hp -= ((rand() % (eAt / 5) + eAt));
			std::cout << name << " has " << hp << "HP left \n" << std::flush;
			break;
		}
		return 0;
		break;
	}
}

void battleGeneric() // For when the battle starts
{
	std::cout << "\nA " << enemy << " prepares to fight!\n\n";
	std::cout << "The " << enemy << " has " << eHp << "HP" << std::endl <<
		name << " has " << hp << "HP \n\n" << std::flush;
	pAdvantage();
	eAdvantage();
	while (eHp > 0 && hp > 0)
	{
		if (escape == 1)
			break;
		std::cout << "Press 1 to attack, 2 to charge your attack, or 3 to run\n\n" << std::flush;
		attack();
	}
	if (eHp <= 0)
	{
		hard += 1;
		Exp += (300 / hard);
		std::cout << "You gained " << (300 / hard) << " exp!\n";
		if (Exp >= 100)
		{
			Level += 1;
			levelUp();
		}
		std::cout << "\n\nYou now have " << Exp << " EXP left." << std::endl;
		goldC(5);
		std::cout << "You got " << hard * 5 << " gold!\n";
		std::cout << "You now have " << gold << " total gold\n\n";
		at = Att * 4;
		hp = Hp * 3;
		eHp = hard * Hp;
		whatDo();
	}
	if (hp <= 0)
	{
		std::cout << "GAME OVER!\n\n";
		exit;
	}
	else
		if (escape = 1)
			return;
}

void randomBattle() // Decides what battle you get
{

	switch (rand() % 5)
	{
	case 1:
		enemy = "plankton";
		eType = type[0];
		battleGeneric();
	case 2:
		enemy = "jelly fish";
		eType = type[1];
		battleGeneric();
	case 3:
		enemy = "bottlenose dolphin";
		eType = type[2];
		battleGeneric();
	case 4:
		enemy = "hermit crab";
		eType = type[3];
		battleGeneric();
	}
}

void whatDo() // Lets you choose what to do next
{
	std::cout << "\nWhat would you like to do next?\n";
	std::cout << "To go to the next battle, press 1.\nTo go to the shop, press 2.\nTo check your stats, press 3.\n\n";
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
		randomBattle();
	case 2:
		shop();
	case 3:
		std::cout << "\nYour attack is " << Att << std::endl << "Your defence is " << Def << std::endl << "Your HP is " << Hp << std::endl << "Your agility is " << Agi << std::endl << "Your level is " << Level << std::endl << "You have " <<
			Exp << " EXP\n" << "You have " << gold << " gold\n";
		whatDo();
	}
}

int main() // The story and where decisions are made
{
	system("Title        Fishies       ");
	system("Color 3");
	std::cout << "Welcome to the world of fishies! Also know as the ocean. Pick your starter fish/crustacean:" << std::endl << std::endl <<
		"To choose a minnow, the agile fishy, type 1" << std::endl << "To choose a squid, the health-ful, type 2 " << std::endl << "To choose a sharkie, the one that is good at fighting, type 3" << std::endl
		<< "To choose a crabster, the defensive ... thing, type 4 " << std::endl << std::endl << std::flush;
	std::cin >> Choice;

	switch (Choice)
	{
	case 1:
		Agi += 5;
		std::cout << "\nYou picked the minnow! \n Agility + 5!\n" << std::flush;
		pType = type[0];
		break;
	case 2:
		Hp += 5;
		std::cout << "\nYou picked the squid! \n HP + 5!\n" << std::flush;
		pType = type[1];
		break;
	case 3:
		Att += 5;
		std::cout << "\nYou picked the shark! \n Attack + 5!\n" << std::flush;
		pType = type[2];
		break;
	case 4:
		Def += 5;
		std::cout << "\nYou picked the crab! \n Defense + 5!\n" << std::flush;
		pType = type[3];
		break;
	}

	std::cout << "\nEnter your fish's name:\n\n" << std::flush;
	std::cin >> name;
	std::cout << "\nSo your fishes name is " << name << "? Cool!\n\n";
	enemy = "sea anemone";
	eType = type[1];
	battleGeneric();
	escape = 0;

	srand(time(0));

	while (hp > 0)
		whatDo;

	system("pause");
	return 0;
}


