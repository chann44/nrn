game: random.c
	gcc random.c -o game \
	-I/opt/homebrew/include \
	-L/opt/homebrew/lib \
	-lraylib \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

clean:
	rm -f game

