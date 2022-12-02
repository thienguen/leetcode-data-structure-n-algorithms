/// @author: Thien Nguyen
/// @date: Finished by
/// @note: Tiplayer spent in debugging:

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

auto main() -> int
{
    int score1 = 0;
    int score2 = 0;
    std::string line;
    std::ifstream part1("in2.txt");
    std::ifstream part2("in2.txt");

    while (std::getline(part1, line))
    {
        char *data = line.data();

        // offset of ASCII
        // A = 65 - 65 + 1 = 1
        // B = 66 - 65 + 1 = 2
        // C = 67 - 65 + 1 = 3
        // X = 88 - 88 + 1 = 1
        // Y = 89 - 88 + 1 = 2
        // Z = 90 - 88 + 1 = 3
        int computer = data[0] - 'A' + 1;
        int player   = data[2] - 'X' + 1;

        bool draw = computer == player;
        bool wins = (player - computer + 3) % 3 == 1;

        score1 += player + (wins ? 6 : (draw ? 3 : 0));
    }

    printf("Total score Day2D:  Part 1: %d\n", score1);

    while (std::getline(part2, line))
    {
        char *data = line.data();

        // offset of ASCII
        // A = 65 - 65 + 1 = 1
        // B = 66 - 65 + 1 = 2
        // C = 67 - 65 + 1 = 3
        // X = 88 - 88 + 1 = 1
        // Y = 89 - 88 + 1 = 2
        // Z = 90 - 88 + 1 = 3
        int computer = data[0] - 'A';
        int player   = data[2] - 'X';

        // if player is 0, we must lose to computer
        // if player is 1, we must draw with computer
        // if player is 2, we must win against computer
        switch (player)
        {
            case 0:
                score2 += (computer == 0) ? 3
                        : (computer == 1) ? 1
                        : (computer == 2) ? 2
                                          : 0;
                break;
            case 1:
                score2 += 3;
                score2 += (computer == 0) ? 1
                        : (computer == 1) ? 2
                        : (computer == 2) ? 3
                                          : 0;
                break;
            case 2:
                score2 += 6;
                score2 += (computer == 0) ? 2
                        : (computer == 1) ? 3
                        : (computer == 2) ? 1
                                          : 0;
                break;
        }
    }

    printf("Total score Day2D:  Part 2: %d\n", score2);

    return EXIT_SUCCESS;
}