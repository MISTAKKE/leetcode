#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
using namespace std;
#include <iostream>
using namespace std;
class A {
  public:
    int _a;
    A(int a = 1) : _a(a) {
        cout << "constructor() called, _a:" << _a << endl;
    };
    ~A() {
        cout << "deconstructor() called, _a:" << _a << endl;
    }
    A(const A& obj) {
        _a = obj._a;
        cout << "copy constructor() called, _a:" << _a << endl;
    }
    A& operator=(const A& obj) {
        _a = obj._a;
        cout << "assignment operator called, _a:" << _a << endl;
    }
    static void display() {
        cout << "display called()" << endl;
    }
    void show() {
        cout << "show() called, _a:" << _a << endl;
    }
    void constshow() const {
        cout << "constshow() called, _a:" << _a << endl;
    }
};

A f() {
    return A(2);
}

int main(int argc, char** argv) {
    A a = f();  // constructor() called
    a.show();
    cout << endl;

    A b(a);  // copy constructor() called
    b.show();
    cout << endl;

    b = a;  // assignment operator() called
    b.show();
    cout << endl;

    auto k = a;  // copy constructor() called
    k.show();
    k._a = 3;
    k.show();
    cout << endl;

    // auto &k1 = f();  error: invalid initialization of non-const reference of type ‘A&’ from an rvalue of type ‘A’
    // k1.show();

    //用f()返回的对象初始化创建k0，用const修饰标识k0是常量对象
    const auto& k0 = f();  // constructor() called, but k0 is const
    // k0.show(); //error: passing ‘const A’ as ‘this’ argument of ‘void A::show()’ discards qualifiers [-fpermissive]
    k0.constshow();
    k0.display();
    cout << endl;

    //常引用，只能调const修饰的成员函数
    const auto& k1 = a;  // const reference
    // k1.show(); //error: passing ‘const A’ as ‘this’ argument of ‘void A::show()’ discards qualifiers [-fpermissive]
    k1.constshow();
    k1.display();
    cout << endl;

    //引用
    auto&& k2 = a;  // reference not make object
    k2.show();
    k2._a = 3;
    k2.show();
    cout << endl;

    //用f()返回的对象初始化创建k3
    auto&& k3 = f();  // constructor() called
    k3.show();
    k3._a = 3;
    k3.show();
    cout << endl;

    auto k4 = k0;
    k4.show();
    k4.constshow();
    cout << endl;

    return 0;
}
