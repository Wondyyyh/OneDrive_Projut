#pragma once
#include <list>
#include <memory>
#include <iostream>
#include<string>

class Inventory
{
public:

	string Name;
	int Count;
	float Weight;
	float Price;


	//Constructor
	void Item(string name, int count, float weight, float price);

	//Destructor
	/*~Item();*/

	/*void RemoveItem();
	void AddItem(list <unique_ptr<Inventory> >& Inv, string name, int count);*/


};

