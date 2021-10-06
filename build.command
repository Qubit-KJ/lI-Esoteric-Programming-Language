gcc src/main.c      -o builds/main.o     -c
gcc src/io.c        -o builds/io.o        -c
gcc src/interpret.c -o builds/interpret.o -c

cd builds
gcc -o Ill main.o io.o interpret.o

rm main.o io.o interpret.o