#include <iostream>
using namespace std;

class Component
{
public:
    virtual void Operation() {}
};

class ConcreteComponent : public Component
{
public:
    void Operation()
    {
        cout << "具体对象的操作" << endl;
    }
};

class Decorator : public Component
{
public:
    void SetComponent(Component *component)
    {
        this->component = component;
    }

    void Operation()
    {
        if (component != nullptr)
        {
            component->Operation();
        }
    }

private:
    Component *component;
};

class ConcreteDecoratorA : public Decorator
{
public:
    void Operation()
    {
        this->Operation();
        addedState = "New State";
        cout << "具体装饰对象A的操作" << endl;
    }

private:
    string addedState;
};

class ConcreteDecoratorB : public Decorator
{
public:
    void Operation()
    {
        this->Operation();
        AddedBehavior();
        cout << "具体装饰对象B的操作" << endl;
    }

private:
    void AddedBehavior()
    {
    }
};

int main(int argc, char const *argv[])
{
    ConcreteComponent *c = new ConcreteComponent();
    ConcreteDecoratorA *d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB *d2 = new ConcreteDecoratorB();

    d1->SetComponent(c);
    d2->SetComponent(d1);
    d2->Operation();

    return 0;
}
