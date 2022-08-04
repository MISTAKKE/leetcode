#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution

#include <iostream>
using namespace std;

class CFather {
  public:
    CFather(){};
    virtual void A()  //第一个虚函数
    {
        cout << "CFather :: A()" << endl;
    }
    virtual void A1()  //第二个虚函数
    {
        cout << "CFather :: A()" << endl;
    }
    void B()  //普通成员函数
    {
        cout << "CFather :: B()" << endl;
    }
    static void C()  //静态函数
    {
        cout << "CFather  :: C()" << endl;
    }
};
class CSon : public CFather {
  public:
    CSon(){};
    void A() {
        cout << "CSon :: A()" << endl;
    }
    void B() {
        cout << "CSon :: B()" << endl;
    }
};

void f0(){};

int f1(int a, int b){};

int f2(const int& a, int b){};

int main() {
    void (*pNormal)() = &f0;
    pNormal();  //调用
    int (*pf1)(int, int) = &f1;
    int (*pf2)(const int&, int) = &f2;

    CFather f;
    CSon c;
    void (*pC)() = &(CFather::C);         //静态成员函数指针
    void (CFather::*pB)() = &CFather::B;  //成员函数指针，需要用作用域修饰
    void (CFather::*pA)() =
        &CFather::A;  //虚函数指针，需要用作用域修饰，因为虚函数是在虚函数表中的便宜，需要有虚函数表的地址
    void (CFather::*pA1)() = &CFather::A1;  //虚函数指针，非第一个需函数
    (f.*pA)();  //基类对象，调用虚函数：基类虚函数表+偏移(需要有对象是因为需要虚表指针)
    (c.*pA)();  //子类对象，调用虚函数：子类虚函数表+偏移

    printf("Static Function dest:%p\n", pC);
    printf("Member Function dest:%p\n", pB);
    printf("Virtual Function(1) dest:%p\n", pA);   // 0x1 偏移量为1
    printf("Virtual Function(2) dest:%p\n", pA1);  // 0x9 偏移量为1+8
    return 0;
}
