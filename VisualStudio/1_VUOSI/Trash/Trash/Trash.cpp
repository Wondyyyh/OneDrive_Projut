//Ohjelmointiprojekti - Sukunimi Etunimi

//Kirjoitetaan t�h�n viel� ohjeeksi, ett� korvaat kohdan "Sukunimi Etunimi" omalla nimell�si
//ja poistat tiedostosta ohjeet, joita et en�� tarvitse!

//Sis�llyt� iostream l�hdekoodi (mm. cout ja cin -funktiot)
#include <iostream>
//clocale tarvitaan vain ��kk�si� varten
#include <clocale>
#include <cmath>
#include <string>

//Kerro, ett� k�yt�mme namespacea std (C++ standard libraryn funktiot ovat t�ss� namespacessa)
using namespace std;

//C/C++ -ohjelmissa funktiot t�ytyy esitell� ennen niiden kutsumista 
void Osio1();
void Osio2();
void Osio3();
void osio4();


//Funktio main on ohjelman aloituspiste ja sen t�ytyy l�yty� jokaisesta ohjelmasta:
int main()
{
    //��kk�set UTF-8 merkist�ll�
    setlocale(LC_ALL, "fi_FI.");

    //cout-funktiolla tulostetaan:
    cout << "Ohjelma alkaa:" << endl;


    //Funktioista voidaan kutsua toisia funktioita miss� tahansa j�rjestyksess�.    
    //Osio1();
    //Ohjelma "hypp��" suorittamaan funktion ja palaa sen j�lkeen seuraavalle riville
    //kohtaan, josta funktiota kutsuttiin. Kutsutaan seuraavaa funktiota:
    //Osio2();
    //Ja sen j�lkeen viel� kolmatta
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
    //Yleens� ohjelmat kirjoitetaan jatkuvasti k�ynniss� pysyviksi, se saadaan aikaiseksi silmukalla (loop).
    //Jos ohjelma ei looppaa, sen suoritus loppuu, kun main-funktiossa ei ole en�� suoritettavia rivej�.
    //cout << "\nOhjelma loppuu ja sammuu automaattisesti." << endl;
}

//Kommentoi omin sanoin jokaisen osion toimintoa. Normaalisti funktion kommentit
//kertovat mit� funktio tekee, mit� muuttujia sinne vied��n ja mit� se palauttaa...
void Osio1()
{
    cout << "Ensimm�isen osion l�hdekoodi" << endl;
}

//...t�ll� kurssilla kirjoitetaan kommentteihin my�s mik� oli k�sitelt�v� aihe ja mit� siit�
//opittiin, mitk� asiat j�iv�t viel� ep�selviksi ja mit� opit aiheesta.
void Osio2()
{
    cout << "Toisen osion l�hdekoodi" << endl;
}

void Osio3()
{
    cout << "Kolmannen osion l�hdekoodi" << endl;
}

//Osio 3:n j�lkeen jatka uusien funktioiden tekemist� saman mallin mukaisesti. Muista my�s,
//ett� C/C++ -kieless� funktio t�ytyy esitell� ennen sen kutsumista (eli lis�� esittely main funktion ylle).

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