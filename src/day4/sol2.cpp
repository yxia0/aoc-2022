/*
how many assignment pairs do the ranges overlap?
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /* Strategy
    Read 4 values as integer
    complement of (val2 < val 3) union (val1 , val4) 
    is the overlapping condition to meet
    */

    std::ifstream in("input.txt");
    int val1;
    int val2;
    int val3;
    int val4;
    char separator1;
    char separator2;
    char comma;
    int numOverlap = 0;

    while (in >> val1 >> separator1 >> val2 >> comma >> val3 >> separator2 >> val4)
    {
        if (!((val2 < val3) || (val1 > val4)))
        {
            ++numOverlap;
        }
    }

    std::cout << "Number of pairs that overlap at all: " << numOverlap << std::endl;

    return 1;
}