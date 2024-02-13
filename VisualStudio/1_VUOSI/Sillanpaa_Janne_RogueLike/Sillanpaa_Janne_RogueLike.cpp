#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <time.h> 
#include <conio.h>

//Include enemy header:
#include "Enemy.h"

//Include player header
#include "Player.h"

//Include uusi header
#include "uusi.h"
#include "Sillanpaa_Janne_RogueLike.h"

using namespace std;
using namespace Helper;



int main()
{
	//Initialize randomness
	srand(time(0));

	//declare 20x10 char array for simple map
	const int mapWidth = 20;
	const int mapHeight = 10;
	char map[mapHeight][mapWidth];

	//List of enemies
	list <unique_ptr<Enemy>> enemyList;

	//Add five random enemies
	for (int i = 0; i < 5; i++) {
		Helper::AddNewEnemy(enemyList, mapWidth, mapHeight);
	}

	//New Player character object (to stack since we only have one)
	Player player("Sepi", '@', mapWidth, mapHeight, 10, 5, 30, 5);
	

	

	//"Game loop"
	while (true)
	{
		if (player.Hp > 0) //toistetaan gameloop jos pelaajalla on enemmän kuin 0 hp
		{
			system("cls");
			//<-- Windows console only, just calling command prompt 'cls' to clear console

			//Call drawmap from Helper
			Helper::DrawMap(*map, mapWidth, mapHeight, enemyList, player);

			cout << "\nPlayer has " << player.Hp << " hp left" << endl;
			cout << "Players strenght is " << player.Strenght << endl;

			//Call handleInput from Helper
			Helper::handleInput(player, enemyList);
		}
		else //jos pelaajan hp alle 0 tulostetaan game over
		{
			char input;
			bool rightInput = false;
			cout << "\n--You died!!--" << endl;
			cout << "GAME OVER (Q - quit)" << endl;
			
			//loopataan kunnes input on haluttu eli Q character
			while (!rightInput)
			{
				input = _getch();
				input = tolower(input);
				//kun oikea input löytyy rikotaan tämä looppi
				if (input == 'q') 
				{
					rightInput = true;
					break;
				}

			}
			//jonka jälkeen rikotaan gameloop
			break;
		}
	}
}