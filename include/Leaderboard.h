#pragma once
#include "Player.h"
#include "Match.h"
#include <vector>
#include <string>

class Leaderboard {
public:
    Leaderboard();
    void processMatchesFromFile(const std::string& filename);
    void display(int filter);
    void showPlayerStats(const std::string& name);

private:
    std::vector<Player> players;
    std::vector<Match> matches;

    Player* findOrCreatePlayer(const std::string& name);
    void updateStats(const Match& match);
    static bool compareByWinrate(const Player& a, const Player& b);
    static bool compareByWins(const Player& a, const Player& b);
    static bool compareByLosses(const Player& a, const Player& b);
};
