#include "../tool/helper.cpp"
using namespace std;

/*
description:


*/

// Class Solution
using namespace std;
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int num = 0x00636261;  //用16进制表示32位int，0x61是字符'a'的ASCII码
    int* pnum = &num;
    char* pstr = reinterpret_cast<char*>(pnum);
    cout << "sizeof(void*>" << sizeof(void*) << endl;
    cout << "变量num的地址: " << &num << endl;
    cout << "pnum指针的值(也就是num的地址): " << pnum << endl;
    cout << "pnum指针指向的值(也就是pnum指向的地址，以类型int展示的值): " << *pnum << endl;
    cout << "pstr指针的值: " << static_cast<void*>(pstr)
         << endl;  //直接输出pstr会输出其指向的字符串，这里的类型转换是为了保证输出pstr的值
    cout << "pnum指向的内容: " << hex << *pnum << endl;
    cout << "pstr指向的内容: " << pstr << endl;
    return 0;
}
