CFLAGS = -g -Wall -pedantic -O3 -std=c++17 -I/usr/local/include/sol/include
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -llua -ldl
#UNIT = -ftest-coverage -fprofile-arcs

SRC = $(wildcard src/*.cpp)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

INCLUDE = $(wildcard include/*.hpp)

TARGET = Metro.out

all: $(TARGET)

remake: clean all

$(TARGET) : $(OBJ)
	g++ $(OBJ) $(LDFLAGS) -o $@ 

obj/%.o: src/%.cpp $(INCLUDE)
	g++ -c -Iinclude $(CFLAGS) -o $@ $<

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f

git:
	git add .
	git commit
	git pull
	git push
