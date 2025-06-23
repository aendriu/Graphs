CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./AdjMatrix -I./AdjLst -I./graph

SRCS = main.cpp
OBJS = main.o
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp AdjMatrix/adjmat.hpp AdjLst/adjlst.hpp graph/graph.hpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
