CXX = g++
CXXFLAGS = -std=c++17
INCLUDES = -I./incl

VISUALISER_SRC = src/visualiser.cpp src/visualise_strimage.cpp
DECODER_SRC = src/decoder.cpp src/decode_gdlg.cpp

VISUALISER_OBJ = $(VISUALISER_SRC:.cpp=.o)
DECODER_OBJ = $(DECODER_SRC:.cpp=.o)

.PHONY: clean visualiser decoder

visualiser: $(VISUALISER_OBJ)
	$(CXX) $(VISUALISER_OBJ) -o $@

decoder: $(DECODER_OBJ)
	$(CXX) $(DECODER_OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f src/*.o visualiser decoder