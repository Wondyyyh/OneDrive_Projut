//using System;

//class Program
//{

//    public delegate void Show(string _msg);
//    public static event Show OnShow;

//    public delegate void Three(int _amount);
//    public static event Three OnThree;

//    public delegate void Messages(string _word, string _secondWord);
//    public static event Messages OnMessages;

//    static void Main()
//    {
//        Listener listener = new Listener();
//        listener.ListenToProgramEvents();

//        //Raise events
//        if (OnShow != null)
//            OnShow("Display ");

//        if (OnThree != null)
//            OnThree(3);

//        if (OnMessages != null)
//            OnMessages(" different", " messages");
//    }
//}

//class Listener
//{
//    public void ListenToProgramEvents()
//    {
//        //Add your listeners HERE
//        Program.OnShow += Nayta;
//        Program.OnThree += Kolmonen;
//        Program.OnMessages += viestit;


//        //Appropriate methods HERE (that are called when events are received from Program)
       
//        //Expected result: print "Display 3 different messages" to console
//    }
//    private void Nayta(string msg)
//    {
//        Console.Write(msg);
//    }
//    private void Kolmonen(int amount)
//    {
//        Console.Write(amount);
//    }
//    private void viestit(string word, string word2)
//    {
//        Console.Write(word + " " + word2);
//    }
//}

using System;

class Program
{
    static void Main()
    {
        //Start listening CharacterController events HERE
        CharacterController.OnSound += HandlePlaySound;
        CharacterController.OnHealth += HandleHealthChanged;
        CharacterController.OnWeapon += HandleWeaponChanged;

        CharacterController playerController = new CharacterController();
        //Raise all events
        playerController.RaiseAllEvents();
    }
    
    static void HandlePlaySound(string _sound)
    {
        Console.WriteLine("*" + _sound + "*");
    }

    static void HandleHealthChanged(int _health)
    {
        Console.WriteLine("Current health: " + _health);
    }

    static void HandleWeaponChanged(CharacterController.Weapon _currentWeapon)
    {
        Console.WriteLine("Current weapon: " + _currentWeapon.ToString());
    }
}

class CharacterController
{
    public enum Weapon { Pistol, Shotgun, SMG };
    //Declare delegates and events HERE
    public delegate void WeaponHandler(CharacterController.Weapon _weapon);
    public static event WeaponHandler OnWeapon;

    public delegate void HealthHandler(int health);
    public static event HealthHandler OnHealth;

    public delegate void SoundHandler(string sound);
    public static event SoundHandler OnSound;

    private string shootSound = "pew! pew!";
    private int health = 100;
    private Weapon currentWeapon = Weapon.Pistol;

    public void RaiseAllEvents()
    {
        //Raise all three events you have HERE
        if (OnWeapon != null)
            OnWeapon(currentWeapon);
        if (OnHealth != null)
            OnHealth(health);
        if (OnSound != null)
            OnSound(shootSound);
    }
}
