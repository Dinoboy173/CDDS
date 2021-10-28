#include <iostream>
#include <chrono>
#include <algorithm>

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
    
    list.Sort();
    

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Count: " << list.Count() << "\t\t Expected: 5" << std::endl;

    list.PushBack(60);
    std::cout << "Count: " << list.Count() << "\t\t Expected: 6" << std::endl;

    list.PushFront(5);
    std::cout << "Count: " << list.Count() << "\t\t Expected: 7" << std::endl;

    list.PopBack();
    std::cout << "Count: " << list.Count() << "\t\t Expected: 6" << std::endl;
    
    list.PopFront();
    std::cout << "Count: " << list.Count() << "\t\t Expected: 5" << std::endl;

    list.Remove(std::find(list.begin(), list.end(), 30));
    std::cout << "Count: " << list.Count() << "\t\t Expected: 4" << std::endl;
    
    list.Remove(std::find(list.begin(), list.end(), 50));
    std::cout << "Count: " << list.Count() << "\t\t Expected: 3" << std::endl;
    
    list.Insert(std::find(list.begin(), list.end(), 20), 30);
    std::cout << "Count: " << list.Count() << "\t\t Expected: 4" << std::endl;
    
    list.Remove(std::find(list.begin(), list.end(), 10));
    std::cout << "Count: " << list.Count() << "\t\t Expected: 3" << std::endl;

    list.Clear();
    std::cout << "Count: " << list.Count() << "\t\t Expected: 0" << std::endl;

    list.PopBack();
    std::cout << "Count: " << list.Count() << "\t\t Expected: 0" << std::endl;

    for (auto iter = list.begin(); iter != list.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
}