/*
What would your total score be if everything goes
exactly according to your strategy guide?
Rules:
Y: Paper, X: Rock, Z: Scissors
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

    Too bad there is no pattern matching in C++
    too bad switch statement only works for integer :(
    */
    std::string pair;
    char fst;
    char snd;
    int sum = 0;

    std::ifstream in("input.txt");
    while (std::getline(in, pair))
    {
        // in >> fst >> snd; --> this skips the first line
        // of the input file. tricky!
        // std::string pair = "";
        // pair += fst;
        // pair += snd;

        if (pair == "A X")
            sum += 4; // Rock 1 + draw 3
        else if (pair == "A Y")
            sum += 8; // Paper 2 + win 6
        else if (pair == "A Z")
            sum += 3; // Scissors 3 + lost 0
        else if (pair == "B X")
            sum += 1; // Rock 1 + lost 0
        else if (pair == "B Y")
            sum += 5; // Paper 2 + draw 3
        else if (pair == "B Z")
            sum += 9; // Scissors 3 + win 6
        else if (pair == "C X")
            sum += 7; // Rock 1 + win 6
        else if (pair == "C Y")
            sum += 2; // Paper 2 + lost 0
        else if (pair == "C Z")
            sum += 6; // Scissor 3 + draw 3
    }

    std::cout << "Total score is " << sum << std::endl;

    return 1;
}
