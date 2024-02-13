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

		cout << "Anna mikä tahansa luku paitsi 5: " << endl;
		cin >> luku;
		if (luku == 5) {
			cout << "Hei! Sinun ei pitänyt antaa lukua 5" << endl;
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
	cout << "Luvussa on " << chars << " merkkiä" << endl;

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
	cout << "Syötä palkkasi euroina: ";
	cin >> palkka;
	cout << "Syötä palkankorotuksen määrä: ";
	cin >> raise;
	raise = raise / 100 + 1;
	cout << "Syötä työvuosien määrä: ";
	cin >> vuodet;

	for (int x = 0; x < vuodet; x++) {

		sum = sum + (palkka * 12);
		palkka = palkka * raise;
		//cout << palkka << endl;

	}

	cout << "Tulet tienaamaan työurallasi " << sum << " euroa." << endl;

}
void teht62() {

	int luku, luku2 = 1;

	cout << "Syötä luku: ";
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
	cout << "Syötä ruudukon leveys: ";
	cin >> xy;
	cout << "Syötä ruudukon korkeus: ";
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

	cout << "Syötä 7 numeroa (väliltä 1-40): \n";

	for (int x = 0; x < 7; x++)
	{

		cin >> numb;

		if (numb > 40) {
			cout << "Ei näin!! 1-40!!!!" << endl;
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
	cout << "Syötä minimiarvo: ";
	cin >> min;
	cout << "Syötä maksimiarvo: ";
	cin >> max;

	int rnd = rand() % max + min;
	cout << "Arvottu luku: " << rnd << endl;

}
void teht72() {

	int age, rnd;
	cout << "Syötä ikäsi: ";
	cin >> age;

	while (true) {

		rnd = rand() % age + 1;
		if (rnd == age) {

			cout << "Löytyi!! Ikäsi on: " << rnd << endl;
			false;
			break;

		}
		else {

			cout << "Olisitkohan sä " << rnd << "-vuotias" << endl;

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

			cout << "Jatka suoraan " << x << " kilometriä tiellä " << y << endl;
			matka = matka - x;

		}
		else if (guidenumb == 1) {

			int numb = rand() % 3;
			if (numb == 0) {
				cout << "Poistu kiertoliittymän ensimmäisestä liittymästä\n";
			}
			else if (numb == 1) {
				cout << "Poistu kiertoliittymän toisesta liittymästä\n";
			}
			else
			{
				cout << "Poistu kiertoliittymän kolmannesta liittymästä\n";
			}

		}
		else
		{
			int numb = rand() % 2;

			if (numb == 0) {
				cout << "Käänny oikealle\n";
			}

			else (numb == 1); {
				cout << "Käänny vasemmalle\n";
			}


		}

		cout << "Matkaa jäljellä " << matka << " km" << endl;

	}


}
void teht74() {

	int arvaus;
	string a = "Sininen";
	string b = "Punainen";
	string c = "Vihreä";
	string d = "Keltainen";
	string array[4] = { a,b,c,d };



	int x = rand() % 4 + 1;
	cout << "Arvaa mitä väriä ajattelen ?";
	while (true) {


		cout << "\n1 - Sininen\n2 - Punainen\n3 - Vihreä\n4 - Keltainen" << endl;
		cin >> arvaus;

		if (arvaus != x)
		{
			cout << "Väärin!! Ei ollut " << array[arvaus - 1] << ". Yritä uudelleen" << endl;
		}
		else {
			cout << "Oikein, ajattelin " << array[arvaus - 1] << ", arvaa mitä väriä nyt ajattelen." << endl;
			x = rand() % 4 + 1;
		}

	}



}
void teht81() {

	float luku;
	cout << "Syötä desimaaliluku: ";
	cin >> luku;

	cout << "Luku pyöristettynä ylös: " << ceil(luku) << endl;
	cout << "Luku pyöristettynä alas: " << floor(luku) << endl;

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
	cout << "Syötä aloituspiste: ";
	cin >> alkupiste;
	cout << "Syötä lopetuspiste: ";
	cin >> loppupiste;

	cout << "Etäisyys annetuiden pisteiden välillä on: " << fdimf(alkupiste, loppupiste) << endl;


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

		cout << "Ei!! Lauseet eivät vastaa toisiaan" << endl;

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

		cout << "Lauseessa on enemmän kuin 10 merkkiä." << endl << "Näytetään 10 ensimmäistä merkkiä: "
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
		"Kieli on kehitetty C - kielestä lisäämällä siihen muun muassa olio - ohjelmointiin ja geneerisyyteen liittyviä ominaisuuksia.\n"
		"C++ sisältää muun muassa luokat, virtuaalisen moniperintätuen, mallit(templates) ja poikkeukset.\n"
		"C++ perustuu C - kieleen siten, ettei kieltä ole suunniteltu uudelleen, vaan uusia ominaisuuksia on lisätty.\n";
	cout << lause;
	cout << "Anna sana tekstistä sana: ";
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

		cout << "Anna käyttäjänimi (vähintään 8 merkkiä): ";
		cin >> input;

	}
	cout << "Käyttäjänimi *" << input << "* hyväksytty" << endl;
}
void teht90() {

	string juomat[] = { "1. Vesi", "2. Coca - cola", "3. Sprite", "4. Fanta", "5. KarhuIII" };
	int input = 0;
	for (int i = 0; i < 5; i++) {

		cout << juomat[i] << endl;

	}
	cout << "Valitse minkä juoman haluat(1 - 5)" << endl;
	cin >> input;
	cout << "Valitsit juoman: " << juomat[input-1] << endl;
}
void teht91() {

	int input = 0, current, min;
	int testi[] = {0,0,0,0,0,0,0,0,0,0};
	cout << "Syötä 10 luku väliltä 1-100" << endl;
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
