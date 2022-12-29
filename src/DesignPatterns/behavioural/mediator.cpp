/**
 * The mediator pattern is a behavioral design pattern that reduces dependencies between objects, and all the objects communicate through a mediator object.
 */

#include <string>
#include <iostream>

class DialogBox;

class UIControl
{
protected:
    DialogBox *owner;

public:
    UIControl(DialogBox *owner) : owner(owner){};
};

class DialogBox
{
public:
    virtual void changed(UIControl *control) = 0;
};

class ListBox : public UIControl
{
private:
    std::string selection;

public:
    ListBox(DialogBox *owner) : UIControl(owner)
    {
    }

    std::string getSelection()
    {
        return selection;
    }
    void setSelection(std::string selection)
    {
        this->selection = selection;
        owner->changed(this);
    }
};

class TextBox : public UIControl
{
private:
    std::string title;

public:
    TextBox(DialogBox *owner) : UIControl(owner)
    {
    }

    std::string getContent()
    {
        return title;
    }
    void setContent(std::string title)
    {
        this->title = title;
        owner->changed(this);
    }
};

class Button : public UIControl
{
private:
    bool isEnabled = true;

public:
    Button(DialogBox *owner) : UIControl(owner)
    {
    }
    void setEnabled(bool enable)
    {
        isEnabled = enable;
        owner->changed(this);
    }
    bool isEnabledOrNot()
    {
        return isEnabled;
    }
};

class ArticlesDialogBox : public DialogBox
{
private:
    ListBox *articleListBox = new ListBox(this);
    TextBox *titleTextBox = new TextBox(this);
    Button *saveBtn = new Button(this);
    void articleSelected()
    {
        titleTextBox->setContent(articleListBox->getSelection());
        saveBtn->setEnabled(true);
    }
    void titleChanged()
    {
        std::string title = titleTextBox->getContent();
        bool isEmpty = title.empty();
        saveBtn->setEnabled(!isEmpty);
    }

public:
    void changed(UIControl *control) override
    {
        if (control == articleListBox)
        {
            articleSelected();
        }
        else if (control == titleTextBox)
        {
            titleChanged();
        }
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

int main() {
    ArticlesDialogBox* adb = new ArticlesDialogBox();
    adb->simulateUserInteraction();
}