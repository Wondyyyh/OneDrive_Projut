#pragma once
#include <iostream>
#include <list>
#include <memory>
#include "Enemy.h"
 
using namespace std;

namespace Helper 
{
	void DrawMap(char* mapArray, int width, int height, list <unique_ptr<Enemy> >& enemyList, Player& player);
	void handleInput(Player& player, list <unique_ptr<Enemy>>& enemies);
	void AddNewEnemy(list <unique_ptr<Enemy> >& enemyList, const int& mapW, const int& mapH);
}
