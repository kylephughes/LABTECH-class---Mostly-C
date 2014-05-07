/* MakeList2.c - make a list of the characters we need
 *               (character version)
 *
 * D Provine, 2 November 2012
 *            1 January 2014
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int charnum;
    int person;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s name1 name2 name3 . . .\n", argv[0]);
        exit(1);
    }

    for (person = 1; person < argc; person++) {
        printf ("%9s: ", argv[person]);
        /* start with the space char */
        charnum = 0x20 + (person - 1);
        while (charnum <= 0x7e) {
            printf("%c", charnum);
            charnum += (argc - 1);
        }
        printf ("\n");
    }
}
