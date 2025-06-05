#pragma once
#include <string>

class Player {
public:
    Player(const std::string& name, int wins = 0, int losses = 0);

    void recordWin();
    void recordLoss();

    std::string getName() const;
    int getWins() const;
    int getLosses() const;
    double winRate() const;

private:
    std::string name;
    int wins;
    int losses;
};
