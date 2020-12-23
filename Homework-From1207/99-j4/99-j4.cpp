/* 1952339 ��08 ��ܰ�� */
#include <iostream>
using namespace std;

template<class T, int N>
void test(T (&array)[N])	//��...�滻Ϊ��Ӧ����
{
	cout << sizeof(array) << endl;	//arrayΪ�β���
}

template<class ch, int M>
char* tj_strcpy_s(ch (&dst)[M], const char *src)	//��...�滻Ϊ��Ӧ����
{
	char* d = dst;		//dstΪҪ���Ƶ�Ŀ�괮
	const char* s = src;	//srcΪҪ���Ƶ�Դ��

	while (*s != '\0' && d - dst < sizeof(dst) - 1)
		*d++ = *s++;
	*d = '\0';

	return dst;
}

int main()
{
	int t1[10];
	double t2[20];
	test(t1);	//��������40
	test(t2);	//�������160

	char s1[10], s2[20];
	const char* s = "Welcome to Tongji University!";
	cout << tj_strcpy_s(s1, s) << '*' << endl; //���������Welcome t*
	cout << tj_strcpy_s(s2, s) << '*' << endl; //���������Welcome to Tongji U*

	return 0;
}
