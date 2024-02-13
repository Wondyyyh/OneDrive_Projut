using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Resources;

class CraftingGame
{

    static void Main()
    {
        ApplicationController app = new ApplicationController();
        app.Init();
        app.Run();
    }
}
class ApplicationController
{
    public List<CraftableItemRecipe> CraftableItems { get; private set; } = new List<CraftableItemRecipe>();

    private Wood wood = new Wood();
    private IronIngot ironIngot = new IronIngot();
    private Rope rope = new Rope();
    public void Init()
    {
        CraftableItems.Add(new CraftableItemRecipe("Bow", new Dictionary<Resource, int>() { [wood] = 1, [rope] = 1 }));
        CraftableItems.Add(new CraftableItemRecipe("Shovel", new Dictionary<Resource, int>() { [ironIngot] = 1, [wood] = 1 }));
        CraftableItems.Add(new CraftableItemRecipe("Helmet", new Dictionary<Resource, int>() { [ironIngot] = 3 }));
        CraftableItems.Add(new CraftableItemRecipe("Fishing Rod", new Dictionary<Resource, int>() { [ironIngot] = 1, [wood] = 2, [rope] = 1 }));
        UI ui = new UI();
        ui.Init();
    }
    public void Run()
    {
        Player player1 = new Player();
        player1.CollectResource(ironIngot, 5);
        player1.CollectResource(rope, 3);
        player1.CollectResource(wood, 4);
        player1.Resources();

        while (true)
        {
            Console.WriteLine("\nType item name to craft it:");
            CraftableItems.ForEach(item => Console.WriteLine(item.Name));
            string inputItemName = Console.ReadLine();
            CraftableItemRecipe recipe = CraftableItems.Where(x => x.Name.ToLower() == inputItemName.ToLower()).FirstOrDefault();
            if (recipe != null)
                player1.Craft(recipe);

            player1.Resources();


            // Test of drop item
            player1.DropItem(CraftableItems.Last());
        }
    }
}
class UI
{
    public void Init()
    {
        Player.OnInventory += PrintInventory;
        Player.OnResources += PrintResourcesLeft;
    }
    public void PrintInventory(Dictionary<CraftableItemRecipe, int> inventory)
    {
        Console.WriteLine("\nItems:");
        inventory.ToList().ForEach(item => Console.WriteLine(item.Key.Name + " x " + item.Value));
        
    }
    public void PrintResourcesLeft(Dictionary<Resource, int> resources)
    {
        Console.WriteLine("\nResources:");
        resources.ToList().ForEach(resource => Console.WriteLine(resource.Key + " x " + resource.Value));
    }
}
class Player
{
    private Dictionary<Resource, int> resources = new Dictionary<Resource, int>();
    private Dictionary<CraftableItemRecipe, int> inventory = new Dictionary<CraftableItemRecipe, int>();

    public delegate void PrintInventory(Dictionary<CraftableItemRecipe, int> inventory);
    public static event PrintInventory OnInventory;
    public delegate void PrintResourcesLeft(Dictionary<Resource, int> resources);
    public static event PrintResourcesLeft OnResources;


    public int totalweight = 0;
    public void Resources()
    {
        if (OnResources != null)
            OnResources(resources);

    }



    private int InventoryWeight { get {
            
            foreach (KeyValuePair<CraftableItemRecipe, int> resource in inventory)
            {
                //i feel dum here
                //osaan tulostaa ingredient countin per tavara mutten pikeaa painoa
                totalweight += resource.Key.Ingredients.Count;
            }
            return totalweight;
            ; } }

    public void CollectResource(Resource resource, int amount)
    {
        //Either add a amount of resource collected,
        //if the player already has the type of resource...
        if (resources.ContainsKey(resource))
            resources[resource] += amount;
        //or add the new resource type with collected amount
        else
            resources.Add(resource, amount);
    }
    public void Craft(CraftableItemRecipe itemToCraft)
    {
        bool enoughResources = false;
        
        foreach (KeyValuePair<Resource, int> resource in itemToCraft.Ingredients)
        {
            //Käy tuotteet läpi onko tarpeeksi
            //Jos ei ole tarpeeks tulostetaan itemin nimi jota ei ollut tarpeeksi
            if (resources[resource.Key] < resource.Value)
            {
                Console.WriteLine("You don't have enough: " + resource.Key + " to craft: " + itemToCraft.Name);
                enoughResources = false;
                continue;
            }
            
            //jos if ei toteudu kertaakaan jää arvoksi true loopin loputtua
            enoughResources = true;
        }

        //jos resuja oli tarpeeks suoritetaan itemin craft loppuun
        if (enoughResources)
        {
            //Use resources:
            foreach (KeyValuePair<Resource, int> resource in itemToCraft.Ingredients)
            {
                resources[resource.Key] -= resource.Value;
            }
            //Add crafted item to inventory
            if (inventory.ContainsKey(itemToCraft))
            inventory[itemToCraft]++;
            else
                inventory.Add(itemToCraft, 1);
            OnInventory(inventory);

        }
        //Print inventory weight
        Console.WriteLine("Weight of : " + InventoryWeight);
    }
    
    

    //  -----DROP ITEM METHOD HERE-----
    public void DropItem(CraftableItemRecipe item)
    {
        if (inventory.ContainsKey(item))
        {
            if(inventory[item] > 1)
            {
                inventory[item]-= 1;
                Console.WriteLine("removed one " + item.Name + " from inventory");
                OnInventory(inventory);
            }
            else
            {
                Console.WriteLine("All " + item.Name + "'s are dropped");
                inventory.Remove(item);
                OnInventory(inventory);
            }

        }
        else
            Console.WriteLine("There wasn't any " + item.Name + "'s to drop");
    }
}

class CraftableItemRecipe
{
    //Unique name of the item
    public string Name;
    //How much spesific type of Resource is needed for the item (int is amount)
    public Dictionary<Resource, int> Ingredients;
    public CraftableItemRecipe(string uniqueName, Dictionary<Resource, int> ingredients)
    {
        Name = uniqueName;
        Ingredients = ingredients;
    }
}
class Resource { }
class IronIngot : Resource { }
class Rope : Resource { }
class Wood : Resource { }