/*
Find the top three Elves carrying the most Calories.
How many Calories are those Elves carrying in total?
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /*Strategy:
     read calories and sum them up until hits an empty line
     keep top three calories
     Execute insertion sort on the go but only for the three elements
     */

    int calories = 0;
    int topThree[4] = {0, 0, 0, 0}; // topThree[0] is a sentinel node

    std::string line;

    std::ifstream in("input.txt");
    while (std::getline(in, line))
    {
        if (line == "")
        {
            int i = 3;
            while (i > 0 && topThree[i] < calories)
            {
                topThree[i] = topThree[i - 1];
                --i;
            }
            topThree[i + 1] = calories;
            calories = 0; // reset calories counting for one elf
        }
        else
        {
            calories += stoi(line);
        }
    }

    // sum top three calories
    int sum = 0;
    for (int k = 1; k < 4; ++k)
    {
        sum += topThree[k];
    }

    std::cout << "Sum of top three calories is " << sum << std::endl;

    return 0;
}