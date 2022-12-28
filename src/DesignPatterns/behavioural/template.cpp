/**
 * Template design pattern is a behavioral design pattern that defines the skeleton of an algorithm in a method, leaving some steps to be implemented by derived classes.
 */
#include <iostream>

class Task
{
private:
    void init()
    {
        std::cout << "Task initialization running... \n";
    }

protected:
    virtual void doExecute() = 0;
    virtual void displayCompleteMsg()
    {
        std::cout << "Task completed.\n";
    }

public:
    void execute()
    {
        init();
        doExecute();
        displayCompleteMsg();
    }
};

class TransferMoneyTask : public Task
{
protected:
    void doExecute() override
    {
        std::cout << "Transfering money.\n";
    }
    void displayCompleteMsg() override
    {
        std::cout << "Successfully transferred money.\n";
    }
};

class GenerateReportTask : public Task
{
protected:
    void doExecute()
    {
        std::cout << "Generating report\n";
    }
};

int main()
{
    TransferMoneyTask *task1 = new TransferMoneyTask();
    task1->execute();
    GenerateReportTask *task2 = new GenerateReportTask();
    task2->execute();
}