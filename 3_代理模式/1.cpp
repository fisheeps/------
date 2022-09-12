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
        cout << mm->GetName() << " ����������" << endl;
    }

    void GiveFlowers()
    {
        cout << mm->GetName() << " �����ʻ�" << endl;
    }

    void GiveChocolate()
    {
        cout << mm->GetName() << " �����ɿ���" << endl;
    }

private:
    SchoolGirl *mm;
};

int main(int argc, char const *argv[])
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->SetName("���");

    Pursuit *zhoujiayi = new Pursuit(jiaojiao);

    zhoujiayi->GiveChocolate();
    zhoujiayi->GiveDolls();
    zhoujiayi->GiveFlowers();

    return 0;
}
