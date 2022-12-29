/**
 * The visitor pattern is a way to separate an algorithm from an object structure by moving the algorithm into a separate class called a visitor. 
 * This allows for the addition of new operations to be performed on the object structure without modifying the objects themselves.
 * In the example below, adding new operations do not need to modify the HeadingNode and AnchorNode.
 */

#include <iostream>
#include <vector>

class HeadingNode;
class AnchorNode;

// Visitor
class Operation {
public:
    virtual void apply(HeadingNode* heading) = 0; // pure virtual function
    virtual void apply(AnchorNode* anchor) = 0; // pure virtual function
};

class HtmlNode {
public:
    virtual void execute(Operation* operation) = 0; // pure virtual function
};

class HeadingNode: public HtmlNode {
public:
    void execute(Operation* operation) override{
        operation->apply(this);
    } 
};

class AnchorNode: public HtmlNode {
public:
    void execute(Operation* operation) override{
        operation->apply(this);
    } 
};

class HtmlDocument {
private:
    std::vector<HtmlNode*> nodes;
public:
    void add(HtmlNode* node) {
        nodes.push_back(node);
    }
    void execute(Operation* operation) {
        for (HtmlNode* n:nodes) {
            n->execute(operation);
        }
    }
};

class HighlightOperation: public Operation {
public:
    void apply(HeadingNode* heading) override{
        std::cout<<"Highlight heading\n";
    }
    void apply(AnchorNode* anchor) override{
        std::cout<<"Highlight anchor\n";
    }
};

class ExtractTextOperation: public Operation {
public:
    void apply(HeadingNode* heading) override{
        std::cout<<"Extract text from heading\n";
    }
    void apply(AnchorNode* anchor) override{
        std::cout<<"Extract text from anchor\n";
    }
};

int main() {
    HtmlDocument* document = new HtmlDocument();
    document->add(new HeadingNode());
    document->add(new AnchorNode());
    document->execute(new HighlightOperation());
    document->execute(new ExtractTextOperation());
}