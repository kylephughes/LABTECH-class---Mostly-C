/* clock.h -- header file for clock program
 *
 * Darren Provine, 17 July 2009
 */

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

#include "LEDisplay.h"

/* model prototypes */
void start_timer(void);

/* controller prototypes */
void tick(int);

/* view prototypes */
void show(struct tm *, int);
void ledshow(struct tm *, int,int);

