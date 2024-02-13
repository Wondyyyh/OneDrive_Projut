/*

TEHTÄVÄ 1
- Lisää inventory nimiseen listaan kolme instanssia InventoryItem -luokasta AddItem() -funktiolla
- Lisättävät esineet ja niiden tiedot ovat:
	1. nimi: Short Sword, ikonitiedosto: short_sword.png, ja tyyppi: Weapon
	2. nimi: Health Potion, ikonitiedosto: health_potion.png, ja tyyppi: Potion
	3. nimi: Plate Mail, ikonitiedosto:  plate_mail.png, ja tyyppi: Armor
- Tulosta inventaariossa olevat esineet PrintInventory() -funktiolla.

TEHTÄVÄ 2

- Lisää InventoryItem -luokkaan esineen paino float -tyyppisenä public propertyna nimeltä Weight.
- Lisää luokan constructoriin weight parametri ja anna siitä tehdyille (teht. 1) instansseille sopivat painot.
- Muuta PrintInventory() -funktiota niin,
  että se laskee yhteen kaikkien inventaarion esineiden painot ja tulostaa ne (esineluettelon alle) esim. näin: "Inventory items weight: 15.5kg"

TEHTÄVÄ 3

- Lisää InventoryItem -luokkaan destruktori. Destruktorissa ei tehdä muuta kuin tulostetaan: "Item [esineen nimi] was destroyed."
- Lisää ohjelmaan funktio ClearInventory()
- Funktio tyhjentää inventaarion ja poistaa kaikki esineet. Destruktorilla näet, että instanssi myös varmasti tuhoutui.
- Kutsu funktiota sen jälkeen kun olet tulostanut  inventaarion (ed. tehtävä).

TEHTÄVÄ 4

- Kirjoita Inventory-luokka.
- Annetussa (ja täydennetyssä) koodissa on jo AddInventoryItem(), ClearInventory() ja PrintInventory() -funktiot,
  joten olisi ehkä kätevämpää jos kaikki Inventoryyn liittyvät toiminnot olisivat osa Inventory-luokkaa.
- Tarvitset myös luokkaan list <unique_ptr<InventoryItem>> public propertyn.
- Muuta siis koodia paremmaksi niin, että siirrät edellä mainitut funktiot Inventory -luokan metodeiksi.
- Muuta sitten ohjelma käyttämään luokan instanssia (proseduuralisten funktioiden sijaan) tähän tyyliin:

	//list <unique_ptr<InventoryItem>> inventory; //<-- tätä ei siis enää käytetä...
	Inventory inventory; //<-- ...vaan

	//Teht. 1 - kolme instanssia inventaarioon
	inventory.AddInventoryItem("Short Sword", InventoryItem::Weapon);
	inventory.AddInventoryItem("Health Potion", InventoryItem::Potion);
	inventory.AddInventoryItem("Plate Mail", InventoryItem::Armour);
	inventory.PrintInventory();

TEHTÄVÄ 5

- Kirjoita luokka Character. Luokka on tarkoitettu pelin hahmoille ja kullakin hahmolla on oma inventaarionsa.
- Luokalla on siis public propertyt: string Name ja list <unique_ptr<InventoryItem>> Inventory
- Character -luokkaan tulee myös samat metodit, jotka ohjelmassa on jo funktioina: AddInventoryItem() ja PrintInventory()
- Näillä voi siis lisätä tietyn hahmon inventaarioon esineitä ja tulostaa juuri sen hahmon inventaarion.
- Tee kaksi instanssia hahmoista ja lisää esineitä niiden inventaarioon, esim. näin:

	Character character1;
	character1.Name = "Frodo";
	character1.AddInventoryItem("Short Sword", InventoryItem::Weapon);
	character1.AddInventoryItem("The One Ring", InventoryItem::Ring);
	character1.PrintInventory();

	Character character2;
	character2.Name = "Legolas";
	character2.AddInventoryItem("Elven Bow", InventoryItem::Weapon);
	character2.AddInventoryItem("Mithril Scale Mail", InventoryItem::Armour);
	character2.PrintInventory();

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <time.h>
#include <list>
#include <memory>
#include <string>

using namespace std;

class Inventory;
class InventoryItem;
class Character;


class InventoryItem {
public:

	//Inventory item type enum
	enum ItemType { Weapon, Armour, Potion, Ring };

	string Name;
	ItemType Type;
	//Teht. 2 - lisää paino
	float Weight;

	//Constructor
	InventoryItem(string name, ItemType type, float weight) //Teht. 2 - lisää paino
	{
		Name = name;
		Type = type;
		//Teht. 2 - lisää paino
		Weight = weight;

	}

	//Teht. 3 - destructor
	~InventoryItem() {
		cout << "Item " << Name << " was destroyed." << endl;

	}

	string GetTypeString() {
		return GetEnumString(Type);
	}

private:

	string GetEnumString(ItemType type) {
		if (type == 0) return "Weapon";
		else if (type == 1) return "Armour";
		else if (type == 2) return "Potion";
		else if (type == 3) return "Ring";
	}
};

class Inventory
{
public:

	list <unique_ptr<InventoryItem>> Inventorylist;

	void AddInventoryItem(string itemName, InventoryItem::ItemType type, float weight, list<unique_ptr<InventoryItem>>& inventory);
	void ClearInventory(list<unique_ptr<InventoryItem>>& inventory);
	void PrintInventory(list<unique_ptr<InventoryItem>>& inventory);

};

class Character
{
public:

	string Name;
	list<unique_ptr<InventoryItem>>Inventory;

	void AddInventoryItem(string itemName, InventoryItem::ItemType type, float weight, list<unique_ptr<InventoryItem>>& inventory);
	void ClearInventory(list<unique_ptr<InventoryItem>>& inventory);
	void PrintInventory(list<unique_ptr<InventoryItem>>& inventory);


};


void Inventory::AddInventoryItem(string itemName, InventoryItem::ItemType type, float weight, list<unique_ptr<InventoryItem>>& inventory) {
	inventory.push_back(make_unique<InventoryItem>(itemName, type, weight));
}
void Character::AddInventoryItem(string itemName, InventoryItem::ItemType type, float weight, list<unique_ptr<InventoryItem>>& inventory) {
	inventory.push_back(make_unique<InventoryItem>(itemName, type, weight));
}

//Teht. 3 - ClearInventory
list<unique_ptr<InventoryItem>>::iterator it; // <- Iterator Inventory

void Inventory::ClearInventory(list<unique_ptr<InventoryItem>>& inventory) {

	while (inventory.size() > 0)
	{
		for (it = inventory.begin(); it != inventory.end(); it++) {
			inventory.erase(it);
			break;
		}

	}
}
void Character::ClearInventory(list<unique_ptr<InventoryItem>>& inventory) {

	while (inventory.size() > 0)
	{
		for (it = inventory.begin(); it != inventory.end(); it++) {
			inventory.erase(it);
			break;
		}

	}
}

void Inventory::PrintInventory(list<unique_ptr<InventoryItem>>& inventory)
{
	float SumOfWeights = 0;
	//Heading - format string with iomanip setw and left
	cout
		<< left << setw(15) << "Item name"
		<< setw(12) << "Item type" << endl;

	for (const auto& item : inventory) {

		SumOfWeights += item->Weight;
		cout
			<< left << setw(15) << item->Name
			<< setw(12) << item->GetTypeString() << endl;
		
	}

	//Teht. 2 - tulosta inventaarion esineiden yhteenlaskettu paino
	cout << "Inventory items weight: " << SumOfWeights << "kg." << endl << endl;

}

void Character::PrintInventory(list<unique_ptr<InventoryItem>>& inventory)
{
	float SumOfWeights = 0;
	cout << "\n~~ Inventory of " << Name << " ~~" << endl;

	//Heading - format string with iomanip setw and left
	cout
		<< left << setw(15) << "Item name"
		<< setw(12) << "Item type" << endl;

	for (const auto& item : inventory) {

		SumOfWeights += item->Weight;
		cout
			<< left << setw(15) << item->Name
			<< setw(12) << item->GetTypeString() << endl;
		
	}

	//Teht. 2 - tulosta inventaarion esineiden yhteenlaskettu paino
	cout << "Inventory items weight: " << SumOfWeights << "kg." << endl << endl;

}

//Teht. 5 - Character-luokka

int main() {

	Inventory inventory;

	//Teht. 1 - kolme instanssia InventoryItemeitä inventaarioon; tulosta inventaario
	inventory.AddInventoryItem("Short Sword", InventoryItem::ItemType::Weapon, 5.0f, inventory.Inventorylist);
	inventory.AddInventoryItem("Health Potion", InventoryItem::ItemType::Potion, 0.5f, inventory.Inventorylist);
	inventory.AddInventoryItem("Plate Mail", InventoryItem::ItemType::Armour, 10.0f, inventory.Inventorylist);

	inventory.PrintInventory(inventory.Inventorylist);

	//Teht. 3 - tyhjennä inventaario tulostamisen jälkeen
	inventory.ClearInventory(inventory.Inventorylist);


	//Teht. 5 - kaksi (Character) hahmoa ja heidän inventaarionsa

	Character character1;
	character1.Name = "Frodo";
	character1.AddInventoryItem("Short Sword", InventoryItem::Weapon, 10.0f, character1.Inventory);
	character1.AddInventoryItem("The One Ring", InventoryItem::Ring, 0.2f, character1.Inventory);
	character1.PrintInventory(character1.Inventory);

	Character character2;
	character2.Name = "Legolas";
	character2.AddInventoryItem("Elven Bow", InventoryItem::Weapon, 12.0f, character2.Inventory);
	character2.AddInventoryItem("Mithril Mail", InventoryItem::Armour, 5.0f, character2.Inventory);
	character2.PrintInventory(character2.Inventory);


}

