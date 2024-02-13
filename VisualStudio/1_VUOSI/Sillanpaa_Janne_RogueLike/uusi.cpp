#include "uusi.h"
#include <iostream>
#include <list>
#include <memory>
#include "Enemy.h"
#include "Player.h"
#include <conio.h>

using namespace std;
using namespace Helper;
//List of enemies
list <unique_ptr<Enemy>> enemyList;


	void Helper::DrawMap(char* mapArray, int width, int height, list <unique_ptr<Enemy> >& enemyList, Player& player)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				char mapSymbolToDraw = '.';
				//Loop through all enemies and draw them
				for (auto& enemy : enemyList) {
					if (enemy->MapPosX == x && enemy->MapPosY == y)
					{
						//If looped point has enemy, set char to enemy's symbol
						mapSymbolToDraw = enemy->MapSymbol;
						break;
					}
				}

				//Check if position is player's position
				if (player.MapPosX == x && player.MapPosY == y) {
					mapSymbolToDraw = player.MapSymbol;
				}

				cout << mapSymbolToDraw;

			}
			//Change row
			cout << endl;
		}
	}

	void Helper::AddNewEnemy(list <unique_ptr<Enemy> >& enemyList, const int& mapW, const int& mapH)
	{
		int randomPosX = rand() % mapW;
		int randomPosY = rand() % mapH;
		int strenght = rand() % 8; //strenght randomilla 0-8
		int hp = rand() % 10; //hp randomilla 0-10

		string names[]{ "Goblin", "Orc", "Dragon" };
		string randomName = names[rand() % 3];

		//luodaan enemy ja laitetaan enemylistin loppuun
		enemyList.push_back(make_unique<Enemy>(randomName, randomPosX, randomPosY, strenght, hp));
	}

	void Helper::handleInput(Player& player, list <unique_ptr<Enemy>>& enemies) 
	{

		char input = _getch(); //<-- Windows only
		input = tolower(input); //<-- to handle uppercase characters

		//Input mapping, call Player's Move with enum parameter


		switch (input)
		{
		case 'w':
			player.Move(Player::North, enemies);
			break;
		case 'a':
			player.Move(Player::West, enemies);
			break;
		case 's':
			player.Move(Player::South, enemies);
			break;
		case 'd':
			player.Move(Player::East, enemies);
			break;
		default:
			cout << input;
			break;
		}


	}
