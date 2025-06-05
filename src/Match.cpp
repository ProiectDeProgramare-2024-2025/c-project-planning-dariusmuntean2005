#include "Match.h"
#include <sstream>

Match::Match(const std::string& p1, int s1, int s2, const std::string& p2)
    : player1(p1), score1(s1), score2(s2), player2(p2) {}

bool Match::isValidScore() const {
    return ((score1 == 21) ^ (score2 == 21)) && (score1 <= 21 && score2 <= 21) && (score1>=0 && score2>=0);
}

std::string Match::toString() const {
    std::ostringstream oss;
    oss << player1 << "," << score1 << "," << score2 << "," << player2;
    return oss.str();
}

std::string Match::getPlayer1() const { return player1; }
std::string Match::getPlayer2() const { return player2; }
int Match::getScore1() const { return score1; }
int Match::getScore2() const { return score2; }
