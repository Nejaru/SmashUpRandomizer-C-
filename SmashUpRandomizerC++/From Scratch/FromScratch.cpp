#include <iostream>
//#include <process.h>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <ctime>

using namespace std;

vector<int> packs{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
vector<string> pot;
vector<string> core{ "Aliens", "Dinosaurs", "Ninjas", "Pirates", "Robots", "Tricksters", "Wizards", "Zombies" };
vector<string> al9k{ "Bear Cavalry", "Ghosts", "Killer Plants", "Steampunks" };
vector<string> ocs{ "Elder Things", "Innsmouth", "Minions of Cthulu", "Miskatonic University" };
vector<string> sfdf{ "Cyborg Apes", "Shapeshifters", "Super Spies", "Time Travelers" };
vector<string> bgb{ "Geeks" };
vector<string> ms{ "Giant Ants", "Mad Scientists", "Vampires", "Werewolves" };
vector<string> ppsu{ "Fairies", "Kitty Cats", "Mythic Horses", "Princesses" };
vector<string> sum{ "Clerics", "Dwarves", "Elves", "Halflings", "Mages", "Orcs", "Thieves", "Warriors" };
vector<string> iyf{ "Dragons", "Mythic Greeks", "Sharks", "Superheroes", "Tornadoes" };
vector<string> cad{ "Astroknights", "Changerbots", "Ignobles", "Star Roamers" };
vector<string> wwwt{ "Explorers", "Grannies", "Rock Stars", "Teddy Bears" };
vector<string> asek{ "All Stars" };
vector<string> bij{ "Itty Critters", "Kaiju", "Magical Girls", "Mega Troopers" };
vector<string> sp{ "Sheep" };
vector<string> t70e{ "Disco Dancers", "Kung Fu Fighters", "Truckers", "Vigilantes" };
vector<string> oydia{ "Egypt", "Samurai", "Cowboys", "Vikings" };

int randNum(int x)
{
	srand(time(NULL));
	return ((rand() % x));
}

void fillPot(vector<string> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		pot.push_back(vec.at(i));
	}
}

void fillPot(int n)
{
	int m;
	int j;
	vector<int> temp = packs;
	if (n == 1)
		fillPot(core);
	else if (n == 2)
		fillPot(al9k);
	else if (n == 3)
		fillPot(ocs);
	else if (n == 4)
		fillPot(sfdf);
	else if (n == 5)
		fillPot(bgb);
	else if (n == 6)
		fillPot(ms);
	else if (n == 7)
		fillPot(ppsu);
	else if (n == 8)
		fillPot(sum);
	else if (n == 9)
		fillPot(iyf);
	else if (n == 10)
		fillPot(cad);
	else if (n == 11)
		fillPot(wwwt);
	else if (n == 12)
		fillPot(asek);
	else if (n == 13)
		fillPot(bij);
	else if (n == 14)
		fillPot(sp);
	else if (n == 15)
	{
		//fillPot(t70e);
		cout << "Packs 15 and 16 have not yet been released, please select a different one: ";
		cin >> m;
		j = --m;
		fillPot(temp.at(j));
	}
	else if (n == 16)
	{
		//fillPot(oydia);
		cout << "Packs 15 and 16 have not yet been released, please select a different one: ";
		cin >> m;
		j = --m;
		fillPot(temp.at(j));
	}
	else if (n == 0)
	{
		cout << "That pack has already been chosen, please select a different one: ";
		cin >> m;
		while (m >= 17 || m <= 0)
		{
			if (m >= 17)
			{
				cout << "That number is too high, please enter a pack between 1 and 16: ";
				cin >> m;
			}
			else if (m <= 0)
			{
				cout << "That number is too low, please enter a pack between 1 and 16: ";
				cin >> m;
			}
		}
		j = --m;
		fillPot(temp.at(j));
		temp.erase(temp.begin() + j);
		temp.insert(temp.begin() + j, 0);
	}
}


void fillAll()
{
	fillPot(core);
	fillPot(al9k);
	fillPot(ocs);
	fillPot(sfdf);
	fillPot(bgb);
	fillPot(ms);
	fillPot(ppsu);
	fillPot(sum);
	fillPot(iyf);
	fillPot(cad);
	fillPot(wwwt);
	fillPot(asek);
	fillPot(bij);
	fillPot(sp);
}

