#include <iostream>
#include <string>
#include <map>
// TODO:
// Create a function that returns the number of characters shared between two words.

int SharedLetters1(std::string word1, std::string word2)
{
    int count = 0;

    for (int i = 0; i < word1.length(); i++)
    {
        for (int j = 0; j < word2.length(); j++)
        {
            if (word1[i] == word2[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

int SharedLetters2(std::string word1, std::string word2)
{
    int count = 0;

    std::map<std::string, int> words;
    
    words.insert(std::make_pair(word1, 1));
    words.insert(std::make_pair(word2, 2));

    std::map<std::string, int>::iterator iter = words.begin();
    while (iter != words.end())
    {
        
    }

    return count;
}

int Client()
{
    std::cout << SharedLetters1("apple", "meaty") << std::endl; // 2
    std::cout << SharedLetters1("fan", "forsook") << std::endl; // 1
    std::cout << SharedLetters1("spout", "shout") << std::endl; // 4
}
