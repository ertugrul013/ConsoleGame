#include <iostream>

#include "Constants.h"

#include "Player.h"

#include "Church.h"
#include "Cliff.h"
#include "Forrest.h"
#include "Swamp.h"

#include "Diamond.h"

#include "Map.h"

using namespace std;

void welcome(Player& a_Player);
void printInventory(vector<Object*>& a_Invent);
void initMap(Map& a_Map);
void run(Map& a_Map, Player& a_Player);
std::string showMenu(Map& a_Map, vector<std::string>& a_Menu);
void showDirections(Map& a_Map, vector<std::string>& a_Menu);
void quit();

int main()
{
	int mapWidth = MAPWIDTH;
	int mapHeigth = MAPHEIGHT;
	int yStartPos = 0;
	int xStartPos = 2;

	cout << "Welcome to a textbased adventure!\n";
	cout << "Before you can start your journey, you will have to enter your name.\n\n";

	string name = "";
	
	bool error = false;
	do
	{
		error = false;
		if (!error)
		{
			cout << "Please enter your name:\n";
		}
		else
		{
			cout << "Something went wrong, would you please enter your name:\n";
		}
		cin >> name;
	} while (error || name == "");
	
	Player* player = new Player(name, 100);

	welcome(*player);

	vector< vector<Location*> > m(mapHeigth, vector<Location*>(mapWidth));
	Map map(m, yStartPos, xStartPos);
	
	initMap(map);
	
	run(map, *player);

	quit();
	return 0;
}

void welcome(Player& player)
{
	system("CLS");
	string output = "Welcome to the world of Flightwood.\n";
	output += "You just woke up from a very long sleep.\n";
	output += "You can't really remember anything but your name.\n";
	output += "Which by the way is " + player.GetName();
	cout << output << endl;
	
	printInventory(player.GetInventory());
	
	output = "\nYou look around you and realise that you are in a forest.\n";
	output += "In the distance you hear the howl of an animal.\n";
	output += "You slowly come to your senses and choose to go.\n";
	cout << output << endl;
	cout << "Press enter to continue...";
	cin.ignore(cin.rdbuf()->in_avail() + 1);
}

void printInventory(vector<Object*>& a_Invent)
{
	int size = a_Invent.size();
	cout << "There are " << size << " items in your inventory.\n";
	if (size > 0)
	{
		cout << "These are:\n";
		for (int i = 0; i < size; i++)
		{
			cout << a_Invent[i]->GetName() << endl;
		}
	}
}

void initMap(Map& a_Map)
{
	Forrest* forrest = new Forrest("Black Forrest");
	a_Map.AddLocation(*forrest, 0, 2);
	
	Cliff* cliff = new Cliff("Rockface");
	a_Map.AddLocation(*cliff, 0, 3);

	Church* church = new Church("Old Chapel");
	Diamond* diamond = new Diamond("Diamond", true, 100);
	church->AddObject((Object*)diamond);
	a_Map.AddLocation(*church, 1, 2);

	Swamp* swamp = new Swamp("Bog");
	a_Map.AddLocation(*swamp, 0, 1);
}

void run(Map& a_Map, Player& a_Player)
{
	std::vector<string> menuItems;
	std::string choice;

	do
	{
		system("CLS");
		cout << a_Map.GetLocation().Description() << endl;
		choice = showMenu(a_Map, menuItems);

		if (choice == "North.")
			a_Map.Move("Go North");
		if (choice == "East.")
			a_Map.Move("Go East");
		if (choice == "South.")
			a_Map.Move("Go South");
		if (choice == "West.")
			a_Map.Move("Go West");
		if (choice == "Search.")
		{
			// Add code to pick an item up.
		}
		if (choice == "Fight.")
		{
			// Add code to fight an enemy.
		}
		if (choice == "Run.")
		{
			// Add code to run away from a fight.
		}

	} while (choice != "Exit.");
}

std::string showMenu(Map& a_Map, vector<std::string>& a_Menu)
{
	int choice;
	a_Menu.clear();
	a_Menu.shrink_to_fit();

	showDirections(a_Map, a_Menu);

	if (a_Map.GetLocation().CheckForItems())
	{
		bool acquirableItems = false;
		vector<Object*> list = a_Map.GetLocation().GetObjects();
		for (unsigned int i = 0; i < list.size(); i++)
		{
			if (list[i]->IsAcquirable())
			{
				acquirableItems = true;
			}
		}
		if (acquirableItems)
			a_Menu.push_back("Search.");
	}

	if (a_Map.GetLocation().HasEnemy())
	{
		a_Menu.push_back("Fight.");
		a_Menu.push_back("Run.");
	}
	a_Menu.push_back("Exit.");

	bool error = false;
	do
	{
		for (unsigned int i = 0; i < a_Menu.size(); i++)
		{
			cout << i + 1 << " - " << a_Menu[i] << endl;
		}
		cout << "Please enter you choice (1 - " << a_Menu.size() << "):\n";
		cin >> choice;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			error = true;
		}
	} while (error || choice < 1 || choice > a_Menu.size());

	return a_Menu[choice - 1];
}

void showDirections(Map& a_Map, vector<std::string>& a_Menu)
{
	a_Map.AllowedDirections();

	if (a_Map.GetNorth() == 1)
		a_Menu.push_back("North.");
	if (a_Map.GetEast() == 1)
		a_Menu.push_back("East.");
	if (a_Map.GetSouth() == 1)
		a_Menu.push_back("South.");
	if (a_Map.GetWest() == 1)
		a_Menu.push_back("West.");
}

void quit()
{
	system("CLS");
	cout << "Thanks for playing! Hope you had a good time!\n";
	cout << "Press enter to exit...";
	cin.ignore(cin.rdbuf()->in_avail() + 1);
}