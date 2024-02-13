using System;
using System.Runtime.CompilerServices;

namespace Osio2_Abstraktio
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Create new Player instance 'player'
            Player player = new Player();
            //Set properties for 'player' instance
            player.Character = Player.Characters.Mario;
            player.Speed = 600.0f;
            player.Health = 10.0f;
            player.Coins = 0;
            player.Lives = 5;

            //Create new Enemy instance 'enemy'
            Enemy enemy = new Enemy();
            //Set properties for 'enemy' instance
            enemy.enemy = Enemy.Characters.Tatti;
            enemy.Speed = 300.0f;
            enemy.Health = 5.0f;
            enemy.Damage = 8.0f;

            //Create new Tíle instance 'tile'
            Tile tile = new Tile();
            //Set properties for 'tile' instance
            tile.tile = Tile.Tiles.PlusCoins;
            tile.Lives = 0;
            tile.Health = 0.0f;
            tile.Coins = 100;



        }
    }
    //Vehicle class
    class Player
    {
        //Public enum (can be used outside of this class)
        public enum Characters
        {
            Mario, Luigi, Yoshi
        };

        //Player specs as public fields
        public Characters Character;
        public float Speed;
        public float Health;
        public int Coins;
        public int Lives;

        private void Movement()
        {
            //Do moving stuff here
        }
        public float TakeDamage(float damage)
        {
            //Player take damage
            Health -= damage;
            return Health;

            //jos health menee nollaan tuhoa pelaaja
            //Destroy();
        }
        private void Destroy()
        {
            //Die

        }
        private void CollectItem(/*ItemType collectedItem*/)
        {
           //Calculate health, coins and lives

        }

    }
    class Enemy
    {
        //Public enum (can be used outside of this class)
        public enum Characters
        {
            Tatti, Patti, Matti
        };

        //Player specs as public fields
        public Characters enemy;
        public float Speed;
        public float Health;
        public float Damage;

        private void Movement()
        {
            //Do moving stuff here
        }
        public float TakeDamage(float damage)
        {
            //Player take damage
            Health -= damage;
            return Health;

            //jos health menee nollaan tuhoa pelaaja
            //Destroy();
        }
        private void Destroy()
        {
            //Die
        }

    }
    class Tile
    {
        //Public enum (can be used outside of this class)
        public enum Tiles
        {
            PlusHealth, PlusLives, PlusCoins
        };

        //Player specs as public fields
        public Tiles tile;
        public int Coins;
        public float Health;
        public int Lives;

        private void Destroy()
        {
            //Die
        }

    }

    

}