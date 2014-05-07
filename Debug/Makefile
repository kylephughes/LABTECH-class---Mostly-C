# simple makefile for example debugging programs

COMPILER = g++
CC       = gcc
CFLAGS = -g

all: assert buggy runoff stack Stack_bug

assert: assert.c
	$(CC) $(CFLAGS) -o assert assert.c

buggy: buggy.C
	$(COMPILER) $(CFLAGS) -o buggy buggy.C

runoff: runoff.C
	$(COMPILER) $(CFLAGS) -o runoff runoff.C

stack: stack.C
	$(COMPILER) $(CFLAGS) -o stack stack.C

Stack_bug : Stack_bug.java Stack_bug.manifest
	javac -g Stack_bug.java
	jar cmf Stack_bug.manifest $@ Stack_bug.class StackItem.class
	chmod +x Stack_bug

clean:; /bin/rm -f stack runoff buggy assert \
        Stack_bug Stack_bug.class StackItem.class \
        core.[0-9]*


