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
        cout << "�������Ĳ���" << endl;
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
        cout << "����װ�ζ���A�Ĳ���" << endl;
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
        cout << "����װ�ζ���B�Ĳ���" << endl;
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
