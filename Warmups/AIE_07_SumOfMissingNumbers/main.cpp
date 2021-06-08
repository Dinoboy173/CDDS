#include <iostream>
#include <vector>

// TODO: Write the sumMissingNumbers method here
int SumOfMissingNumbers(std::vector<int> arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        int nextI = i + 1;

        int nextNum = 0;

        if (arr[i] < arr[nextI])
            nextNum = arr[i] + 1;
        else if (arr[i] > arr[nextI])
            nextNum = arr[i] - 1;

        while (nextNum != arr[nextI])
        {
            if (arr[i] < arr[nextI])
            {
                sum = sum + nextNum;

                nextNum++;
            }
            else if (arr[i] > arr[nextI])
            {
                sum = sum + nextNum;

                nextNum--;
            }
        }
    }

    return sum;
}

int main(int argc, char** argv)
{
    // TODO: write tests to verify your output
    std::vector<int> arr1{ 1, 3, 5 };
    std::vector<int> arr2{ 1, 3, 5, 7, 10 };
    std::vector<int> arr3{ 10, 7, 5, 3, 1 };
    std::vector<int> arr4{ 10, 20, 30, 40, 50, 60 };

    std::cout << SumOfMissingNumbers(arr1) << " Expected: 6\n";
    std::cout << SumOfMissingNumbers(arr2) << " Expected: 29\n";
    std::cout << SumOfMissingNumbers(arr3) << " Expected: 29\n";
    std::cout << SumOfMissingNumbers(arr4) << " Expected: 1575";

}