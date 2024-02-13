//Ohjelmointiprojekti - Sillanpaa Janne

#include <iostream>
#include <string>
#include <time.h>
#include <fstream>



//STD jotta ei tarvitse kirjoittaa jokaisen cout tai cin eteen std::, nopeuttaa huomattavasti kirjoittamista
using namespace std;
bool menu = true; // K‰ytet‰‰n ettei menua tulosteta uudestaa jos input ei ollut validi
char input; //MainMenun input variable

void osio1();
void osio2();
void osio3();
void osio4();
void osio5();
void help();
void osio6();
void osio7();
void osio8();
void osio9();
void osio10();

//osio10 asioita
void WriteToFile(string pathfile, string content); //Funktion nime‰minen, jota tullaan k‰ytt‰m‰‰n myˆhemmin tekstitiedostoon kirjoittamista varten
string ReadFromFile(string pathfile); // Funktion nime‰minen, jota tullaan k‰ytt‰m‰‰n tekstitiedostosta lukemiseen
string path = "user.dat"; //Luotavan tekstitiedoston nimi


void main()
{
	//‰‰kkˆstimet
	setlocale(LC_ALL, "fi_FI");
	//n‰ytt‰‰ ohjelmointiprojektin alussa Projekti ja nimitiedot
	cout << "Ohjelmointiprojekti - Janne Sillanp‰‰\n";
	cout << "--------------------------------------\n";

	//Testataan hakea tietoa tekstitiedostosta ja verrataan haetun tiedon pituutta nollaan
	if (size(ReadFromFile(path)) > 0) //jos lˆydettiin jotain on pituus enemm‰n kuin nolla, joten suoritetaan osio10
	{
		osio10();
	}

	//while loop pit‰‰ sovelluksen auki kunnes q inputilla rikotaan looppaus ja ohjelma sulkeutuu
	while (true)
	{

		osio4(); //tulosteaan aluksi menu info
		menu = true;
		cin >> input;

		if (input == '1')
		{
			osio1();
		}
		else if (input == '2')
		{
			osio2();
		}
		else if (input == '3')
		{
			osio3();
		}
		else if (input == 'q') //Break loop and close application
		{
			break;
		}
		else if (input == '4')
		{
			help();
		}
		else if (input == '5')
		{
			osio5();
		}
		else if (input == '6')
		{
			osio6();
		}
		else if (input == '7')
		{
			osio7();
		}
		else if (input == '8')
		{
			osio8();
		}
		else if (input == '9')
		{
			osio9();
		}
		else
		{
			menu = false; //jos input on jotain muuta ei tulosteta menua uudestaan vaan odotetaan kunnes input on validi
		}
	}

}
void help() //hieman turha, koska olisi vaan voinut 4. Help -inputilla tulostaa ohjeet uudestaan, mutta t‰m‰ on hauska n‰in
{
	char x;
	cout << "\nWhat you want me to do? Print same text twice so you can read it again?\n" << endl;
	cout << "Press R when you feel helped and want to go back\n";
	cin >> x;
	if (x == 'r' || x == 'R')
	{
		//we don't need anything here ;)
	}


}


