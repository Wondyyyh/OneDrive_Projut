//Ohjelmointiprojekti - Sukunimi Etunimi

//Kirjoitetaan tähän vielä ohjeeksi, että korvaat kohdan "Sukunimi Etunimi" omalla nimelläsi
//ja poistat tiedostosta ohjeet, joita et enää tarvitse!

//Sisällytä iostream lähdekoodi (mm. cout ja cin -funktiot)
#include <iostream>
//clocale tarvitaan vain ääkkösiä varten
#include <clocale>
#include <cmath>
#include <string>

//Kerro, että käytämme namespacea std (C++ standard libraryn funktiot ovat tässä namespacessa)
using namespace std;

//C/C++ -ohjelmissa funktiot täytyy esitellä ennen niiden kutsumista 
void Osio1();
void Osio2();
void Osio3();
void osio4();


//Funktio main on ohjelman aloituspiste ja sen täytyy löytyä jokaisesta ohjelmasta:
int main()
{
    //Ääkköset UTF-8 merkistöllä
    setlocale(LC_ALL, "fi_FI.");

    //cout-funktiolla tulostetaan:
    cout << "Ohjelma alkaa:" << endl;


    //Funktioista voidaan kutsua toisia funktioita missä tahansa järjestyksessä.    
    //Osio1();
    //Ohjelma "hyppää" suorittamaan funktion ja palaa sen jälkeen seuraavalle riville
    //kohtaan, josta funktiota kutsuttiin. Kutsutaan seuraavaa funktiota:
    //Osio2();
    //Ja sen jälkeen vielä kolmatta
    //Osio3();
    //osio4();
	enum Options { Option1, Option2, Option3, Option4 };
	Options selectedOption = Option3;

	switch (selectedOption)
	{
	case Option1:
	case Option2:
		cout << "First options" << endl;
		break;
	case Option3:
	case Option4:
		cout << "Last options" << endl;
		break;
	default:
		cout << "Default option" << endl;
		break;
	}
    //Yleensä ohjelmat kirjoitetaan jatkuvasti käynnissä pysyviksi, se saadaan aikaiseksi silmukalla (loop).
    //Jos ohjelma ei looppaa, sen suoritus loppuu, kun main-funktiossa ei ole enää suoritettavia rivejä.
    //cout << "\nOhjelma loppuu ja sammuu automaattisesti." << endl;
}

//Kommentoi omin sanoin jokaisen osion toimintoa. Normaalisti funktion kommentit
//kertovat mitä funktio tekee, mitä muuttujia sinne viedään ja mitä se palauttaa...
void Osio1()
{
    cout << "Ensimmäisen osion lähdekoodi" << endl;
}

//...tällä kurssilla kirjoitetaan kommentteihin myös mikä oli käsiteltävä aihe ja mitä siitä
//opittiin, mitkä asiat jäivät vielä epäselviksi ja mitä opit aiheesta.
void Osio2()
{
    cout << "Toisen osion lähdekoodi" << endl;
}

void Osio3()
{
    cout << "Kolmannen osion lähdekoodi" << endl;
}

//Osio 3:n jälkeen jatka uusien funktioiden tekemistä saman mallin mukaisesti. Muista myös,
//että C/C++ -kielessä funktio täytyy esitellä ennen sen kutsumista (eli lisää esittely main funktion ylle).

void osio4() {

	char input;
	bool running = true;

	while (running)
	{
		cout << "e. Play game\n";
		cout << "/. Resume\n";
		cout << "3. Exit\n";
		cout << "Selection: ";

		cin >> input;

		switch (input) {
		case 'e':
			cout << "Starting new game..." << endl;
			break;
		case '/':
			cout << "Loading game..." << endl;
			break;
		case 3:
			cout << "Thank you for playing!" << endl;
			running = false; //<-- exit loop
			break;
		default:
			cout << "Error, bad input, quitting" << endl;
			break;
		}
	}

}