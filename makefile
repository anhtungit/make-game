all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp gameloop.cpp tuyet.cpp texturemanager.cpp player.cpp background.cpp fence.cpp road.cpp object.cpp banhxe.cpp sky.cpp sun.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	

run:
	./main
