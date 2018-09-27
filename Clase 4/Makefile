prac_compo.exe: prac_compo.cpp Rectangulo.o
	g++ prac_compo.cpp Rectangulo.o Coordenada.o -o prac_compo.exe
Rectangulo.o: Rectangulo.cpp Coordenada.o Rectangulo.h
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
