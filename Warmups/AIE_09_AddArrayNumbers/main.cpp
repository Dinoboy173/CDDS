#include <map>
#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <utility>

namespace solution
{
    std::pair<int, int> AddArrayNumbers(std::vector<int> vec, int answer)
    {
        int size = vec.size();

        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (vec[i] + vec[j] == answer)
                    return std::make_pair(vec[i], vec[j]);

        return std::make_pair(0, 0);
    }
}

void RunSolution(
    const char* name,
    std::function< std::pair<int, int>(std::vector<int> numbers, int answer)> solutionFn)
{
    int totalTime = 0;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    std::pair<int, int> r1, r2, r3, r4;
    for (int i = 0; i < 5; i++)
    {
        auto t1 = high_resolution_clock::now();
        for (int i = 0; i < 100000; i++)
        {

            r1 = solutionFn({ 1, 4, 8, 9, 12 }, 13);
            r2 = solutionFn({ 1, 2, 3, 7, 8, 9 }, 10);
            r3 = solutionFn({ 5, 7, 12, 13, 14, 15, 16, 17 }, 20);
            r4 = solutionFn({ 1, 4, 8, 9, 12 }, 21);
        }
        auto t2 = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(t2 - t1);
        totalTime += ms_int.count();
    }

    std::cout << name << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << r1.first << " + " << r1.second << " = " << 13 << std::endl;
    std::cout << r2.first << " + " << r2.second << " = " << 10 << std::endl;
    std::cout << r3.first << " + " << r3.second << " = " << 20 << std::endl;
    std::cout << r4.first << " + " << r4.second << " = " << 21 << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Average Time: " << totalTime / 5.0f << std::endl << std::endl;
}

int main()
{
    RunSolution("Solution", solution::AddArrayNumbers);
}