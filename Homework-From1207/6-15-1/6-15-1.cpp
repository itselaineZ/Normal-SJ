/* 1952339 信08 张馨月 */
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
void average(int(*score)[SCORE_NUM])
{
	int sum = 0;
	for (int(*p)[SCORE_NUM] = score; p < score + STUDENT_NUM; ++p)
		sum += **p;
	cout << "第1门课平均分：" << double(sum) / STUDENT_NUM << endl;
}

/***************************************************************************
  函数名称：
  功    能：找出有两门以上课程不及格的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fail(int(*score)[SCORE_NUM])
{
	cout << "2门以上不及格的学生：\n";
	for (int(*p)[SCORE_NUM] = score; p < score + STUDENT_NUM; ++p) {
		int tot = 0;
		for (int j = 0; j < SCORE_NUM; ++j)
			tot += (*(*p+j) < 60);
		if (tot >= 2) {
			int sum = 0;
			cout << "No：" << p - score + 1 << ' ';
			for (int j = 0; j < SCORE_NUM; sum += *(*p+j), ++j)
				cout << *(*p + j) << ' ';
			cout << "平均：" << double(sum) / SCORE_NUM << '\n';
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
void good(int(*score)[SCORE_NUM])
{
	cout << "平均90以上或全部85以上的学生：\n";
	for (int(*p)[SCORE_NUM] = score; p < score + STUDENT_NUM; ++p) {
		int tot = 0, sum = 0;
		for (int j = 0; j < SCORE_NUM; sum += *(*p+j), ++j)
			tot += (*(*p + j) >= 85);
		if (tot == SCORE_NUM || sum >= 90 * SCORE_NUM) {
			cout << "No：" << p - score + 1 << ' ';
			for (int j = 0; j < SCORE_NUM; ++j)
				cout << *(*p + j) << ' ';
			cout << "平均：" << double(sum) / SCORE_NUM << '\n';
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
	int a[STUDENT_NUM][SCORE_NUM] = {
		{91, 81, 71, 61, 51},	//第1个学生的1-5门课的成绩
		{92, 82, 72, 32, 52},   //第2个学生的1-5门课的成绩
		{93, 83, 99, 80, 95},   //第3个学生的1-5门课的成绩
		{97, 85, 87, 91, 88} }; //第4个学生的1-5门课的成绩
	cout << "初始信息：\n";
	for (int (*p)[SCORE_NUM] = a; p < a+STUDENT_NUM; ++ p) {
		cout << "No." << p-a+1 << "的1 - 5门课成绩：" << **p;
		for (int j = 1; j < SCORE_NUM; ++j)
			cout << ' ' << *(*p + j);
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
