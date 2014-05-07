/* main.c - main section of "trig" project
 *
 * DFP
 */

#include <stdlib.h>
static char rcsid[] =
  "$Id: main.c,v 1.4 2014/03/27 17:20:55 hughes72 Exp $";
int main(int argc, char *argv[])
{
  double angle;
  void sine(double), cosine(double), tangent(double);

  if (argc < 2) {
      angle = 45.0;
  } else {
      angle = strtod(argv[1], NULL);
  }
  angle = angle/180.00 * 3.1459265;
  sine(angle);
  cosine(angle);
  tangent(angle);

  return 0;
}
