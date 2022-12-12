/*
How many characters need to be processed
before the first start-of-packet marker is detected?
14 distinct char
*/

#include <iostream>
#include <fstream>
#include <string>
#include <deque>

int main()
{

    /* Strategy
    1. use deque
    2. intialise the deque with the first three elements with a sentinel at the front
    4. iterate by push one char and deque the top char
    5. sadly do pair-wise comparison - can we do better?
    Note: since all inputs are in lower case, we can put whatever captical letter as
    sentinel!
    */

    // Read input in line
    std::string line;
    std::ifstream in("input.txt");
    std::getline(in, line);

    // Initialisation
    std::deque<char> window = {'A'};
    int idx = 0;
    while (idx < 13)
    {
        window.push_back(line[idx]);
        ++idx;
    }

    while (true)
    {
        bool found = false;
        window.pop_front();
        window.push_back(line[idx]);
        // TODO: can we do better at comparison here?
        for (int i = 0; i < 13; ++i)
        {
            for (int j = (i + 1); j < 14; ++j)
            {
                if (window[i] == window[j])
                {
                    found = true;
                    break;
                }
            }
        }

        if (found)
        {
            ++idx;
        }
        else
        {
            std::cout << "pucket starts at " << (idx + 1) << std::endl;
            break;
        }
    }

    return 1;
}