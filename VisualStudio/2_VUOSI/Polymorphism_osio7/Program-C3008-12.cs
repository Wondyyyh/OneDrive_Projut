using System;
using System.Security.Cryptography.X509Certificates;

// Implement your classes here.

public class Program
{
    public static void Main()
    {
        R2 r2 = new R2();
        r2.GetSound("Beep bop");
        Console.WriteLine();
    }
}
interface I
{
    void GetSound(string sound);
}
abstract class Astrodroid : I
{
    public virtual void GetSound(string sound)
    {
        MakeSound(sound);
    }
    void MakeSound(string sound)
    {
        Console.WriteLine(sound + "\n");
    }
}
class R2 : Astrodroid
{
    public override void GetSound(string sound)
    {
       base.GetSound(sound);
    }
}