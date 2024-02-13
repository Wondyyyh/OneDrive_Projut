using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    public AudioClip DeathSound;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.tag == "Projectile")
        {
            AudioSource.PlayClipAtPoint(DeathSound, transform.position, 1f);
            Destroy(gameObject);
            FindObjectOfType<ScoringSystem>().ScoreEnemyPoints();
            Destroy(collision.gameObject);
        }

        if (collision.gameObject.tag == "Player")
        {
            collision.gameObject.transform.position = new Vector3(-5, -1.75f, 0);
        }

    }
   
}
