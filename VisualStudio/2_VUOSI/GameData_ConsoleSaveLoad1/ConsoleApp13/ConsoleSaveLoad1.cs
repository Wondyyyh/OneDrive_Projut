using System;
using System.Text;
using System.IO;
using System.Collections.Generic;

class GameDataSaveLoadExample
{
    static void Main()
    {
        ApplicationController app = new ApplicationController();
        app.InitGame();
        app.TestSavingAndLoading();
        
    }        
}

public class ApplicationController {

    private List<SaveableWorldObject> saveableWorldObjects;
    private int musicVolume;
    private int soundsVolume;
    
    //Instantiate some "world objects" and set random values for music and sounds volume
    public void InitGame() {
        Random rand = new Random(); //Random number generator

        //Obviously id would be something auto-generated and unique instead of hard-coded values 1, 2, 3 and 4...
        Player player1 = new Player(1, "Player 1", rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-90, 90), rand.Next(-90, 90), rand.Next(-90, 90));
        Enemy goblin = new Enemy(2, "Goblin", rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-90, 90), rand.Next(-90, 90), rand.Next(-90, 90));
        Enemy orc = new Enemy(3, "Orc", rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-10, 10),rand.Next(-90, 90), rand.Next(-90, 90), rand.Next(-90, 90));
        MovingPlatform elevator1 = new MovingPlatform(4, "Elevator1", rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-10, 10), rand.Next(-90,90),rand.Next(-90, 90),rand.Next(-90, 90));

        saveableWorldObjects = new List<SaveableWorldObject>() { player1, goblin, orc, elevator1 };
        musicVolume = rand.Next(0, 100);
        soundsVolume = rand.Next(0, 100);

        //Now that everything is initialized, let's print initial state of objects:
        PrintCurrentGameState(saveableWorldObjects, musicVolume, soundsVolume, "INIT STATE");

        Console.WriteLine("NEW GAME INITIALIZED...\n");
    }

    //Save initial state of the game, change the state, save that state and then try loading states
    public void TestSavingAndLoading()
    {
        //Combine everything we want to save/load to one serializable SaveData object
        SaveData stuffWeWantToSave = new SaveData(saveableWorldObjects, musicVolume, soundsVolume);

        //Save in string format that is of my own design and doesn't follow any standards. 
        //It's commonly used format to save data with semicolon or colon and eol splitting, e.g. .CSV,
        //but the order of data (how to read it later) is only "known" by me...
        SaveGameStateInTextFormat(stuffWeWantToSave);

        //Move objects and print their state after that
        Console.WriteLine("Game is being played and objects move around and player adjusts settings...\n");
        MoveObjects(ref saveableWorldObjects, ref musicVolume, ref soundsVolume);
        PrintCurrentGameState(saveableWorldObjects, musicVolume, soundsVolume);

        //Load text file to restore initial state
        LoadTextGameState();
        PrintCurrentGameState(saveableWorldObjects, musicVolume, soundsVolume, "LOADED (TEXT) STATE");
    }

    //Print current state of the game
    public void PrintCurrentGameState(List<SaveableWorldObject> saveables, int musicVol, int soundsVol, string heading = "CURRENT GAME STATE")
    {
        Console.WriteLine("::: " + heading + ":::\n");
        Console.WriteLine("Music: " + musicVol);
        Console.WriteLine("Sounds: " + soundsVol + "\n\nOBJECTS:");
        saveables.ForEach(saveableObj => Console.WriteLine(saveableObj.UniqueID + ": " + saveableObj.Name + " | pos: " + saveableObj.PosX + ", " + saveableObj.PosY + ", " + saveableObj.PosZ + " | rot: " + saveableObj.RotX + ", " + saveableObj.RotY + ", " + saveableObj.RotZ));
        Console.WriteLine("---\n");
    }

    //Randomly changes values of "world objects"
    public void MoveObjects(ref List<SaveableWorldObject> worldObjects, ref int musicVol, ref int soundsVol)
    {
        Random rand = new Random();
        
        //Set new random volumes as well
        musicVol = rand.Next(0, 100);
        soundsVol = rand.Next(0, 100);

        //New random positions for each saveable object:
        worldObjects.ForEach(obj => {
            obj.PosX = rand.Next(-10, 10);
            obj.PosY = rand.Next(-10, 10);
            obj.PosZ = rand.Next(-10, 10);
            obj.RotX = rand.Next(-90, 90);
            obj.RotY = rand.Next(-90, 90);
            obj.RotZ = rand.Next(-90, 90);
        });
    }

    //Save in text format
    public void SaveGameStateInTextFormat(SaveData saveData)
    {
        //Form a string that can be later parsed
        string stringToSave = saveData.MusicVolume + "\n"; //first line: music volume, new line
        stringToSave += saveData.SoundsVolume + "\n"; //second line: sounds volume, new line

        //Parse all saveables and concat to string. Split saveable data with semicolons and new lines...
        saveData.Saveables.ForEach(saveable =>
        {
            //id; name; posx; posy; posz and new line for each saveable object
            stringToSave += saveable.UniqueID + ";" + saveable.Name + ";" + saveable.PosX + ";" + saveable.PosY + ";" + saveable.PosZ + ";" +saveable.RotX + ";" + saveable.RotY + ";" + saveable.RotZ + "\n";
        });

        FileStream fs = new FileStream("Sillanpaa_Janne_SavedGameText.txt", FileMode.Create); //Create or overwrite file

        byte[] info = new UTF8Encoding(true).GetBytes(stringToSave); //to byte array
        fs.Write(info, 0, info.Length); //write array content to file

        //Close file stream
        fs.Close();
    }
    
    //Load saved game state from text file
    public void LoadTextGameState()
    {
        FileStream fs = new FileStream("Sillanpaa_Janne_SavedGameText.txt", FileMode.Open); //open text file for reading
        StreamReader reader = new StreamReader(fs); //pass stream to StreamReader
        string fileContents = reader.ReadToEnd();

        //Parse string using splitting...

        //First we can split file's content to lines (separated by "\n" newline)
        string[] lines = fileContents.Split(new[] { "\n" }, StringSplitOptions.None );
        
        //First two lines in our save file format are music and sounds volume:
        musicVolume = Int32.Parse(lines[0]);
        soundsVolume = Int32.Parse(lines[1]);
        
        //New list for objects that we load (and parse) from the file:
        List<SaveableWorldObject> loadedObjects = new List<SaveableWorldObject>();

        //Rest of the lines are saveable world objects that we still need to split by semicolon to create saveableWorldObjects of them
        for (int objLine = 2; objLine < lines.Length - 1; objLine++)
        {
            string[] objData = lines[objLine].Split(new[] { ";" }, StringSplitOptions.None);

            //New object instance from loaded data:
            SaveableWorldObject loadedSaveable = new SaveableWorldObject(Int32.Parse(objData[0]), objData[1], float.Parse(objData[2]), float.Parse(objData[3]), float.Parse(objData[4]), float.Parse(objData[5]), float.Parse(objData[6]), float.Parse(objData[7]));

            //Add to list:
            loadedObjects.Add(loadedSaveable);
        }
        
        saveableWorldObjects = loadedObjects;
        
    }
}

