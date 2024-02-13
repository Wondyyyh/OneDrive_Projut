// DesicionMaking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
void teht1();
void teht2();
void teht3();
void teht4();
void teht5();

int main()
{
	setlocale(LC_ALL, "fi_FI");
	//teht1();
	//teht2();
	teht3();
	teht4();
	teht5();
}

void teht1() {

	int x, y;
	cout << "Kirjoita kaksi numeroa: ";
	cin >> x >> y;
	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " - " << y << " = " << x - y << endl;
	cout << y << " - " << x << " = " << y - x << endl;
	cout << x << " * " << y << " = " << x * y << endl;
	cout << x << " / " << y << " = " << x / y << endl;
	cout << y << " / " << x << " = " << y / x << endl;
	cout << x << " % " << y << " = " << x % y << endl;
	cout << y << " % " << x << " = " << y % x << endl;

}

void teht2() {

	float days;
	int vuodet, viikot, päivät;

	cout << "Montako päivää? ";
	cin >> days;
	vuodet = days / 365;
	viikot = (days - (vuodet * 365)) / 7;
	päivät = days - (vuodet * 365);
	päivät = päivät % 7;
	
	cout << "Vuosia: " << vuodet << endl;
	cout << "Viikkoja: " << viikot << endl;
	cout << "Päiviä: " << päivät  << endl;
}

void teht3() {

	float sec;
	int hours, mins, secs;
	cout << "Montako sekunttia? ";
	cin >> sec;
	hours = sec / 3600;
	mins = (sec - (hours * 3600)) / 60;
	secs = sec - (hours * 360);
	secs = secs % 60;

	cout << "Tunteja: " << hours << endl;
	cout << "Minuuttia: " << mins << endl;
	cout << "Sekunttia: " << secs << endl;

}

void teht4() {

	int pisteet;
	cout << "Koe pisteet: ";
	cin >> pisteet;
	if (pisteet >= 90)
	{
		cout << "Arvosanasi on: 5\n";
	}
	else if (pisteet >= 80) {
		cout << "Arvosanasi on: 4\n";
	}
	else if (pisteet >= 70) {
		cout << "Arvosanasi on: 3\n";
	}
	else if (pisteet >= 60) {
		cout << "Arvosanasi on: 2\n";
	}
	else if (pisteet >= 50) {
		cout << "Arvosanasi on: 1\n";
	}
	else {
		cout << "Arvosanasi on: 0\n";
	}
}

void teht5() {
	float money, sum;
	int boys, girls, leski;
	string KE;
	cout << "Perinnön määrä rupioina: ";
	cin >> money;
	cout << "Montako poikaa? ";
	cin >> boys;
	cout << "Montako tyttöä? ";
	cin >> girls;
	cout << "Onko leski elossa? (K tai E): ";
	cin >> KE;
	if (KE == "k" || KE == "K") {
		leski = 1;
	}
	else {
		leski = 0;
	}
	sum = money / (boys + girls + leski);
	cout << "Perintösi on: " << sum << " rupionia" << endl;
}