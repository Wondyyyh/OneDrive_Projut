// Loops.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

void harkka1();

void teht1();
void teht2();
void teht3();
void teht4();
void teht5();
void teht61();
void teht62();
void teht63();
void teht64();
void teht71();
void teht72();
void teht73();
void teht74();
void teht81();
void teht82();
void teht83();
void teht84();
void teht85();
void teht86();
void teht87();
void teht88();
void teht89();
void teht90();
void teht91();
void teht121();
void teht122();


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "fi_FI");
	//teht1();
	//teht2();
	//teht3();
	//teht4();
	//teht5();
	//teht61();
	//teht62();
	//teht63();
	//teht64();
	//harkka1();
	//teht71();
	//teht72();
	//teht73();
	//teht74();
	//teht81();
	//teht82();
	//teht83();
	//teht84();
	//teht85();
	//teht86();
	//teht87();
	//teht88();
	//teht89();
	//teht90();
	//teht91();
	//teht121();
	teht122();
}

void teht1() {

	int luku = 0;
	int print = 0;

	cout << "Anna tasaluku (>1): ";
	cin >> luku;
	while (print < luku)
	{
		print++;
		cout << print << endl;
	}

}
void teht2() {

	int luku = 0;
	while (luku != 5) {

		cout << "Anna mik� tahansa luku paitsi 5: " << endl;
		cin >> luku;
		if (luku == 5) {
			cout << "Hei! Sinun ei pit�nyt antaa lukua 5" << endl;
			break;
		}
	}

}
void teht3() {
	int luku1 = 6;
	int print = 0;
	while (print <= luku1)
	{

		cout << "Luku on nyt: " << print << endl;
		print++;
		if (print == 3 || print == 5) {

			print++;
			continue;

		}

	}

}
void teht4() {

	int input;
	int chars = 0;
	cout << "Anna iso luku: ";
	cin >> input;
	while (input > 0)
	{
		input = input / 10;
		chars++;
	}
	cout << "Luvussa on " << chars << " merkki�" << endl;

}
void teht5() {

	int luku;
	float kerroin;
	float sum = 1;
	cout << "Anna maximi luku: ";
	cin >> luku;
	cout << "Anna kerroin: ";
	cin >> kerroin;
	while (sum < luku)
	{
		cout << sum << endl;
		sum = kerroin * sum;
	}
	cout << sum << endl;

}
void teht61()
{
	float palkka, raise, vuodet, sum = 0;
	cout << "Sy�t� palkkasi euroina: ";
	cin >> palkka;
	cout << "Sy�t� palkankorotuksen m��r�: ";
	cin >> raise;
	raise = raise / 100 + 1;
	cout << "Sy�t� ty�vuosien m��r�: ";
	cin >> vuodet;

	for (int x = 0; x < vuodet; x++) {

		sum = sum + (palkka * 12);
		palkka = palkka * raise;
		//cout << palkka << endl;

	}

	cout << "Tulet tienaamaan ty�urallasi " << sum << " euroa." << endl;

}
void teht62() {

	int luku, luku2 = 1;

	cout << "Sy�t� luku: ";
	cin >> luku;


	for (int x = 1; x <= luku;) {

		cout << setfill(' ') << setw(luku);


		for (int x = 0; x < luku2; x++) {

			cout << luku2 << " ";

		}

		cout << endl;
		luku--;
		luku2++;

	}

}
void teht63() {

	int xy, yx;
	cout << "Sy�t� ruudukon leveys: ";
	cin >> xy;
	cout << "Sy�t� ruudukon korkeus: ";
	cin >> yx;

	for (int y = 0; y < yx; y++) {

		for (int x = 0; x < xy; x++) {

			cout << "[" << x << ", " << y << "]";
		}

		cout << endl;

	}

}
void teht64() {

	string print = "";
	int numb;

	cout << "Sy�t� 7 numeroa (v�lilt� 1-40): \n";

	for (int x = 0; x < 7; x++)
	{

		cin >> numb;

		if (numb > 40) {
			cout << "Ei n�in!! 1-40!!!!" << endl;
			break;
		}
		else if (x < 6) {
			print = print + to_string(numb) + ",";
		}
		else {
			print = print + to_string(numb);
		}
	}
	cout << "Lottorivisi on: " << print << endl;
}
void harkka1()
{

	for (int y = 0; y < 10; y++) {

		for (int x = 0; x < 10; x++) {

			cout << "[" << y << ", " << x << "]";
		}

		cout << endl;

	}
}
void teht71() {

	int min, max;
	cout << "Sy�t� minimiarvo: ";
	cin >> min;
	cout << "Sy�t� maksimiarvo: ";
	cin >> max;

	int rnd = rand() % max + min;
	cout << "Arvottu luku: " << rnd << endl;

}
void teht72() {

	int age, rnd;
	cout << "Sy�t� ik�si: ";
	cin >> age;

	while (true) {

		rnd = rand() % age + 1;
		if (rnd == age) {

			cout << "L�ytyi!! Ik�si on: " << rnd << endl;
			false;
			break;

		}
		else {

			cout << "Olisitkohan s� " << rnd << "-vuotias" << endl;

		}
	}

}
void teht73() {

	int matka = 100, x, y;
	cout << "--- Navigaattori ---\n\nReitti Porvoo - Kotka\nMatka 100km\n" << endl;

	while (matka >= 0) {

		int guidenumb = rand() % 3;
		x = rand() % 20 + 1;
		y = rand() % 9999 + 1;

		if (guidenumb == 0) {

			cout << "Jatka suoraan " << x << " kilometri� tiell� " << y << endl;
			matka = matka - x;

		}
		else if (guidenumb == 1) {

			int numb = rand() % 3;
			if (numb == 0) {
				cout << "Poistu kiertoliittym�n ensimm�isest� liittym�st�\n";
			}
			else if (numb == 1) {
				cout << "Poistu kiertoliittym�n toisesta liittym�st�\n";
			}
			else
			{
				cout << "Poistu kiertoliittym�n kolmannesta liittym�st�\n";
			}

		}
		else
		{
			int numb = rand() % 2;

			if (numb == 0) {
				cout << "K��nny oikealle\n";
			}

			else (numb == 1); {
				cout << "K��nny vasemmalle\n";
			}


		}

		cout << "Matkaa j�ljell� " << matka << " km" << endl;

	}


}
void teht74() {

	int arvaus;
	string a = "Sininen";
	string b = "Punainen";
	string c = "Vihre�";
	string d = "Keltainen";
	string array[4] = { a,b,c,d };



	int x = rand() % 4 + 1;
	cout << "Arvaa mit� v�ri� ajattelen ?";
	while (true) {


		cout << "\n1 - Sininen\n2 - Punainen\n3 - Vihre�\n4 - Keltainen" << endl;
		cin >> arvaus;

		if (arvaus != x)
		{
			cout << "V��rin!! Ei ollut " << array[arvaus - 1] << ". Yrit� uudelleen" << endl;
		}
		else {
			cout << "Oikein, ajattelin " << array[arvaus - 1] << ", arvaa mit� v�ri� nyt ajattelen." << endl;
			x = rand() % 4 + 1;
		}

	}



}
void teht81() {

	float luku;
	cout << "Sy�t� desimaaliluku: ";
	cin >> luku;

	cout << "Luku py�ristettyn� yl�s: " << ceil(luku) << endl;
	cout << "Luku py�ristettyn� alas: " << floor(luku) << endl;

}
void teht82() {

	float luku, potenssi;
	cout << "Anna luku: ";
	cin >> luku;
	cout << "Potenssiin: ";
	cin >> potenssi;
	cout << luku << " potenssiin " << potenssi << " on: " << pow(luku, potenssi);
}
void teht83() {

	float alkupiste, loppupiste;
	cout << "Sy�t� aloituspiste: ";
	cin >> alkupiste;
	cout << "Sy�t� lopetuspiste: ";
	cin >> loppupiste;

	cout << "Et�isyys annetuiden pisteiden v�lill� on: " << fdimf(alkupiste, loppupiste) << endl;


}
void teht84() {

	float luku;
	cout << "Anna luku: ";
	cin >> luku;
	cout << "Luvun " << luku << "kuutiojuuri on: " << sqrtl(luku);
}
void teht85() {

	string input, toinen;
	cout << "Anna lause: ";
	getline(cin, input);
	cout << "Anna lause uudestaan: ";
	getline(cin, toinen);

	if (input.compare(toinen) == 0)
	{

		cout << "Lauseet ovat samat." << endl;

	}
	else
	{

		cout << "Ei!! Lauseet eiv�t vastaa toisiaan" << endl;

	}
}
void teht86() {

	string input;
	cout << "Anna lause: ";
	getline(cin, input);

	for (int spot = 0; spot < input.length(); spot++)
	{
		cout << input[spot] << endl;
	}

}
void teht87() {

	string input;
	cout << "Anna lause: ";
	getline(cin, input);

	if (input.length() > 10) {

		cout << "Lauseessa on enemm�n kuin 10 merkki�." << endl << "N�ytet��n 10 ensimm�ist� merkki�: "
			<< input.substr(0, 10) << endl;

	}
	else
	{
		cout << input << endl;
	}
}
void teht88() {

	string sana;

	string lause = "C++ on ohjelmointikieli, jonka Bjarne Stroustrup kehitti 1980-luvulla. \n"
		"Kieli on kehitetty C - kielest� lis��m�ll� siihen muun muassa olio - ohjelmointiin ja geneerisyyteen liittyvi� ominaisuuksia.\n"
		"C++ sis�lt�� muun muassa luokat, virtuaalisen moniperint�tuen, mallit(templates) ja poikkeukset.\n"
		"C++ perustuu C - kieleen siten, ettei kielt� ole suunniteltu uudelleen, vaan uusia ominaisuuksia on lis�tty.\n";
	cout << lause;
	cout << "Anna sana tekstist� sana: ";
	cin >> sana;
	size_t found = lause.rfind(sana);
	if (found != string::npos) {

		lause.replace(found, sana.length(), "[sensuroitu]");

	}
	cout << lause;

}
void teht89() {

	string input;
	while (input.length() < 8) {

		cout << "Anna k�ytt�j�nimi (v�hint��n 8 merkki�): ";
		cin >> input;

	}
	cout << "K�ytt�j�nimi *" << input << "* hyv�ksytty" << endl;
}
void teht90() {

	string juomat[] = { "1. Vesi", "2. Coca - cola", "3. Sprite", "4. Fanta", "5. KarhuIII" };
	int input = 0;
	for (int i = 0; i < 5; i++) {

		cout << juomat[i] << endl;

	}
	cout << "Valitse mink� juoman haluat(1 - 5)" << endl;
	cin >> input;
	cout << "Valitsit juoman: " << juomat[input-1] << endl;
}
void teht91() {

	int input = 0, current, min;
	int testi[] = {0,0,0,0,0,0,0,0,0,0};
	cout << "Sy�t� 10 luku v�lilt� 1-100" << endl;
	for (int i = 0; i < 10; i++) {

		cin >> input;
		if (input <= 100 && input > 0) {

			testi[i] = input;
			cout << "Added" << endl;

		}
		else {

			cout << "try again" << endl;
			i--;
		}
		
	}
	current = testi[0];
	for (int i = 0; i < 10; i++) {
		if (testi[i] > current) {

			current = testi[i];

		}
		

	}
	min = testi[0];
	for (int i = 0; i < 10; i++) {
		if (testi[i] < min) {

			min = testi[i];

		}


	}

	cout << "Suurin luku oli: " << current << endl;
	cout << "Pienin luku oli: " << min << endl;

}
void teht121() {

	char input;
	bool running = true;

	while (running) {

		cout << "Anna operaattori: ";
		cin >> input;

		switch (input)
		{

		case '+':
			cout << "Suoritetaan yhteenlasku." << endl;
			break;
		case '-':
			cout << "Suoritetaan miinuslasku." << endl;
			break;
		case '*':
			cout << "Suoritetaan kertolasku." << endl;
			break;
		case '/':
			cout << "Suoritetaan jakolasku." << endl;
			break;



		default:
			cout << "Tuntematon operaattori." << endl;
			break;
		}

	}
	


}



void teht122() {

	bool running = true;
	int input;
	enum suunnat { North = 8, East = 6, South = 2, West = 4 };

	
	while (running) {

		
		cout << "Move to direction with numpad: " << endl;
		cout << "8 - North" << endl;
		cout << "6 - East" << endl;
		cout << "2 - South" << endl;
		cout << "4 - West" << endl;
		cin >> input;
		if (input < 100 && input >= 0) {

			switch (input) {

			case North:
				cout << "You moved " << "North" << endl;
				break;
			case East:
				cout << "You moved " << "East" << endl;
				break;
			case South:
				cout << "You moved " << "South" << endl;
				break;
			case West:
				cout << "You moved " << "West" << endl;
				break;


			default:
				cout << "Error, bad input, quitting" << endl;
				break;
			}
		}
		else {
			cout << "Bad BOY!! You shouldn't have done that";
			break;
		}

		
		
		
	}

}
