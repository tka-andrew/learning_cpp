/**
 * Memento is a behavioral design pattern that allows you to save and restore the previous state of an object without revealing the details of its implementation.
 */
#include <iostream>
#include <string>
#include <stack>

// Memento Class
class EditorState
{
private:
    std::string _content;

public:
    EditorState(std::string content) : _content{content} {};

    std::string getContent()
    {
        return _content;
    }
};

// Originator Class
class Editor
{
private:
    std::string _content;

public:
    EditorState createState()
    {
        return EditorState(_content);
    }

    void restore(EditorState state)
    {
        _content = state.getContent();
    }

    void setContent(std::string c)
    {
        _content = c;
    }

    std::string getContent()
    {
        return _content;
    }
};

// Caretaker class
class History
{
private:
    std::stack<EditorState> history;

public:
    void add(EditorState state)
    {
        history.push(state);
    }

    EditorState undo()
    {
        EditorState prev = history.top();
        history.pop();
        return prev;
    }
};

int main()
{
    Editor *editor = new Editor();
    History *history = new History();

    editor->setContent("A");
    history->add(editor->createState());
    editor->setContent("B");
    history->add(editor->createState());
    editor->setContent("C");
    std::cout << "current content: " << editor->getContent() << '\n';
    editor->restore(history->undo());
    std::cout << "current content: " << editor->getContent() << '\n';
    editor->restore(history->undo());
    std::cout << "current content: " << editor->getContent() << '\n';

    return 0;
}