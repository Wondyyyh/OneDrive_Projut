#include "character.h"
#include <memory>
#include <iostream>


Character::Character(string name, char mapSymbol, int mapPosX, int mapPosY, int hp, int strenght) {

	//käännetään tuodut variablet headerille
	Name = name;
	MapSymbol = mapSymbol;
	MapPosX = mapPosX;
	MapPosY = mapPosY;
	Hp = hp;
	Strenght = strenght;

}