void reset()
{
	for (int i = 0; i < pot.size(); i++)
	{
		pot.erase(pot.begin() + i);
	}
}

vector<string> randomize(vector<string> vec, int n, vector<string> choices)
{
	int size = vec.size(), x = randNum(size);
	if (n > choices.size())
	{
		choices.push_back(vec.at(x));
		vec.erase(vec.begin() + x);
		return randomize(vec, n, choices);
	}
	else
		return choices;
}

void randomizer(vector<string> vec, int n, vector<string> choices)
{
	vector<string> vec2;
	vec2 = randomize(vec, 4 * n, choices); //How many factions chosen per person.
	cout << "Your choices are: ";
	for (int i = 0; i < vec2.size() - 1; i++)
	{
		cout << vec2.at(i) << ", ";
	}
	cout << "and " << vec2.at(vec2.size() - 1) << "\n";
}

void runner()
{
	int numPlay, numPacks, packNum;
	string exCheck;
	vector<string> selection, selection2;
	vector<int> temp = packs;

	cout << "\nHow many people are playing? ";
	cin >> numPlay;
	while (numPlay <= 1 || numPlay > 10)
	{
		if (numPlay <= 1)
		{
			cout << "Too few players, please enter a number between 2 and 10: ";
			cin >> numPlay;
		}
		else if (numPlay > 10)
		{
			cout << "Too many players, please enter a number between 2 and 10: ";
			cin >> numPlay;
		}
	}

	cout << "Would you like to use all of the expansions (Y/N)? ";
	cin >> exCheck;
	cout << endl;
	do
	{
		if (exCheck == "y" || exCheck == "Y")
		{
			fillAll();
			randomizer(pot, numPlay, selection);
			exCheck = "hello";
		}
		else if (exCheck == "n" || exCheck == "N")
		{
			cout << "List of Expansion Packs:\n" << "1) Core Set\n" << "2) Awesome Level 9000\n" << "3) The Obligatory Cthulu Set\n"
				<< "4) Science Fiction Double Feature\n" << "5) The Big Geeky Box\n" << "6) Monster Smash\n" << "7) Pretty Pretty Smash Up\n"
				<< "8) Smash Up: Munchkin\n" << "9) It's Your Fault!\n" << "10) Cease and Desist\n" << "11) What Were We Thinking?\n"
				<< "12) All Stars Event Kit\n" << "13) Big in Japan\n" << "14) Sheep Promotion\n" << "15) That '70s Expansion\n"
				<< "16) Oops You Did It Again\n\n" << "How many packs do you want to use (1-14; 15 and 16 aren't realeased yet)?: ";
			cin >> numPacks;
			do
			{
				if (numPacks >= 1 && numPacks <= 14)
				{
					cout << "Enter the number of the pack you want (after each entry, press enter):\n";
					do
					{
						cin >> packNum;
						int j = packNum - 1;
						fillPot(temp.at(j));
						temp.erase(temp.begin() + j);
						temp.insert(temp.begin() + j, 0);
						numPacks--;
					} while (numPacks > 0);
					cout << endl;
					randomizer(pot, numPlay, selection2);
				}
				else
				{
					do
					{
						cout << "Please enter a number between 1 and 14 (15 and 16 are not yet released): ";
						cin >> numPacks;
					} while (numPacks < 1 || numPacks > 14);
				}
			} while (numPacks >= 1 && numPacks <= 16);
			exCheck = "hello";
		}
		else
		{
			do
			{
				cout << "Nice try, please enter a valid response: ";
				cin >> exCheck;
			} while (exCheck != "y" && exCheck != "Y" && exCheck != "n" && exCheck != "N");
			cout << endl;
		}
	} while (exCheck == "y" || exCheck == "Y" || exCheck == "n" || exCheck == "N");
}

int main()
{
	string check = "y";
	cout << "Welcome to the Smash Up Randomizer\n";
	do
	{
		if (check == "y" || check == "Y")
		{
			reset();
			runner();
			cout << "\nWould you like to randomize again (Y/N)? ";
			cin >> check;
		}
		else if (check != "n" && check != "N")
		{
			cout << "Nice try, please enter a valid response: ";
			cin >> check;
		}
	} while (check != "n" && check != "N");




	return 0;
}