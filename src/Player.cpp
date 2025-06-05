#include "Player.h"

Player::Player(const std::string& name, int wins, int losses)
    : name(name), wins(wins), losses(losses) {}

void Player::recordWin() { ++wins; }
void Player::recordLoss() { ++losses; }

std::string Player::getName() const { return name; }
int Player::getWins() const { return wins; }
int Player::getLosses() const { return losses; }

double Player::winRate() const {
    int total = wins + losses;
    return total == 0 ? 0.0 : static_cast<double>(wins) / total;
}
