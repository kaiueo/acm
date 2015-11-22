#include <iostream>
#include<stdio.h>
using namespace std;

int a = 1, b = 2, c = 3;
int fun(int n, int a, int b, int c);
int main()
{
	int n;
	while ((scanf("%d", &n)) != EOF)
	{
		fun(n,a,b,c);
		printf("\n");
	}
	return 0;
}

int fun(int n, int a, int b, int c)
{
	if (n == 1)
	{

		printf("%c to %c\n",a+64,c+64);
	}

	else
	{
		fun(n - 1,a,c,b);
		printf("%c to %c\n",a+64,c+64);
		fun(n-1,b,a,c);
	}
}