void osio1() //osio1 kysyt‰‰n tietoja yksitellen, ker‰t‰‰n ne ja lopuksi printataan k‰ytt‰j‰lle h‰nen syˆtt‰m‰ns‰ tiedot
{
	string name; //string nime‰ varten
	int age, studentnumber; //int koska kysyt‰‰n kokonaislukuja
	float height, weight; //float, koska n‰m‰ ei v‰ltt‰m‰tt‰ ole kokonaislukuja

	//kysyt‰‰n ja syˆtet‰‰n nimi
	cout << "\nName: ";
	cin >> name;
	//kysyt‰‰n ja syˆtet‰‰n ik‰
	cout << "Age: ";
	cin >> age;
	//kysyt‰‰n ja syˆtet‰‰n opiskelijanumero
	cout << "Studentnumber: ";
	cin >> studentnumber;
	//kysyt‰‰n ja syˆtet‰‰n pituus
	cout << "Height: ";
	cin >> height;
	//kysyt‰‰n ja syˆtet‰‰n paino
	cout << "Weight: ";
	cin >> weight;

	//tulostetaan k‰ytt‰j‰lle takaisin juuri syˆtetyt tiedot
	cout << "\n\n" << "Antamasi tiedot: \n";
	cout << "\nName: " << name << "\nAge: " << age << "\nStudentnumber: " << studentnumber << "\nHeight: "
		<< height << "\nWeight: " << weight << endl;

	//osio10 varten kirjoitetaan syˆtetyt tiedot erilliseen tekstitiedostoon talteen
	WriteToFile(path, name + "," + to_string(age) + "," + to_string(studentnumber) + "," + to_string(height) + "," + to_string(weight));


}

void osio2() //osio2 kysyy tukikuukaudet ja tuen m‰‰r‰, jonka j‰lkeen ne kerrotaan yhteen jolloin saadaan vuosittaisten tulojen m‰‰r‰
{

	int months;
	float tuki, Sum;
	cout << "\nMoneltako kuukaudelta saat opintotukea? ";
	cin >> months; //input1
	cout << "Paljonko opintotukesi on kuukaudessa? ";
	cin >> tuki; //input2
	Sum = months * tuki; //kerrotaan inputit kesken‰‰n
	cout << "Opintotuen m‰‰r‰ on " << Sum << " vuodessa." << endl;


}
// Osio3 tarvittavat erilliset funktiot nimettyn‰ k‰yttˆ‰ varten
void Arvosanakone();
void MileConverter();
void osio3() //osio 3 on kaksi eri toimintoa, jotka tekev‰t eri asioita ja t‰ss‰ valitaan kumpi halutaan suorittaa
{

	cout << "\nValitse kumpaa haluat k‰ytt‰‰\n";
	cout << "------------------------------\n"
		<< "A - Arvosanakone\n" << "D - Distance Converter\n";

	char x;
	cin >> x;
	if (x == 'A' || x == 'a')
	{
		Arvosanakone();
	}
	else if (x == 'D' || x == 'd')
	{
		MileConverter();
	}

}

void Arvosanakone() //Arvosanakone kysyy pisteet, jotka sen j‰lkeen muunnetaan arvosananaksi 0-5 if lausekkeilla
{


	cout << "\n\n*** Pisteet arvosanoiksi ***\n\n";

	int pisteet;
	cout << "Anna kokeen pisteet: ";
	cin >> pisteet;
	if (pisteet == 100) //jos pisteet ovat tasan sata tulostetaan, ett‰ sait t‰ydet pisteet
	{
		cout << "Onneksi olkoon sait t‰ydet pisteet!\n";
	}
	else if (pisteet >= 90) //jos pisteet eiv‰t olleet t‰ydet seuraavaksi verrataan ovatko ne suuremmat tai yht‰suuret kuin 90
	{
		cout << "Arvosanasi on: 5\n"; //jos kyll‰, niin tulostetaan arvosanaksi 5
	}
	else if (pisteet >= 80) // jos viel‰k‰‰n ei t‰rp‰nnyt niin jatketaan arvosanan etsimist‰...
	{
		cout << "Arvosanasi on: 4\n";
	}
	else if (pisteet >= 70)
	{
		cout << "Arvosanasi on: 3\n";
	}
	else if (pisteet >= 60)
	{
		cout << "Arvosanasi on: 2\n";
	}
	else if (pisteet >= 50)
	{
		cout << "Arvosanasi on: 1\n";
	}
	else //jos mit‰‰n edellisit‰ arvosanoista ei voitu antaa, tulostetaan jokatapauksessa arvosanaksi 0
	{
		cout << "Arvosanasi on: 0\n";
	}


}

