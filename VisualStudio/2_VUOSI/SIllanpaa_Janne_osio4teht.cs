using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using static System.Net.Mime.MediaTypeNames;


namespace Osio4
{
    

    internal class Program
    {
        
        static void Main(string[] args)
        {
            //Erikoismerkit
            Console.OutputEncoding = System.Text.Encoding.Unicode;

            //Configure 3persons
            Person[] persons = new Person[3];
            persons[0] = new Person(10);
            persons[1] = new Person(20);
            persons[2] = new Person(22);

            PrintPersons(persons);


            char readChar;
            do
            {
                //Global Variable numb
                int numb = 0;

                Console.WriteLine("\n   ***    ***");
                Console.WriteLine("Select number of Jorma: ");
                Console.WriteLine("Or press Q to quit");

                //readchar variable
                readChar = Console.ReadKey(true).KeyChar;

                //quit if pressed Q
                if (readChar == 'Q' || readChar == 'q')
                    break;
                else
                {
                    //Get input
                    string line =  readChar.ToString();
                    numb = int.Parse(line);
                    if (numb > 2)
                    {
                        Console.WriteLine("Not valid input");
                        break;
                    }

                }

                Console.WriteLine("\n   ***    ***");
                Console.WriteLine("Press 1 to add one year");
                Console.WriteLine("Press 2 to rewrite persons age");
                

                //readchar variable
                readChar = Console.ReadKey(true).KeyChar;

                if (readChar == '1')
                    persons[numb].AddYear();

                else if (readChar == '2')
                {
                    Console.WriteLine("Enter persons age: ");
                    string line2 = Console.ReadLine();
                    int age = int.Parse(line2);
                    persons[numb].Age = age;
                }
                PrintPersons(persons);
            }
            while (true);


            //Doubler Task
            Doubler doubler = new Doubler();
            doubler.Double = 5;
            Console.WriteLine("\n   ***    ***");
            Console.WriteLine("Here we have value 5 doubled: " + doubler.Double);

            //Continue thingie
            Console.WriteLine("Press anything to continue...");
            readChar = Console.ReadKey(true).KeyChar;


            Console.WriteLine("\n   ***    ***");
            Console.WriteLine("Now let's play dice:");


            Nopat noppa = new Nopat();
            //Noppa loop
            do
            {
                Console.WriteLine("Press 1 to roll dice");
                Console.WriteLine("Press 2 to quit");

                //Take input
                readChar = Console.ReadKey(true).KeyChar;
                //Reroll
                if (readChar == '1')
                    noppa.Roll();
                //Return
                else if (readChar == '2')
                    return;

            } while (readChar != '2');




        }
        
        public static void PrintPersons(Person[]persons)
        {
            for (int i = 0; i<persons.Length; i++)
            {
                Console.WriteLine("Person number " + i + ": " + persons[i].name + " age of " + persons[i].Age); ;

            }

        }

        public class Person
        {
            private string Name;
            public int Age;


            public string name
            {
                get { return Name; }
                private set { }
            } 
            public int age
            {
                get { return Age; }
                private set { }
            }

            public int AddYear()
            {
                Age++;
                return Age;
            }


            public Person( int age)
            {
              
                Name = "Jorma";
                Age = age;
            }
            ~Person()
            {
                Console.WriteLine(Name + " was cleaned by Garbage Collection");
            }
        }

        public class Nopat
        {
            
            public void Roll()
            {
                int sum = 0;
                for (int i = 0; i < 5; i++)
                {
                    Random result = new Random();
                    int resultInt = result.Next(1, 7);
                    sum += resultInt;
                    RenderDie(resultInt);

                }
                Console.WriteLine("Noppalukujen summa: " + sum);
            }
            private void RenderDie(int _result)
            {
               Console.WriteLine("┌─────────┐");

               switch (_result)
               {
                   case 1:
                       Console.WriteLine("│         │\n│    ●    │\n│         │");
                       break;
                   case 2:
                       Console.WriteLine("│         │\n│  ●   ●  │\n│         │");
                       break;
                   case 3:
                       Console.WriteLine("│  ●      │\n│    ●    │\n│      ●  │");
                       break;
                   case 4:
                       Console.WriteLine("│  ●   ●  │\n│         │\n│  ●   ●  │");
                       break;
                   case 5:
                       Console.WriteLine("│  ●   ●  │\n│    ●    │\n│  ●   ●  │");
                       break;
                   case 6:
                       Console.WriteLine("│  ●   ●  │\n│  ●   ●  │\n│  ●   ●  │");
                       break;
               }
               
               Console.WriteLine("└─────────┘");
            }

        }
        public class Doubler
        {
            private int number;

            public int Double
            {
                get { return number; }
                set { number = value * 2; }
            }


        }
    }
}