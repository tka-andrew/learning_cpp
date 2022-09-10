#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

void loading()
{
    std::cout << "\nLoading Multi Threading Demo\n";
    float progress = 0.0;
    while (progress <= 1.00)
    {
        int barWidth = 70;

        std::cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                std::cout << "=";
            else if (i == pos)
                std::cout << ">";
            else
                std::cout << " ";
        }
        std::cout << "] " << int(progress * 100.0) << " %\r";
        std::cout.flush();

        progress += 0.2;
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
    }
    std::cout << std::endl
              << std::endl;
}

void currentTime()
{
    while (true)
    {
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << ctime(&time);
    }
}

void printMsgEvery5seconds(std::string msg)
{
    while (true)
    {
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(5));
        std::cout << msg << '\n';
    }
}

int main()
{
    std::thread task1(loading);
    task1.join(); // This line is placed before declaration of task2 and task3, to ensure task1 is finished running before proceeding to other tasks

    std::thread task1b(loading);
    task1b.detach(); // Calling detach() will leave the thread to run in the background

    // Constructs the new thread and runs it. Does not block execution.
    std::thread task2(currentTime);
    std::thread task3(printMsgEvery5seconds, "Hello World!"); // thread constructor with parameters

    task2.join(); // thread should be either detach() or join()
    task3.join(); // thread should be either detach() or join()

    return 0;
}