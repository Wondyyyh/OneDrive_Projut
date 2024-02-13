//Ohjelmointiprojekti - Sillanpaa Janne

#include <iostream>
#include <string>
//conio tarvitaan getch inputteja varten
#include <conio.h>

//t‰rke‰!!
using namespace std;

void osio1();
void osio2();
void osio3();
void osio4();
void osio5();
void help();
void osio6();
void osio7();

char input;
// menu = extra s‰‰tˆ‰ siistim‰‰n p‰‰valikon looppausta
bool menu = true;

void main()
{
	//‰‰kkˆstimet
	setlocale(LC_ALL, "fi_FI");
	//n‰ytt‰‰ ohjelmointiprojektin alussa Projekti ja nimitiedot
	cout << "Ohjelmointiprojekti - Janne Sillanp‰‰\n";
	cout << "--------------------------------------\n";

	//while loop pit‰‰ sovelluksen auki kunnes q inputilla rikotaan looppaus ja ohjelma sulkeutuu
	while (true) {

		osio4();
		menu = true;
		input = _getch();

		if (input == '1') {
			osio1();
		}
		else if (input == '2') {
			osio2();
		}
		else if (input == '3') {
			osio3();
		}
		else if (input == '4') {
			osio5();
		}
		else if (input == 'q') {
			break;
		}
		else if (input == 'h') {
			help();
		}
		else if (input == '5') {
			osio6();
		}
		else if (input == '6') {
			osio7();
		}
		else {
			menu = false;
		}
	}

}
void help() {
	char x;
	cout << "\nWhat you want me to do?? Print same text twice so you can read it again??\n" << endl;
	cout << "Press R when you feel helped and want to go back\n";
	x = _getch();
	if (x == 'r' || x == 'R')
	{
		//we don't need anything here ;)
	}


}
void osio1() {

	//osio1 kysyt‰‰n tietoja yksitellen, ker‰t‰‰n ne ja lopuksi printataan kaikki syˆtetyt tiedot
	string name;
	int age, studentnumber;
	float height, weight;

	cout << "\nName: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "Studentnumber: ";
	cin >> studentnumber;
	cout << "Height: ";
	cin >> height;
	cout << "Weight: ";
	cin >> weight;

	cout << "\n\n" << "Antamasi tiedot: \n";
	cout << "\nName: " << name << "\nAge: " << age << "\nStudentnumber: " << studentnumber << "\nHeight: "
		<< height << "\nWeight: " << weight << endl;

}

void osio2() {

	//osio2 kysyt‰‰n tukikuukaudet ja tuen m‰‰r‰ jonka j‰lkeen ne kerrotaan yhteen jolloin saadaan vuosittaisten tulojen m‰‰r‰
	int months;
	float tuki, Sum;
	cout << "\nMoneltako kuukaudelta saat opintotukea? ";
	cin >> months;
	cout << "Paljonko opintotukesi on kuukaudessa? ";
	cin >> tuki;
	Sum = months * tuki;
	cout << "Opintotuen m‰‰r‰ on " << Sum << " vuodessa." << endl;


}
void exec1();
void exec2();
void osio3()
{
	//osio 3 on kaksi eri toimintoa, jotka tekev‰t eri asioita ja t‰ss‰ valitaan kumpi halutaan suorittaa, omalla pikku lis‰s‰‰dˆll‰ tietenkin
	cout << "\nValitse kumpaa haluat k‰ytt‰‰\n";
	cout << "------------------------------\n"
		<< "A - Arvosanakone\n" << "D - Distance Converter\n";
	//getch ottaa inputin huomaamattomasti tulostamatta sit‰ konsoliin ja ilman enteri‰, joka oli mielest‰ni hyvin ruman n‰kˆist‰ ja kˆmpelˆ‰
	//ja string muuttujaa siksi, koska aluksi en saanut char:ia toimimaan kun en tiennyt ett‰ se k‰ytt‰‰ '''' n‰it‰ merkkej‰ "" n‰iden sijaan
	string x;
	x = _getch();
	if (x == "A" || x == "a")
	{
		exec1();
	}
	else if (x == "D" || x == "d")
	{
		exec2();
	}

}

