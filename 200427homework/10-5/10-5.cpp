/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class matrix {
private:
    int value[2][3];
    //����֮�ⲻ������������ݳ�Ա
public:
    matrix operator+(const matrix& b);

    /* ----������Ҫ��ӳ����ݳ�Ա����Ķ��壬��������---- */
    friend istream& operator >> (istream& in, matrix& x);
    friend ostream& operator << (ostream& out, const matrix& x);
};

/* ----�������Ա����������ʵ��---- */
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
/* ----main������׼��---- */
int main()
{
    matrix m1, m2, m3;

    cout << "���������m1��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m1;
    cout << "���������m2��ֵ(��2��3�У������к��е�˳������)" << endl;
    cin >> m2;

    cout << "��ʼ����m1��ֵ��" << endl;
    cout << m1 << endl;
    cout << "��ʼ����m2��ֵ��" << endl;
    cout << m2 << endl;
    cout << "��Ӻ����m3��ֵ��" << endl;
    cout << (m3 = m1 + m2) << endl;

    return 0;
}
