#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <time.h> 
#include <conio.h>


#include "pch.h"

//Incluce Inventory
#include "Inventory.h"
#include "main.h"

using namespace std;

class Inventory;

void main()
{

    //List of items
    list <unique_ptr<Inventory>> Inv;
    string name = "Pekka";
    
    
    //Inventory Item (name, 5, 10, 300);

    //Inventory::AddItem (Inv, "Pekka", 3);
    Inv.push_back(make_unique<Inventory>("Pekka", 3, 30.0f, 500.0f));

    for (auto& Inventory : Inv) 
    {
        cout << Inventory->Weight;

    }
    
}
