#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Character
{
public:

	string Name;
	int HP;
	float MoveSpeed;

	Character(string name, int hp, float moveSpeed)
	{
		Name = name;
		HP = hp;
		MoveSpeed = moveSpeed;
	}
};

int main()
{
	string name;
	int hp;
	float movespeed;

	//1. pyydä käyttäjältä tiedot uuden hahmo objektin luomista varten
	cout << "Give player Name: ";
	cin >> name;
	cout << "Give player Hp: ";
	cin >> hp;


	while (cin.fail()) //"catch" a fail bit
	{
		//clear and ignore input stream:
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//try again:
		cout << "Bad entry.  Enter a valid integer number: ";
		cin >> hp;
	}


	//2. Tee inputin validointi Name ja HP -syötteille
	while (true)
	{
		try
		{
			cout << "Enter a number: ";
			cin.exceptions(ifstream::failbit); // may throw exception            
			cin >> hp;
			break;
		}
		catch (const ios_base::failure& fail)
		{
			//show exception
			cout << fail.what() << '\n';
			//clear and ignore input stream:
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//try again:
			cout << "Bad entry.  Enter a valid integer number." << endl;
		}
	}
	
	
	//3. Hahmon MoveSpeediksi ei voi antaa negatiivista arvoa, joten
	
	cout << "Give player MoveSpeed: ";
	cin >> movespeed;

	
	//	 rakenna (tarkoituksella turhan monimutkaisesti) siihen try-catch -lohko,
	//   jossa kokeillaan antoiko käyttäjä negatiivisen arvon ja jos antoi,
	//	 throwataan ja catchataan siitä virheilmoitus. Voit myös validoida tämän inputin.
	//4. Tee hahmosta uusi instanssi ja tulosta hahmon tiedot. Voit parannella myös luokkaa.

	Character Player(name, hp, movespeed);
	cout << "\n Done";

}