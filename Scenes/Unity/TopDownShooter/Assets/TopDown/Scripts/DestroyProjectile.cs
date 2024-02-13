using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyProjectile : MonoBehaviour
{
    public float zlimit = 30.0f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

        if (transform.position.z > zlimit)
        {
            Destroy(gameObject);
            Debug.Log("Destroy -function was called.");
        }
    }
}
