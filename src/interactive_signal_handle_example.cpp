#include <iostream>
#include <signal.h>

// Reference: https://www.tutorialspoint.com/how-do-i-catch-a-ctrlplusc-event-in-cplusplus
void interactive_signal_callback_handler(int signum)
{
    std::cout << "\nCaught interactive signal: " << signum << std::endl;
    std::cout << "Terminatng program" << std::endl;
    std::exit(signum);
}

int main()
{
    // Register interactive signal and interactive signal handler
    signal(SIGINT, interactive_signal_callback_handler);

    std::cout<<"\nThis program is running while(true) loop, use CTRL+C to terminate this program.\n";
    while (true)
    {

    }

    std::cout<<"This will not be reached as the program will exit in the callback handler.";
    return 0;
}