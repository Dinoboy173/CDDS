#include <iostream>
#include <chrono>
#include "LinkedList.h"

int Client()
{
    LinkedList<int> list = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;

    while (true)
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
    }

    /*LinkedList<int> myList = { 10, 20, 30, 40, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.PushBack(70);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;
    
    myList.PushFront(5);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;
    
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;
    
    myList.PopFront();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;
    
    myList.Remove(std::find(myList.begin(), myList.end(), 30));
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 5" << std::endl;
    
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;

    myList = { 10, 20, 30, 40, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.Clear();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;*/
}