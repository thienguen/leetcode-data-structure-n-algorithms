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
    std::string in = "";
    bool noModify = false;
    bool IMPOSSIBLE = false;
    std::cin >> in;

    for (std::string::size_type i = 0; i < in.size() / 2; i++)
    {
        int j = in.size() - 1 - i;
        if (in[i] != 'a')
        {
            in[i] = 'a';
            std::cout << in << std::endl;
            return 0;
        }

        if (in[i] != in[j])
        {
            noModify = true;
        }
        j++;
    }

    if (in[in.size() - 1] != 'a' && noModify)
    {
        in[in.size() - 1] = 'b';
        std::cout << in << std::endl;
    }
    else
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }

    return EXIT_SUCCESS;
}