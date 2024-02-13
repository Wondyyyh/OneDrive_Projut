#pragma once
#include <list>
#include <memory>
#include <iostream>
#include <string>

using namespace std;

class ShopItems
{
public:

	string Name;
	int Count;
	float Weight;
	float Price;


	//Constructor
	ShopItems(string name, int count, float weight, float price);

	//Destructor
	~ShopItems();

};

