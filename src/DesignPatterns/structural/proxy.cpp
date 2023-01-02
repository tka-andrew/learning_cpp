/**
 * A proxy is a design pattern in which a class represents the functionality of another class, allowing for additional control and customization of operations such as lazy loading, 
 * where the object being represented is only created when it is needed. 
 * In this example, although all the books are added to the library, but they are only loaded when they are needed
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

class Ebook {
public:
    virtual void show() = 0;
    virtual std::string getFileName() = 0;
};

class RealEbook: public Ebook {
private: 
    std::string fileName;
public:
    void load() {
        std::cout<<"Loading the ebook: "<<fileName<<std::endl;
    }
    void show() override{
        std::cout<<"Showing the ebook: "<<fileName<<std::endl;
    }
    RealEbook(std::string fileName): fileName(fileName) {
        load();
    };
    std::string getFileName() override{
        return fileName;
    }
};

// Proxy class
class EbookProxy : public Ebook {
private: 
    RealEbook* ebook;
    std::string fileName;
public:
    EbookProxy(std::string fileName): fileName(fileName) {
    };
    void show() override {
        if (ebook == nullptr) {
            ebook = new RealEbook(fileName);
        }
        ebook->show();
    }
    std::string getFileName() override{
        return fileName;
    }
};


class Library{
    private:
        std::map<std::string, Ebook*> ebooks;
public:
    void add(Ebook* ebook){
        ebooks[ebook->getFileName()] = ebook;       
    }
    void openEbook(std::string fileName) {
        ebooks[fileName]->show();
    }
};

int main() {
    Library library;
    std::vector<std::string> fileNames = {"a", "b", "c", "d"};
    for (std::string f : fileNames) {
        library.add(new EbookProxy(f));
    }
    library.openEbook("a");
    library.openEbook("c");
    library.openEbook("a"); // each ebook is only loaded once
}