#include <iostream>
using namespace std;

class Person
{
public:
    Person() {}

    Person(string name)
    {
        this->name = name;
    }

    virtual void Show()
    {
        cout << "装扮的" << name << endl;
    }

private:
    string name;
};

class Finery : public Person
{
public:
    virtual void Show()
    {
        if (component != nullptr)
        {
            component->Show();
        }
    }

    void Decorate(Person *component)
    {
        this->component = component;
    }

protected:
    Person *component;
};

class TShirts : public Finery
{
public:
    void Show()
    {
        cout << "大T恤 ";
        component->Show();
    }
};

class BigTrouser : public Finery
{
public:
    void Show()
    {
        cout << "垮裤 ";
        component->Show();
    }
};

class Sneakers : public Finery
{
public:
    void Show()
    {
        cout << "破球鞋 ";
        component->Show();
    }
};

class Suit : public Finery
{
public:
    void Show()
    {
        cout << "西装 ";
        component->Show();
    }
};

class Tie : public Finery
{
public:
    void Show()
    {
        cout << "领带 ";
        component->Show();
    }
};

class LeatherShoes : public Finery
{
public:
    void Show()
    {
        cout << "皮鞋 ";
        component->Show();
    }
};

int main(int argc, char const *argv[])
{
    Person *xc = new Person("fisheeps");

    cout << "第一种装扮:" << endl;
    Sneakers *pqx = new Sneakers();
    BigTrouser *kk = new BigTrouser();
    TShirts *dtx = new TShirts();

    //下一个成员的装饰方法中传入上一个成员
    //这样就可以实现递归的效果
    pqx->Decorate(xc);
    kk->Decorate(pqx);
    dtx->Decorate(kk);
    dtx->Show();

    return 0;
}
