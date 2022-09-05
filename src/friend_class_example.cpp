#include <iostream>

class RobotController; // forward declaration

class Robot
{
private:
    float x{0.0f};
    float y{0.0f};
    float theta{0.0f};

public:
    Robot()
    {
    }

    Robot(float x, float y, float theta) : x{x}, y{y}, theta{theta}
    {
    }

    void getCurrentPosition()
    {
        std::cout<<"x: "<< x <<" y: "<< y << " theta: "<<theta<<'\n';
    }

    friend class RobotController; // RobotController is considered a friend by Robot
};

class RobotController
{
private:
    bool safety_triggered{false};

public:
    void setRobotPosition(Robot &r, float x, float y, float theta)
    {
        r.x = x;
        r.y = y;
        r.theta = theta;
    }
};

int main()
{
    Robot robot1;
    Robot robot2;
    RobotController robot_ctrl;
    robot_ctrl.setRobotPosition(robot1, 2.0f, 3.0f, 3.14f);
    robot_ctrl.setRobotPosition(robot2, 4.0f, 1.0f, 0.0f);
    robot1.getCurrentPosition();
    robot2.getCurrentPosition();
    return 0;
}