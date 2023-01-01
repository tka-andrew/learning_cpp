/**
 * The bridge pattern is a design pattern used to decouple an abstraction from its implementation so that the two can vary independently.
 * In this example, we no longer need SonyAdvancedRemoteControl, PanasonicAdvancedRemoteControl etc
 */

#include <iostream>
#include <string>

class Device
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void setChannel(int channel) = 0;
};

class SonyTV : public Device
{
public:
    void turnOn() override
    {
        std::cout << "Sony: Turn On.\n";
    }
    void turnOff() override
    {
        std::cout << "Sony: Turn Off.\n";
    }
    void setChannel(int channel) override
    {
        std::cout << "Sony: Set Channel: " << channel << std::endl;
    }
};

class PanasonicTV : public Device
{
public:
    void turnOn() override
    {
        std::cout << "Panasonic: Turn On.\n";
    }
    void turnOff() override
    {
        std::cout << "Panasonic: Turn Off.\n";
    }
    void setChannel(int channel) override
    {
        std::cout << "Panasonic: Set Channel: " << channel << std::endl;
    }
};

class RemoteControl
{
protected:
    Device *device;

public:
    RemoteControl(Device *device) : device(device)
    {
    }
    void turnOn()
    {
        device->turnOn();
    }
    void turnOff()
    {
        device->turnOff();
    }
};

class AdvancedRemoteControl : public RemoteControl
{
public:
    AdvancedRemoteControl(Device *device) : RemoteControl(device){};
    void setChannel(int channel)
    {
        device->setChannel(channel);
    }
};

int main()
{
    RemoteControl *rc = new RemoteControl(new SonyTV());
    rc->turnOn();
    rc->turnOff();
    AdvancedRemoteControl *rc2 = new AdvancedRemoteControl(new SonyTV());
    rc2->setChannel(2);
    AdvancedRemoteControl *rc3 = new AdvancedRemoteControl(new PanasonicTV());
    rc3->setChannel(9);
    return 0;
}