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
        cout << "װ���" << name << endl;
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
        cout << "��T�� ";
        component->Show();
    }
};

class BigTrouser : public Finery
{
public:
    void Show()
    {
        cout << "��� ";
        component->Show();
    }
};

class Sneakers : public Finery
{
public:
    void Show()
    {
        cout << "����Ь ";
        component->Show();
    }
};

class Suit : public Finery
{
public:
    void Show()
    {
        cout << "��װ ";
        component->Show();
    }
};

class Tie : public Finery
{
public:
    void Show()
    {
        cout << "��� ";
        component->Show();
    }
};

class LeatherShoes : public Finery
{
public:
    void Show()
    {
        cout << "ƤЬ ";
        component->Show();
    }
};

int main(int argc, char const *argv[])
{
    Person *xc = new Person("fisheeps");

    cout << "��һ��װ��:" << endl;
    Sneakers *pqx = new Sneakers();
    BigTrouser *kk = new BigTrouser();
    TShirts *dtx = new TShirts();

    //��һ����Ա��װ�η����д�����һ����Ա
    //�����Ϳ���ʵ�ֵݹ��Ч��
    pqx->Decorate(xc);
    kk->Decorate(pqx);
    dtx->Decorate(kk);
    dtx->Show();

    return 0;
}
