/* clock.c -- controller part of the clock project
 * clock with stopwatch functionality!
 * Kyle Hughes 4/08/14
 */

#include "clock.h"

/* CONTROLLER */

static char bugaddress[]="hughes7@students.rowan.edu";
char title_text[] = "                                This is Kyles clock                            ";

//struct tm * start (int);

// version -- say which version this is and exit
// (note simple output; you could also print the rcsid too)
void version()
{
    fprintf(stderr, "simple clock version 1\n");
    exit(0);
}

// usage -- print brief summary and instructions
void usage(char *progname)
{
    fprintf(stderr, "This program displays a realtime clock.\n");
    fprintf(stderr, "Usage: %s [-avh] [-o number]\n", progname);
    fprintf(stderr, "  -a    : am/pm instead of 24 hour\n");
    fprintf(stderr, "  -l    : use simulated LED display\n");
    fprintf(stderr, "  -o #  : offset the time by # seconds \n");
    fprintf(stderr, "  -v    : show version information\n");
    fprintf(stderr, "  -h    : this help message\n");
    fprintf(stderr, "report bugs to %s \n", bugaddress);
    exit (0);
}

/* These have to be global because tick() is called
 * automatically; we can't pass it any arguments because
 * we don't call it.
 */

int stoptime =0;  //amount of time the timer is stopped
int offset = 0;
int ampm = 0;
int LED  = 0;
int MODE_TIMER= 0; 
int TIMER_RUNNING = 0;
time_t TIMER_START = 0;
time_t TIMER_PAUSE = 0;  //gets the time the stop button is pushed
int STOP_TIME =0;        //handles the case when stop is pressed 
int firstimestart =0;    
time_t FIRST_TIME = 0;   //gets the time when start is clicked for the first
void start_timer_run()   //time
{
  (void) time(&TIMER_START);
  //get the time you are stopped until the time start is pressed again
  if(firstimestart<1 || firstimestart >1)
    stoptime+= (TIMER_START-TIMER_PAUSE);
    TIMER_RUNNING = 1;

}
void process_key(keybits KeyCode)
{
  void stop_clock(void);
  int KeyRow, KeyCol,therow,thecol;
  if (KeyCode & 0x80) {
    therow = KeyCode >>4;
    thecol = KeyCode & 15;
    KeyRow = therow & 7;
    KeyCol = thecol;

    //second row used for timer(start,stop,reset,done)
    if(KeyRow == 1){

      switch(KeyCol){
      case 0:

	if(firstimestart == 0){        //when  we first start clock
	  (void)time(&FIRST_TIME);
	}
        firstimestart++;
        MODE_TIMER = 1;    
	STOP_TIME = 0;
      	start_timer_run();
	break;
      case 1: 

	STOP_TIME= 1;
        (void) time(&TIMER_PAUSE);  
	break;

      case 2:
	stoptime=0;     
	firstimestart=0;
	STOP_TIME = 0;
	TIMER_RUNNING = 0;
        (void) time(&TIMER_START);
	break;
      case 3:
	set_key_text(0,"");
	set_key_text(1,"");
	set_key_text(2,"");
	set_key_text(3,"");
       	MODE_TIMER = 0;   //go back to normal clock
        TIMER_RUNNING = 0;
	ampm =0;
	stoptime=0;
	STOP_TIME=0;
	firstimestart=0;
	break;
	  }
    }
    //initial set of buttons
    if (KeyRow == 0) {
      switch (KeyCol) {     
      case 0: 
	stoptime = 0;
	MODE_TIMER = 0;         // 24h
	ampm =0;
	break;
      case 1:
	MODE_TIMER = 0;
	ampm =1;               //ampm
	break;
      case 2:
	set_key_text(0,"Start");   //timer
	set_key_text(1,"Stop");
	set_key_text(2,"Reset");
	set_key_text(3,"Done");

	MODE_TIMER = 1;
	break;
      case 3:
	MODE_TIMER= 2;       //test
	
	break;
      case 4:
	stop_clock();        //quit
	break;
      }
    }
  } else { // keystroke
    switch(KeyCode) {
    case '2':
      ampm = 0;
      break;
    case 'a':
      ampm = 1;
      break;
    case 'q':
      stop_clock();
      break;
    }
  }
}


void stop_clock()
{
  end_display();
  exit(0);
}

int main(int argc, char *argv[])
{
    int letter;  // option character
    
    // loop through all the options; getopt() can handle together or apart
    while ( ( letter = getopt(argc, argv, "alo:vh")) != -1 ) {
        switch (letter) {
            case 'a':  ampm = 1;               break;
            case 'l':  LED  = 1;               break;
            case 'o':  offset = atoi(optarg);  break;
            case 'v':  version();              break;
            case 'h':  usage(argv[0]);         break;

            case '?':  // unknown flag; fall through to next case
            default:   // shouldn't happen, but Just In Case
                       // note that getopt() warns about the unknown flag
                  fprintf(stderr, "run \"%s -h\" for help\n", argv[0]);
                  exit(1);
        }
    }

    if (LED) { // set up the fancy display
      start_display();
      set_title_bar(title_text);
      register_keyhandler(process_key);
    }

    /* get the model running */
     start_timer();

    while (1) {
      get_key();
    }

    /* no return because never reached */
}

/* This function is called when the timer ticks.
 * Then it calls the show() function, which is our View.
 * The Controller talks to the Model and the View.
 *
 * Note we ignore the argument!
 * sigaction() arranges to pass us the signal that caused the function
 * to be called, so you can use one signal handler for multiple signals.
 * But we only catch one signal, so no need to worry about it.
 */
void tick(int sig)
{

     time_t now;
     struct tm *dateinfo; 
     int seconds, hours, minutes;
     int stopsince=0;    

     (void) time(&now);
     now += offset;
     dateinfo = localtime(&now);
    

 //sets timer to all 0 when timer is clicked
     if(MODE_TIMER == 1){

	 dateinfo->tm_hour = 00;
	 dateinfo->tm_min = 00;
	 dateinfo->tm_sec = 00;
	
      }     
     //start button is clicked
    if (MODE_TIMER && TIMER_RUNNING) {
    
       seconds = (now - FIRST_TIME - stoptime);
       hours = seconds / 3600;
       seconds = seconds - (hours * 3600);
       minutes = seconds / 60;
       seconds = seconds - (minutes * 60);
       dateinfo->tm_hour = hours;
       dateinfo->tm_min = minutes;
       dateinfo->tm_sec = seconds;
       
     }
    //handles what to display when stop is pressed
    if(STOP_TIME){
      stopsince = (TIMER_PAUSE - FIRST_TIME) - stoptime;
      hours = stopsince/3600;
      stopsince = stopsince - (hours *3600);
      minutes = stopsince /60;
      stopsince = stopsince - (minutes *60);
      
        dateinfo->tm_hour = hours;
	dateinfo->tm_min = minutes;
	dateinfo->tm_sec = stopsince;
    }    

    /* call View to show the time */
  if (LED){
      ledshow(dateinfo, ampm, MODE_TIMER);
                 //adjusted header file
}
    else
      show(dateinfo, ampm);
  }
