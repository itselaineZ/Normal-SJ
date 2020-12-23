/* 1952339 信08 张馨月 */
#include <stdio.h>

int main()
{
	/* 四个条件编译的相互位置可互换（例：目前#if满足是输出VS2019，允许先换为Linux）*/
#if _MSC_VER
	printf("VS2019\n");
#elif __gnu_linux__
	printf("Linux\n");
#elif __GNUC__ == 5 
	printf("CodeBlocks\n");
#elif __GNUC__ == 4 
	printf("DevCPP\n");
#endif

	return 0;
}
