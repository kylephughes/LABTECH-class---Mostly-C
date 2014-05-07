/* buggy.C -- fill an array with multiples of two
 *            and then print it out backwards.
 * by Darren Provine
 * Known bugs: yes!
 */
#include <iostream>
using namespace std;

main()
{
  int i, a[5];

  // fill in multiples of two
  for (i = 0; i < 5; i++)
    a[i] = i*2;

  // i = 5, but the array is 0-4, so
  // now we back up one
  i--;

  // print the array, going backwards
  while (i >= 0) {
    cout << a[i] << " ";
    i++;
  }
  cout << endl;
}
