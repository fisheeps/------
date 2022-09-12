#include <iostream>
using namespace std;

class Subject
{
public:
    virtual void Request() {}
};

class RealSubject : public Subject
{
public:
    void Request()
    {
        cout << "真实的请求" << endl;
    }
};

class Proxy : public Subject
{
public:
    void Request()
    {
        if (realSubject == nullptr)
        {
            realSubject = new RealSubject();
        }
        realSubject->Request();
    }

private:
    RealSubject *realSubject;
};

int main(int argc, char const *argv[])
{
    Proxy *proxy = new Proxy();
    proxy->Request();

    return 0;
}
