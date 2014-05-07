/* fibonacci.c -- compute Fibonacci numbers
 *
 * by Darren Provine, 24 April 2003
 * debugging example
 */

/* Fibonacci numbers are the sequence where each number is the
 * sum of the previous two.  That is, they go like this:
 *     1 1 2 3 5 8 13 21 34 55 89 . . .
 * Obviously, you have to pick two starting numbers.
 */

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 4;

main()
{
  int  x = 0, a[ARRAY_SIZE];

  cout << "x = " << x << endl;

  // initialize Fibonacci series
  a[0] = 1;
  a[1] = 1;

  // fill each element of array with sum of previous two
  for (int i=0; i <= ARRAY_SIZE; i++)
    a[i+2] = a[i+1] + a[i];

  // print series
  for (int i=0; i <= ARRAY_SIZE; i++)
    cout << "a[" << i << "] = " << a[i] << endl;

  cout << "x = " << x << endl;
}
