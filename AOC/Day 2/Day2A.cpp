/// @author: Thien Nguyen
/// @date: Finished by
/// @note: Time spent in debugging:

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

auto main(void) -> int
{
    // read in input of each player
    int score1 = 0;
    int score2 = 0;
    std::vector<char> player1;
    std::vector<char> player2;
    std::ifstream input("in2.txt");

    // read in player 1
    char in1;
    char in2;

    while (input >> in1 >> in2)
    {
        player1.push_back(in1);
        player2.push_back(in2);
    }

    for (std::size_t i = 0; i < player1.size(); ++i)
    {
        score1 += (player1[i] == 'A' && player2[i] == 'X') ? 3
                : (player1[i] == 'B' && player2[i] == 'Y') ? 3
                : (player1[i] == 'C' && player2[i] == 'Z') ? 3
                : (player1[i] == 'A' && player2[i] == 'Y') ? 6
                : (player1[i] == 'B' && player2[i] == 'Z') ? 6
                : (player1[i] == 'C' && player2[i] == 'X') ? 6
                                                           : 0;

        score1 += (player2[i] == 'X') ? 1 : (player2[i] == 'Y') ? 2
                                                                : 3;
    }

    std::cout << "Total score Day2A:  PART 1: " << score1 << std::endl;

    for (std::size_t i = 0; i < player1.size(); i++)
    {
        switch (player2[i])
        {
        case 'X':
            // X mean we need to lose to player 1
            score2 += (player1[i] == 'A') ? 3
                    : (player1[i] == 'B') ? 1
                    : (player1[i] == 'C') ? 2
                                          : 0;
            break;

        case 'Y':
            // Y mean we need a draw to player 1
            score2 += (player1[i] == 'A') ? 1
                    : (player1[i] == 'B') ? 2
                    : (player1[i] == 'C') ? 3
                                          : 0;
            score2 += 3;
            break;

        case 'Z':
            // Z mean we need to win to player 1
            score2 += (player1[i] == 'A') ? 2
                    : (player1[i] == 'B') ? 3
                    : (player1[i] == 'C') ? 1
                                          : 0;
            score2 += 6;
            break;
        }
    }

    std::cout << "Total score Day2A:  PART 2: " << score2 << std::endl;

    return EXIT_SUCCESS;
}