/*1952339 信08 张馨月*/
#include <iostream>
using namespace std;
class A_1952339 {
public:
    int a;
    virtual void f1() { cout << "A::f1()" << endl; }
    virtual void f2() { cout << "A::f2()" << endl; }
};

class B_1952339{
public:
    int b;
    virtual void f1() { cout << "B::f1()" << endl; }
    virtual void f2() { cout << "B::f2()" << endl; }
};

class C_1952339 : public B_1952339, public A_1952339 {
public:
    int c;
    virtual void f1() { cout << "C::f1()" << endl; }
};

typedef void(*VFPTR)();

void PrintVTable(VFPTR vTable[])
{
    cout << "虚表地址->" << vTable << endl;
    for (int i = 0; vTable[i] != nullptr; ++i) { 
        printf("第%d个虚函数表地址:0x%x,->", i, vTable[i]);
        VFPTR f = vTable[i];
        f();
    }
    cout << endl;
}

int main()
{
    A_1952339 a;
    B_1952339 b;
    C_1952339 c;

    VFPTR* avTable = (VFPTR*)*(int*)&a;
    PrintVTable(avTable);

    VFPTR* bvTable = (VFPTR*)*(int*)&b;
    PrintVTable(bvTable);

    VFPTR* cvTable = (VFPTR*)*(int*)&c;
    PrintVTable(cvTable);
    return 0;
}


