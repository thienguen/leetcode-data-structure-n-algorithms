/// @author: Thien Nguyen
/// @date: Finished by 
/// @note: Time spent in debugging: 


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> teamA, teamB, result;

    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        teamA.push_back(temp);
    }

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        teamB.push_back(temp);
    }

    std::sort(teamA.begin(), teamA.end());

    int count = 0;
    std::cout << "\nResult: " << std::endl;

    for (auto i : teamB)
    {
        for (auto j : teamA)
        {
            if (j > i)
            {
                break;
            }
            count++;
        }
        result.push_back(count);
        count = 0;
    }


    return EXIT_SUCCESS;
}