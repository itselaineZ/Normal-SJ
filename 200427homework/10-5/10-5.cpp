/* 1952339 信08 张馨月 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class matrix {
private:
    int value[2][3];
    //除此之外不允许再添加数据成员
public:
    matrix operator+(const matrix& b);

    /* ----根据需要添加除数据成员以外的定义，数量不限---- */
    friend istream& operator >> (istream& in, matrix& x);
    friend ostream& operator << (ostream& out, const matrix& x);
};

/* ----给出类成员函数的体外实现---- */
matrix matrix::operator + (const matrix& b)
{
    matrix c;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            c.value[i][j] = value[i][j] + b.value[i][j];
    return c;
}

istream& operator >> (istream& in, matrix& x)
{
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            in >> x.value[i][j];
    return in;
}

ostream& operator << (ostream& out, const matrix& x)
{
    for (int i = 0; i < 2; ++i) {
        cout << x.value[i][0];
        for (int j = 1; j < 3; ++j)
            cout << ' ' << x.value[i][j];
        cout << '\n';
    }
    return out;
}
/* ----main函数不准动---- */
int main()
{
    matrix m1, m2, m3;

    cout << "请输入矩阵m1的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m1;
    cout << "请输入矩阵m2的值(共2行3列，按先行后列的顺序输入)" << endl;
    cin >> m2;

    cout << "初始矩阵m1的值：" << endl;
    cout << m1 << endl;
    cout << "初始矩阵m2的值：" << endl;
    cout << m2 << endl;
    cout << "相加后矩阵m3的值：" << endl;
    cout << (m3 = m1 + m2) << endl;

    return 0;
}
