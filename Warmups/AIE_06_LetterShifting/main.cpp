#include <iostream>

std::string shiftLetters(std::string w, int n)
{
    std::string spacelessStr = "";
    std::string shiftedStr = "";

    int numOfSpaces = 0;

    for (int i = 0; i < w.length(); i++)
    {
        if (w[i] != ' ')
            spacelessStr += w[i];
        else
            numOfSpaces++;
    }

    int fullShiftStart = w.length() - n;
    int halfShiftStart = spacelessStr.length() - n;

    int j = halfShiftStart;

    for (int i = fullShiftStart; i < w.length();)
    {
        if (j != spacelessStr.length())
        {
            if (w[i] == ' ')
            {
                shiftedStr += ' ';

                shiftedStr += spacelessStr[j];

                j++;
            }
            else
            {
                shiftedStr += spacelessStr[j];

                j++;
                i++;
            }
        }
        else
            break;
    }

    

    return shiftedStr;
}

int main(int argc, char** argv)
{
    std::cout << shiftLetters("Boom", 1) << "; Expected : mBoo" << std::endl;
    std::cout << shiftLetters("Boom", 2) << "; Expected : omBo" << std::endl;
    std::cout << shiftLetters("This is a test", 4) << "; Expected: test Th i sisa" << std::endl;
    std::cout << shiftLetters("A B C D E F G H", 5) << "; Expected : D E F G H A B C" << std::endl;

    return 0;
}
