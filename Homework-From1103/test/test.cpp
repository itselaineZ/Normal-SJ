#define _CRT_SECURE_NO_WARNINGS  //VS2019��Ҫ
#include<stdio.h>
#include<string.h>
using namespace std;

const char chistr[] = "��Ҽ��������½��ƾ�";

char result[256];

int main()
{
	result[0] = chistr[0], result[1] = chistr[1];
	printf("%s\n", result);
	return 0;
}
