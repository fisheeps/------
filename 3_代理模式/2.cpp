#include <iostream>
using namespace std;

class SchoolGirl
{
private:
    string name;

public:
    void SetName(string name)
    {
        this->name = name;
    }

    string GetName()
    {
        return this->name;
    }
};

class GiveGift
{
public:
    virtual void GiveDolls()
    {
    }

    virtual void GiveFlowers()
    {
    }

    virtual void GiveChocolate()
    {
    }
};

class Pursuit : public GiveGift
{
public:
    Pursuit(SchoolGirl *mm)
    {
        this->mm = mm;
    }

    void GiveDolls()
    {
        cout << mm->GetName() << " ËÍÄãÑóÍÞÍÞ" << endl;
    }

    void GiveFlowers()
    {
        cout << mm->GetName() << " ËÍÄãÏÊ»¨" << endl;
    }

    void GiveChocolate()
    {
        cout << mm->GetName() << " ËÍÄãÇÉ¿ËÁ¦" << endl;
    }

private:
    SchoolGirl *mm;
};

class Proxy : public GiveGift
{
public:
    Proxy(SchoolGirl *mm)
    {
        gg = new Pursuit(mm);
    }

    void GiveDolls()
    {
        gg->GiveDolls();
    }

    void GiveFlowers()
    {
        gg->GiveFlowers();
    }

    void GiveChocolate()
    {
        gg->GiveChocolate();
    }

private:
    Pursuit *gg;
};

int main(int argc, char const *argv[])
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->SetName("Àî½¿½¿");

    Proxy *daili = new Proxy(jiaojiao);

    daili->GiveChocolate();
    daili->GiveDolls();
    daili->GiveFlowers();

    return 0;
}
