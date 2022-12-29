/**
 * Command design pattern is a behavioural design pattern that encapsulates a request as an object in order to separate the request sender and the request receiver.
 */

#include <iostream>
#include <string>

class Command
{
public:
    virtual void execute() = 0; // pure virtual function
};

class PrintCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Printing..." << std::endl;
    }
};

class CopyCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Copying ..." << std::endl;
    }
};

class Button
{
private:
    std::string label;
    Command *command;

public:
    Button(Command *command) : command(command) {}
    void click()
    {
        command->execute();
    }
};

int main()
{
    Button *printButton = new Button(new PrintCommand());
    printButton->click();
    Button *copyButton = new Button(new CopyCommand());
    copyButton->click();
    return 0;
}