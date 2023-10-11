#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"



int linearSearch(std::vector<std::string> list, const std::string& element);

int binarySearch(std::vector<std::string> stringList, const std::string& element);


int main() {

    std::vector<std::string> data = getStringData();


    std::cout << "Searching for 'not_here'" << std::endl;

    long long time = systemTimeNanoseconds();
    linearSearch(data, "not_here");
    long long currentTime = systemTimeNanoseconds() - time;
    std::cout << "Linear search took " << currentTime << " nanoseconds." << std::endl;

    time = systemTimeNanoseconds();
    binarySearch(data, "not_here");
    currentTime = systemTimeNanoseconds() - time;
    std::cout << "Binary search took " << currentTime << " nanoseconds." << std::endl;

    std::cout << "Searching for 'mzzzz'" << std::endl;

    time = systemTimeNanoseconds();
    linearSearch(data, "mzzzz");
    currentTime = systemTimeNanoseconds() - time;
    std::cout << "Linear search took " << currentTime << " nanoseconds." << std::endl;

    time = systemTimeNanoseconds();
    binarySearch(data, "mzzzz");
    currentTime = systemTimeNanoseconds() - time;
    std::cout << "Binary search took " << currentTime << " nanoseconds." << std::endl;


    std::cout << "Searching for 'aaaaa'" << std::endl;

    time = systemTimeNanoseconds();
    linearSearch(data, "aaaaa");
    currentTime = systemTimeNanoseconds() - time;
    std::cout << "Linear search took " << currentTime << " nanoseconds." << std::endl;

    time = systemTimeNanoseconds();
    binarySearch(data, "aaaaa");
    currentTime = systemTimeNanoseconds() - time;
    std::cout << "Binary search took " << currentTime << " nanoseconds." << std::endl;


    return 0;
}


int linearSearch(std::vector<std::string> stringList, const std::string& element)
{
    for(int i = 0; i < stringList.size(); i++)
    {
        if(element == stringList[i])
        {

            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> stringList, const std::string& element)
{
    int low = 0;
    int mid;
    int high = (stringList.size()) - 1;

    while(high >= low)
    {
        mid = (high + low) / 2;
        if(stringList[mid] > element)
        {
            high = mid - 1;
        }
        else if(stringList[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}