/**
 * Iterator is a behavioral design pattern that lets you traverse elements of a collection without exposing its underlying representation (list, stack, tree, etc.).
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

// Iterator Interface
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual std::string current() = 0;
    virtual void next() = 0;
};

// Collection interface
class Collection
{
public:
    virtual Iterator *createIterator() = 0;
};

class StackIterator : public Iterator
{
private:
    std::stack<std::string> &stack_;
    int position_;
public:
    StackIterator(std::stack<std::string> &stack) : stack_(stack)
    {
        // Initialize the current position to the top of the stack
        position_ = stack.size() - 1;
    }

    bool hasNext() override
    {
        // Return true if the iterator has not reached the bottom of the stack yet
        return position_ >= 0;
    }

    std::string current() override
    {
        // Return the element at the current position
        return stack_.top();
    }

    void next() override
    {
        // Move to the next element by popping the top element from the stack
        stack_.pop();
        --position_;
    }
};

class ListIterator : public Iterator
{
private:
    std::vector<std::string> _urls;
    std::vector<std::string>::iterator it_;

public:
    ListIterator(std::vector<std::string> &urls) : _urls(urls)
    {
        it_ = _urls.begin();
    }
    bool hasNext() override
    {
        return it_ != _urls.end();
    }

    void next() override
    {
        if (this->hasNext()) {
            ++it_;
        }
    }

    std::string current() override
    {
        return *it_;
    }
};

class BrowseHistory : public Collection
{
private:
    std::vector<std::string> urls;

public:
    void push(std::string url)
    {
        urls.push_back(url);
    }

    std::string pop()
    {
        std::string lastUrl = urls[-1];
        urls.pop_back();
        return lastUrl;
    }

    Iterator *createIterator() override
    {
        return new ListIterator(urls);
    }
};

int main()
{
    BrowseHistory history;
    history.push("google.com");
    history.push("youtube.com");
    history.push("reddit.com");

    Iterator *iterator = history.createIterator();
    while (iterator->hasNext())
    {
        std::cout << iterator->current() << std::endl;
        iterator->next();
    }
    delete iterator;

    return 0;
}