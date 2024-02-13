//#pragma once is a non-standard but widely supported preprocessor directive
//designed to cause the current source file to be included only once in a single compilation.
#pragma once

#include <string>
#include "character.h"

using namespace std;

class Player; //<-- forward declaration of Player class
class Character;
class Enemy : public Character //public character jotta childit on myös publickeja
{
public:

	Enemy(string name, int mapPosX, int mapPosY, int hp, int strenght );
	~Enemy();
};

