#include "Leaderboard.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

Leaderboard::Leaderboard() {}

Player* Leaderboard::findOrCreatePlayer(const std::string& name) {
    for (auto& p : players) {
        if (p.getName() == name) return &p;
    }
    players.emplace_back(name);
    return &players.back();
}

void Leaderboard::updateStats(const Match& match) {
    Player* p1 = findOrCreatePlayer(match.getPlayer1());
    Player* p2 = findOrCreatePlayer(match.getPlayer2());

    if (match.getScore1() > match.getScore2()) {
        p1->recordWin();
        p2->recordLoss();
    } else {
        p2->recordWin();
        p1->recordLoss();
    }
}

void Leaderboard::processMatchesFromFile(const std::string& filename) {
    players.clear();
    matches.clear(); // clear existing matches

    std::ifstream in(filename);
    std::string p1, p2;
    int s1, s2;

    while (in.good()) {
        getline(in, p1, ',');
        in >> s1;
        in.ignore();
        in >> s2;
        in.ignore();
        getline(in, p2);

        if (!p1.empty() && !p2.empty()) {
            Match match(p1, s1, s2, p2);
            matches.push_back(match); // store match
            updateStats(match);
        }
    }
}

bool Leaderboard::compareByWinrate(const Player& a, const Player& b) {
    return a.winRate() > b.winRate();
}

bool Leaderboard::compareByWins(const Player& a, const Player& b) {
    return a.getWins() > b.getWins();
}

bool Leaderboard::compareByLosses(const Player& a, const Player& b) {
    return a.getLosses() < b.getLosses();
}

void Leaderboard::display(int filter) {
    if (filter == 1)
        std::sort(players.begin(), players.end(), compareByWinrate);
    else if (filter == 2)
        std::sort(players.begin(), players.end(), compareByWins);
    else if (filter == 3)
        std::sort(players.begin(), players.end(), compareByLosses);

    std::cout<<BOLD<<YELLOW<<"LeaderBoard\n"<<RESET;
    std::cout<<"-------------------------------------\n";

    for (size_t i = 0; i < players.size(); ++i) {
        const auto& p = players[i];
        std::cout << i + 1 << ". "<< CYAN << p.getName() << RESET ;

        if (filter == 1)
            std::cout << " - "<<YELLOW<< "Winrate: " <<RESET<< std::fixed << std::setprecision(2) << p.winRate() * 100 << "%";
        else if (filter == 2)
            std::cout << " - "<<GREEN<< "Wins: " <<RESET<< p.getWins();
        else
            std::cout << " - "<<RED<< "Losses: " <<RESET<< p.getLosses();

        std::cout << "\n";
    }

    std::cout<<"-------------------------------------\n";
}

void Leaderboard::showPlayerStats(const std::string& name) {
    for (const auto& p : players) {
        if (p.getName() == name) {
            std::cout << "\nPlayer: " << CYAN << name << RESET << "\n";
            std::cout << GREEN << "Wins: " << RESET << p.getWins() << "\n";
            std::cout << RED << "Losses: " << RESET << p.getLosses() << "\n";
            std::cout << YELLOW << "Winrate: " << RESET << std::fixed << std::setprecision(2) << p.winRate() * 100 << "%\n";

            std::cout <<BOLD<<YELLOW<< "\nMatches:\n"<<RESET;
            for (const auto& match : matches) {
                if (match.getPlayer1() == name || match.getPlayer2() == name) {
                    std::cout <<CYAN<< match.getPlayer1() <<RESET<< " " << match.getScore1()
                              << " - " << match.getScore2() << " " <<CYAN<< match.getPlayer2() <<RESET<< "\n";
                }
            }
            return;
        }
    }
    std::cout << "Player not found.\n";
}
