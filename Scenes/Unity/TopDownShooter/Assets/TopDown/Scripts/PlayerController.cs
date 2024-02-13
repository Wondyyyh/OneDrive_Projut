using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private float horizontalInput = 0.0f;
    public float speed = 5.0f;
    public float xlimit = 10.0f;
    public GameObject projectile;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Instantiate(projectile, transform.position, projectile.transform.rotation);
        }


        horizontalInput = Input.GetAxis("Horizontal");
        transform.position += new Vector3(horizontalInput*Time.deltaTime*speed, 0.0f, 0.0f);

        if(transform.position.x > xlimit)
        {
            transform.position = new Vector3(xlimit, transform.position.y, transform.position.z);
        }
        if (transform.position.x < -xlimit)
        {
            transform.position = new Vector3(-xlimit, transform.position.y, transform.position.z);
        }
    }
}
