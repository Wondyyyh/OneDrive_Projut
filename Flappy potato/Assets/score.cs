using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class score : MonoBehaviour
{
    public static int points = 0;

    void Start()
    {
        points = 0;
    }

    void Update()
    {
        GetComponent<UnityEngine.UI.Text>().text = points.ToString();
    }
}
