#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <conio.h>

#include <algorithm> // <- for string convert to upper

//Srand includet
#include <time.h> 
#include <stdlib.h>


#include <iterator> // <- iterators

//Incluce Inventory
#include "Inventory.h" 


using namespace std;

class ShopItems; // forward declaration from ShopItems

//List of items
list <unique_ptr<ShopItems> > ItemList;
list <unique_ptr<ShopItems> > ShopCart;

//Iterator list
list<unique_ptr<ShopItems>>::iterator it;



//Players "Public" variables
float cash = 0;
float currentCash = 0;


// Calculate current player money
float CurrentCash(int price)
{
    currentCash -= price; // <- Subtract from players cash

    return currentCash;
}

// Print loop for cart items
void printCart() {

    cout << "\t\t--- Your cart ---\n" << endl;
    // print list of items
    for (auto& Inventory : ShopCart)
    {
        cout << Inventory->Name << "\t";
        cout << "count: " << Inventory->Count << "kpl" << "\t";
        cout << "weight: " << Inventory->Weight << "kg" << "\t";
        cout << "price: " << Inventory->Price << "$" << endl;

    }
}
void shoppingCart() // <- ShoppingCart items
{

    // check if there's items in cart
    if (ShopCart.size() != 0) 
    {
        printCart();
    }

    // if list is empty print message about it
    else
    {
        cout << "Nothing to see here :)" << endl;
    }


    char input; // <- Input variable
    cout << "\nQ - Go back to Menu" << endl;
    cin >> input; // <- Take input
    input = toupper(input); // <- Make input uppercase

    // if Q do nothing and go back to menu
    if (input == 'Q') {

    }

    // else keep printing shopping cart
    else {
        system("cls"); // <- Clear Console
        shoppingCart();
    }
}

void Items() // <- All Items List
{
    for (auto& Inventory : ItemList)
    {

        cout << Inventory->Name << "\t";
        cout << "weight: " << Inventory->Weight << "kg" << "\t";
        cout << "price: " << Inventory->Price << "$" << endl;

    }
    cout << endl;
}

void CartInfo() // <- Cart Status
{


    float price = 0.0f;
    int DifferrentItems = 0;
    int AmmountOfItems = 0;
    float weight = 0;
    //int currentCash = cash;
    currentCash = cash; // <- set current cash to cash value

    for (auto& Inventory : ShopCart)
    {
        // add count * price to price
        price += Inventory->Count * Inventory->Price;
        DifferrentItems++;
        AmmountOfItems += Inventory->Count;
        weight += Inventory->Weight * Inventory->Count;
    }

    //currentCash -= price; 
    /*CurrentCash(price);*/  // <- Subtract from players cash

    cout << "--- ShoppinCart ---" << endl;
    cout << "Number of different items: " << DifferrentItems 
         << "\nNumber of all items: " << AmmountOfItems
         << "\nTotal weight of: " << weight << "kg"
         << "\nWith total value of: " << price << "$" << endl;
    cout << "Cash left: " << CurrentCash(price) << "$" << endl;

}



void Info() // <- Menu Info
{
    


    cout << "\n*** What you want to do? ***" << endl;
    cout << "1 - Look inside the cart" << endl;

    cout << "2 - Add Item to cart" << endl;
    
    cout << "3 - Remove Item from cart" << endl;

    cout << "Q - Quit" << endl;
    
}

void buy(string input, int ammount) // <- Buying Stuff
{
    //Input string to upper
    transform(input.begin(), input.end(), input.begin(), ::toupper);


    // Loop through Itemlist
    for (it = ItemList.begin(); it != ItemList.end(); it++) 
    {

        //List item name to upper
        string check = (*it)->Name;
        transform(check.begin(), check.end(), check.begin(), ::toupper);


        if (check == input) // <- Try to find matcing name
        {
            break; // <- Break loop and leave pointer where it found match
        }
    }

    // if pointer not pointing to end we found something
    if (it != ItemList.end())
    {

        // get variables set from pointer copy
        string name = (*it)->Name;
        float weight = (*it)->Weight;
        float price = (*it)->Price;

        // if currentcash - price is bigger than 0 we can buy
        if (CurrentCash(0) - price*ammount > 0)  
        {
            // PushBack to shoppingcart with found variables
            ShopCart.push_back(make_unique<ShopItems>(name, ammount, weight, price));
            cout << "~~ Added " << ammount << " of " << input << " to cart ~~" << endl;
        }
        else
        {
            cout << "Sorry you don't have money for " << ammount << " " << name << endl;
        }
    }

    // Else print not found text
    else 
    {
        cout << "Didn't find " << input << " from the shop" << endl;
    }

}

