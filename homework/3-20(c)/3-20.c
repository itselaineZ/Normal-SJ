/*1952339 ĞÅ08 ÕÅÜ°ÔÂ*/
#include<stdio.h>

int main() 
{
	int num = 2, i; 
	while(num <= 1000) {
		int t = num;
		i = 1;
		while(i < num){ 
			if (num % i == 0) 
				t -= i;
			++ i;
		}
		if (t == 0) {
			printf("%d, its factors are 1", num);
			i = 2;
			while(i < num){
				if (num % i == 0)
					printf(",%d", i);
				++ i;
			}
			putchar(10);
		}
		++ num;
	}
	return 0;
}
