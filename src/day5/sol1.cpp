/*
After the rearrangement procedure completes,
what crate ends up on top of each stack?
*/
#include <array>
#include <stack>
#include <string>
#include <iostream>

int main()
{
    /* Strategy
    Array of stack
    */
    // Initialisation
    std::array<std::string, 9> stackElement;
    stackElement[0] = "SZPDLBFC";
    stackElement[1] = "NVGPHWB";
    stackElement[2] = "FWBJG";
    stackElement[3] = "GJNFLWCS";
    stackElement[4] = "WJLTPMSH";
    stackElement[5] = "BCWGFS";
    stackElement[6] = "HTPMQBW";
    stackElement[7] = "FSWT";
    stackElement[8] = "NCR";

    std::array<std::stack<int>, 9> supplyStacks;

    for (int i = 0; i < 9; ++i)
    {

        std::string elements = stackElement[i];
        int len = elements.length();
        int k = 0;
        while (k < len)
        {
            supplyStacks[i].push(elements[k]);
            ++k;
        }
    }

    // for (int k = 0; k < 9; ++k)
    // {
    //     std::stack<int> s;
    //     s = supplyStacks[k];
    //     while (s.size() != 0)
    //     {
    //         std::cout << (char)(s.top()) << ", ";
    //         s.pop();
    //     }
    //     std::cout << "\n"
    //               << std::endl;
    // }

    return 1;
}