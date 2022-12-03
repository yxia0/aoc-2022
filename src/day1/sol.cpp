/*
Find the Elf carrying the most Calories.
How many total Calories is that Elf carrying?
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /*Strategy:
     read calories and sum them up until hits an empty line
     keep id of Elf and its calories
     do comparison on the go and update
     */

    int elf = 1;
    int calories = 0;
    int maxCal = 0;
    int elfMaster = 0;

    std::string line;

    std::ifstream in("input.txt");
    while (std::getline(in, line))
    {
        if (line == "")
        { // compare
            if (calories > maxCal)
            {
                maxCal = calories;
                elfMaster = elf;
            }
            // next elf; reset calories
            ++elf;
            calories = 0;
        }
        else
        {
            calories += stoi(line);
        }
    }

    std::cout << "Elf is " << elfMaster << std::endl;
    std::cout << "Calories are " << maxCal << std::endl;

    return 0;
}