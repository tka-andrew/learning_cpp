/**
 * Composite is a structural design pattern that lets you compose objects into tree structures and then work with these structures as if they were individual objects.
 */

#include <iostream>
#include <vector>

class Component {
public: 
    virtual void render() = 0;
    virtual void move() = 0;
};

class Shape : public Component{
public:
    void render() override{
        std::cout<<"render\n";
    }
    void move() override{
        std::cout<<"move\n";
    }
};

class Group: public Component {
private:
    std::vector<Component*> components;
public:
    void add(Component* c) {
        components.push_back(c);
    }
    void render() override{
        for (Component* obj: components) {
            obj->render();
        }
    }
    void move() override{
        for (Component* obj: components) {
            obj->move();
        }
    }
};

int main() {
    Group* g1 = new Group();
    g1->add(new Shape());
    g1->add(new Shape());

    
    Group* g2 = new Group();
    g2->add(new Shape());
    g2->add(new Shape());

    Group* g = new Group();
    g->add(g1);
    g->add(g2);
    g->render();
    g->move();
    return 0;
}