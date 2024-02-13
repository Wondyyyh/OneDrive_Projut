// Olio ohjelmointi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <iterator> // <-- iterators
#include <algorithm> // <-- sort ja reverse erilliset funktiot
#include <list> // <-- list
#include <vector> // <-- vector

using namespace std;


class Auto
{
public:

	string  v�ri;
	string  merkki;
	string  malli;
	int  moottoritilavuus;
	int vuosimalli;
	int mittar�lukema;
	int   id;
};
class Elokuva
{
public:

	string  Nimi;
	string  Ohjaaja;
	string	p��n�yttelij�;
	string  genre;
	int julkaisuvuosi;
	int pituus;
	int   id;
};
class Kurssi
{
public:

	string  kurssinimi;
	string  opettaja;
	string  lukukausi;
	int oppilasm�r�;
	int osp;
	int   id;
};

void teht1()
{
	Auto auto1;
	Elokuva elokuva1;
	Kurssi kurssi1;

	//m��rit� auto1
	auto1.v�ri = "Beige";
	auto1.merkki = "Mercedes Benz";
	auto1.malli = "C180 Kompressor";
	auto1.moottoritilavuus = 1996;
	auto1.vuosimalli = 2006;
	auto1.mittar�lukema = 230000;
	//m��rit� elokuva1
	elokuva1.Nimi = "The Wolf of Wall Street";
	elokuva1.Ohjaaja = "Martin Scorsese";
	elokuva1.p��n�yttelij� = "Leonardo DiCaprio";
	elokuva1.genre = "Draama";
	elokuva1.julkaisuvuosi = 2013;
	elokuva1.pituus = 180;
	//m��rit� kurssi1
	kurssi1.kurssinimi = "Olio-ohjelmmointi";
	kurssi1.opettaja = "Pekka Vilpponen";
	kurssi1.lukukausi = "Kev�t";
	kurssi1.oppilasm�r� = 38;
	kurssi1.osp = 5;

}

//oppilas "luokka"
class student
{
public:
	string name;
	int age;
	string studentnumber;
};

//t�rke�t muuttujat
const int x = 3; //oppilasm��r�
student library[x];

void teht2()
{
	//loopataan oppilasm��r�ll� eli 3
	for (int i = 0; i < x; i++)
	{
		//kaikki tiedot kysyt��n yksitellen
		//ja sijoitetaan arrayhin indexin mukaan
		cout << "\nSy�t� oppilaan numero " << i + 1 << " tiedot:" << endl;
		cout << "Name: ";
		cin >> library[i].name;
		cout << "Age: ";
		cin >> library[i].age;
		cout << "StudentNumber: ";
		cin >> library[i].studentnumber;
	}
	cout << "\n--- STUDENTS IN DATABASE ---\n" << endl;
	for (int i = 0; i < x; i++)
	{
		//tulostetaan sy�tetyt tiedot listaksi rivi kerrallaan
		//setfill ja setw lis�� "tyhji�" v�liin paremman visuaalisuuden vuoksi
		cout << "Name: " << setfill(' ') << setw(7) << left << library[i].name
			<< " | Age: " << setfill(' ') << setw(5) << left << library[i].age
			<< " | Student number: " << library[i].studentnumber << endl;
	}
}

void teht4_1()
{
	list<string> names = { "Arska", "Heikki", "Pertsa", "Maija", "Seppo", "Tiia", "Hanna", "Minna", "Fiia", "Ida" };
	list<string>::iterator it;
	cout << "\n*** Nimet aakkosj�rjestykseen ***\n" << endl;
	//tulostetaan asetettu string lista loopilla
	for (it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}

	cout << "\nNames shorted by alphabets:" << endl;
	names.sort(); //j�rjest�� akkosittain listan

	//tulostetaan j�rjestetty lista nyt uudestaan
	for (it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}

}
void teht4_2()
{
	bool looping = true; // loopin p��ll� pit�v� boolean

	char input; //painettu n�pp�in
	string givenName; //sy�tetty nimi
	list<string> names = {}; //lista johon tiedot tulee
	list<string>::iterator it;

	while (looping)
	{
		// Alkutekstit
		cout << "\n\nValitse toiminto:" << endl;
		cout << "L - Lis�� nimi" << endl;
		cout << "P - Poista nimi" << endl;
		cout << "Q - Sammuta ohjelma" << endl;

		cin >> input;

		// Nimen sy�tt�minen t�h�n
		if (input == 'l' || input == 'L')
		{
			cout << "Anna nimi: ";
			cin >> givenName;
			names.insert(names.end(), 1, givenName); // lis�t��n uusi arvo listan loppuun, (yksi kopio)
		}

		// Nimen poistaminen t�h�n
		else if (input == 'P' || input == 'p')
		{
			cout << "Anna nimi: ";
			string removeName; //muuttuja sy�tett� varten
			cin >> removeName;

			// etsit��n listasta (begin - end v�lilt� -> removeName) 
			// ja asetetaan it pointteri l�ydetyn kohdalle
			it = find(names.begin(), names.end(), removeName);

			//jos pointteri ei ole lopussa se l�ysi nimen ja if on samalla tosi
			if (it != names.end())
			{
				names.erase(it); //poistetaan listasta itemi j�tetyn pointerin kohdalta
				cout << "Poistettiin: " << removeName << endl;
			}

			// muuten tulostetaan "Not found"
			else
			{
				cout << "Nime� " << removeName << " ei l�ytynyt, katso t�st� lista:" << endl;
			}
		}

		// lopeta loop ja osion toistaminen
		if (input == 'Q' || input == 'q')
		{
			break;
			looping = false;
		}

		// lopuksi tulostetaan koko lista
		int i = 0; //k�ytet��n indeksin laskemiseen
		for (it = names.begin(); it != names.end(); it++, i++) //loopataan lista l�pi
		{
			// jos indexi > 0, lis�t��n extrana pilkku ja v�li siistim��n listaa
			if (i > 0) 
			{
				cout << ", " << *it;
			}
			else 
			{
				cout << endl << *it;
			}
		}
	}


}
//Luodaan public luokka
class Student 
{
public:
	int ID, StudentNumber;
	string FirstName, LastName;

