using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveForward : MonoBehaviour
{
    float speed = 40;
    float startpos;
    float maxDistance = 40;
    // Start is called before the first frame update
    void Start()
    {
        startpos = transform.position.x;
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Vector2.right * Time.deltaTime * speed);
        if (transform.position.x > startpos + maxDistance || transform.position.x < startpos - maxDistance)
        {
           Destroy(gameObject);
        }
       
    }
   
    
}
