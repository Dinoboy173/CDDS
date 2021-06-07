#include <iostream>
#include <string>
#include <vector>
#include <cstring>


std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;

    // TODO: write code that "splits" the input string by the sperator
    // store each word in the resuts.

    std::string tempStr = "";

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == seperator)
        {
            result.push_back(tempStr);
            tempStr.clear();
        }
        else
        {
            tempStr += str[i];
        }
    }

    if (!tempStr.empty())
    {
        result.push_back(tempStr);
    }

    return result;
}

int main(int argc, char** argv)
{
    // Test 1
    std::cout << "---------------------------------------------------------" << std::endl;
    auto words = Explode(' ', "the quick brown fox jumps over the lazy dog");

    std::cout << "There are: " << words.size() << std::endl << std::endl;
    for (auto& w : words) {
        std::cout << w << std::endl;
    }


    // Test 2
    std::cout << "---------------------------------------------------------" << std::endl;
    auto kvp = Explode('&', "aaa:10&bbb:20ccc:30&&&&&ddd:30");

    std::cout << "There are: " << kvp.size() << std::endl << std::endl;
    for (auto& w : kvp) {
        std::cout << w << std::endl;
    }

    return 0;
}