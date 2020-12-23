/* 1952339 ��08 ��ܰ��*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

/* -------------------------- */
/* ---- ��׼����κ����� ---- */
/* -------------------------- */
long long cnt;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int fibonacci(int n)
{
	++cnt;
	if (n == 1 || n == 2)
		return 1;
	return fibonacci(n-1)+fibonacci(n-2); //����ɰ����޸�
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	int n, f;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n);
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;

	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
	for (int i = 1; i <= 46; ++i) {
		cnt = 0;
		fibonacci(i);
		cout << i << "            " << cnt << "*****\n";
	}
	return 0;
}
