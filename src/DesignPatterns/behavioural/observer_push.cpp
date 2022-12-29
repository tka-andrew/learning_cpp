/**
 * The Observer pattern is a behavioral design pattern that allows an object, called the subject, to notify a set of objects, called observers, about changes in its state,
 * This example shows a push style communication, 
 */

#include <iostream>
#include <numeric>
#include <vector>

class Observer
{
public:
    virtual void update(std::vector<int> v) = 0; // pure virtual function
};

class TotalChart : public Observer
{
public:
    void update(std::vector<int> v) override
    {
        double sum = std::accumulate(v.begin(), v.end(), 0);
        std::cout << "TotalChart got updated: " << sum << std::endl;
    }
};

class AverageChart : public Observer
{
public:
    void update(std::vector<int> v) override
    {
        double sum = std::accumulate(v.begin(), v.end(), 0);
        double average = sum / v.size();
        std::cout << "AverageChart got updated: " << average <<std::endl;
    }
};

// Observable
class Subject
{
private:
    std::vector<Observer *> observers;

public:
    void addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer *observer)
    {
        for (std::vector<Observer *>::iterator it = observers.begin(); it != observers.end(); ++it)
        {
            if (*it == observer)
            {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers(std::vector<int> v) {
        for (Observer* obs:observers) {
            obs->update(v);
        }
    }
};

class DataSource: public Subject
{
private:
    std::vector<int> data;

public:
    std::vector<int> getValue()
    {
        return data;
    }
    void setValue(std::vector<int> d)
    {
        data = d;
        notifyObservers(d);
    }
};

int main() {
    DataSource* ds = new DataSource();
    TotalChart* s1 = new TotalChart();
    AverageChart* c = new AverageChart();

    ds->addObserver(s1);
    ds->addObserver(c);

    ds->setValue({4, 2, 3});
    ds->setValue({1, 2, 3});

    return 0;
}