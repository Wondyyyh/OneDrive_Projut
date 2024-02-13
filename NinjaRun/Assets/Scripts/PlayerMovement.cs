using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    private float runSpeed = 400f;
    float horizontalMove = 0f;
    bool inAir = false;
    bool Glide = false;
    //bool space = false;
    private Rigidbody2D rb;
    private Vector3 m_velocity = Vector3.zero;
    public GameObject Bullet;
    private Vector3 slideoffset = new Vector3(0, -0.25f, 0);
    public Collider2D Collider;

    //bool slide = false;

    public Animator Animator;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }
    void FixedUpdate()
    {
        //Left Right MOVING!!
        horizontalMove = Input.GetAxisRaw("Horizontal");
        Animator.SetFloat("Speed", Mathf.Abs(horizontalMove));


        rb.velocity = new Vector2(horizontalMove * Time.deltaTime * runSpeed, rb.velocity.y);

    }
    
    // Update is called once per frame
    void Update()
    {

        //Jumppaa
        if (Input.GetButtonDown("Jump") )
        {
            if (inAir == false)
            {
                rb.AddForce(new Vector2(0f, 600f), ForceMode2D.Impulse);

                Animator.SetBool("jump", true);
                Animator.SetBool("IsInAir?", true);
                inAir = true;

            }
            //Glide thingerino
            else
            {
                Animator.SetBool("Glide", true);
                Animator.SetBool("jump", false);
                Glide = true;
                rb.gravityScale = 0.5f;
            }
          
        }
        //Sliding thingerino
        if (Input.GetKeyDown(KeyCode.LeftShift) && inAir == false)
        {
            if(horizontalMove != 0)
            {
                Collider.offset = new Vector2(0f, -0.6f);
                Animator.SetBool("Slide", true);
            }
          
        }

        if (Input.GetKeyUp(KeyCode.LeftShift))
        {
            Collider.offset = new Vector2(0f, -1.22f);
            Animator.SetBool("Slide", false);
            

        }

        //ATTACK
        if (Input.GetKeyDown(KeyCode.Q) && Glide == false)
        {
            attack();
        }

        void attack()
        {

           Animator.SetTrigger("Attack");
 
        }

        Vector3 offset;
        offset = new Vector3(2, 0, 0);
        //Firing darts!!!!
        if (Input.GetKeyDown(KeyCode.E) && Glide == false)
        {
            Animator.SetBool("Fire", true);
            if (transform.rotation.y == 0)
            {
                Instantiate(Bullet, transform.position + offset, transform.rotation);
            }
            else
            {
                Instantiate(Bullet, transform.position - offset, transform.rotation);
            }
        }
        if (Input.GetKeyUp(KeyCode.E))
        {
            Animator.SetBool("Fire", false);
        }

        //Rotate Player Sprite
        if (horizontalMove < 0)
        {
            transform.rotation = Quaternion.Euler(0, -180, 0);
        }
        if (horizontalMove > 0)
        {
            transform.rotation = Quaternion.Euler(0, 0, 0);
        }

    }
    //Reset things when colliding with ground
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Ground")
        {
            Animator.SetBool("IsInAir?", false);
            Animator.SetBool("Glide", false);
            Animator.SetBool("jump", false);
            inAir = false;
            Glide = false;
            rb.gravityScale = 3;
        }
    }
}
