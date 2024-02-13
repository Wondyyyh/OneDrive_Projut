using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ScoringSystem : MonoBehaviour
{
    public GameObject scoreText;
    public int TheScore;
    public GameObject winningText;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void ScorePoints()
    {
        TheScore += 10;
        scoreText.GetComponent<Text>().text = "Score: " + TheScore;
    }
    public void ScoreEnemyPoints()
    {
        TheScore += 100;
        scoreText.GetComponent<Text>().text = "Score: " + TheScore;
        Invoke("checkScore", 0.5f);
    }
    void checkScore()
    {
        if (TheScore >= 120)
        {
            scoreText.SetActive(false);
            winningText.SetActive(true);
            Invoke("MainMenu", 1.5f);
            
        }
    }
    void MainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}