void exec1() {

	//ensimm‰isess‰ osassa kysyt‰‰n pisteet, jotka sen j‰lkeen annetaan arvosanana 0-5 if lausekkeilla
	cout << "\n\n*** Pisteet arvosanoiksi ***\n\n";

	int pisteet;
	cout << "Anna kokeen pisteet: ";
	cin >> pisteet;
	if (pisteet == 100)
	{
		cout << "Onneksi olkoon sait t‰ydet pisteet!\n";
	}
	else if (pisteet >= 90) {
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

void exec2() {

	//toisesa osassa kysyt‰‰n kilometrim‰‰r‰, joka muutetaan perus laskutoimituksella maileiksi tai merimaileiksi halutun inputin mukaan
	float km, mile, merimile;
	cout << "\n\n*** Distance Converter ***\n\n";
	cout << "Give distance in kilometers: ";
	cin >> km;
	mile = km * 1000 / 1609;
	merimile = km * 1000 / 1852;
	cout << "------------------------------\n";
	cout << "M - Convert to miles\n" << "N - Conver to nautical miles\n";

	//t‰ss‰ sama getch taas siistim‰‰n ohjelmaa :)
	string key;
	key = _getch();
	if (key == "M" || key == "m") {
		cout << "The disctance in miles: " << mile << endl;
	}
	else if (key == "n" || key == "N") {
		cout << "The disctance in nautical miles: " << merimile << endl;
	}

}

void osio4() {

	//t‰ss‰ se menu nyt sitten on t‰ydess‰ toiminnassa
	if (menu) {
		//valikkoteksti joka tuodaan aina main function alussa n‰kyville
		cout << "\n---Main Menu---" << endl;
		cout << "\n1. User Information" << endl;
		cout << "2. Study grants" << endl;
		cout << "3. Convert score and miles" << endl;
		cout << "4. Prime numbers" << endl;
		cout << "5. Viikkoteht‰v‰ 5" << endl;
		cout << "H - Help" << endl;
		cout << "Q - Quit" << endl;
	}
}

void osio5() {

	//t‰ss‰ osiossa otetaan k‰ytt‰j‰n syˆtt‰m‰ luku ja testataan sit‰ looppaamalla kaikki mahdolliset kertotaulut paitsi 0,1 ja itsens‰ l‰pi
	int given, test;
	cout << "\nAnna luku tarkistaaksesi onko se alkuluku: ";
	cin >> given;
	bool jaollinen = false;

	//jos joku kokonais luku 2-(given-1) tuo jakoj‰‰nnˆksen 0 eli luku on t‰ll‰ suoraa jaettavissa looppi rikotanaan ja annetaan 
	//true arvon booleaniin. Muuten kelataan loopin l‰pi ja boolean pysyy falsena.
	for (int x = 2; x < given; x++) {

		test = given % x;
		if (test == 0) {
			jaollinen = true;
			break;
		}


	}
	//nyt verrataan oliko booleani asetettu todeksi vai ei ja sit‰ hyˆdynt‰en tulostetaan oikea vastaus
	if (jaollinen == true) {

		cout << "\nEI!! Luku " << given << " ei ole alkuluku\n";

	}
	else {
		cout << "\nKYLLƒ!! Luku " << given << " on alkuluku\n";
	}
	//t‰m‰n osion kanssa tappelin hetken aikaa mutta isoimpana haasteena saattoi olla omat cout lausekkeet, jotka olivat aluksi liian
	//samann‰kˆisi‰ kesken‰‰n ja v‰syneen‰ pohdin miksei mik‰‰n toimi, mutta kyll‰ se siit‰ parilla huutomerkill‰ tokeni
}
void osio6() {

	string input;
	int count = 0, luku = 0;
	cout << "\nAnna lause: ";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
		{
			count++;
		}
	}

	cout << "Sanojen m‰‰r‰ lauseessa on: " << count + 1 << endl;
	cout << "Lauseessa on " << input.length() << " merkki‰" << endl;

	if (input.find(",") != string::npos) {

		for (int i = 0; i < input.length(); i++) {

			if (input[i] == ',') {

				luku++;

			}



		}
		cout << "HOLD UP!!! Kirjoitit sittenkin virkkeen, jossa on " << luku + 1 << " lausetta" << endl;
	}
	else
	{
		cout << "Lause on p‰‰lause." << endl;
	}
}
//lopputulema t‰h‰n menness‰: helppoa ja kivaa niin kauan kun ei ole yliv‰synyt..
//tuntiteht‰v‰t kun teki kaikki ajatuksella, niin osasi niiden pohjalta n‰pp‰r‰sti toteuttaa viikkoteht‰v‰tkin mutkitta


void rivitys();
string paikat[10][20];
for (int i = 0; i <= size(paikat); i++) {

	

}

void osio7() {

	int input = 0, input2 = 0;
	cout << "\nROW SEAT" << endl;
	rivitys();
	cout << "\nReserve a seat (give a row and seat numebr separated with space): ";
	cin >> input, input2;
	paikat[input-1][input2-1] = "XX";
	rivitys();
}

void rivitys() {

	for (int i = 0; i < size(paikat); i++) {


		if (i < 9) {
			cout << "0" << i + 1 << "  ";
		}
		else {
			cout << i + 1 << "  ";
		}

		for (int i = 0; i < size(*paikat); i++) {

			cout << paikat[i] + 1 << " ";

		}
		cout << endl;

	}



}