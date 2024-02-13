#include "Enemy.h"
#include <string>

Enemy::Enemy(string name, int mapPosX, int mapPosY, int hp, int strenght)
	: Character( name, name[0],  mapPosX,  mapPosY,  hp,  strenght)
{
	//Name's first letter is symbol on the map
	Name = name;
	MapSymbol = name[0];
	MapPosX = mapPosX;
	MapPosY = mapPosY;
	Hp = hp;
	Strenght = strenght;
}

Enemy::~Enemy()
{
}
