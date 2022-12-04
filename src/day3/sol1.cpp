/*
Find the item type that appears in both compartments of each rucksack.
What is the sum of the priorities of those item types?
 */
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /*
    Strategy:
    read each line, get string length, get the paritition index
    find common char in two string:
        1. if one char occur in the first compartment, set 1
        2. set the char occur in the second compartment to 2
        only if its occurence is 1.
    */
    int OFFSET = 65; // used to set 'A' as 0, 'B' as 1..
    int prioritySum = 0;

    // initialise priority array
    int priority[58] = {};
    // int point = 27; // A has priority 27
    for (int i = 0; i < 26; ++i)
    {
        // A...Z
        priority[i] = (i + 27);
    }
    // int point = 1; // a has priority 1
    for (int i = 32; i < 58; ++i)
    {
        priority[i] = (i - 31);
    }

    std::ifstream in("input.txt");
    std::string rucksack;
    while (std::getline(in, rucksack))
    {
        int typeFreq[58] = {}; // initialise array with all zeros
        int rucksackLen = rucksack.length();
        int fstCompEnd = (rucksackLen / 2);
        for (int c = 0; c < fstCompEnd; ++c)
        {
            typeFreq[rucksack[c] - OFFSET] = 1;
        }
        for (int k = fstCompEnd; k < rucksackLen; ++k)
        {
            if (typeFreq[rucksack[k] - OFFSET] == 1)
            {
                typeFreq[rucksack[k] - OFFSET] = 2;
            }
        }
        // traverse frequency to get priority
        for (int i = 0; i < 58; ++i)
        {
            if (typeFreq[i] == 2)
            {
                prioritySum += priority[i];
                break;
            }
        }
    }

    std::cout << "Total priority is " << prioritySum << std::endl;
    return 1;
}