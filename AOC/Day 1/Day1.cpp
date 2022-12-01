/// @author: Thien Nguyen
/// @date: Finished by 
/// @note: Time spent in debugging: 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

auto main(void) -> int
{
    std::vector<int> input, total;
    int tmp;
    int tmp2;
    int sum = 0;
    int max = 0;

    while (std::cin >> tmp)
    {
        input.push_back(tmp);

        // if ther is a blank line, stop reading
        tmp = std::cin.get();
        tmp2 = std::cin.peek();

        if (tmp == '\n' && tmp2 == '\n')
        {
            for (auto &i : input)
                sum += i;

            max = std::max(max, sum);
            total.push_back(max);
            input.clear();
        }
        sum = 0;
    }

    std::sort(total.begin(), total.end());

    for (auto i = total.end() - 3; i != total.end(); i++)
        sum += *i;

    std::cout << "\n FINAL MAX: " << max << std::endl;
    std::cout << "\n FINAL MAX OF 3: " << sum << std::endl;

    return EXIT_SUCCESS;
}