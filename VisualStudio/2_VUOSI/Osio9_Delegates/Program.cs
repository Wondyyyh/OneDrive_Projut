//using System;
//using static System.Net.Mime.MediaTypeNames;

//class Program
//{
//    static void Main()
//    {
//        //Instantiate delegate
//        Elapsed elapsed = ElapsedTime;

//        Printer printer = new Printer();

//        //Deliver delegate instance
//        printer.PrintStuff(elapsed);

//    }

//    public delegate void Elapsed(DateTime start, DateTime end);
//    static void ElapsedTime(DateTime startTime, DateTime endTime)
//    {
//        TimeSpan time = endTime - startTime;
//        Console.WriteLine("Elapsed time: " + time.TotalMilliseconds + "ms");
//    }
//}

//class Printer
//{
//    public void PrintStuff(Program.Elapsed elapsed)
//    {
//        DateTime startTime = DateTime.Now;

//        for (int i = 0; i < 100000; i++)
//        {
//            Console.Write(i);
//        }

//        DateTime endTime = DateTime.Now;

//        //Call the delegate
//        elapsed(startTime, endTime);
//    }
//}

using System;
using System.Collections.Generic;

class Program
{
    //Introduce your delegate HERE
    public delegate bool WEPO(InventoryItem _item);
    static void Main()
    {
        List<InventoryItem> playersInventory = new List<InventoryItem>
        {
            new InventoryItem("Rags"),
            new InventoryItem("Mug"),
            new Weapon("Short Sword", 10f),
            new Weapon("Long Sword", 15f),
            new Potion("Oil", true),
            new Potion("Poison", true),
            new Potion("Health", false)
        };

        Console.WriteLine("-- All Items --");
        PrintInventory(playersInventory, PrintItems);
        Console.WriteLine("\n-- Weapons --");
        PrintInventory(playersInventory, PrintWeapons);
        Console.WriteLine("\n-- Potions --");
        PrintInventory(playersInventory, PrintPotions);

    }

    static void PrintInventory(List<InventoryItem> _inventory, WEPO wepo) //<-- add filter parameter that is type of your delegate, default to null
    {
        foreach (var item in _inventory)
        {
            if (wepo == null || wepo(item)) //<-- call filter if it's not null 
                Console.WriteLine(item.Name);
        }
    }
    static bool PrintItems(InventoryItem _item)
    {
        return _item is InventoryItem;
    }
    static bool PrintWeapons(InventoryItem _item)
    {
        return _item is Weapon;
    }

    static bool PrintPotions(InventoryItem _item)
    {
        return _item is Potion;
    }
}

class InventoryItem
{
    public string Name;
    public InventoryItem(string _name) { Name = _name; }
}

class Weapon : InventoryItem
{
    public float Damage;
    public Weapon(string _name, float _dmg) : base(_name) { Damage = _dmg; }
}

class Potion : InventoryItem
{
    public bool UseForDipping;
    public Potion(string _name, bool _dippable) : base(_name) { UseForDipping = _dippable; }

    //Just to explain UseForDipping's potential use :)
    public void Dip(Weapon _weapon)
    {
        if (UseForDipping)
            Console.WriteLine(_weapon.Name + " is now covered with " + Name);
        else
            Console.WriteLine("You can't dip " + _weapon.Name + " in " + Name);
    }
}