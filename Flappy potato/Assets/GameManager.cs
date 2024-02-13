using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{



    // Start is called before the first frame update
    void Start()
    {
        Time.timeScale = 1;
        gameOverCanvas.SetActive(false);
    }


    public GameObject gameOverCanvas;

    public void GameOver()
    {
        gameOverCanvas.SetActive(true);
        Time.timeScale = 0;
    }

    public void Replay()
    {
        SceneManager.LoadScene(0);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
