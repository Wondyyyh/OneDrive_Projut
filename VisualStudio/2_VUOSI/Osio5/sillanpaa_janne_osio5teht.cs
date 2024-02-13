using System;

namespace Osio5
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Erikoismerkit
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            char readChar;

            //Tehtävä 1
            Stack<string> notesStack = new Stack<string>();
            string input;

            while (true)
            {
                Console.Write("\nAdd note or (u)ndo: ");
                input = Console.ReadLine();

                if (input == "undo" || input == "u")
                {
                    if (notesStack.Count > 0)
                    {
                        string undoString = notesStack.Pop();
                        Console.WriteLine("Undo last note: " + undoString);
                    }
                    else
                    {
                        Console.WriteLine("No notes to undo");
                        break;
                    }
                    
                }
                else //Lisätään päivät, kuukaudet ja vuodet?
                    notesStack.Push(DateTime.Now.ToString("dd.MM.yyyy HH.mm.ss") + " -> " + input);

                Console.WriteLine("\n -- notes --");
                foreach (string note in notesStack)
                {
                    Console.WriteLine(note);
                }
            }


            //Tehtävä 2
            InventoryItem[] items = new InventoryItem[4];
            items[0] = new InventoryItem("Laptop", 1000f, 1);
            items[1] = new InventoryItem("Phone", 500f, 1);
            items[2] = new InventoryItem("Mouse", 50f, 1);
            items[3] = new InventoryItem("Keyboard", 40f, 1);
            Product inventory1 = new Product();


            do
            {
                PrintItemShop(items);

                //readchar variable
                readChar = Console.ReadKey(true).KeyChar;

                switch (readChar)
                {
                    case '1':
                        inventory1.CollectItem(items[0]);
                        break;

                    case '2':
                        inventory1.CollectItem(items[1]);
                        break;

                    case '3':
                        inventory1.CollectItem(items[2]);
                        break;

                    case '4':
                        inventory1.CollectItem(items[3]);
                        break;

                        default:
                        break;
                    
                }
                   
                //Print Shopping cart
                inventory1.PrintInventory();
                //New loop? user selection
                Console.WriteLine("\n*** Options ***");
                Console.WriteLine("1 - Add new item");
                Console.WriteLine("2 - Quit");
                //readchar variable
                readChar = Console.ReadKey(true).KeyChar;

            } while (readChar != '2');

        }
        public static void PrintItemShop(InventoryItem[] items)
        {
            Console.WriteLine("\n*** ItemShop ***");
            for (int i = 0; i < items.Length; i++)
            {
                Console.WriteLine(i+1 + " - " + items[i].Name + " " + items[i].Price + "€");
            }

        }

    }
   
    class Product
    {
        public Dictionary<InventoryItem, int> inventory { get; private set; } = new Dictionary<InventoryItem, int>();
        public void CollectItem(InventoryItem item)
        {
            if (inventory.ContainsKey(item))
            {
                inventory[item]++;
            }
            else
            {
                inventory.Add(item, item.Amount);
            }
        }
        public void PrintInventory()
        {
            float i = 0;
            Console.WriteLine("\n-- Inventory --");
            foreach (KeyValuePair<InventoryItem, int> item in inventory)
            {
                float totalPrice = item.Key.Price * item.Value;
                Console.WriteLine(item.Key.Name + " x " + item.Key.Price + "e x " + item.Value + " = " + totalPrice + "e");
                i = i + item.Key.Price * item.Value; //Lasketaan tuotteiden kokonaishinta
            }
            Console.WriteLine("Total Price = " + i + "e"); //Tulostetaan kokonais hinta
        }
    }
    class InventoryItem
    {
        public string Name { get; set; }
        public float Price { get; set; }
        public int Amount { get; set; }
        public InventoryItem(string name, float price, int amount)
        {
            Name = name;
            Price = price;
            Amount = amount;
        }

    }
}

    
        
    
