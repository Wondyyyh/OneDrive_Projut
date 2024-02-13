using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        PlatformerApp platformerApp = new PlatformerApp();
        platformerApp.Init();
        platformerApp.Run();
    }
}

class PlatformerApp
{
    private List<Enemy> enemies;
    private List<Collectable> collectables;
    private Player player1;
    private UI ui;

    public void Init()
    {
        //List of enemies to stomp
        enemies = new List<Enemy>()
        {
            new Enemy("Goomba"),
            new Enemy("Goomba"),
            new Enemy("Koopa Troopa"),
            new Enemy("Koopa Troopa")
        };

        //List of items to collect
        collectables = new List<Collectable>()
        {
            new Coin(5),
            new Coin(50),
            new Coin(1),
            new ExtraLife()
        };

        player1 = new Player();

        //Instantiate and Init UI to start listening for events:
        ui = new UI();
        ui.Init();

        Console.WriteLine("\n ** GAME LOADED **\n");
    }

    public void Run()
    {
        Console.WriteLine("\n ** READY PLAYER ONE **\n");
        //Stomp some enemies...
        enemies.ForEach(enemy =>
        {
            player1.StompEnemy(enemy);
            System.Threading.Thread.Sleep(1000);
        });

        //Wait for a while
        System.Threading.Thread.Sleep(2000);

        //Then collect some loot
        collectables.ForEach(collectable =>
        {
            collectable.Collect();

            if (collectable is Coin coin)
            {
                player1.CollectedCoin(coin.Value);
            }
            else if (collectable is ExtraLife extraLife)
            {
                player1.CollectedExtraLife();
            }

            System.Threading.Thread.Sleep(1000);
        });
    }
}

class UI
{
    private Dictionary<string, int> enemiesKilled = new Dictionary<string, int>();

    public void Init()
    {
        //Start listening to events:
        Enemy.OnStomped += UpdateAndRenderEnemyStats;
        Player.OnCollectedItem += RenderPlayerStats;
    }

    private void RenderPlayerStats(int coins, int lives)
    {
        Console.WriteLine("\nLives x " + lives + " Coins: " + coins + "$");
    }

    private void UpdateAndRenderEnemyStats(string typeOfEnemy)
    {
        if (enemiesKilled.ContainsKey(typeOfEnemy))
            enemiesKilled[typeOfEnemy]++;
        else
            enemiesKilled.Add(typeOfEnemy, 1);

        Console.WriteLine("\nUI: ENEMIES PERISHED");
        enemiesKilled.ToList().ForEach(distinctEnemy => Console.WriteLine(distinctEnemy.Key + " x " + distinctEnemy.Value));
    }
}

#region Characters
abstract class Character
{
    public bool IsAlive { get; protected set; } = true;

    public virtual void Die()
    {
        if (!IsAlive)
            return;

        IsAlive = false;
    }
}

class Enemy : Character
{
    public delegate void Stomped(string typeOfEnemy);
    public static event Stomped OnStomped;

    //Would probably be actual derived type,
    //but here just represents different enemies
    public string TypeOfEnemy { get; private set; }

    public Enemy(string typeOfEnemy)
    {
        TypeOfEnemy = typeOfEnemy;
    }

    public override void Die()
    {
        base.Die();

        //Raise event, pass "type" of enemy stomped
        if (OnStomped != null)
            OnStomped(TypeOfEnemy);

        //Tai: https://learn.microsoft.com/en-us/dotnet/visual-basic/language-reference/operators/null-conditional-operators
        //OnStomped?.Invoke(TypeOfEnemy);
    }
}

class Player : Character
{
    public delegate void CollectedItem(int coins, int lives);
    public static event CollectedItem OnCollectedItem;

    public int Coins { get; private set; } = 0;
    public int Lives { get; private set; } = 3;

    //https://www.mariowiki.com/Stomp
    public void StompEnemy(Enemy enemy)
    {
        Console.WriteLine("\n *JUMP* " + enemy.TypeOfEnemy + " -> PLOP!");
        enemy.Die();
    }

    public override void Die()
    {
        base.Die();
        if (Lives > 1)
        {
            Lives--;
            //Some animations, maybe reset position and...
            IsAlive = true;
        }
        else
        {
            Lives = 0;
            Console.WriteLine("GAME OVER");
        }
    }

    public void CollectedCoin(int value)
    {
        //Add amount of coins
        Coins += value;

        //Raise event, pass coins & lives values
        if (OnCollectedItem != null)
            OnCollectedItem(Coins, Lives);
    }

    public void CollectedExtraLife()
    {
        //Add one life
        Lives++;

        //Raise event, pass coins & lives values
        if (OnCollectedItem != null)
            OnCollectedItem(Coins, Lives);
    }
}

#endregion

#region Collectables

abstract class Collectable
{
    public bool Collected = false;
    public void Collect()
    {
        if (Collected)
            return;

        Collected = true;
    }
}

class Coin : Collectable
{
    public int Value;

    public Coin(int value)
    {
        Value = value;
    }
}

class ExtraLife : Collectable { }

#endregion