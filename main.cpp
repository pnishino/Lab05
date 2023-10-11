#include <iostream>
#include <string>
#include <vector>
#include "StringData.h"

int binarySearch(std::vector<std::string> container, std::string element);
int linearSearch(std::vector<std::string> container, std::string element);

int main() {
    std::vector<std::string> data = getStringData();
    std::cout<<"Searching for not here using linear search"<<"\n";
    long long time = systemTimeNanoseconds();
    std::cout<<"The index of not here is "<<linearSearch(data,"not_here")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    std::cout<<"\n";
    std::cout<<"Searching for not here using binary search"<<"\n";
    time = systemTimeNanoseconds();
    std::cout<<"The index of not here is "<<binarySearch(data,"not_here")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    std::cout<<"\n";
    std::cout<<"Searching for mzzzz using linear search"<<"\n";
    time = systemTimeNanoseconds();
    std::cout<<"The index of mzzzz is "<<linearSearch(data,"mzzzz")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    std::cout<<"\n";
    std::cout<<"Searching for mzzzz using binary search"<<"\n";
    time = systemTimeNanoseconds();
    std::cout<<"The index of mzzzz is "<<binarySearch(data,"mzzzz")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    std::cout<<"\n";
    std::cout<<"Searching for aaaaa using linear search"<<"\n";
    time = systemTimeNanoseconds();
    std::cout<<"The index of aaaaa is "<<linearSearch(data,"aaaaa")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    std::cout<<"\n";
    std::cout<<"Searching for aaaaa using binary search"<<"\n";
    time = systemTimeNanoseconds();
    std::cout<<"The index of aaaaa is "<<binarySearch(data,"aaaaa")<<"\n";
    std::cout<<"The time required to do this is "<<(systemTimeNanoseconds() - time)<<" nanoseconds"<<"\n";
    return 0;
}

int binarySearch(std::vector<std::string> container, std::string element){
    int i = 0;
    int j = container.size() - 1;
    int location = -1;
    while(i < j){
        int middle = (i+j)/2;
        if(element > container[middle]){
            i = middle + 1;
        }
        else{
            j = middle;
        }
        if(element == container[i]){
            location = i;
        }
    }
    return location;
}

int linearSearch(std::vector<std::string> container, std::string element){
    for(int i = 0; i< container.size();i++){
        if(container[i] == element){
            return i;
        }
    }
    return -1;
}