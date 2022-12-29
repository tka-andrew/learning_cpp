/**
 * The Observer pattern is a behavioral design pattern that allows an object, called the subject, to notify a set of objects, called observers, about changes in its state,
 * This example shows a pull style communication, 
 */

#include <iostream>
#include <numeric>
#include <vector>

class Observer
{
public:
    virtual void update() = 0; // pure virtual function
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

    void notifyObservers() {
        for (Observer* obs:observers) {
            obs->update();
        }
    }
};


class DataSource: public Subject
{
private:
    std::vector<int> data;

public:
    std::vector<int> getDataSource()
    {
        return data;
    }
    void setValue(std::vector<int> d)
    {
        data = d;
        notifyObservers();
    }
};

class TotalChart : public Observer
{
private:
    DataSource* ds;
public:
    TotalChart(DataSource* ds): ds(ds) {};
    void update() override
    {
        std::vector<int> v = ds->getDataSource();
        double sum = std::accumulate(v.begin(), v.end(), 0);
        std::cout << "TotalChart got updated: " << sum << std::endl;
    }
};

class AverageChart : public Observer
{
private:
    DataSource* ds;
public:
    AverageChart(DataSource* ds): ds(ds) {};
    void update() override
    {
        std::vector<int> v = ds->getDataSource();
        double sum = std::accumulate(v.begin(), v.end(), 0);
        double average = sum / v.size();
        std::cout << "AverageChart got updated: " << average <<std::endl;
    }
};


int main() {
    DataSource* ds = new DataSource();
    TotalChart* s1 = new TotalChart(ds);
    AverageChart* c = new AverageChart(ds);

    ds->addObserver(s1);
    ds->addObserver(c);

    ds->setValue({4, 2, 3});
    ds->setValue({1, 2, 3});

    return 0;
}