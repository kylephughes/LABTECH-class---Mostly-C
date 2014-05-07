/* assert.c -- show assertions
 *
 * NOTE: assert() is a macro, not a function!
 *       Assertions may not contain string literals!
 *
 * You can turn assertions off by compiling with '-DNDEBUG' as a
 * compiler flag.  So once your program is working, add that to
 * your Makefile, "make clean ; make" will rebuild without the
 * assertions.
 *
 * Do not take assertions out of your code; just add '-DNDEBUG'
 * to CFLAGS in the Makefile.  That way, if a bug you didn't know
 * about is reported, you can turn the assertions back on.
 *
 * DFP
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int  i;
    char name[] = "Bellatrix";
    char c = 'd';

    i = 5;

    assert(i < 6); // this will pass
    printf("Passed first assertion\n");

    assert(c == 'd'); // single char, okay
    printf("Passed second assertion\n");

    assert(strlen(name) > 0); // string by name, okay
    printf("Passed third assertion\n");

    assert(i == 6); // this will fail

    printf("Passed fourth assertion (should never get here)\n");

    return 0;
    
}
