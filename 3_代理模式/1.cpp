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

class Pursuit
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

int main(int argc, char const *argv[])
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->SetName("Àî½¿½¿");

    Pursuit *zhoujiayi = new Pursuit(jiaojiao);

    zhoujiayi->GiveChocolate();
    zhoujiayi->GiveDolls();
    zhoujiayi->GiveFlowers();

    return 0;
}
