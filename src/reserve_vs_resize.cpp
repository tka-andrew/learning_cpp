#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;

    std::cout << "\n============== default size and capacity =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 0, default size
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 0, default capacity

    // resize(10) set the number of elements to 10
    // resize() supposedly only affect size, unless capacity is not enough
    // if current size() is less than that, instance creation will be done
    // if current size() is more than that, throw away the extra elements
    v.resize(10);
    std::cout << "\n============== after v.resize(10) =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 10
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 10, capacity changed due to increased in size

    v.resize(5);
    std::cout << "\n============== after v.resize(5) =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 5
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 10

    // reserve(100) set the capacity to 100, means the vector now can store up to 100 elements
    // reserve() only affects capacity, it does not affect size and elements in the vector
    // if current capacity() is more than that, it will remain the capacity
    v.reserve(100);
    std::cout << "\n============== after v.reserve(100) =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 5
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 100

    v.reserve(50);
    std::cout << "\n============== after v.reserve(50) =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 5
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 100
    
    v.shrink_to_fit();
    std::cout << "\n============== after v.shrink_to_fit() =========\n";
    std::cout << "size: " << v.size() << std::endl;         // prints 5
    std::cout << "capacity: " << v.capacity() << std::endl; // prints 5

    return 0;
}