#Makefile for 2-part print
SOURCES = main.c part1.c part2.c
OBJECTS = main.o part1.o part2.o
PROGRAMS = test2
$(PROGRAMS) : $(OBJECTS)
	cc -o $@ -O $(OBJECTS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o: ; cc -c $<
clean: ; /bin/rm -f $(PROGRAM) $(OBJECTS) core
depend: $(SOURCES)
	makedepend $(SOURCES)
# DO NOT DELETE

part1.o: /usr/include/stdio.h /usr/include/features.h
part1.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
part1.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
part1.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
part1.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
part1.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
part2.o: /usr/include/stdio.h /usr/include/features.h
part2.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
part2.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
part2.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
part2.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
part2.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