void MileConverter()//Mileconverter kysyy kilometrim‰‰r‰, joka muutetaan laskutoimituksella maileiksi tai merimaileiksi halutun inputin mukaan
{


	float km, mile, merimile;
	cout << "\n\n*** Distance Converter ***\n\n";
	cout << "Give distance in kilometers: "; //kysyt‰‰n kilometrim‰‰r‰ k‰ytt‰j‰lt‰
	cin >> km; //poimitaan kilometrim‰‰r‰ float variableen

	mile = km * 1000 / 1609; //laskutoimitus, jolla saadaan kilometrit maileiksi
	merimile = km * 1000 / 1852; //laskutoimitus, jolla saadaan kilometrit merimaileiksi

	cout << "------------------------------\n";
	cout << "M - Convert to miles\n" << "N - Conver to nautical miles\n"; //kysyt‰‰n k‰ytt‰j‰lt‰ input sen mukaan kummaksi h‰n haluaa muuttaa kilometrit

	char key;
	cin >> key; //poimitaan input key variableen

	if (key == 'M' || key == 'm') //verrataan oliko input iso tai pieni M, jos kyll‰ muutetaan maileiksi
	{
		cout << "The disctance in miles: " << mile << endl;
	}
	else if (key == 'n' || key == 'N') //verrataan oliko input iso tai pieni N, jos kyll‰ muutetaan merimaileiksi
	{
		cout << "The disctance in nautical miles: " << merimile << endl;
	}

}

void osio4() //MainMenu ohjeet fucktiossa, jota voidaan helposti kutsua tarvittaessa
{
	if (menu) // lis‰varmistus, ett‰ input oli validi ja teki jotain eik‰ esim ollut kirjain
	{
		//valikkoteksti joka tuodaan aina main function alussa n‰kyville
		cout << "\n---Main Menu---" << endl;
		cout << "\n1. User Information" << endl;
		cout << "2. Study grants" << endl;
		cout << "3. Convert score and miles" << endl;
		cout << "4. Help" << endl;
		cout << "5. Prime numbers" << endl;
		cout << "6. Random characters" << endl;
		cout << "7. Word count" << endl;
		cout << "8. Seats and Rows" << endl;
		cout << "9. Random Ints" << endl;

		cout << "Q - Quit" << endl;
	}
}

void osio5()
{

	//t‰ss‰ osiossa otetaan k‰ytt‰j‰n syˆtt‰m‰ luku ja testataan sit‰ looppaamalla kaikki mahdolliset kertotaulut paitsi 0,1 ja itsens‰ l‰pi
	int given, test;
	cout << "\nAnna luku tarkistaaksesi onko se alkuluku: ";
	cin >> given;
	bool jaollinen = false;

	//jos joku kokonaisluku 2-(given-1) tuo jakoj‰‰nnˆksen 0 eli luku on t‰ll‰ suoraa jaettavissa looppi rikotanaan ja annetaan 
	//true arvon booleaniin. Muuten kelataan loopin l‰pi ja boolean pysyy falsena.
	for (int x = 2; x < given; x++)
	{

		test = given % x;
		if (test == 0) {
			jaollinen = true;
			break;
		}


	}
	//nyt verrataan oliko booleani asetettu todeksi vai ei ja sit‰ hyˆdynt‰en tulostetaan oikea vastaus
	if (jaollinen == true)
	{

		cout << "\nEI! Luku " << given << " ei ole alkuluku\n";

	}
	else
	{
		cout << "\nKYLLƒ! Luku " << given << " on alkuluku\n";
	}
	//t‰m‰n osion kanssa tappelin hetken aikaa mutta isoimpana haasteena saattoi olla omat cout lausekkeet, jotka olivat aluksi liian
	//samann‰kˆisi‰ kesken‰‰n ja v‰syneen‰ pohdin miksei mik‰‰n toimi, mutta kyll‰ se siit‰ parilla huutomerkill‰ tokeni
}
//lopputulema t‰h‰n menness‰: helppoa ja kivaa niin kauan kun ei ole yliv‰synyt..
//tuntiteht‰v‰t kun teki kaikki ajatuksella, niin osasi niiden pohjalta n‰pp‰r‰sti toteuttaa viikkoteht‰v‰tkin mutkitta

