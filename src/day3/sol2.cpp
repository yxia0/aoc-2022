/*
Find the item type that corresponds to the badges of each three-Elf group.
What is the sum of the priorities of those item types?
 */

/*
Notes:
See TODO
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /*
    Strategy:
    read each line, get string length, get the paritition index
    for first line - occurence set to 1
    for second line - only if any char's occurence is 1, set to 2
    for third line - only if any char's occurence is 2, set to 3
    traverse the frequency array to get the priority of a char with
    frequency 3 and add it to priority sum.
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
    int row = 0;
    int typeFreq[58] = {};
    while (std::getline(in, rucksack))
    {
        int rucksackLen = rucksack.length();
        if (row % 3 == 0)
        {
            std::fill_n(typeFreq, 58, 0); // reset array with all zeros
            /*
            TODO:
            Initially I did `int typeFreq[58] = {};` instead to
            reset the array, but found that the typeFreq here is not
            the typeFreq defined outside of the while loop.
            Is it because they point to different array in memory?
            how shall I better handle this typeFreq without using fill_n to reset?
            I was thinking of using malloc and discard once every group is done.
            */
            for (int c = 0; c < rucksackLen; ++c)
            {
                typeFreq[rucksack[c] - OFFSET] = 1;
            }
        }
        else if (row % 3 == 1)
        {
            for (int c = 0; c < rucksackLen; ++c)
            {
                if (typeFreq[rucksack[c] - OFFSET] == 1)
                {
                    typeFreq[rucksack[c] - OFFSET] = 2;
                }
            }
        }
        else if (row % 3 == 2)
        {
            for (int c = 0; c < rucksackLen; ++c)
            {
                if (typeFreq[rucksack[c] - OFFSET] == 2)
                {
                    typeFreq[rucksack[c] - OFFSET] = 3;
                }
            }
            // traverse frequency to get priority
            for (int i = 0; i < 58; ++i)
            {
                if (typeFreq[i] == 3)
                {
                    prioritySum += priority[i];
                    break;
                }
            }
        }

        ++row;
    }

    std::cout << "Total priority is " << prioritySum << std::endl;
    return 1;
}