/**
 * The facade pattern is a design pattern that provides a simplified interface to a complex system, hiding its internal complexity and implementation details behind the facade.
 */

#include <string>
#include <iostream>

class Message
{
private:
    std::string content;

public:
    Message(std::string content) : content(content) {}
    std::string getContent()
    {
        return content;
    }
};

class Connection
{
public:
    void disconnect()
    {
        std::cout << "Connection terminated. \n";
    }
};

// dummy AuthToken class
class AuthToken
{
};

class NotificationServer
{
public:
    Connection *connect(std::string ipAddress)
    {
        std::cout << "Connection established. \n";
        return new Connection();
    }

    AuthToken *authenticate(std::string appID, std::string tokenKey)
    {
        return new AuthToken();
    }

    void send(AuthToken *authToken, Message *msg, std::string target)
    {
        std::cout << "Sending: " << msg->getContent() << std::endl;
        std::cout << "Target: " << target << std::endl;
    }
};

// Facade class
class NotificationService
{
public:
    void send(std::string message, std::string target)
    {
        NotificationServer *server = new NotificationServer();
        Connection *conn = server->connect("ip");
        AuthToken *authToken = server->authenticate("appID", "key");
        server->send(authToken, new Message(message), target);
        conn->disconnect();
    }
};

int main()
{
    NotificationService *ns = new NotificationService();
    ns->send("Hello World", "home panel");
    return 0;
}