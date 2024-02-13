using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Rigidbody playerRb;
    public float gravityModifier = 2.0f;
    public float jumpForce = 600.0f;
    private bool bOnGround = true;
    private Animator playerAnim;
    public ParticleSystem explosionParticle;
    public ParticleSystem dirtParticle;
    public AudioClip jumpSound;
    public AudioClip crashSound;
    private AudioSource playerAudio;

    // Start is called before the first frame update
    void Start()
    {
        Physics.gravity *= gravityModifier;
        Debug.Log("Gravity" + Physics.gravity);
        playerAnim = GetComponent<Animator>();
        playerRb = GetComponent<Rigidbody>();
        playerAudio = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && bOnGround && !gameOver)
        {
            dirtParticle.Stop();
            playerRb.AddForce(transform.up * jumpForce, ForceMode.Impulse);
            bOnGround = false;
            playerAnim.SetTrigger("Jump_trig");
            playerAudio.PlayOneShot(jumpSound, 0.3f);
        }
    }
    public bool gameOver = false;

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            dirtParticle.Play();
            bOnGround = true;
        }
        else if (collision.gameObject.CompareTag("Obstacle"))
        {
            dirtParticle.Stop();
            explosionParticle.Play();
            gameOver = true;
            Debug.Log("Game Over!");
            playerAnim.SetBool("Death_b", true);
            playerAnim.SetInteger("DeathType_int", 1);
            playerAudio.PlayOneShot(crashSound, 0.3f);
        }
    }
}
