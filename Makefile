CXX = g++
CXXFLAGS = -std=c++11
INCLUDES = -I../incl

SRC = src/visualiser.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = visualiser

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)