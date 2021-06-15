// TODO: write your own starter code.
// Remember the following.
// 1. create the project and write the main method (1 min)
// 2. write some tests (2 min)
//    - call your function, pass in data... 
//    - just make sure its called... dont worry about logic yet.
// 3. make it compile(3 min max)
// 4. work out the logic (the rest of the time)
//    - work through the problem gradually, small steps, you dont need to know the answer upfront.
//    - use comments to help figure out what you need to do.
//    - iterate on your solution, use the debugger.
//
// NOTE:
// Like last week, many of you didnt even get to step 4. This is not ok!

#include <iostream>
#include <string>
#include <vector>

bool IsVowel(char letter)
{
	if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
	{
		return true;
	}

	return false;
}

std::string RemoveLastVowel(std::string sentence)
{
	int wordCount = 0;
	std::string word = "";
	std::vector<std::string> words;

	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == ' ')
		{
			words.push_back(word);
			word = "";
			wordCount++;
		}
		else
		{
			word += tolower(sentence[i]);
		}
	}

	for (int i = 0; i < wordCount; i++)
	{
		for (int j = words[i].length(); j > 0; j--)
		{
			if (IsVowel(words[i][j]))
			{
				words[i][j] = NULL;
				break;
			}
		}
	}

	std::string newSentence = "";

	for (int i = 0; i < wordCount; i++)
	{
		newSentence += words[i];
		newSentence += ' ';
	}

	return newSentence;
}

int main()
{
	std::cout << RemoveLastVowel("Those who dare to fail miserable can achieve greatly.") << std::endl;
	std::cout << RemoveLastVowel("Love is a serious mental disease.") << std::endl;
	std::cout << RemoveLastVowel("Get busy living or get busy dying.") << std::endl;

	return 0;
}