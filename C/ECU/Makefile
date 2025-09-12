all: main.c
	cls
	gcc main.c -o main -I ./raylibInclude/ -L ./raylibLib/ -lraylib -lopengl32 -lgdi32 -lwinmm

run:
	.\main.exe

clean:
	rm main.exe