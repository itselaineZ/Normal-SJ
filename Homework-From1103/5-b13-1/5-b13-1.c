/* 1952339 ��08 ��ܰ�� */
#include <stdio.h>

int main()
{
	/* �ĸ�����������໥λ�ÿɻ���������Ŀǰ#if���������VS2019�������Ȼ�ΪLinux��*/
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