void osio6() //Tulostetaan random m‰‰r‰ merkkej‰ konsoliin ja lasketaan kauanko siin‰ meni
{

	time_t startTime;
	time_t endTime;

	double seconds;

	//Aloitusaika
	startTime = time(NULL);

	//j‰tet‰‰n rivi v‰li‰ ennen looppia
	cout << endl;

	//Alustetaan rand
	srand(time(NULL));

	int count = 0; // k‰ytet‰‰n laskemiseen montako numeroa lopulta tulostettiin
	int random = 0; // k‰ytet‰‰n randomin m‰‰rit‰miseen

	//Valitaan 100k-200k v‰lilt‰ random luku
	random = rand() % 100000 + 100000;

	for (int i = 0; i < random; i++) //loopataan 0 - randomiin asetettu luku
	{

		char rndChar = rand() % 26 + 97; //etsit‰‰n ascii kirjastosta merkki v‰lilt‰ 97 - (97+26)
		cout << rndChar; //tulostetaan valittu merkki konsoliin
		count++; //lis‰t‰‰n counteriin joka looppilla plus yksi, jotta pysyt‰‰n per‰ss‰ montako merkki‰ on tulostettu

	}

	//Lopetusaika
	endTime = time(NULL);

	//Lasketaan lopetusaika - aloitus aika jolloin saadaan kulunut aika
	seconds = difftime(endTime, startTime);

	//Tulostetaan tiedot konsoliin
	cout << "\n\nRandomizing and printing of " << count << " letters took:  " << seconds << " seconds.\n";

}

void osio7() //Kysyt‰‰n k‰ytt‰j‰ kirjoittamaan lause ja sen j‰ljeen lasketaan montako merkki‰ ja sanaa...
{

	string input;
	int count = 0, luku = 0;
	cout << "\nAnna lause: ";
	cin.ignore(); //"tyhjennet‰‰n" cin varmuudeksi
	getline(cin, input); //poimitaan input variableen koko syˆtetty rivi

	for (int i = 0; i < input.length(); i++) //loopataan niin monta kertaa kun inputissa on merkkej‰
	{
		if (input[i] == ' ') //jos syˆtetyss‰ tekstiss‰ tulee vastaan v‰lilyˆnti, lis‰t‰‰n yksi counteriin
		{
			count++;
		}
	}

	cout << "Sanojen m‰‰r‰ lauseessa on: " << count + 1 << endl; //tulostetaan lˆydetty sanam‰‰r‰
	cout << "Lauseessa on " << input.length() << " merkki‰" << endl;

	if (input.find(",") != string::npos) //tarkistetaan oliko syˆtteess‰ pilkkuja, jos kyll‰ loopataan koko syˆtteen l‰pi
	{

		for (int i = 0; i < input.length(); i++)
		{

			if (input[i] == ',') { //jos syˆtetyss‰ tekstiss‰ tulee vastaan pilkku, lis‰t‰‰n "luku" integeriin yksi

				luku++; //k‰ytet‰‰n t‰t‰ integeri‰ nyt lauseiden laskemiseen

			}



		}
		cout << "HOLD UP!!! Kirjoitit sittenkin virkkeen, jossa on " << luku + 1 << " lausetta" << endl;
	}
	else //jos lauseessa ei ollut pilkkuja, tulostetaan ett‰ se oli p‰‰lause
	{
		cout << "Lause on p‰‰lause." << endl;
	}
}


//Osio8 variableja, jotta ne n‰kyy ns "globaalina"
void rivitys(); // erillinen nimetty funktion rivien printtaamiselle
string paikat[10][20]; //2 ulotteinen array rivityst‰ varten
int x = 0; //input1
int x1 = 0; //input2


