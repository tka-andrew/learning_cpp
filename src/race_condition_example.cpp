#include <iostream>
#include <thread>
#include <fstream>
#include <string>

// for this example, you need to create a file called dummy.txt and put a number in it

int userCount = 0;

void registerUser() {
    std::fstream db;
    db.open("dummy.txt", std::ios::in); // open for read
    int count = 0;
    while (db >> count) {
        userCount = count + 1;
    }
    db.close();
    db.open("dummy.txt", std::ios::out | std::ios::trunc); // open to update file
    db << userCount;
    db.close();
}

int main() {
    std::thread registrationCounter1(registerUser);
    std::thread registrationCounter2(registerUser);
    std::thread registrationCounter3(registerUser);
    std::thread registrationCounter4(registerUser);

    registrationCounter1.join();
    registrationCounter2.join();
    registrationCounter3.join();
    registrationCounter4.join();

    // even though there are 4 threads here, but the end result will be less than 4 due to race condition
    std::cout<<"userCount: "<<userCount<<'\n';
    return 0;
}