CXX := clang++
CXXFLAGS := -std=c++20 -Wall -Wextra -g -O0

TARGET := build/solve
SRC := solve.cpp

all: build

build: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
