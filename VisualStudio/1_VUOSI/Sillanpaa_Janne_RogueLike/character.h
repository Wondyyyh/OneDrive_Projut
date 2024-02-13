#pragma once
#include <string>
#include <memory>

using namespace std;

class Player;
class Enemy;
class Character
{
public:

	//Public variablet headermuodossa
	string Name;
	char MapSymbol;
	int MapPosX;
	int MapPosY;
	int Hp;
	int Strenght;

	//Constructor
	Character(string name, char mapSymbol, int mapPosX, int mapPosY, int hp, int strenght);
};

