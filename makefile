all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp gameloop.cpp texturemanager.cpp player.cpp background.cpp object.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	

run:
	./main
