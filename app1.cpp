#include "Match.h"
#include <iostream>
#include <fstream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr <<RED<< "Invalid format."<<RESET<<" Correct Usage: " << argv[0] << " Player1 Score1 Score2 Player2\n" ;
        return 1;
    }

    std::string p1 = argv[1];
    int s1 = std::stoi(argv[2]);
    int s2 = std::stoi(argv[3]);
    std::string p2 = argv[4];

    Match match(p1, s1, s2, p2);
    if (!match.isValidScore()) {
        std::cerr <<RED<< "Invalid match."<<RESET<<" One score must be 21, and the other positive and < 21.\n";
        return 1;
    }


    std::ofstream out("matches.txt", std::ios::app);
    out << match.toString() << "\n";
    std::cout <<GREEN<< "Match added: "<<RESET << match.toString() << "\n";

    return 0;
}
