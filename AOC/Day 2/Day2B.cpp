/// @author: Thien Nguyen
/// @date: Finished by
/// @note: Time spent in debugging:

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>

auto main(void) -> int
{
    char player, computer;
    int score1 = 0, score2 = 0;
    std::ifstream part1("in2.txt");
    std::ifstream part2("in2.txt");

    /*
     * Part 1:
     * 1. Read in the input of each player
     * 2. Taking different between player, computer
     *    X:
     *      - Win difference = -2
     *      - Lose difference = -1
     *    Y:
     *      - Win difference = 1
     *      - Lose difference = -1
     *    Z:
     *      - Win difference = 1
     *      - Lose difference = 2
     *
     * All draw case difference = 0
     * 3. Add score1 with player type XYZ
    */

    std::unordered_map<char, int> RPS = {
        {'A', 1}, // rock
        {'B', 2}, // paper
        {'C', 3}, // scissors
        {'X', 1}, // rock
        {'Y', 2}, // paper
        {'Z', 3}  // scissors
    };

    while (part1 >> computer >> player)
    {
        score1 += RPS[player];
        score1 += RPS[player] - RPS[computer] == 0  ? 3 
                : RPS[player] - RPS[computer] == 1  ? 6
                : RPS[player] - RPS[computer] == -2 ? 6
                : 0;
    }

    std::cout << "Total score Day2B:  PART 1: " << score1 << std::endl;

    /*
     * Part 2:
     * 1. Read in the input of each player
     * 2. Taking different between player, computer
     *   X: LOSE
     *     - A --> + 3
     *     - B --> + 1
     *     - C --> + 2
     *   Y: WIN
     *     - A --> + 1
     *     - B --> + 2
     *     - C --> + 3
     *   Z: DRAW
     *     - A --> + 2
     *     - B --> + 3
     *     - C --> + 1
     *
     * 3. Add score1 with player type XYZ
    */

    while (part2 >> computer >> player)
    {
        switch (player)
        {
        case 'X':
            score2 += (computer == 'A') ? 3 : (computer == 'B') ? 1
                                                                : 2;
            break;
        case 'Y':
            score2 += 3;
            score2 += (computer == 'A') ? 1 : (computer == 'B') ? 2
                                                                : 3;
            break;
        case 'Z':
            score2 += 6;
            score2 += (computer == 'A') ? 2 : (computer == 'B') ? 3
                                                                : 1;
            break;
        }
    }

    std::cout << "Total score Day2B:  PART 2: " << score2 << std::endl;

    return EXIT_SUCCESS;
}