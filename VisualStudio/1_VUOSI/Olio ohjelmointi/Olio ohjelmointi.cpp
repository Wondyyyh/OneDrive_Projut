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

	string  väri;
	string  merkki;
	string  malli;
	int  moottoritilavuus;
	int vuosimalli;
	int mittarílukema;
	int   id;
};
class Elokuva
{
public:

	string  Nimi;
	string  Ohjaaja;
	string	päänäyttelijä;
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
	int oppilasmärä;
	int osp;
	int   id;
};

void teht1()
{
	Auto auto1;
	Elokuva elokuva1;
	Kurssi kurssi1;

	//määritä auto1
	auto1.väri = "Beige";
	auto1.merkki = "Mercedes Benz";
	auto1.malli = "C180 Kompressor";
	auto1.moottoritilavuus = 1996;
	auto1.vuosimalli = 2006;
	auto1.mittarílukema = 230000;
	//määritä elokuva1
	elokuva1.Nimi = "The Wolf of Wall Street";
	elokuva1.Ohjaaja = "Martin Scorsese";
	elokuva1.päänäyttelijä = "Leonardo DiCaprio";
	elokuva1.genre = "Draama";
	elokuva1.julkaisuvuosi = 2013;
	elokuva1.pituus = 180;
	//määritä kurssi1
	kurssi1.kurssinimi = "Olio-ohjelmmointi";
	kurssi1.opettaja = "Pekka Vilpponen";
	kurssi1.lukukausi = "Kevät";
	kurssi1.oppilasmärä = 38;
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

//tärkeät muuttujat
const int x = 3; //oppilasmäärä
student library[x];

void teht2()
{
	//loopataan oppilasmäärällä eli 3
	for (int i = 0; i < x; i++)
	{
		//kaikki tiedot kysytään yksitellen
		//ja sijoitetaan arrayhin indexin mukaan
		cout << "\nSyötä oppilaan numero " << i + 1 << " tiedot:" << endl;
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
		//tulostetaan syötetyt tiedot listaksi rivi kerrallaan
		//setfill ja setw lisää "tyhjiä" väliin paremman visuaalisuuden vuoksi
		cout << "Name: " << setfill(' ') << setw(7) << left << library[i].name
			<< " | Age: " << setfill(' ') << setw(5) << left << library[i].age
			<< " | Student number: " << library[i].studentnumber << endl;
	}
}

void teht4_1()
{
	list<string> names = { "Arska", "Heikki", "Pertsa", "Maija", "Seppo", "Tiia", "Hanna", "Minna", "Fiia", "Ida" };
	list<string>::iterator it;
	cout << "\n*** Nimet aakkosjärjestykseen ***\n" << endl;
	//tulostetaan asetettu string lista loopilla
	for (it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}

	cout << "\nNames shorted by alphabets:" << endl;
	names.sort(); //järjestää akkosittain listan

	//tulostetaan järjestetty lista nyt uudestaan
	for (it = names.begin(); it != names.end(); it++) {
		cout << *it << endl;
	}

}
void teht4_2()
{
	bool looping = true; // loopin päällä pitävä boolean

	char input; //painettu näppäin
	string givenName; //syötetty nimi
	list<string> names = {}; //lista johon tiedot tulee
	list<string>::iterator it;

	while (looping)
	{
		// Alkutekstit
		cout << "\n\nValitse toiminto:" << endl;
		cout << "L - Lisää nimi" << endl;
		cout << "P - Poista nimi" << endl;
		cout << "Q - Sammuta ohjelma" << endl;

		cin >> input;

		// Nimen syöttäminen tähän
		if (input == 'l' || input == 'L')
		{
			cout << "Anna nimi: ";
			cin >> givenName;
			names.insert(names.end(), 1, givenName); // lisätään uusi arvo listan loppuun, (yksi kopio)
		}

		// Nimen poistaminen tähän
		else if (input == 'P' || input == 'p')
		{
			cout << "Anna nimi: ";
			string removeName; //muuttuja syötettä varten
			cin >> removeName;

			// etsitään listasta (begin - end väliltä -> removeName) 
			// ja asetetaan it pointteri löydetyn kohdalle
			it = find(names.begin(), names.end(), removeName);

			//jos pointteri ei ole lopussa se löysi nimen ja if on samalla tosi
			if (it != names.end())
			{
				names.erase(it); //poistetaan listasta itemi jätetyn pointerin kohdalta
				cout << "Poistettiin: " << removeName << endl;
			}

			// muuten tulostetaan "Not found"
			else
			{
				cout << "Nimeä " << removeName << " ei löytynyt, katso tästä lista:" << endl;
			}
		}

		// lopeta loop ja osion toistaminen
		if (input == 'Q' || input == 'q')
		{
			break;
			looping = false;
		}

		// lopuksi tulostetaan koko lista
		int i = 0; //käytetään indeksin laskemiseen
		for (it = names.begin(); it != names.end(); it++, i++) //loopataan lista läpi
		{
			// jos indexi > 0, lisätään extrana pilkku ja väli siistimään listaa
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

	//opiskelijoiden lisäystä varten
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
	//looppaa kaikki opiskelijat läpi
	for (auto& item : students)
	{
		//tulostetaan opiskelijoiden tiedot järjestyksessä
		cout << item->ID << " | " << item->StudentNumber << " | " << item->FirstName
			<< " | " << item->LastName << endl;

	}
	cout << endl;
}
void AddStudent(list<unique_ptr<Student>>& students)
{
	string firstName, lastName;
	int iD, studentNumber;

	//Syötetään nimi
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

	//lisätään listan perälle "Student" syötetyillä tiedoilla
	students.push_back(make_unique<Student>(firstName, lastName, studentNumber, iD));
}
void DeleteStudent(list<unique_ptr<Student>>& students)
{
	//inputtia varten
	int givenID;
	cout << "Syötä ID: ";
	cin >> givenID;

	bool found = false;
	//loopataan kaikki opiskelijat läpi
	for (auto& item : students)
	{
		//jos syötetty id vastaa loopissa tällähetkellä olevan opiskelijan idtä
		if (givenID == item->ID) {
			cout << "Poistettiin: " << item->FirstName << " " << item->LastName;
			//opiskelija poistetaan listalta
			students.erase(remove(students.begin(), students.end(), item), students.end());
			found = true;
			break;
		}
	}
	//jos haluttua idtä ei löytynyt tulostetaan teksti siitä
	if (!found) {
		cout << "Opiskelijaa ID:llä " << givenID << " ei löytynyt" << endl;
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

	//looppi opiskelijoiden listan läpi
	for (auto& item : students) 
	{
		//yhdistetään etu ja sukunimi kokonimeksi
		//jotta niistä voidaan etsiä samaan aikaan haluttua sanaa
		string fullName = item->FirstName + " " + item->LastName;
		//tämäkin isoiksi kirjaimiksi poistamaan casesensitive
		transform(fullName.begin(), fullName.end(), fullName.begin(), ::toupper);

		//testataan löytyykö haluttu sana juuri luodusta kokonimestä
		if (fullName.find(input) != string::npos) 
		{
			//lisätään löytyneiden määrään
			//ja tulostetaan jo löytynyt opiskelija
			ammount++;
			cout << item->ID << " | " << item->StudentNumber << " | " << item->FirstName
				<< " | " << item->LastName << endl;

		}
	}
	//lopuksi tieto montako opiskelijaa löytyi tai ei löytynyt
	cout << "Hakusanalla löytyneet opiskelijat " << ammount << " kpl" << endl << endl;
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
			<< "L - Lisää nimi\n"
			<< "P - Poista (ID)\n"
			<< "H - Haku (nimi)" << endl;

		//kysytään input
		cin >> input;
		//nostetaan isoiksi kirjaimiksi
		 input = toupper(input);

		if (input == 'L') 
		{

			//Lisää käyttäjän antama opiskelija listaan
			AddStudent(students);
			//Tulosta mitä listassa on
			PrintStudents(students);
		}
		if (input == 'P') 
		{
			//Poistetaan haluttu opiskelija
			DeleteStudent(students);
			//Tulosta mitä listassa on
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
	setlocale(LC_ALL, "fi_FI"); //ääkköstimet
	cout << "*** Database Program ***" << endl; //alkuteksti
	teht1();
	teht2();
	teht4_1();
	teht4_2();
	teht6_1();
}

