gcc src/main.c      -o builds/main.o      -c
gcc src/io.c        -o builds/io.o        -c
gcc src/interpret.c -o builds/interpret.o -c
gcc src/util.c      -o builds/util.o      -c
gcc src/runargs.c   -o builds/runargs.o   -c

cd builds
gcc -o Ill main.o io.o interpret.o util.o runargs.o

rm main.o io.o interpret.o util.o runargs.o