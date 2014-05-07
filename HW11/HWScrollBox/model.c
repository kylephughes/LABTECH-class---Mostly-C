/* model.c -- Data and Timing for the Scroll Box
 *
 * Kyle Hughes
 */

#include "scroll.h"
#include <string.h>

/* the message that we're scrolling */
char scrollmessage[256];


/* pad scrollmessage with 9 spaces left and right */
void setup(char *text)
{

  
    sprintf(scrollmessage, "         %s         ", text);
         if (debug >= 2) {
             fprintf(stderr, "text is: |%s|\r\n", scrollmessage);
             sleep(5);
	 }
    }



/* declared outside function so pointer is valid when passed */
char viewport[9];
char *display_string(int TEST)
{
    
  //    int i;
  //   int startpos;
    static int step = 0; // initialization only happens once


    
     if(TEST == 1) {
       strcpy(viewport, "TESTING");
      }
        else{
      strncpy(viewport, &(scrollmessage[step]), 9);

       }

    if (debug >= 4) {
        fprintf(stderr, "viewport: |%s|\r\n", viewport);
        sleep(1);
    }

    step ++;
    if (step > strlen(scrollmessage) - 9)
      step = 0;

    return &viewport[0];
}


/* Set up an interval timer for our scroll box.
 * This is part of the model; as with the clock, it's what actually
 * measures real time passing.
 * When the interval is over, notify tick(), which is part of the
 * controller for this program.
 */
void start_timer(int delay)
{
    struct itimerval interval; // interval object
    struct sigaction new_action, old_action;  // signal actions

    // blank out the signal mask
    sigemptyset( &new_action.sa_mask );
    // clear flags (our application is pretty simple)
    new_action.sa_flags = 0;
    // set tick() as the signal handler when we get the timer signal.
    new_action.sa_handler = tick;
 
    /* sigaction takes a pointer as an argument, so you have to
     * allocate space.  The declaration of new_action() up above
     * has no star - that's the actual object, not just a pointer.
     */
    if ( sigaction(SIGALRM, &new_action, &old_action) == -1 ) {
        perror("Could not set new handler for SIGALRM");
        exit(1);
    }

    /* set interval to the specified delay value. */
    if (delay == 0) {   //fast
      interval.it_value.tv_sec = 0; // seconds
        interval.it_value.tv_usec = 200000;
        interval.it_interval = interval.it_value;
    } 
    else{
      if(delay == 1){   //slow
        interval.it_value.tv_sec = 3;
        interval.it_value.tv_usec = 0;
        interval.it_interval = interval.it_value;
    }

      else{  //5 second clock
      if(delay == 4){
	interval.it_value.tv_sec = 1;
	interval.it_value.tv_usec = 0;
	interval.it_interval = interval.it_value;

      }

      else{          //normal
      
      interval.it_value.tv_sec = 1;
      interval.it_value.tv_usec = 0;
      interval.it_interval = interval.it_value;

      }
      }
    }
    /* set a timer for the real time clock using the interval object */
    /* NOTE: takes a pointer, so no * in our declaration of "interval */
    setitimer(ITIMER_REAL, &interval, NULL);
    }
