#include <iostream>
#include <vector>

// TODO: Write the FindOdd function

int FindOdd(std::vector<int> arr)
{
    int arrSize = arr.size();
    int count = 1;

    for (int i = 0; i < arrSize; i++)
    {
        //count = 1;

        for (int j = 0; j < arrSize; j++)
        {
            if (i != j)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }

            if (count % 2 != 0)
            {
                return arr[i];
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::vector<int> arr1{ 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 }; // -1
    std::vector<int> arr2{ 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 }; // 5
    std::vector<int> arr3{ 10 };

    // TODO: write test code to verify your function works as expected

    std::cout << FindOdd(arr1) << std::endl;
    std::cout << FindOdd(arr2) << std::endl;
    std::cout << FindOdd(arr3) << std::endl;

    return 0;
}