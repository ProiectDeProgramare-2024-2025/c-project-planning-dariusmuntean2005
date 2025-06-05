#pragma once
#include <string>

class Match {
public:
    Match(const std::string& p1, int s1, int s2, const std::string& p2);

    bool isValidScore() const;
    std::string toString() const;

    std::string getPlayer1() const;
    std::string getPlayer2() const;
    int getScore1() const;
    int getScore2() const;

private:
    std::string player1, player2;
    int score1=-1, score2=-1;
};
