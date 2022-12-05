/*
In how many assignment pairs does one range fully contain the other?
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /* Strategy
    Read 4 values as integer
    the two ends of a range shall be larger than the two ends
    of the range it contain, check if two pairs meet this condition
    */

    std::ifstream in("input.txt");
    int val1;
    int val2;
    int val3;
    int val4;
    char separator1;
    char separator2;
    char comma;
    int numContain = 0;

    while (in >> val1 >> separator1 >> val2 >> comma >> val3 >> separator2 >> val4)
    {
        if (((val1 <= val3) && (val4 <= val2)) || ((val3 <= val1) && val2 <= val4))
        {
            ++numContain;
        }
    }

    std::cout << "Number of pairs that fully contain one or another: " << numContain << std::endl;

    return 1;
}