void AddItems() 
{
    char input[15];
    char YN;
    int Ammount;
    bool rightInput = true;
   
    // loop until told otherwise
    while (bool x = true)
    {
         // header text
        cout << "\n\t--- ItemShop ---" << endl;
        Items(); // <- Print item list
        
        CartInfo();

        // ask item name
        cout << "\nChoose something from the list: ";
        cin.clear();
        cin.ignore();
        cin.getline(input, 15);

        // ask ammount
        cout << "How many: ";
        cin >> Ammount;

        // Buy Function called with input name and given ammount
        buy(input, Ammount);



        cout << "\nWant buy something else?" << endl;
        cout << "Y - Yes" << endl;
        cout << "N - No" << endl;

        cin.clear();
        cin.ignore();
        cin >> YN;

        YN = toupper(YN);
        if (YN == 'Y') 
        {
            system("cls"); // <- Clear Console
            AddItems();   
        }
        else if (YN == 'N') 
        {
            // tell to stop while loop and break
            x = false;
            break;
        }
        // one more break
        break;


    }



}

// Removeitems functio
void removeItems()
{
    char input[15];
    bool found = false; 

    // print cart items
    printCart();

    cout << "\nWhat you want to remove: ";

    // get input
    cin.clear();
    cin.ignore();
    cin.getline(input, 15);

    string convert = input; // <- converted to string

    //Input string to upper
    transform(convert.begin(), convert.end(), convert.begin(), ::toupper);

    // loop through shopcart
    for (it = ShopCart.begin(); it != ShopCart.end(); it++)
    {

        //List item name to upper
        string check = (*it)->Name;
        transform(check.begin(), check.end(), check.begin(), ::toupper);


        if (check == convert) // <- Try to find matcing name
        {
            ShopCart.erase(it); // <- remove item from current pointer location
            found = true;
            break;
            
        }
        
    }

        //refreshing cart view
        system("cls"); // <- Clear Console
        printCart(); // <- print cart items



    // Confirm texts for removing items
    if (found) // <- print removed text if foumd = true
    {
        cout << "\n~~ Removed " << convert << " from the list ~~" << endl;
    }
    else // <- print didn't find if not found
    {
        cout << "\n~~ Didn't find " << convert << " from the list ~~" << endl;
    }



    // Some quide texts
    cout << "\nWant remove something else?" << endl;
    cout << "Y - Yes" << endl;
    cout << "N - No" << endl;

    char YN;
    cin >> YN;

    // Get input for another remove or do nothing and go menu
    YN = toupper(YN);
    if (YN == 'Y')
    {
        system("cls"); // <- Clear Console
        removeItems();
    }
}

int main()
{

    //ääkköstimet
    setlocale(LC_ALL, "fi_FI");

    //initialize random seed evevry time for cash value
    srand(time(NULL));

    cash = rand() % 50000 + 5000; // <- Set cash value after seeding
    

    //listataan kaikki mahdolliset objektit listaan
    ItemList.push_back(make_unique<ShopItems>("Kala", 1, .5f, 9.50f));
    ItemList.push_back(make_unique<ShopItems>("Liha", 1, .4f, 1.99f));
    ItemList.push_back(make_unique<ShopItems>("Kana", 1, .4f, 3.49f));
    ItemList.push_back(make_unique<ShopItems>("Peruna", 1, 1.0f, 3.50f));
    ItemList.push_back(make_unique<ShopItems>("Kinkku", 1, .2f, 1.49f));
    ItemList.push_back(make_unique<ShopItems>("Suklaa", 1, .6f, 1.95f));
    ItemList.push_back(make_unique<ShopItems>("Auto", 1, 3000.0f, 25500.0f));
    ItemList.push_back(make_unique<ShopItems>("PC", 1, 20.0f, 1999.99f));
    ItemList.push_back(make_unique<ShopItems>("TV", 1, 9.0f, 899.99f));
    ItemList.push_back(make_unique<ShopItems>("Headset", 1, 0.3f, 199.99f));



    while (true) // <- Actual GameLoop
    {

        system("cls"); // <- Clear Console

        CartInfo(); // <- Print cart info
        Info(); // <- Print menu info
        char input;
        cin >> input;
        input = toupper(input);


        if (input == '1') {

            system("cls"); // <- Clear Console
            shoppingCart(); // <- Print shopping cart items
        }


        if (input == '2') {

            system("cls"); // <- Clear Console
            AddItems();
           
        }


        if (input == '3') {

            system("cls"); // <- Clear Console
            removeItems();
        }

        if (input == 'Q') {

            break;
        }

    }

}
