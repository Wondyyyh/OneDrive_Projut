using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShowText : MonoBehaviour
{
    public GameObject GuideText;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnTriggerEnter2D(Collider2D collision)
    {

        if (collision.gameObject.tag == "Player")
        {
            GuideText.SetActive(true);
        }
        if (GuideText.tag == "ThisOne")
        {
            GameObject.Find("Player").GetComponent<BoxCollider2D>().enabled = true;

        }
    }
    void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            GuideText.SetActive(false);
        }
    }
}
