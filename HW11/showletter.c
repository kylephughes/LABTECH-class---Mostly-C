/* showletter.c - show a letter from the character list
 *  prints multiple characters in one command!
 *K.Hughes 4/13/14
 */

#include <stdio.h>
#include <stdlib.h>
#include "Chars/All_Chars.h"
#include <string.h>
int main(int argc, char *argv[])
{
    int line;
    int bit;
    int charnum;
    int arraypos;
    int total[strlen(argv[1])];
    int i; 
    int pos[strlen(argv[1])];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s letter", argv[0]);
        exit(1);
      }
    
    //retrieve all letters in first argument to be used later
    for (i=0;i< strlen(argv[1]);i++){
       total[i] = (int)argv[1][i];
       pos[i] = total[i] - 0x20;
      }

    for (line = 0; line < 10; line++) {
      	  for(i =0;i<strlen(argv[1]);i++){
	    for(bit = 7; bit >=0; bit--){
	    if ((*glyph[pos[i]])[line] & ( 1 << bit) ) 
                printf("@");
            else
                printf(" ");
	    }
	  }
  	printf("\n");   
     }
   
    return 0;
}

