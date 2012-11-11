OPENGL = -L/usr/X11R6/lib -L/usr/local/lib -lglut -lGLU -lGL -lm -lGLEW
OPT = -O2

OBJS = Vector.o IOstuff.o proj3.o
CPPS = Vector.cpp IOstuff.cpp proj3.cpp
EXES = proj3

all: proj3

proj3: objects $(OBJS)
	g++ $(OBJS) -o proj3 $(OPT) $(OPENGL)

objects: $(CPPS)
	g++ -c $(CPPS) $(OPT)

clean: 
	rm $(EXES)
	rm $(OBJS)

