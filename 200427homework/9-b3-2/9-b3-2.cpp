/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <cmath>
using namespace std;

class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ�����һ����Ա����������1����,Ҫ������ʵ�� */
	void set(int a, int b)
	{
		x = a, y = b;
	}
	/* �������������Ǹ���Ա�����⣬�������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ������������ */
	friend triangle;
};

class triangle {
private:
	point p1;
	point p2;
	point p3;
public:
	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		point a, b;
		a.set(p1.x - p2.x, p1.y - p2.y);
		b.set(p1.x - p3.x, p1.y - p3.y);
		if (a.x * b.y == a.y * b.x)
			return -1;
		return abs(0.5 * a.x * b.y - 0.5 * a.y * b.x);
	}
	/* ���캯�� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣��������������ݳ�Ա */

};

/* main������׼�� */
int main()
{
	if (1) {
		triangle tr(0, 0, 0, 1, 1, 0);  //������Ϊ(0,0) (0,1) (1,0)�������
		cout << "���������Ӧ���ǣ�0.5��ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 2, -1, -1, 1, -1);  //������Ϊ(0,2) (-1,-1) (1,-1)�������
		cout << "���������Ӧ���ǣ�3��  ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(5, 5, -3, 1, 9, -2);  //������Ϊ(5,5) (-3,1) (9,-2)�������
		cout << "���������Ӧ���ǣ�36�� ʵ���ǣ�" << tr.area() << endl;
	}

	if (1) {
		triangle tr(0, 0, 1, 1, 2, 2);  //���㹲��
		cout << "���������Ӧ���ǣ�-1�� ʵ���ǣ�" << tr.area() << endl;
	}

	return 0;
}