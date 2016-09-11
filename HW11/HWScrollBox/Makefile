# Makefile for scroll
#
# hughesk

SOURCES = scroll.c model.c view.c
OBJECTS = scroll.o model.o view.o
DRIVERS = LEDots.o
INCLUDE = -I/usr/lib/gcc/x86_64-redhat-linux/3.4.6/include
LIBRARY = -lncurses
CFLAGS  = -g -Wall
COMPILER= gcc
PROGRAM = scroll

.SUFFIXES:
.SUFFIXES: .c .o

.c.o: ; $(COMPILER) $(CFLAGS) -c $< $(INCLUDE)

$(PROGRAM) : $(OBJECTS)
	$(COMPILER) -o $(PROGRAM) $(CFLAGS) $(OBJECTS) $(DRIVERS) $(LIBRARY)

clean: ; /bin/rm -f $(PROGRAM) $(OBJECTS) core

depend: $(SOURCES)
	makedepend $(INCLUDE) $(SOURCES)

# DO NOT DELETE

scroll.o: /usr/include/time.h /usr/include/features.h
scroll.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
scroll.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
scroll.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stddef.h
scroll.o: /usr/include/bits/time.h /usr/include/bits/types.h
scroll.o: /usr/include/bits/typesizes.h /usr/include/xlocale.h
scroll.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
scroll.o: /usr/include/wchar.h
scroll.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdarg.h
scroll.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
scroll.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
scroll.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
scroll.o: /usr/include/getopt.h scroll.h /usr/include/sys/time.h
scroll.o: /usr/include/sys/select.h /usr/include/bits/select.h
scroll.o: /usr/include/bits/sigset.h /usr/include/signal.h
scroll.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
scroll.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
scroll.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
scroll.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h
scroll.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
scroll.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
scroll.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
scroll.o: /usr/include/bits/byteswap-16.h /usr/include/sys/types.h
scroll.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
scroll.o: /usr/include/bits/stdlib-float.h LEDots.h /usr/include/strings.h
scroll.o: /usr/include/ctype.h /usr/include/ncurses.h
scroll.o: /usr/include/ncurses_dll.h
scroll.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdbool.h
scroll.o: /usr/include/unctrl.h /usr/include/curses.h /usr/include/term.h
scroll.o: /usr/include/termios.h /usr/include/bits/termios.h
scroll.o: /usr/include/sys/ttydefaults.h
model.o: scroll.h /usr/include/sys/time.h /usr/include/features.h
model.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
model.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
model.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
model.o: /usr/include/time.h
model.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stddef.h
model.o: /usr/include/bits/time.h /usr/include/xlocale.h
model.o: /usr/include/sys/select.h /usr/include/bits/select.h
model.o: /usr/include/bits/sigset.h /usr/include/stdio.h /usr/include/libio.h
model.o: /usr/include/_G_config.h /usr/include/wchar.h
model.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdarg.h
model.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
model.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
model.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
model.o: /usr/include/getopt.h /usr/include/signal.h
model.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
model.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
model.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
model.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h
model.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
model.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
model.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
model.o: /usr/include/bits/byteswap-16.h /usr/include/sys/types.h
model.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
model.o: /usr/include/bits/stdlib-float.h LEDots.h /usr/include/strings.h
model.o: /usr/include/ctype.h /usr/include/ncurses.h
model.o: /usr/include/ncurses_dll.h
model.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdbool.h
model.o: /usr/include/unctrl.h /usr/include/curses.h /usr/include/term.h
model.o: /usr/include/termios.h /usr/include/bits/termios.h
model.o: /usr/include/sys/ttydefaults.h
view.o: scroll.h /usr/include/sys/time.h /usr/include/features.h
view.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
view.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
view.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
view.o: /usr/include/time.h
view.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stddef.h
view.o: /usr/include/bits/time.h /usr/include/xlocale.h
view.o: /usr/include/sys/select.h /usr/include/bits/select.h
view.o: /usr/include/bits/sigset.h /usr/include/stdio.h /usr/include/libio.h
view.o: /usr/include/_G_config.h /usr/include/wchar.h
view.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdarg.h
view.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
view.o: /usr/include/unistd.h /usr/include/bits/posix_opt.h
view.o: /usr/include/bits/environments.h /usr/include/bits/confname.h
view.o: /usr/include/getopt.h /usr/include/signal.h
view.o: /usr/include/bits/signum.h /usr/include/bits/siginfo.h
view.o: /usr/include/bits/sigaction.h /usr/include/bits/sigcontext.h
view.o: /usr/include/bits/sigstack.h /usr/include/sys/ucontext.h
view.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/sigthread.h
view.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
view.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
view.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
view.o: /usr/include/bits/byteswap-16.h /usr/include/sys/types.h
view.o: /usr/include/sys/sysmacros.h /usr/include/alloca.h
view.o: /usr/include/bits/stdlib-float.h LEDots.h /usr/include/strings.h
view.o: /usr/include/ctype.h /usr/include/ncurses.h
view.o: /usr/include/ncurses_dll.h
view.o: /usr/lib/gcc/x86_64-redhat-linux/3.4.6/include/stdbool.h
view.o: /usr/include/unctrl.h /usr/include/curses.h /usr/include/term.h
view.o: /usr/include/termios.h /usr/include/bits/termios.h
view.o: /usr/include/sys/ttydefaults.h Chars/All_Chars.h Chars/Char_20.h
view.o: Chars/Char_21.h Chars/Char_22.h Chars/Char_23.h Chars/Char_24.h
view.o: Chars/Char_25.h Chars/Char_26.h Chars/Char_27.h Chars/Char_28.h
view.o: Chars/Char_29.h Chars/Char_2A.h Chars/Char_2B.h Chars/Char_2C.h
view.o: Chars/Char_2D.h Chars/Char_2E.h Chars/Char_2F.h Chars/Char_30.h
view.o: Chars/Char_31.h Chars/Char_32.h Chars/Char_33.h Chars/Char_34.h
view.o: Chars/Char_35.h Chars/Char_36.h Chars/Char_37.h Chars/Char_38.h
view.o: Chars/Char_39.h Chars/Char_3A.h Chars/Char_3B.h Chars/Char_3C.h
view.o: Chars/Char_3D.h Chars/Char_3E.h Chars/Char_3F.h Chars/Char_40.h
view.o: Chars/Char_41.h Chars/Char_42.h Chars/Char_43.h Chars/Char_44.h
view.o: Chars/Char_45.h Chars/Char_46.h Chars/Char_47.h Chars/Char_48.h
view.o: Chars/Char_49.h Chars/Char_4A.h Chars/Char_4B.h Chars/Char_4C.h
view.o: Chars/Char_4D.h Chars/Char_4E.h Chars/Char_4F.h Chars/Char_50.h
view.o: Chars/Char_51.h Chars/Char_52.h Chars/Char_53.h Chars/Char_54.h
view.o: Chars/Char_55.h Chars/Char_56.h Chars/Char_57.h Chars/Char_58.h
view.o: Chars/Char_59.h Chars/Char_5A.h Chars/Char_5B.h Chars/Char_5C.h
view.o: Chars/Char_5D.h Chars/Char_5E.h Chars/Char_5F.h Chars/Char_60.h
view.o: Chars/Char_61.h Chars/Char_62.h Chars/Char_63.h Chars/Char_64.h
view.o: Chars/Char_65.h Chars/Char_66.h Chars/Char_67.h Chars/Char_68.h
view.o: Chars/Char_69.h Chars/Char_6A.h Chars/Char_6B.h Chars/Char_6C.h
view.o: Chars/Char_6D.h Chars/Char_6E.h Chars/Char_6F.h Chars/Char_70.h
view.o: Chars/Char_71.h Chars/Char_72.h Chars/Char_73.h Chars/Char_74.h
view.o: Chars/Char_75.h Chars/Char_76.h Chars/Char_77.h Chars/Char_78.h
view.o: Chars/Char_79.h Chars/Char_7A.h Chars/Char_7B.h Chars/Char_7C.h
view.o: Chars/Char_7D.h Chars/Char_7E.h
