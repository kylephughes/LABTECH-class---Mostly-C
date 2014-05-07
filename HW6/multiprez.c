/* multiprez.c - Write Information About Multiple Presidents
 *
 * D Provine
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char           inits[4];
    unsigned char  num;
} prezinfo;

int main()
{
    prezinfo  person[4];
    FILE     *saveit;

    strcpy(person[0].inits, "GW");
    person[0].num = 1;
    strcpy(person[1].inits, "JM");
    person[1].num = 4;
    strcpy(person[2].inits, "WHH");
    person[2].num = 9;
    strcpy(person[3].inits, "AL");
    person[3].num = 16;

    saveit = fopen("prez.dat", "w");

    printf("%d\n", fwrite(person, sizeof(prezinfo), 4, saveit));

    fclose(saveit);

    return 0;
}

