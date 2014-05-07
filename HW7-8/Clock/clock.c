/* clock.c -- controller part of the clock project
 *
 * Kyle Hughes 3/27/14
 */

#include "clock.h"

/* CONTROLLER */

static char bugaddress[]="hughes7@students.rowan.edu";
char title_text[] = "                                  This is kyles clock                          ";

struct tm * start (int);

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
int offset = 0;
int ampm = 0;
int LED  = 0;
int MODE_TIMER= 0; //figure out which mode we are in, (will change name)


void process_key(keybits KeyCode)
{
  void stop_clock(void);
  int KeyRow, KeyCol,therow,thecol;
  if (KeyCode & 0x80) {    //mouse hit
    therow = KeyCode >>4;
    thecol = KeyCode & 15;
    KeyRow = therow & 7;
    KeyCol = thecol;
    //TODO disable buttons after leaving the timer

    //second row used for timer(start,stop,reset,done)
    if(KeyRow == 1){
      switch(KeyCol){
      case 0:
	//      	MODE_TIMER = 1;     //doesnt work
        ledshow((struct tm *)start(1),ampm,1);
	start_timer();
	break;
      case 1: 
	pause();           //not sure
	  break;
  
      case 3:
	MODE_TIMER = 0;   //go back to normal clock
	ampm =0;
	break;
	  }
    }
    //initial set of buttons
    if (KeyRow == 0) {
      switch (KeyCol) {     
      case 0: 
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

    // All the flags have been scanned.
    // "optind" is now the index of the first non-option item

    


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
  //    time_t       now;
  //  struct tm   *dateinfo;  // localtime() returns a pointer, so it
                            // allocates space.  We just need a pointer.



    /* get current time into "struct tm" object */

    //    (void) time(&now);
    //  now += offset;
    //  dateinfo = localtime(&now);



    /* call View to show the time */
  if (LED){
    
      ledshow((struct tm *)start(MODE_TIMER), ampm,MODE_TIMER);  //adjusted header file
    
}
    else
      show((struct tm *)start(MODE_TIMER), ampm);
}

// in the works
struct tm * start(int mode){
  time_t now;
  struct tm *dateinfo;
  (void) time (&now);
  now+= offset;
  dateinfo = localtime(&now);
  //timer 
 if(mode == 1){                 // handles the start button in timer
   dateinfo->tm_hour = 00;
   dateinfo->tm_min = 00;
   dateinfo->tm_sec = 00;
 }

  //test
  if(mode == 2){
    dateinfo->tm_hour = 88;
    dateinfo->tm_min= 88;
    dateinfo->tm_sec = 88;

  }
 return dateinfo;


 }
