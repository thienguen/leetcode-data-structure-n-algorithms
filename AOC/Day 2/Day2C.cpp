#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

struct wl
{
    char wins;
    char lose;
    char draw;
};

int main()
{
    /*
     * Maps a choice of computer win against and lose against player
     * If player is X, then it win again C and lose again B draw with A
     * If player is Y, then it win again A and lose again C draw with B
     * If player is Z, then it win again B and lose again A draw with C
     * Where as A, B, C is Rock, Paper, Scissors
     */

    std::unordered_map<char, wl> playerMap = {
        {'X', {'C', 'B', 'A'}},
        {'Y', {'A', 'C', 'B'}},
        {'Z', {'B', 'A', 'C'}}
    };

    /*
     * Maps a choice of computer win against and lose against player
     * If computer is A, then it win again C and lose again B draw with A
     * If computer is B, then it win again A and lose again C draw with B
     * If computer is C, then it win again B and lose again A draw with C
     * Where as A, B, C is Rock, Paper, Scissors
     */

    std::unordered_map<char, wl> computerMap = {
        {'A', {'C', 'B', 'A'}},
        {'B', {'A', 'C', 'B'}},
        {'C', {'B', 'A', 'C'}}
    };

    // Maps a choice to how many points that choice yields
    std::unordered_map<char, int> RPS = {
        {'A', 1}, // rock
        {'B', 2}, // paper
        {'C', 3}, // scissors
        {'X', 1}, // rock
        {'Y', 2}, // paper
        {'Z', 3}  // scissors
    };

    // Maps a round result to how many points are gained for that result
    std::unordered_map<std::string, int> State = {
        {"LOSE", 0},
        {"DRAW", 3}, 
        {"WIN", 6}
    };

    char player;     // Which move you are told to make
    char computer;   // Which move your opponent will make
    int score2a = 0; // Scored total of all rounds
    int score2b = 0; // Scored total of all rounds   
    std::fstream part1("in2.txt");
    std::fstream part2("in2.txt");

    while (part1 >> computer >> player)
    {
        score2a += playerMap[player].wins == computer ? RPS[player] + State["WIN"]
                 : playerMap[player].lose == computer ? RPS[player] + State["LOSE"]
                 : playerMap[player].draw == computer ? RPS[player] + State["DRAW"]
                 : 0;
    }

    while (part2 >> computer >> player)
    {
        // X --> PLayer must lose against computer
        // Y --> Player must draw against computer
        // Z --> Player must win against computer
        score2b +=   player == 'X' ? RPS[computerMap[computer].wins] + State["LOSE"]
                   : player == 'Y' ? RPS[computerMap[computer].draw] + State["DRAW"]
                   : player == 'Z' ? RPS[computerMap[computer].lose] + State["WIN"]
                                   : 0;
    }

    printf("Total score Day2Ca: PART 1: %d\n", score2a);
    printf("Total score Day2Ca: PART 2: %d\n", score2b);

    return 0;
}
