#include <vector>
#include <iostream>

int main()
{
    std::cout<<"===== v1 =====\n";
    std::vector<int> v1;
    v1.resize(10); //allocation + instance creation

    std::cout <<v1.size()<< std::endl;     //prints 10, already 10 items in the vector
    std::cout <<v1.capacity()<< std::endl; //prints 10

    // Since there are already 10 items in the vector, I should modify the elements instead of push_back
    for (int i=0; i<10; ++i) v1[i] = 999999;

    std::cout<<"===== v2 =====\n";
    std::vector<int> v2;
    v2.reserve(10); //only allocation

    std::cout <<v2.size()<< std::endl;     //prints 0, still no item in the vector
    std::cout <<v2.capacity()<< std::endl; //prints 10

    // Since there is no items in the vector, we can only push_back()
    for (int i=0; i<10; ++i) v2.push_back(999999);

    std::cout<<"===== v3 =====\n";
    std::vector<int> v3;
    v3.reserve(10); //only allocation

    std::cout <<v3.size()<< std::endl;     //prints 0, still no item in the vector
    std::cout <<v3.capacity()<< std::endl; //prints 10

    // What if we append 11 items?
    for (int i=0; i<11; ++i) v3.push_back(999999);

    std::cout <<v3.size()<< std::endl;     //prints 11
    std::cout <<v3.capacity()<< std::endl; //prints 20, capacity is doubled when reallocation happens

    return 0;
}