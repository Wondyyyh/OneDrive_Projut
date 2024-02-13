using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InstantiatorScript : MonoBehaviour
{
    public int NumbObjects = 15;
    public int numRows = 3;
    public GameObject WhatToSpawn;
    private float xRange = 10.0f;
    private float zRange = 10.0f;


    // Start is called before the first frame update
    void Start()
    {
        //loop from 0 - NumbObjects-1
        for (int i = 0; i < NumbObjects; i++)
        {
            float x, y, z;
            //get random position for object
            x = i*Random.Range( -xRange, xRange);
            y = 10;
            z = Random.Range( -zRange, zRange);

            //instantiate new object
            Debug.Log("New object position: " + x + ", " + y + ", " + z);
            Instantiate(WhatToSpawn, new Vector3(x, y, z), WhatToSpawn.transform.rotation);
        }

    }

    // Update is called once per frame
    void Update()
    {

    }
}
