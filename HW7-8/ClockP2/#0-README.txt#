VIRTUAL DIGITAL CLOCK

We're building a digital clock with an LED display.  Our company has
ordered a million LED clock faces delivered to the factory.

The company has sent us a file called "LED-layout.txt", which explains
which bits go where to turn on the LEDs.  They've also sent us a file
"LEDisplay.h", which has prototypes and declarations needed for our
compiler, and "LEDisplay.o", which has all the object code.  (They did
not send us the C source files, because they consider that to be a
trade secret.)

What we have to do is modify the View portion of our clock to use this
display instead of just using printf().  (We have to keep the old code
around for debugging purposes.)  The Controller handles flags about
which display to use, but it doesn't have offset ability, which
needs to be added.

I've already written the Makefile; you should read it to see what it's
doing.  (There are more macros than we had in earlier examples.)

Things To Notice:

1) "clock.h" now includes "LEDisplay.h".

2) The Makefile includes LIBRARY and INCLUDE macros, for some of the
   special features needed to do full-screen display.

3) A stub "ledshow()" is in "view.c", but it's just sample code.

4) "clock.c" has variables which go with the option flags, and they
   are global, not local, because they can't be passed.


What You Should Do Before You Start:

1) Figure out how to handle offsets.

2) Figure out am/pm.  Midnight should say "12:00:00 am", not set the
   hour to "00".  At noon, it should go from "11:59:59 am"
   to "12:00:00 pm".

3) Read "LED-layout.txt" and figure out on paper which bits make
   which numbers.  (Making sketches really does help.)


What Remains To Be Done To The Code:

4) Put the offset code in your program and make sure it's right.
   (You need this to test step 4).

5) Code your AM/PM logic and make sure it's right.

6) The View needs to load data into the location pointed at by
   "where", with appropriate offsets.  (You'll need the sketches
   you made in Step 1.)

   Right now, it puts in some bits, but they're all wrong.


7) You should do something with the colons, whether they blink or
   just stay on all the time or whatever.  ALSO, set the AM/PM/24H
   indicator.


