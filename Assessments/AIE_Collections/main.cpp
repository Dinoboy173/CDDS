#include <iostream>
#include <chrono>
#include "LinkedList.h"

int main()
{
    bool loop = false;
    LinkedList<int> list = { 10, 50, 20, 40, 30 };

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    while (!loop)
    {
        std::string command = "";

        std::cin >> command;

        if (command == "sort")
        {
            int sortAttempts = 0;
        
            auto t1 = std::chrono::high_resolution_clock::now();
            list.Sort(); // Do the sort that you want to time
            auto t2 = std::chrono::high_resolution_clock::now();
            // Getting number of milliseconds as a double.
            std::chrono::duration<double, std::milli> duration = t2 - t1;
            std::cout << duration.count() << "ms";
            std::cout << std::endl;
        
            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                std::cout << *iter << std::endl;
            }
            std::cout << std::endl;
        }
        
        if (command == "add")
        {
            int value;
        
            std::cin >> value;
        
            list.PushBack(value);
        
            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                std::cout << *iter << std::endl;
            }
            std::cout << std::endl;
        }

        if (command == "tests")
        {
            LinkedList<int> myList = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120 };
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 12" << std::endl;

            myList.PushBack(70);
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 13" << std::endl;

            myList.PushFront(5);
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 14" << std::endl;

            myList.PopBack();
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 13" << std::endl;

            myList.PopFront();
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 12" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 30));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 11" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 50));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 10" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 70));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 9" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 10));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 120));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

            myList.Remove(std::find(myList.begin(), myList.end(), 90));
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

            myList.Clear();
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;

            myList.PopBack();
            std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;
        }
    }
}