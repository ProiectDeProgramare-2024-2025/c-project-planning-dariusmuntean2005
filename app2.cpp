#include "Leaderboard.h"
#include <iostream>
#include <string>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"


int main(int argc, char* argv[]) {
    Leaderboard lb;
    lb.processMatchesFromFile("matches.txt");

    if (argc < 2) {
        std::cerr << RED << "Invalid input\n" << RESET
                  << "Correct Usage:\n"
                  <<"  --filter" <<"=<" << YELLOW << "winrate" << RESET << "|" << GREEN << "wins" << RESET << "|" << RED << "losses" << RESET << ">  Show leaderboard\n"
                  <<"  --player" <<"=<" << CYAN << "player_name" << RESET << ">          Show player stats\n"
                  << "Examples:\n"
                  << "  ./leaderboard --filter=winrate\n"
                  << "  ./leaderboard --player=Alice\n";
        return 1;
    }

    std::string filterArg;
    std::string playerArg;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.find("--filter=") == 0) {
            filterArg = arg.substr(9);  // after "--filter="
        } else if (arg.find("--player=") == 0) {
            playerArg = arg.substr(9);  // after "--player="
            if (playerArg.empty()) {
                std::cerr <<RED<< "Invalid:"<<RESET<<"No player name introduced\n";
                return 1;
            }
        } else {
            std::cerr <<RED<< "Invalid argument: " <<RESET<< arg << "\n";
            return 1;
        }
    }

    if (!filterArg.empty()) {
        int filter = 0;
        if (filterArg == "winrate") filter = 1;
        else if (filterArg == "wins") filter = 2;
        else if (filterArg == "losses") filter = 3;
        else {
            std::cerr <<RED<< "Invalid filter option: "<<RESET << filterArg << "\n";
            return 1;
        }
        lb.display(filter);
    }

    if (!playerArg.empty()) {
        lb.showPlayerStats(playerArg);
    }

    return 0;
}
