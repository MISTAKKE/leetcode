#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

//Class Solution

#include <iostream>
using namespace std;

class CFather
{
public:
    CFather()
    {
        cout << "CFather :: construct function called" << endl;
    }
     ~CFather()
    {
        /*
            如果基类析构函数声明为virtual, 那么用基类指针实现多态时, delete基类指针时会调用子类的析构函数
        */
        cout << "CFather :: deconstruct function called" << endl;
    }
    virtual void A() //第一个虚函数
    {
        cout << "CFather :: A()" << endl;
    }
};
class CSon : public CFather
{
public:
    CSon()
    {
        cout << "CSon :: construct function called" << endl;
    }
     ~CSon()
    {
        cout << "CSon :: decontract() called" << endl;
    }
    void A()
    {
        cout << "CSon :: A()" << endl;
    }
};

int main()
{
    CFather *b = new CSon();
    delete b;
    return 0;
}