void osio8() //Tulostetaan teatteri paikat, kysyt‰‰n mink‰ paikan haluat varata, jonka j‰lkeen tulostetaan rivitys uudelleen varauksen kera
{

	cout << "Vapaiden paikkojen m‰‰r‰: " << size(paikat) * size(*paikat) << endl; //k‰ytin t‰t‰ itselleni vain arrayn hahmottamiseen ja opetteluun

	for (int i = 0; i < size(paikat); i++) //loopataan rivit
	{
		for (int j = 0; j < size(*paikat); j++) //loopataan vierekk‰iset paikat
		{
			paikat[i][j] = to_string(j + 1); //sijoitetaan jokaiseen paikkaan numero 1 - vierekk‰isten paikkojen m‰‰r‰
		}
	}


	cout << "\nROW SEAT" << endl;
	rivitys(); //tulostetaan paikat ensimm‰isen kerran
	cout << "\nReserve a seat (give a row and seat number separated with space): "; //kysyt‰‰n 2 integeri‰ varausta varten
	cin >> x; //input1
	cin >> x1; //input2
	paikat[x - 1][x1 - 1] = "XX"; //Asetetaan XX valittujen integerien mukaan, miinustetaan vain 1 ensin ett‰ saadaan ne indexeiksi
	rivitys(); //tulostetaan array uudestaan valinnan kera
}

void rivitys() //funktio arrayn piirt‰miseen konsoliin
{

	for (int i = 0; i < size(paikat); i++) // loopataan niin monta kertaa kuin arrayssa on rivej‰
	{

		// lis‰t‰‰n luvun eteen nolla jos se on pienempi kuin 10 siistimm‰n ulkomuodon vuoksi
		if (i < 9) { //numero 9 koska indexit nollasta eteenp‰in
			cout << "0" << i + 1 << "  ";
		}
		else {
			cout << i + 1 << "  ";
		}

		for (int j = 0; j < size(*paikat); j++) { //loopataan niin monta kertaa kuin arrayssa on vierekk‰isi‰ numeroita

			cout << paikat[i][j] << " "; //tulostetaan teksti arraysta molempien looppien sen hetkisen indexin mukaan

		}
		cout << endl;

	}

}


//Osio9 variablet erikseen funktion ulkopuolella, jotta niit‰ voidaan k‰ytt‰‰ muissakin funktioissa
int randoms[40];
int odds = 0, evens = 0, positives = 0, negatives = 0, zeros = 0;

//Osio9 pyydetyt erilliset funktiot
void Odds() //Parilliset
{
	for (int i = 0; i < 40; i++) 
	{
		if (randoms[i] % 2 != 0) //jos luvun jakoj‰‰nnˆs on jotain muuta kuin nolla on se pariton
		{ 
			odds++;
		}
	}
}
void Evens() //Parittomat
{
	for (int i = 0; i < 40; i++) 
	{
		if (randoms[i] % 2 == 0) //jos luvun jakoj‰‰nnˆs on nolla on luku parillinen
		{ 
			evens++;
		}
	}
}
void Positives() //Positiiviset
{
	for (int i = 0; i < 40; i++) 
	{
		if (randoms[i] > 0) //jos luku on suurempi kuin nolla on se positiivinen
		{ 
			positives++;
		}
	}
}
void Negatives() //Negatiiviset
{
	for (int i = 0; i < 40; i++) 
	{
		if (randoms[i] < 0) //jos luku on pienempi kuin nolla on se negatiivinen
		{ 
			negatives++;
		}
	}
}
void HowManyZeros() //Kuinka monta nollaa
{
	for (int i = 0; i < 40; i++) 
	{
		if (randoms[i] == 0) //jos luku on yht‰suuri kuin nolla
		{ 
			zeros++;
		}
	}
}

