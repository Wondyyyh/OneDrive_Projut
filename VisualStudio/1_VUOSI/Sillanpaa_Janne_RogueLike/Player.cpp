#include "Player.h"
#include "Enemy.h"
#include <conio.h>




Player::Player(string name, char mapSymbol, int mapW, int mapH, int mapPosX, int mapPosY, int hp, int strenght)
	: Character(name, mapSymbol, mapPosX, mapPosY, hp, strenght)
	
{
	Name = name;
	MapSymbol = mapSymbol;		
	MapPosX = mapPosX;
	MapPosY = mapPosY;	
	mapWidth = mapW;
	mapHeight = mapH;
	Hp = hp;
	Strenght = strenght;
	
}

bool alive = true;
void Player::Move(Direction dir, list <unique_ptr<Enemy> > & enemies)
{	
	int nextPosX = MapPosX;
	int nextPosY = MapPosY;

	if (dir == North) nextPosY--;
	else if (dir == West) nextPosX--;
	else if (dir == South) nextPosY++;
	else if (dir == East) nextPosX++;

	bool collisionWithEnemy = false;
	
	
	for (auto & enemy : enemies)
	{

		if (nextPosX == enemy->MapPosX && nextPosY == enemy->MapPosY) 
		{
			collisionWithEnemy = true;
			//Fight
			int damage = rand() %Strenght;
			int enemyDamage = rand() % 10;

			cout << "\n***Actions***" << endl;
			
			if (damage == 0) // nolla damage joten ei vahingoiteta vihua
			{
				cout << "You miss the " + enemy->Name << endl;

				// Vihun tekemät damaget pelaajaan
				if (enemyDamage > 0) {
					Hp -= enemyDamage;
					cout << "Player takes " << enemyDamage << " damage from "  << enemy->Name << endl;
					
				}
				else
					cout << enemy->Name << " misses you" << endl;
				
			}

			else //Damage > 0 joten vahingoitetaan vihua
			{
				//vähennetään damage vihun hp:sta ja kerrotaan siitä
			enemy->Hp -= damage;
			cout << "You deal " + to_string(damage) + " to " + enemy->Name + "\n";

			// Vihun tekemät damaget pelaajaan
			if (enemyDamage > 0) {
				Hp -= enemyDamage;
				cout << "Player takes " << enemyDamage << " damage" << endl;
			}
			else
				cout << enemy->Name << " misses you" << endl;

			//_getch();

			//vihun kuolema kun hp alle tai = 0
			if (enemy->Hp <= 0) {
				cout << enemy->Name + " Died" << endl;
				enemies.remove(enemy);

				Strenght += 2; //add playerstrengt from killing enemy
				Hp += 5; //add hp from killing enemy
				cout << "\n---From defeating enemy---" << endl;
				cout << "Player gains " << 2 << " strenght" << endl;
				cout << "Player gains " << 5 << " hp" << endl;
																	
				_getch();
				break;
			}
			}
			_getch();
			break;
		}
			
		
	}

	//Is next position on the map? Also don't move to next position if there was a collision with enemy
	if (nextPosX >= 0 && nextPosX < mapWidth && nextPosY >= 0 && nextPosY < mapHeight && !collisionWithEnemy) {
		MapPosX = nextPosX;
		MapPosY = nextPosY;

	}
}


//Destructor implementation
Player::~Player()
{
}
