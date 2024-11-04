CXX = g++
CXXFLAGS = -g -Wall -O3 -std=c++17

objects = main.o binaryfraction.o

all: out

out: $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o main.out

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

# binaryfraction.o: binaryfraction.cpp
# 	$(CXX) -c $(CXXFLAGS) binaryfraction.cpp -o binaryfraction.o

clean:
	rm -f main.out *.o

fmt:
	clang-format -i *.cpp *.hpp

.DEFAULT: all