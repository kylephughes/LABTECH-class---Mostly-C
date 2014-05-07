/* Stack.java -- a simple stack class with linked lists
 *
 * by Darren Provine, 28 April 1999
 */

class StackItem
{
    Object	item;
    StackItem	next;
}

public class Stack_bug
{
    private StackItem top_;

    public Stack_bug()
    {
        top_ = null;
    }

    public boolean isEmpty()
    {
        return (top_ == null);
    }

    public void push(Object doohickey)
    {
        StackItem holder = new StackItem();
        holder.item = doohickey;
        holder.next = null;
        holder.next = top_;
        top_ = holder;
    }

    public Object pop()
    {
        StackItem holder;
        holder = top_;
        top_ = top_.next;
        return holder.item;
    }

    public static void main(String argv[])
    {
        Stack_bug tester = new Stack_bug();
        int i;

        for (i = 0; i < 5; i++) {
            tester.push(new Integer (i) );
        }
        for (i = 0; i <= 5; i++) {
            System.out.println(tester.pop());
        }
    }
}
