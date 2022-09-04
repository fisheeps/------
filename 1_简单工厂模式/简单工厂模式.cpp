#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum sail_type
{
    normal = 0,
    eight_discount,
    return1
};

//现金收费抽象类
class CashSuper
{
public:
    virtual double acceptCash(double money) = 0;
};

//正常收费子类
class CashNormal : public CashSuper
{
public:
    double acceptCash(double money)
    {
        return money;
    }
};

//打折收费子类
class CashRebate : public CashSuper
{
public:
    CashRebate(string moneyRebate)
    {
        this->moneyRebate = stod(moneyRebate);
    }

    double acceptCash(double money)
    {
        return money * moneyRebate;
    }

private:
    double moneyRebate = 1.00;
};

//返利收费子类
class CashReturn : public CashSuper
{
public:
    CashReturn(string moneyCondition, string moneyReturn)
    {
        this->moneyCondition = stod(moneyCondition);
        this->moneyReturn = stod(moneyReturn);
    }

    double acceptCash(double money)
    {
        double result = money;
        if (money >= moneyCondition)
        {
            result = money - floor(money / moneyCondition) * moneyReturn;
        }
        return result;
    }

private:
    double moneyCondition = 0;
    double moneyReturn = 0;
};

//现金收费工厂类
class CashFactory
{
public:
    static CashSuper *createCashAccept(sail_type type)
    {
        CashSuper *cs = nullptr;
        switch (type)
        {
        case normal:
            cs = new CashNormal();
            break;

        case return1:
            cs = new CashReturn("300", "100");
            break;

        case eight_discount:
            cs = new CashRebate("0.8");
            break;
        }
        return cs;
    }
};

int main(int argc, char const *argv[])
{
    CashSuper *csuper;
    sail_type type;

    type = normal;
    csuper = CashFactory::createCashAccept(type);
    cout << csuper->acceptCash(1000) << endl;

    type = eight_discount;
    csuper = CashFactory::createCashAccept(type);
    cout << csuper->acceptCash(1000) << endl;

    type = return1;
    csuper = CashFactory::createCashAccept(type);
    cout << csuper->acceptCash(1000) << endl;

    return 0;
}
