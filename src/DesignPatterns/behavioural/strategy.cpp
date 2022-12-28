/**
 * Strategy is a behavioral design pattern that allows you to choose between different algorithms or approaches to solve a problem at runtime.
 * Strategy design pattern looks quite similar to State design pattern.
 * The main difference is, State design pattern does keep track of a state and alter its behaviour based on the state, for example, currentTool.
 * On the other hand, Strategy design pattern selects the approaches to be used at run time.
 */

#include <iostream>
#include <string>

// Compressor Interface
class Compressor
{
public:
    virtual void compress(std::string fileName) = 0; // pure virtual function
};

// Filter Interface
class Filter
{
public:
    virtual void apply(std::string fileName) = 0; // pure virtual function
};

class JpegCompressor : public Compressor
{
public:
    void compress(std::string filename) override
    {
        std::cout << "Compressing using JPEG.\n";
    }
};

class PngCompressor : public Compressor
{
public:
    void compress(std::string filename) override
    {
        std::cout << "Compressing using PNG.\n";
    }
};

class BlackAndWhiteFilter : public Filter
{
public:
    void apply(std::string fileName) override
    {
        std::cout << "Filtering using B&W filter.\n";
    }
};

class HighContrastFilter : public Filter
{
public:
    void apply(std::string fileName) override
    {
        std::cout << "Filtering using High Contrast filter.\n";
    }
};

class ImageStorage
{
public:
    void store(std::string fileName, Compressor *compressor, Filter *filter)
    {
        compressor->compress(fileName);
        filter->apply(fileName);
    }
};

int main()
{
    ImageStorage imgStore;
    imgStore.store("abc", new PngCompressor(), new BlackAndWhiteFilter());
    imgStore.store("xyz", new JpegCompressor(), new HighContrastFilter());
}