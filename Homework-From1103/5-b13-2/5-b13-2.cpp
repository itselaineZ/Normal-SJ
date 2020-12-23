/* 1952339 信08 张馨月 */
#include <iostream>
#include <cstdio>
/* --如果某编译器有需要，此处允许按条件编译的格式加入头文件 --*/

using namespace std;


int main()
{
	char a[80];

#if (__GNUC__ && (__GNUC_PATCHLEVEL__ == 2 || __GNUC_PATCHLEVEL__ == 0))  //DevCPP或CodeBlocks
	gets(a);
#elif _MSC_VER       //VS2019
	gets_s(a);
#elif (__gnu_linux__)       //Linux
	fgets(a, 80, stdin); //不需要处理最后的回车
#endif

	cout << a << endl;
	return 0;
}
