// MoreTrash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


void teht1();
void teht2();
void teht3();
void teht4();
void teht5();
void jakojaannos();

void main()
{
	/*teht1();
	teht2();
	teht3();
	teht4();
	teht5();*/
	jakojaannos();

}

void teht1() {

	string sana1, sana2, sana3, sana4;
	sana1 = "My";
	sana2 = "own";
	sana3 = "hello";
	sana4 = "world";

	cout << sana1 << " " << sana2 << " " << sana3 << " " << sana4 << endl;

}

void teht2() {

	int intLuku;
	intLuku = 5;
	float floatLuku;
	floatLuku = 5.3;
	double doubleLuku = 10.1;
	float yhteensa;
	yhteensa = intLuku + floatLuku + doubleLuku;

	cout << yhteensa << endl;


}

void teht3() {

	int luku1, luku2, templuku;
	luku1 = 150;
	luku2 = 300;

	cout << "eka: " << luku1 << " toinen: " << luku2 << endl;

	templuku = luku1;
	luku1 = luku2;
	luku2 = templuku;

	cout << "eka: " << luku1 << " toinen: " << luku2 << endl << endl;

}


void teht4() {

	cout << "Haiku \"October's Gold\" By Paul Holmes" << endl << endl;
	cout << "Like crunchy cornflakes" << endl;
	cout << "Gold leaves rustle underfoot" << endl;
	cout << "Beauty in decay." << endl << endl;



}

void teht5() {

	cout << "If this text";
	cout << " appears on your display, ";
	cout << endl;
	cout << "you can pat yourself on" << " the back!" << endl;

}

void jakojaannos() {

	int Sum, Numb1;
	cout << "Input number: ";
	cin >> Numb1;
	Sum = Numb1 % 2;
	cout << Sum << endl;
	if (Sum == 0)
	{
		cout << "Parillinen";
	}
	else
	{
		cout << "Pariton";
	}

}


