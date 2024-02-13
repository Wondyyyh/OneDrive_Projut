using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyerScript : MonoBehaviour
{
    public string keyword;
    // Awake is called when the script instance is being loaded
    private void Awake()
    {
        Debug.Log("Destroyer is awake!");
    }
    // This function finds one object having keyword in its name and destroys it
    private void DestroyOne()
    {
        GameObject gobj = GameObject.Find(keyword);
        Destroy(gobj);
        Debug.Log("DestroyOne() -function was called.");
    }
    // Start is called before the first frame update
    void Start()
    {
        InvokeRepeating("DestroyOne", 5.0f, 1.0f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
