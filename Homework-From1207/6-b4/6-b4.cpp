/*/*1952339 ��08 ��ܰ��*/
#include<iostream>
#include<cstdio>
using namespace std;

bool Check_palindrome(char *p, int len)
{
	--len;
	int up = len / 2;
	for (int i = 1; i <= up; ++i)
		if (*(p + i) != *(p + len - i + 1))
			return 0;
	return 1;
}

int main()
{
	cout << "������һ������С��80���ַ��������Ĵ���\n";
	char S[85];
	int len = 0;
	while ((S[++len] = getchar()) && S[len] != '\n')
		;
	if (Check_palindrome(S, len))
		puts("yes");
	else
		puts("no");
	return 0;
}