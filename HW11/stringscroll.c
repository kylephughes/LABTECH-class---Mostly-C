/* stringscroll.c - scroll a string
 *
 * D Provine and The Usual Suspects, 15 April 2014
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 255
#define DISPLAYSIZE 16

int main(int argc, char *argv[])
{
    char scrollmessage[BUFSIZE] = "";
    char visible[DISPLAYSIZE + 1];
    int  i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s string\n", argv[0]);
        exit(1);
    }

    for (i = 0; i < DISPLAYSIZE; i++)
        strncat(scrollmessage, " ", 1);

    strncat(scrollmessage, argv[1], BUFSIZE - 1 - DISPLAYSIZE - DISPLAYSIZE);

    for (i = 0; i < DISPLAYSIZE; i++)
        strncat(scrollmessage, " ", 1);


    for (i = 0; i <= strlen(scrollmessage) - DISPLAYSIZE; i++) {
        strncpy(visible, &(scrollmessage[i]), DISPLAYSIZE);
        visible[DISPLAYSIZE] = '\0';
        printf(" |%s|\r", visible);
        fflush(stdout);
        usleep(100000);
    }

    printf("\n");
    return 0;
}
