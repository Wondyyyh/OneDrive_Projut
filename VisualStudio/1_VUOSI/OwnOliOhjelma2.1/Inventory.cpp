#include <list>
#include <memory>
#include "Inventory.h"



using namespace std;
class ShopItems;

list <unique_ptr<ShopItems>> Inv;


ShopItems::ShopItems(string name, int count, float weight, float price)
{

	Name = name;
	Count = count;
	Weight = weight;
	Price = price;

}

ShopItems::~ShopItems()
{
}