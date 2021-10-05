gcc src/main.c -o builds/main.o -c
gcc src/io.c   -o builds/io.o   -c

cd builds
gcc -o ililcomp main.o io.o

rm main.o io.o
