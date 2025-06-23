CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./PreOrder/Online -I./PreOrder/Offline -I./PostOrder/Online -I./PostOrder/Offline

SRCS = main.cpp
OBJS = main.o 
TARGET = main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp PreOrder/Online/PreOGIOnline.cpp PostOrder/Online/PostOGIOnline.cpp #PreOrder/Offline/PreOGIOffline.cpp PostOrder/Offline/PostOGIOffline.cpp

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

