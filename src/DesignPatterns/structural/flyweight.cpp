/**
 * The flyweight pattern is a design pattern that allows you to share common, immutable data among multiple objects, reducing the memory overhead and improving performance.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

enum PointType
{
    HOSPITAL,
    CAFE,
    RESTAURANT
};

// flyweight object
class PointIcon
{
private:
    PointType type;
    std::vector<unsigned char> icon;

public:
    PointIcon(PointType type, std::vector<unsigned char> icon) : type(type), icon(icon){};
    std::string getType()
    {
        std::string typeString = "";
        switch (type)
        {
        case HOSPITAL:
            typeString = "Hospital";
            break;

        case CAFE:
            typeString = "Cafe";
            break;

        case RESTAURANT:
            typeString = "Restaurant";
            break;

        default:
            break;
        }
        return typeString;
    };
};

class Point
{
private:
    int x;
    int y;
    PointIcon *icon;

public:
    Point(int x, int y, PointIcon *icon) : x(x), y(y), icon(icon){};
    void draw()
    {
        std::cout << icon->getType() << ": (" << x << ", " << y << ")\n";
    }
};

// a factory to ensure the icon is stored in a single place
class PointIconFactory
{
private:
    std::map<PointType, PointIcon *> icons;

public:
    PointIcon *getPointIcon(PointType type)
    {
        // To ensure the icon is generated once only for each point type
        if (!icons.count(type) > 0)
        {
            PointIcon *icon = new PointIcon(type, {});
            icons[type] = icon;
        }
        return icons[type];
    }
};

class PointService
{
private:
    PointIconFactory iconFactory;

public:
    PointService(PointIconFactory iconFactory) : iconFactory(iconFactory){};
    std::vector<Point> getPoints()
    {
        std::vector<Point> dummy;
        dummy.push_back(Point(1, 2, iconFactory.getPointIcon(PointType(CAFE))));
        dummy.push_back(Point(9, 12, iconFactory.getPointIcon(PointType(HOSPITAL))));
        return dummy;
    }
};

int main()
{
    PointService *ps = new PointService(PointIconFactory());
    for (Point p : ps->getPoints())
    {
        p.draw();
    }
    return 0;
}