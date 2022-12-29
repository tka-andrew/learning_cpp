/**
 * Chain of Responsibility is a behavioral design pattern that lets you pass requests along a chain of handlers.
 * With this pattern, each handler in the chain is independent and the chain can be easily modified.
 */

#include <iostream>
#include <string>

class HttpRequest
{
private:
    std::string username;
    std::string password;

public:
    HttpRequest(std::string u, std::string p) : username(u), password(p){};
    std::string getUsername() { return username; }
    std::string getPassword() { return password; }
};

class Handler
{
private:
    Handler *next;

public:
    Handler(Handler *next) : next(next){};
    virtual void handle(HttpRequest *request)
    {
        if (doHandle(request))
            return;
        if (next != nullptr)
            next->handle(request);
    };
    virtual bool doHandle(HttpRequest *request) = 0;
};

class Authenticator : public Handler
{
public:
    Authenticator(Handler *next) : Handler(next){};
    bool doHandle(HttpRequest *request) override
    {
        bool isValid = (request->getUsername() == "admin" && request->getPassword() == "1234");
        std::cout << "Authenthication\n";
        return !isValid; // true means end the chain
    }
};

class Compressor : public Handler
{
public:
    Compressor(Handler *next) : Handler(next){};
    bool doHandle(HttpRequest *request) override
    {
        std::cout << "Compress\n";
        return false; // means not yet done processing
    }
};

class Logger : public Handler
{
public:
    Logger(Handler *next) : Handler(next){};
    bool doHandle(HttpRequest *request) override
    {
        std::cout << "Log\n";
        return false; // means not yet done processing
    }
};

class WebServer
{
private:
    Handler *handler;

public:
    WebServer(Handler *handler) : handler(handler){};
    void handle(HttpRequest *request)
    {
        handler->handle(request);
    }
};

int main()
{
    // Pipeline: authenticator -> logger -> compressor
    Compressor *compressor = new Compressor(nullptr);
    Logger *logger = new Logger(compressor);
    Authenticator *authenticator = new Authenticator(logger);
    WebServer *server = new WebServer(authenticator);
    server->handle(new HttpRequest("admin", "1234"));
    server->handle(new HttpRequest("admin", "4321"));
    return 0;
}