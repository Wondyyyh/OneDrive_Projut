using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class ChestScript : MonoBehaviour
{
    public Animator Animator;
    public GameObject Collectible;
    public GameObject Chest;

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
        if(collision.gameObject.tag != "Projectile")
        {
            
                Animator.SetBool("Collect", true);
                Invoke("SpawnCollectible", 0.3f);

        }
      
        
        
    }
    void SpawnCollectible()
    {
        Instantiate(Collectible, transform.position + new Vector3(0f, 0.7f, 0f), transform.rotation);
    }
    private void OnTriggerExit2D(Collider2D collision)
    {
        Animator.SetBool("Collect", false);
        GameObject gobj = GameObject.Find("Collectible(Clone)");
        if (GameObject.Find("Collectible(Clone)"))
        {
            Destroy(gobj);

        }
        else
        {
            Invoke("DestroyChest", 0.4f);
        }

    }
    public void DestroyChest()
    {
        Destroy(Chest);
    }
}
