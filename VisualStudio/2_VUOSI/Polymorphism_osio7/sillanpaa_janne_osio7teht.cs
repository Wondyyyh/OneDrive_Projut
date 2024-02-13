using System;
using System.Security.Cryptography.X509Certificates;

public class Program
{
    public static void Main()
    {
        var MakeSound = new R2();
        Console.WriteLine(MakeSound.GetSound());
    }

}
public abstract class Astrodroid
{
    public virtual string GetSound()
    {
        return "Beep beep";
    }
    public void MakeSound()
    {
        Console.WriteLine(GetSound() + "\n");
    }
}
class R2 : Astrodroid
{
    public override string GetSound()
    {
        return "Beep bop";
    }
}

//using System;

//class Program
//{
//    static void Main()
//    {
//        Person john = new Person("John", 22);

//        Student jane = new Student("Jane", 23, 123456);

//        john.PrintInformation();
//        jane.PrintInformation();
//    }

//}

//class Person
//{
//    public string Name;
//    public int Age;

//    public Person(string _name, int _age)
//    {
//        Name = _name;
//        Age = _age;
//    }

//    public virtual void PrintInformation()
//    {
//        Console.WriteLine("*** " + Name + " ***");
//        Console.WriteLine("Age: " + Age);
//    }
//}

//class Student : Person
//{
//    public int StudentNumber;

//    public Student(string _name, int _age, int _studentNumber) : base(_name, _age) //<-- calls base class constructor, sets Name and Age
//    {
//        //Student's have additional student number
//        StudentNumber = _studentNumber;
//    }
//    public override void PrintInformation()
//    {
//        base.PrintInformation();
//        Console.WriteLine("StudentNumber: " + StudentNumber);
//    }
//}