	//opiskelijoiden lis�yst� varten
	Student(string firstName, string lastName, int studentNumber, int iD)
	{
		FirstName = firstName;
		LastName = lastName;
		StudentNumber = studentNumber;
		ID = iD;
	}

};
//tulostaa listan opiskelijoista
void PrintStudents(list<unique_ptr<Student>>& students)
{
	cout << "\n*** Students ***" << endl;
	//looppaa kaikki opiskelijat l�pi
	for (auto& item : students)
	{
		//tulostetaan opiskelijoiden tiedot j�rjestyksess�
		cout << item->ID << " | " << item->StudentNumber << " | " << item->FirstName
			<< " | " << item->LastName << endl;

	}
	cout << endl;
}
void AddStudent(list<unique_ptr<Student>>& students)
{
	string firstName, lastName;
	int iD, studentNumber;

	//Sy�tet��n nimi
	cout << "\nAnna etunimi: ";
	cin >> firstName;
	//sukunimi
	cout << "Anna sukunimi: ";
	cin >> lastName;
	//opiskelijanumero
	cout << "Anna opiskelijanumero: ";
	cin >> studentNumber;
	//ja id
	cout << "Anna ID: ";
	cin >> iD;

	//lis�t��n listan per�lle "Student" sy�tetyill� tiedoilla
	students.push_back(make_unique<Student>(firstName, lastName, studentNumber, iD));
}
void DeleteStudent(list<unique_ptr<Student>>& students)
{
	//inputtia varten
	int givenID;
	cout << "Sy�t� ID: ";
	cin >> givenID;

	bool found = false;
	//loopataan kaikki opiskelijat l�pi
	for (auto& item : students)
	{
		//jos sy�tetty id vastaa loopissa t�ll�hetkell� olevan opiskelijan idt�
		if (givenID == item->ID) {
			cout << "Poistettiin: " << item->FirstName << " " << item->LastName;
			//opiskelija poistetaan listalta
			students.erase(remove(students.begin(), students.end(), item), students.end());
			found = true;
			break;
		}
	}
	//jos haluttua idt� ei l�ytynyt tulostetaan teksti siit�
	if (!found) {
		cout << "Opiskelijaa ID:ll� " << givenID << " ei l�ytynyt" << endl;
	}

}
void FindStudent(list<unique_ptr<Student>>& students) 
{
		//muuttujat
		string input;
		int ammount = 0;
		//otetaan input
		cout << "\nAnna nimi: ";
		cin >> input;
		//muutetaan isoiksi kirjaimiksi
		transform(input.begin(), input.end(), input.begin(), ::toupper);

	//looppi opiskelijoiden listan l�pi
	for (auto& item : students) 
	{
		//yhdistet��n etu ja sukunimi kokonimeksi
		//jotta niist� voidaan etsi� samaan aikaan haluttua sanaa
		string fullName = item->FirstName + " " + item->LastName;
		//t�m�kin isoiksi kirjaimiksi poistamaan casesensitive
		transform(fullName.begin(), fullName.end(), fullName.begin(), ::toupper);

		//testataan l�ytyyk� haluttu sana juuri luodusta kokonimest�
		if (fullName.find(input) != string::npos) 
		{
			//lis�t��n l�ytyneiden m��r��n
			//ja tulostetaan jo l�ytynyt opiskelija
			ammount++;
			cout << item->ID << " | " << item->StudentNumber << " | " << item->FirstName
				<< " | " << item->LastName << endl;

		}
	}
	//lopuksi tieto montako opiskelijaa l�ytyi tai ei l�ytynyt
	cout << "Hakusanalla l�ytyneet opiskelijat " << ammount << " kpl" << endl << endl;
}
void teht6_1() 
{
	//luodaa opiskelija lista
	list<unique_ptr<Student>> students;
	//menu input
	char input;
	while (true)
	{
		//Main menu ohje tekstit
		cout << "Valitse toiminto:\n"
			<< "L - Lis�� nimi\n"
			<< "P - Poista (ID)\n"
			<< "H - Haku (nimi)" << endl;

		//kysyt��n input
		cin >> input;
		//nostetaan isoiksi kirjaimiksi
		 input = toupper(input);

		if (input == 'L') 
		{

			//Lis�� k�ytt�j�n antama opiskelija listaan
			AddStudent(students);
			//Tulosta mit� listassa on
			PrintStudents(students);
		}
		if (input == 'P') 
		{
			//Poistetaan haluttu opiskelija
			DeleteStudent(students);
			//Tulosta mit� listassa on
			PrintStudents(students);
		}
		if (input == 'H') 
		{
			//opiskelija hakutoiminto
			FindStudent(students);

		}
		

	}

}

int main() //Main Funktio jossa kutsutaan muita funktioita
{
	setlocale(LC_ALL, "fi_FI"); //��kk�stimet
	cout << "*** Database Program ***" << endl; //alkuteksti
	teht1();
	teht2();
	teht4_1();
	teht4_2();
	teht6_1();
}

