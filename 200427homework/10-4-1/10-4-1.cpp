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
	matrix(const int(*p)[3]);	//构造函数，用数组初始化矩阵
	void display() const;		//输出该矩阵
	matrix operator+(const matrix& b);

	/* ----根据需要添加其它成员函数的定义，数量不限---- */
	matrix();
};

/* ----给出成员函数的体外实现---- */
matrix::matrix(const int (*p)[3])
{
	memcpy(value, p, 6*sizeof(int));
}

matrix::matrix()
{
	memset(value, 0, sizeof value );
}

void matrix::display()const
{
	for (int i = 0; i < 2; ++i) {
		cout << value[i][0];
		for (int j = 1; j < 3; ++j)
			cout << ' ' << value[i][j];
		putchar(10);
	}
}

matrix matrix::operator + (const matrix& b)
{
	matrix c;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 3; ++j)
			c.value[i][j] = value[i][j] + b.value[i][j];
	return c;
}
/* ----main函数不准动---- */
int main()
{
	int a[2][3] = { { 1,2,3 },{ 4,5,6 } };
	int b[2][3] = { { 2,4,6 },{ 3,6,9 } };
	matrix m1(a), m2(b), m3;

	cout << "初始矩阵m1的值：" << endl;
	m1.display();
	cout << "初始矩阵m2的值：" << endl;
	m2.display();
	m3 = m1 + m2;
	cout << "相加后矩阵m3的值：" << endl;
	m3.display();

	return 0;
}
