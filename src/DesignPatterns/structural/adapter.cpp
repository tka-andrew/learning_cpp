/**
 * Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate.
 */
#include <iostream>

class Image
{
};

class Filter
{
public:
    virtual void apply(Image *image) = 0;
};

class VividFilter : public Filter
{
public:
    void apply(Image *img) override
    {
        std::cout << "Apply Vivid Filter\n";
    }
};

class ImageView
{
private:
    Image *img;

public:
    ImageView(Image *img) : img(img){};
    void apply(Filter *filter)
    {
        filter->apply(img);
    }
};

// Adoptee (The original filter that doesnt fit the Filter used in imageView)
class Caramel
{
public:
    void init()
    {
    }
    void render(Image *img)
    {
        std::cout << "Applying Camel Filter" << std::endl;
    }
};

// Adapter through Composition
// Acting as Caramel to Filter adapter, so that it can be used with the imageView
class CaramelFilter : public Filter
{
private:
    Caramel *caramel;

public:
    CaramelFilter(Caramel *c) : caramel(c){

                                };
    void apply(Image *img) override
    {
        caramel->init();
        caramel->render(img);
    }
};

// Adapter through Multiple Inheritance
// Acting as Caramel to Filter adapter, so that it can be used with the imageView)
class CaramelAdapter : public Filter, Caramel
{
public:
    void apply(Image *img) override
    {
        init();
        render(img);
    }
};

int main()
{
    ImageView *imgView = new ImageView(new Image());
    imgView->apply(new VividFilter());
    imgView->apply(new CaramelFilter(new Caramel()));
    imgView->apply(new CaramelAdapter());

    return 0;
}