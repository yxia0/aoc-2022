/*
What would your total score be if everything goes
exactly according to your strategy guide?
Rules:
Y: draw, X: lose, Z: win
A: Rock, B: Paper, C: Scissors
Scores:
Rock: 1,  Paper: 2, Scissors: 3
lost: 0, draw: 3, win: 6
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    /* Strategy:
    Write out all the scores for combos:
    AX,AY,AZ,BX,...CZ
    and sum up
    */
    std::string pair;
    char fst;
    char snd;
    int sum = 0;

    std::ifstream in("input.txt");
    while (std::getline(in, pair))
    {
        if (pair == "A X")
            sum += 3; // Sci 3 + lose 0
        else if (pair == "A Y")
            sum += 4; // Rock 1 + draw 3
        else if (pair == "A Z")
            sum += 8; // Paper 2 + win 6
        else if (pair == "B X")
            sum += 1; //  Rock 1 + lost 0
        else if (pair == "B Y")
            sum += 5; // Paper 2 + draw 3
        else if (pair == "B Z")
            sum += 9; // Scissors 3 + win 6
        else if (pair == "C X")
            sum += 2; //  Paper 2 + lose 0
        else if (pair == "C Y")
            sum += 6; // Sci 3 + draw 3
        else if (pair == "C Z")
            sum += 7; // Rock 1 + win 6
    }

    std::cout << "Total score is " << sum << std::endl;

    return 1;
}
