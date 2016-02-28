EXEC=flip
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CC=g++ -std=c++11
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -lSDL_ttf -lSDL_image -lSDL_mixer -lSDL -o $(EXEC)
%.o: %.cc
	$(CC) -Wall  -lSDL_ttf -lSDL_image -lSDL_mixer -lSDL -c $< -o $@

.depend:
	g++ -MM $(SOURCES) > .depend
-include .depend
clean:
	rm -f $(OBJECTS) $(EXEC)
