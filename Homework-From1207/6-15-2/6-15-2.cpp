/* ѧ�� ���� �༶ */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- ���������κ���ʽ��ȫ�ֱ��� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ����һ�ſε�ƽ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void average(int(*score)[STUDENT_NUM])
{
	int sum = 0;
	for (int*p = *score; p-*score < STUDENT_NUM; ++p)
		sum += *p;
	cout << "��1�ſ�ƽ���֣�" << double(sum) / STUDENT_NUM << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ����������Ͽγ̲������ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fail(int(*score)[STUDENT_NUM])
{
	cout << "2�����ϲ������ѧ����\n";
	for (int j = 0; j < STUDENT_NUM; ++j) {
		int tot = 0;
		for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; ++p)
			tot += (*(*p+j) < 60);
		if (tot >= 2) {
			cout << "No��" << j+1;
			int sum = 0;
			for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; sum += *(*p+j), ++p)
				cout << ' ' << *(*p + j);
			cout << " ƽ����" << double(sum) / SCORE_NUM << endl;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ҳ�ƽ���ɼ���90�����ϻ�ȫ���ɼ���85�����ϵ�ѧ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void good(int(*score)[STUDENT_NUM])
{
	cout << "ƽ��90���ϻ�ȫ��85���ϵ�ѧ����\n";
	for (int j = 0; j < STUDENT_NUM; ++j) {
		int tot = 0, sum = 0;
		for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; sum += *(*p + j), ++p)
			tot += (*(*p + j) >= 85);
		if (tot == SCORE_NUM || sum >= 90 * SCORE_NUM) {
			cout << "No��" << j + 1;
			for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; ++p)
				cout << ' ' << *(*p + j);
			cout << " ƽ����" << double(sum) / SCORE_NUM << endl;
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int a[SCORE_NUM][STUDENT_NUM] = {
		{91,92,93,97},  //��1-4��ѧ���ĵ�1�ſγɼ�
		{81,82,83,85},  //��1-4��ѧ���ĵ�2�ſγɼ�
		{71,72,99,87},  //��1-4��ѧ���ĵ�3�ſγɼ�
		{61,32,80,91},  //��1-4��ѧ���ĵ�4�ſγɼ�
		{51,52,95,88} };//��1-4��ѧ���ĵ�5�ſγɼ�
	cout << "��ʼ��Ϣ��\n";
	for (int(*p)[STUDENT_NUM] = a; p < a + SCORE_NUM; ++p) {
		cout << "No.1-4ѧ���ĵ�" << p-a+1 << "�ſεĳɼ���";
		for (int j = 0; j < STUDENT_NUM; ++j)
			cout << " " << *(*p+j);
		cout << '\n';
	}
	cout << '\n';
	average(a);
	cout << '\n';
	fail(a);
	cout << '\n';
	good(a);
	return 0;
}
