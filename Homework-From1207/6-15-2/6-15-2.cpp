/* 学号 姓名 班级 */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- 不允许定义任何形式的全局变量 --- */

/***************************************************************************
  函数名称：
  功    能：求第一门课的平均分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void average(int(*score)[STUDENT_NUM])
{
	int sum = 0;
	for (int*p = *score; p-*score < STUDENT_NUM; ++p)
		sum += *p;
	cout << "第1门课平均分：" << double(sum) / STUDENT_NUM << endl;
}

/***************************************************************************
  函数名称：
  功    能：找出有两门以上课程不及格的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fail(int(*score)[STUDENT_NUM])
{
	cout << "2门以上不及格的学生：\n";
	for (int j = 0; j < STUDENT_NUM; ++j) {
		int tot = 0;
		for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; ++p)
			tot += (*(*p+j) < 60);
		if (tot >= 2) {
			cout << "No：" << j+1;
			int sum = 0;
			for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; sum += *(*p+j), ++p)
				cout << ' ' << *(*p + j);
			cout << " 平均：" << double(sum) / SCORE_NUM << endl;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：找出平均成绩在90分以上或全部成绩在85分以上的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void good(int(*score)[STUDENT_NUM])
{
	cout << "平均90以上或全部85以上的学生：\n";
	for (int j = 0; j < STUDENT_NUM; ++j) {
		int tot = 0, sum = 0;
		for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; sum += *(*p + j), ++p)
			tot += (*(*p + j) >= 85);
		if (tot == SCORE_NUM || sum >= 90 * SCORE_NUM) {
			cout << "No：" << j + 1;
			for (int(*p)[STUDENT_NUM] = score; p < score + SCORE_NUM; ++p)
				cout << ' ' << *(*p + j);
			cout << " 平均：" << double(sum) / SCORE_NUM << endl;
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int a[SCORE_NUM][STUDENT_NUM] = {
		{91,92,93,97},  //第1-4个学生的第1门课成绩
		{81,82,83,85},  //第1-4个学生的第2门课成绩
		{71,72,99,87},  //第1-4个学生的第3门课成绩
		{61,32,80,91},  //第1-4个学生的第4门课成绩
		{51,52,95,88} };//第1-4个学生的第5门课成绩
	cout << "初始信息：\n";
	for (int(*p)[STUDENT_NUM] = a; p < a + SCORE_NUM; ++p) {
		cout << "No.1-4学生的第" << p-a+1 << "门课的成绩：";
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