//All classes referenced by SaveData (including itself) must be marked as Serializable or BinaryFormatter will throw an exception
[Serializable]
public class SaveData {

    public List<SaveableWorldObject> Saveables;
    public int MusicVolume;
    public int SoundsVolume;
        
    public SaveData(List<SaveableWorldObject> saveables, int musicVol, int soundsVol)
    {
        Saveables = saveables;
        MusicVolume = musicVol;
        SoundsVolume = soundsVol;
    }
}

[Serializable]
public class SaveableWorldObject
{
    //We need to know which object we're saving/loading...
    public int UniqueID = 0;
    
    //Let's also give objects some string name to make something more human-readable
    public string Name;

    /*
     * Local/world position with separate components. 
     * Of course we would need rotation (quaternion) as well, 
     * but to keep this example simple enough it's been left out...
    */ 

    public float PosX;
    public float PosY;
    public float PosZ;
    public float RotX;
    public float RotY;
    public float RotZ;

    public SaveableWorldObject(int id, string name, float posX, float posY, float posZ, float rotX, float rotY, float rotZ)
    {
        UniqueID = id;
        Name = name;
        PosX = posX;
        PosY = posY;
        PosZ = posZ;
        RotX = rotX;
        RotY = rotY;
        RotZ = rotZ;
    }
}

[Serializable]
public class Player : SaveableWorldObject
{    
    public Player(int id, string name, float posX, float posY, float posZ, float rotX, float rotY, float rotZ) : base(id, name, posX, posY, posZ, rotX, rotY, rotZ) { }
    //Player methods...
}

[Serializable]
public class Enemy : SaveableWorldObject
{    
    public Enemy(int id, string name, float posX, float posY, float posZ, float rotX, float rotY, float rotZ) : base(id, name, posX, posY, posZ, rotX, rotY, rotZ) { }
    //Enemy methods...
}

[Serializable]
public class MovingPlatform : SaveableWorldObject
{
    public MovingPlatform(int id, string name, float posX, float posY, float posZ, float rotX, float rotY, float rotZ) : base(id, name, posX, posY, posZ, rotX, rotY, rotZ) { }
    //Platform (or some other moving map object like door, trap etc.) methods...
}