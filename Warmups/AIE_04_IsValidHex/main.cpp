#include <iostream>
#include <string>

// TODO: Write your function here
bool isValidHexCode(std::string hexCode)
{
    const int validCharsLength = 15;
    const char validChars[validCharsLength] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

    if (hexCode[0] != '#')
        return false;

    if (hexCode.length() != 7)
        return false;

    for (int i = 1; i < hexCode.length(); i++)
    {
        bool isValidChar = false;
        hexCode[i] = std::tolower(hexCode[i]);

        for (int j = 0; j < validCharsLength; j++)
        {
            if (hexCode[i] == validChars[j])
            {
                isValidChar = true;
                break;
            }
            else
                isValidChar = false;
        }

        if (isValidChar == false)
            return false;
    }

    return true;
}


int Client()
{
    std::string hex1 = "#CD5C5C";
    std::string hex2 = "#EAECEE";
    std::string hex3 = "#eaecee";
    std::string hex4 = "#Cd5C5C";
    std::string hex5 = "#CD5C58C";
    std::string hex6 = "#CD5C5Z";
    std::string hex7 = "#CD5C&C";
    std::string hex8 = "CD5C5C";

    std::cout << hex1 << ": " << isValidHexCode(hex1) << ": expected true" << std::endl;
    std::cout << hex2 << ": " << isValidHexCode(hex2) << ": expected true" << std::endl;
    std::cout << hex3 << ": " << isValidHexCode(hex3) << ": expected true" << std::endl;
    std::cout << hex4 << ": " << isValidHexCode(hex4) << ": expected true" << std::endl;
    std::cout << hex5 << ": " << isValidHexCode(hex5) << ": expected false" << std::endl;
    std::cout << hex6 << ": " << isValidHexCode(hex6) << ": expected false" << std::endl;
    std::cout << hex7 << ": " << isValidHexCode(hex7) << ": expected false" << std::endl;
    std::cout << hex8 << ": " << isValidHexCode(hex8) << ": expected false" << std::endl;
}