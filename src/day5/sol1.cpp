/*
After the rearrangement procedure completes,
what crate ends up on top of each stack?
*/
#include <array>
#include <stack>
#include <iostream>

int main()
{
    /* Strategy
    Array of stack
    */
    std::array<std::stack<int>, 9> supplyStacks;

    for (int i = 0; i < 9; ++i)
    {
        supplyStacks[i].push(i);
    }

    for (int k = 0; k < 9; ++k)
    {
        std::stack<int> s;
        s = supplyStacks[k];
        while (s.size() != 0)
        {
            std::cout << s.top() << ", " << std::endl;
            s.pop();
        }
        std::cout << "\n"
                  << std::endl;
    }

    return 1;
}