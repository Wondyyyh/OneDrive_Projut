#include "Inventory.h"
#include "pch.h"


using namespace std;
class Inventory;

list <unique_ptr<Inventory>> Inv;





//void Inventory::RemoveItem()
//{
//}
//
//void Inventory::AddItem(list<unique_ptr<Inventory>>& Inv, string name, int count)
//{
//
//
//
//	Inv.push_back(make_unique<Inventory>(name, count));
//}
//
//
//
void Inventory::Item(string name, int count, float weight, float price) 
{

	Name = name;
	Count = count;
	Weight = weight;
	Price = price;

}

//Inventory::~Item()
//{
//}