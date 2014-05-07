#include <iostream>
using namespace std;

class IntStack
{
 private:

  // linked list structure
  struct ListItem {
    int	       data;
    ListItem  *next;
  };

  // top of the stack
  ListItem *top;

 public:
  // constructor: make an empty stack;
  IntStack()  { top = NULL; }

  // destructor: clean up remaining entries, if any
  ~IntStack() {
    ListItem *killme = top;
    while (killme) {
      top = killme->next;
      delete killme;
      killme = top;
    }
  }

  // put something on the stack
  void push(int i) {
    ListItem *holder = new ListItem();
    holder->data = i;
    holder->next = top;
    top = holder;
  }

  // take something off the stack
  int pop() {
    ListItem *holder = top;
    int data = top->data;
    top = top->next;
    delete holder;
    return data;
  }

  // check for empty
  bool isEmpty() {
    return top == NULL;
  }
};

main()
{
  IntStack tester;
  int i;

  for (i = 0; i < 5; i++) 
    tester.push(i);

  for (i = 0; i <= 5; i++)
    cout << tester.pop() << " ";
  cout << endl;
}
