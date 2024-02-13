using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using static System.Net.Mime.MediaTypeNames;

class Program
{
    public static Person[] persons = new Person[10];

    static void Main(string[] args)
    {
        // Tehtävä1
        float lev = 5f;
        float pit = 3.5f;
        float kork = 2f;

        Console.WriteLine("Input balloon radius: ");
        string line = Console.ReadLine();
        float sade = int.Parse(line);


        float pohjanala = GeometryHelper.RectArea(lev, pit);
        float tilavuus = GeometryHelper.RectVolume(lev, pit, kork);
        float pallonpintaala = GeometryHelper.pintaala(sade);
        float pallontilavuus = GeometryHelper.tilavuus(sade);

        Console.WriteLine("Pohjan ala -> " + pohjanala + "m2");
        Console.WriteLine("Tilavuus -> " + tilavuus + "m3");
        Console.WriteLine("Pallon pinta-ala -> " + pallonpintaala + "m2");
        Console.WriteLine("Pallon tilavuus -> " + pallontilavuus + "m3");

        Console.WriteLine("Persons and NULLS: ");

        // Tehtävä2
        for(int i = 0; i < persons.Length; i++)
        {
            persons[i] = Program.PersonOrNot(i);
            Console.WriteLine(persons[i]);
        }

        ItemExcercise.Osio3(args);
    }
    
    static Person PersonOrNot(int i)
    {
        Random r = new Random();
        int rInt = r.Next(0, 100);


        if (rInt >= 50)
        {
            Person persons = new Person();
            return persons;
        }
        else return null;        
    }
    public static void PrintNames(Person[] _persons)
    {
        if (_persons.Length != 0)
        {
            for (int i = 0; i < _persons.Length; i++)
            {
                Console.WriteLine("Name " + i + ": " + _persons[i].Name + ", age: " + _persons[i].Age);
            }
        }
        else Console.WriteLine("Lengt is zero");
    }
}

class Person
{
    public string Name;
    public int Age;
}

static class GeometryHelper
{
    public static float RectArea(float _width, float _length)
    {
        return _width * _length;
    }

    public static float RectVolume(float _width, float _length, float _height)
    {
        return _width * _length * _height;
    }

    public static float pintaala(float sade)
    {
        return 4 * MathF.PI * sade * sade;
    } 
    public static float tilavuus(float sade)
    {
        return 4 * MathF.PI * sade * sade * sade / 3;
    }

}

class ItemExcercise
{
    private static Random random = new Random();
    public static void Osio3(string[] args)
    {
        Item[] items = new Item[10];

        char readChar;

        do
        {
            Console.WriteLine("1 - lisää itemeitä");
            Console.WriteLine("2 - poista itemeitä");

            readChar = Console.ReadKey(true).KeyChar;

            if (readChar == '1')
                AddRandomItem(items);
            else if (readChar == '2')
                RemoveRandomItem(items);

            PrintItems(items);

        } while (readChar != 'Q' && readChar != 'q');

    }

    public static void AddRandomItem(Item[] _items)
    {
        int arrayIndex = random.Next(0, _items.Length);
        Item addItem = new Item(RandomString(8), random.Next(5, 100));
        if (_items[arrayIndex] == null)
        {
            _items[arrayIndex] = addItem;

            Console.WriteLine("Added new item " + addItem.Name + " to random position in array..." + "\n ");

        }
        else
            Console.WriteLine("This index already has an item." + "\n" + "No new items added." + "\n");
    }

    public static void RemoveRandomItem(Item[] _items)
    {
        int arrayIndex = random.Next(0, _items.Length);
        if (_items[arrayIndex] != null)
        {
            _items[arrayIndex] = null;
            Console.WriteLine("Removed item from ranodm position in array..." + "\n");
        }
        else
            Console.WriteLine("Nothing in this random index to remove" + "\n");
    }

    public static void PrintItems(Item[] _items)
    {
        for (int i = 0; i < _items.Length; i++)
        {

            if (_items[i] != null)
            {
                Console.WriteLine("Item " + i + ": " + _items[i].Name + ", " + _items[i].Weight + "kg");
            }
            else Console.WriteLine(" - ");
            
        }
    }

    public static string RandomString(int length)
    {
        const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        return new string(Enumerable.Repeat(chars, length)
          .Select(s => s[random.Next(s.Length)]).ToArray());
    }
}

class Item
{
    public string Name;
    public int Weight;

    public Item(string _name, int _weight)
    {
        Name = _name;
        Weight = -_weight;
    }
}



