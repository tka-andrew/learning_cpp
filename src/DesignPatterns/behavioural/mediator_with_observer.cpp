/**
 * The mediator pattern is a behavioral design pattern that reduces dependencies between objects, and all the objects communicate through a mediator object.
 * This example shows how Observer pattern can be used to further refactor the code.
 * The Observer below is actually similar to the EventHandler that we normally see in UI frameworks.
 */

#include <string>
#include <iostream>
#include <vector>

class Observer
{
public:
    virtual void update() = 0;
};

class UIControl
{
private:
    std::vector<Observer *> observers;

public:
    void attachObserver(Observer *ob)
    {
        observers.push_back(ob);
    }

protected:
    void notifyObservers()
    {
        for (Observer *obs : observers)
        {
            obs->update();
        }
    }
};

class ListBox : public UIControl
{
private:
    std::string selection;

public:
    std::string getSelection()
    {
        return selection;
    }
    void setSelection(std::string selection)
    {
        this->selection = selection;
        notifyObservers();
    }
};

class TextBox : public UIControl
{
private:
    std::string title;

public:
    std::string getContent()
    {
        return title;
    }
    void setContent(std::string title)
    {
        this->title = title;
        notifyObservers();
    }
};

class Button : public UIControl
{
private:
    bool isEnabled = true;

public:
    void setEnabled(bool enable)
    {
        isEnabled = enable;
        notifyObservers();
    }
    bool isEnabledOrNot()
    {
        return isEnabled;
    }
};

class ArticleListBoxObserver : public Observer
{
private:
    ListBox *articleListBox;
    TextBox *titleTextBox;
    Button *saveBtn;

public:
    ArticleListBoxObserver(ListBox *articleListBox, TextBox *titleTextBox, Button *saveBtn) : articleListBox(articleListBox), titleTextBox(titleTextBox), saveBtn(saveBtn){};
    void update() override
    {
        titleTextBox->setContent(articleListBox->getSelection());
        saveBtn->setEnabled(true);
    }
};

class TitleTextBoxObserver: public Observer {
private:
    TextBox *titleTextBox;
    Button *saveBtn;

public:
    TitleTextBoxObserver(TextBox *titleTextBox, Button *saveBtn) : titleTextBox(titleTextBox), saveBtn(saveBtn){};
    void update() override
    {
        std::string title = titleTextBox->getContent();
        bool isEmpty = title.empty();
        saveBtn->setEnabled(!isEmpty);
    }
};

class ArticlesDialogBox
{
private:
    ListBox *articleListBox = new ListBox();
    TextBox *titleTextBox = new TextBox();
    Button *saveBtn = new Button();

public:
    ArticlesDialogBox()
    {
        articleListBox->attachObserver(new ArticleListBoxObserver(articleListBox, titleTextBox, saveBtn));
        titleTextBox->attachObserver(new TitleTextBoxObserver(titleTextBox, saveBtn));
    }

    void simulateUserInteraction()
    {
        articleListBox->setSelection("Article 1");
        std::cout << "TextBox: " << titleTextBox->getContent() << std::endl;
        std::cout << "Button: " << saveBtn->isEnabledOrNot() << std::endl;
        titleTextBox->setContent("");
        std::cout << "TextBox: " << titleTextBox->getContent() << std::endl;
        std::cout << "Button: " << saveBtn->isEnabledOrNot() << std::endl;
        articleListBox->setSelection("Article 2");
        std::cout << "TextBox: " << titleTextBox->getContent() << std::endl;
        std::cout << "Button: " << saveBtn->isEnabledOrNot() << std::endl;
    }
};

int main()
{
    ArticlesDialogBox *adb = new ArticlesDialogBox();
    adb->simulateUserInteraction();
}