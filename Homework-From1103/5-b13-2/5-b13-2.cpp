/* 1952339 ��08 ��ܰ�� */
#include <iostream>
#include <cstdio>
/* --���ĳ����������Ҫ���˴�������������ĸ�ʽ����ͷ�ļ� --*/

using namespace std;


int main()
{
	char a[80];

#if (__GNUC__ && (__GNUC_PATCHLEVEL__ == 2 || __GNUC_PATCHLEVEL__ == 0))  //DevCPP��CodeBlocks
	gets(a);
#elif _MSC_VER       //VS2019
	gets_s(a);
#elif (__gnu_linux__)       //Linux
	fgets(a, 80, stdin); //����Ҫ�������Ļس�
#endif

	cout << a << endl;
	return 0;
}
