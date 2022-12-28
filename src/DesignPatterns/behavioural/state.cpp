/**
 * State is a behavioral design pattern that allows an object to alter its behavior when its internal state changes.
 */

#include <iostream>

class ITool {
public:
    virtual void mouseUp() = 0; // pure virtual function
    virtual void mouseDown() = 0; // pure virtual function
    virtual ~ITool() {} // make a virtual destructor in case we delete an ITool pointer, so the proper derived destructor is called
};

class SelectionTool: public ITool {
    void mouseDown() override {
        std::cout << "Selection Icon\n";
    }
    void mouseUp() override {
        std::cout << "Draw a dashed rectangle.\n";
    }
};

class BrushTool: public ITool {
    void mouseDown() override {
        std::cout << "Brush Icon\n";
    }
    void mouseUp() override {
        std::cout << "Draw a line.\n";
    }
};

class Canvas {
private:
    ITool* currentTool;

public:
    void mouseDown() {
        currentTool->mouseDown();
    }

    void mouseUp() {
        currentTool->mouseUp();
    }

    ITool* getCurrentTool() {
        return currentTool;
    }

    void setCurrentTool(ITool* t) {
        currentTool = t;
    }
};

int main() {
    Canvas c;
    c.setCurrentTool(new SelectionTool());
    c.mouseDown();
    c.mouseUp();
    c.setCurrentTool(new BrushTool());
    c.mouseDown();
    c.mouseUp();
    return 0;
}