void osio9() //Asetetaan arrayhin 40 random lukua v‰lilt‰ -10 ja 10, jonka j‰lken lasketaan erillisill‰ funktioilla montako paritonta, parillista yms.
{
	odds = 0, evens = 0, positives = 0, negatives = 0, zeros = 0; //nollataan luvut silt‰varalta, ett‰ osio9 suoritetaan uudestaan

	cout << "\nGenerated 40 random numbers and there was : \n" << endl; //Alkuteksti funktiolle

	//Loopataam 40x ja asetetaan random numero v‰lilt‰ -10 - +10
	for (int i = 0; i < 40; i++)
	{

		// arvo 21, koska lasketaan kuinka isolta rangelta halutaan numeroita -10 yl‰puolelta ja v‰liss‰ on nolla
		randoms[i] = rand() % 21 - 10;

		//Tulostetaan joka kierroksella mink‰ arvon rand() laittoi arrayhin
		cout << randoms[i] << "  ";

		// Halusin tehd‰ teh‰t‰v‰n n‰in ja vahingossa teinkin ennenkˆ luin ohjeet kunnolla
		// joten siin‰ on nyt siis sama asia hieman tiivistetymmin

		// Turhuuden alku
		// if (randoms[i] != 0) {
		//
		//	if (randoms[i] < 0) {
		//		negatives++;
		//		if (randoms[i] % 2 == 0) {
		//			evens++;
		//		}
		//		else {
		//			odds++;
		//		}
		//	}
		//	else 
		//  {
		//		positives++;
		//		if (randoms[i] % 2 == 0) {
		//			evens++;
		//		}
		//		else {
		//			odds++;
		//		}
		//	}
		// }
		// else 
		// {
		//	zeros++;
		// }
		// Turhuuden loppu
	}

	// T‰ss‰ oikea osuus
	// Sen j‰lkeen kun array on asetettu 40 luvulla, kutsutaan luodut funktiot, jotka etsiv‰t looppaamalla kuinka monta mit‰kin on
	Odds();
	Evens();
	Positives();
	Negatives();
	HowManyZeros();

	//Tulostettan lopuksi montako mit‰kin lˆytyi
	cout << "\n\nOdds: " << odds << "\nEvens: " << evens << "\nPositives: " << positives << "\nNegatives: "
		<< negatives << "\nZeros: " << zeros << endl;
}

void WriteToFile(string pathfile, string content) //Aukaisee tekstitiedoston nimen mukaan ja vie sinne halutut tiedot, jonka j‰lkeen sulkee tiedoston
{

	ofstream somefile;
	somefile.open(pathfile);
	somefile << content;
	somefile.close();

}

string ReadFromFile(string pathfile) //luetaan tiedostosta jos lˆydett‰viss‰
{

	string content = ""; //t‰h‰n stringiin ker‰t‰‰n kaikki teksti tiedostosta
	ifstream somefile(pathfile); //Instanssi, jolla luetaan tiedostosta
	if (somefile.is_open()) //tarkistetaan lˆytyykˆ luotua tiedostoa
	{
		string line; //muuttuja, johon v‰litallennetaan lˆydetty‰

		while (getline(somefile, line)) //Poimii rivej‰ niin kauan kuin niit‰ lˆytyy tiedostosta
		{
			//lis‰‰ lˆydetty rivi stringiin rivinvaihdoin kera
			content += line;
			content.push_back('\n');
		}

	}

	return content; //palautetaan kutsujalle lˆydetty tiedoston sis‰ltˆ
}

void osio10()
{
	string filecontent = ReadFromFile(path); //filecontent stringiin asetetaan koko teksti tallennetusta tiedostosta
	string Name = filecontent.substr(0, filecontent.find(",")); //Etsit‰‰n nimi tiedoston alusta l‰htien ekaan pilkkuun asti

	cout << "Wellcome back, " << Name << "!" << endl; //tulostetaan Tervetuloa ja lˆydetty nimi
}