/*
After the rearrangement procedure completes,
what crate ends up on top of each stack?
*/
#include <array>
#include <stack>
#include <string>
#include <fstream>
#include <iostream>

int main()
{
    /* Strategy
    Array of stack
    First out First in.
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

    int row = 0;
    std::string line;
    char char1;
    int num;
    int strId;
    int dstId;
    int removedItem;
    std::ifstream in("input.txt");

    // Skip lines
    while (row < 10)
    {
        std::getline(in, line);
        ++row;
    }

    // Read and perform instructions
    while ((in >> char1 >> char1 >> char1 >> char1 >> num >> char1 >> char1 >> char1 >> char1 >> strId >> char1 >> char1 >> dstId))
    {
        for (int p = 0; p < num; ++p)
        {
            removedItem = supplyStacks[strId - 1].top();
            supplyStacks[strId - 1].pop();
            supplyStacks[dstId - 1].push(removedItem);
        }
    }

    // Print the top char across stacks
    for (int k = 0; k < 9; ++k)
    {
        std::stack<int> s;
        s = supplyStacks[k];
        int i = 0;
        while (i != 1)
        {
            std::cout << (char)(s.top());
            s.pop();
            ++i;
        }
    }

    return 1;
}