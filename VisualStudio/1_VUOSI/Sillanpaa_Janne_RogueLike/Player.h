//#pragma once is a non-standard but widely supported preprocessor directive
//designed to cause the current source file to be included only once in a single compilation.
#pragma once

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include <time.h>  
#include "character.h"

using namespace std; //And use std namespace (or refer to strings as std::string)

class Character;
class Enemy; //<-- forward declaration of Enemy class, try commenting out
class Player : public Character //public character jotta childit on myös publickeja
{
private:
	//Private variables
	int mapWidth;
	int mapHeight;

public:

	//Public variables (members, fields, properties)	
	enum Direction { North, South, West, East };

	//Constructor
	Player(string name, char mapSymbol, int mapWidth, int mapHeight, int mapPosX, int mapPosY, int hp, int strenght);
	
		

	//Destructor
	~Player();

	//Give move direction and list of enemies that player can "collide" with
	void Move(Direction dir, list <unique_ptr<Enemy> > & enemies);
};

