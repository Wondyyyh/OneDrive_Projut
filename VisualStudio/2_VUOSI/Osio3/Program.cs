using System;
using System.Collections.Specialized;

class Program
{
    static void Main(string[] args)
    {
        float lev = 5f;
        float pit = 3.5f;
        float kork = 2f;

        //Console.WriteLine("Input balloon radius: ");
        //float sade = Console.ReadKey(true).KeyChar;
        //float radius;


        float pohjanala = GeometryHelper.RectArea(lev, pit);
        float tilavuus = GeometryHelper.RectVolume(lev, pit, kork);
        //float pallonpintaala = GeometryHelper.pintaala(sade);

        Console.WriteLine("Pohjan ala -> " + pohjanala + "m2");
        Console.WriteLine("Tilavuus -> " + tilavuus + "m3");
        //Console.WriteLine("Pallon pinta-ala -> " + pallonpintaala + "m3");


    }
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

    //public static float pintaala(float sade)
    //{
    //    return 4 * MathF.PI * sade * sade;
    //}

}