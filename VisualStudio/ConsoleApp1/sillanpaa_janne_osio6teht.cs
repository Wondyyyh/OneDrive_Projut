//using System;
//using System.Collections.Generic;

//class Program
//{
//    static void Main()
//    {
//        List<Vehicle> vehicles = new List<Vehicle>() {
//            new Car(){ Name = "Toyota" },
//            new Car(){ Name = "Volvo" },
//            new Car(){ Name = "Mazda" },
//            new Boat(){ Name = "Alma II" },
//            new Boat(){ Name = "Jenny" },
//            new Boat(){ Name = "Boaty McBoatface" }
//        };

//        DMV.RegisterVehicle(vehicles);
//        CarWash.Wash(vehicles);
//        Marina.Dock(vehicles);

//        foreach (Vehicle vehicle in vehicles)
//        {
//            Console.WriteLine(vehicle.Name + vehicle.Registered);
//        }
//    }
//}

//public class DMV
//{
//    public static void RegisterVehicle(List<Vehicle> vehicles)
//    {
//        //Set registered TRUE
//        foreach (Vehicle vehicle in vehicles)
//        {
//            vehicle.Registered = true;
//        }
//    }
//}
//class CarWash
//{
//    public static void Wash(List<Vehicle> vehicles)
//    {
//        //Set car's Clean to TRUE
//        foreach (var vehicle in vehicles)
//        {
//            if (vehicle is Car car)
//            {
//                car.Clean = true;
//            }
//        }
//    }
//}

//class Marina
//{
//    public static void Dock(List<Vehicle> vehicles)
//    {
//        //Set boat's Docked to TRUE
//        foreach (var vehicle in vehicles)
//        {
//            if (vehicle is Boat boat)
//            {
//                boat.Docked = true;
//            }
//        }
//    }
//}

////Abstract indicates that Vehicle is intended only to be a base class of other classes
//public abstract class Vehicle
//{
//    public string Name;
//    public bool Registered = false;
//}

//public class Car : Vehicle
//{
//    public bool Clean = false;
//}

//public class Boat : Vehicle
//{
//    public bool Docked = false;
//}

using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        List<Animal> animals = new List<Animal>()
        {
             new Mammal(){ Species = "Bear", Weight=150f },
             new Mammal(){ Species = "Deer", Weight=50f },
             new Bird(){ Species = "Owl", Weight=2f },
             new Bird(){ Species = "Swan", Weight=5f },
             new Reptile(){ Species = "LeafFrog", Weight=0.05f },
             new Reptile(){ Species = "CommonLizard", Weight=0.02f }
        };

        Zoo korkeaSaari = new Zoo(812.6f);
        korkeaSaari.AddAnimals(animals);
        korkeaSaari.FeedAllAnimals();

        Console.WriteLine("Food left: " + korkeaSaari.Food);
    }
}

public class Zoo
{

    public float Food { get; private set; } //kg

    private List<Mammal> mammalZone = new List<Mammal>();
    private List<Bird> birdZone = new List<Bird>();
    private List<Reptile> reptileZone = new List<Reptile>();

    public Zoo(float food)
    {
        Food = food;
    }

    public void AddAnimals(List<Animal> animals)
    {
        // Divide animals to corresponding 'zones' 
        foreach(Animal animal in animals)
        {
         
            if (animal is Mammal)
            {
                Mammal mammal = (Mammal)animal;
                mammalZone.Add(mammal);
               
            }
            else if(animal is Bird)
            {
                Bird bird = (Bird)animal;
                birdZone.Add(bird);

            }
            else if(animal is Reptile)
            {
                Reptile reptile = (Reptile)animal;
                reptileZone.Add(reptile);
            }

        }

        // Print how many animals
        Console.WriteLine("manmals: " + mammalZone.Count);
        Console.WriteLine("birds: " + birdZone.Count);
        Console.WriteLine("reptiles: " + reptileZone.Count);

    }

    public void FeedAllAnimals()
    {
         //- Feed the animals with 'food'
         //- Each animal eats 1/10 of her weight
         
        // Floats for counting
        float foodConsumed = 0;
        float manmalfood = 0, birdfood = 0, reptilefood = 0 ;

        // Loop trough every zone
        foreach(Animal animal in mammalZone) // Count manmal foods
        {
            manmalfood += animal.Weight / 10;
        }
        foreach (Animal animal in birdZone) // Count birds food
        {
            birdfood += animal.Weight / 10;
        }
        foreach(Animal animal in reptileZone) // Count reptiles food
        {
            reptilefood += animal.Weight / 10;
        }

        // Print every zones foodusage
        Console.WriteLine("Manmals used " + manmalfood + "kg food");
        Console.WriteLine("Birds used " + birdfood + "kg food");
        Console.WriteLine("Reptiles used " + reptilefood + "kg food");

        // Calculate total foodusage and print it
        foodConsumed = manmalfood + birdfood + reptilefood;
        Console.WriteLine("Total food used " + foodConsumed + "kg");

        // Remove total food from Zoo Food
        Food -= foodConsumed;


    }
}

public class Animal
{
    public string Species;
    public float Weight; //kg
}

public class Bird : Animal { }
public class Mammal : Animal { }
public class Reptile : Animal { }
