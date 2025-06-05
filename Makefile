CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/Player.cpp src/Match.cpp src/Leaderboard.cpp
HEADERS = include/Player.h include/Match.h include/Leaderboard.h

all: add_match leaderboard

add_match: app1.cpp $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) app1.cpp $(SRC) -o add_match

leaderboard: app2.cpp $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) app2.cpp $(SRC) -o leaderboard

clean:
	rm -f add_match leaderboard
