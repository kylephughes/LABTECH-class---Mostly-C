/* view.c -- view module for clock project
 * with added functionality!!
 * Kyle Hughes 4/08/14
 */

#include "clock.h"
#include "string.h"
/* VIEW */

/* We get a pointer to a "struct tm" object, put it in a string, and
 * then send it to the screen.
 */
void ledshow(struct tm *dateinfo, int ampm, int modetimer)
{
    char       timestring[9];
    digit *where = get_display_location();
    int i;
    //handles the test event
     if(modetimer ==2){
       dateinfo->tm_hour =88;
       dateinfo->tm_min = 88;
       dateinfo->tm_sec = 88;
       sprintf(timestring,"%02d%02d%02d",dateinfo->tm_hour,dateinfo->tm_min,
	       dateinfo->tm_sec);
     }
    else{
      //handles the timer event
       if(modetimer == 1){
	 sprintf(timestring,"%02d%02d%02d",dateinfo->tm_hour,dateinfo->tm_min,
   	      dateinfo->tm_sec);      
      }
        else{
   
 // handles am/pm mode otherwise use 24h mode
    if(ampm ==1)
      strftime(timestring,9,"%I%M%S",dateinfo); 
     else{
      if(ampm ==0){
        sprintf(timestring,"%02d%02d%02d",
	      dateinfo->tm_hour,
	      dateinfo->tm_min,
	      dateinfo->tm_sec);
        }       
      }
     }
       }
    for (i = 0; i < 6; i++) {
       switch ( timestring[i] ) {
           case ' ': where[i] = 0x00; break;
           case '1': where[i] = 0x24; break;
           case '2': where[i] = 0x5d; break;
           case '3': where[i] = 0x6d; break;
           case '4': where[i] = 0x2e; break;
           case '5': where[i] = 0x6b; break;
           case '6': where[i] = 0x7b; break;
           case '7': where[i] = 0x25; break;
           case '8': where[i] = 0x7f; break;
           case '9': where[i] = 0x2f; break;
           case '0': where[i] = 0x77; break;
       }
    }
 
    char mode[9];
    
    //determine which indicators should be turned on
    //handles timer and test cases
    if(modetimer ==2){
      where[6]=0xf7;

    }
    else{
    if(modetimer == 1)
      {
	where[6]= 0xf0;
      }
    else{
      //normal clock mode
    if(ampm ==1){
      strftime(mode,9,"%p",dateinfo);
      if(strcmp(mode,"AM") == 0)
	{
	  where[6]= 0xf2;
	}
      else{
	  where[6] = 0xf4;
      }
    }
    else{
          where[6] = 0xf1;
    }
    }
    }
    display();
    fflush(stdout);
}

void show(struct tm *dateinfo, int ampm)
{
    char       timestring[9];

    // handles am/pm mode otherwise use 24h mode
    if(ampm == 1){
      strftime(timestring,80,"%I:%M:%S%p",dateinfo);
      printf("\r%s", timestring);
    }
    else{
      sprintf(timestring,
	      "%02d:%02d:%02d",
	      dateinfo->tm_hour,
	      dateinfo->tm_min,
	      dateinfo->tm_sec);
      printf("\r%s",timestring);

    }
    fflush(stdout);
}
