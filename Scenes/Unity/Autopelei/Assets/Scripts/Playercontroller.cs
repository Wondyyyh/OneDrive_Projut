using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Playercontroller : MonoBehaviour
{
    public int speed = 20;
    public float turnSpeed;
    public float horizontalinput;
    public float forwardInput;
    // Start is called before the first frame update
    void Start()
    {
        
    }
    void Update()
    {
        //get input keys and multiplayer from unity InputAxis preset
        horizontalinput = Input.GetAxis("Horizontal");
        forwardInput = Input.GetAxis("Vertical");

        transform.Translate(Vector3.forward * Time.deltaTime * speed * forwardInput);
        transform.Rotate(Vector3.up, horizontalinput * Time.deltaTime * turnSpeed * forwardInput);
    }
}
