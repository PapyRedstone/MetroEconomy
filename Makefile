CFLAGS = -g -Wall -pedantic -O3 -std=c++17
LDFLAGS = -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system -llua -ldl
#UNIT = -ftest-coverage -fprofile-arcs

SRC = $(wildcard src/*.cpp)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

INCLUDE = $(wildcard include/*.hpp)

TARGET = Metro.out

all: $(TARGET)

remake: clean all

$(TARGET) : $(OBJ)
	g++ obj/* $(LDFLAGS) -o $@ 

obj/%.o: src/%.cpp $(INCLUDE)
	g++ -c -Iinclude $(CFLAGS) -o $@ $<

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f

git:
	git pull
	git add .
	git commit
	git push
