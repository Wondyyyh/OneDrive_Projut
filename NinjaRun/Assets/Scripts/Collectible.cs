using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Collectible : MonoBehaviour
{
    
    public AudioClip collectibleSound;
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
        if (collision.gameObject.tag != "Projectile")
        {
            AudioSource.PlayClipAtPoint(collectibleSound, transform.position, 1f);
            Destroy(gameObject);
            FindObjectOfType<ScoringSystem>().ScorePoints();
            
        }
        
    }
}
