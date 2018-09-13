#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		putchar('+');
		return 0;
	}
	if(n==1)
	{
		printf("++\n");
		printf("+*");
		return 0;
	}
	n = 1 << n;
	
	for(int i = 0; i<n; i++)
	{
		putchar('+');
	}
	putchar('\n');
	for(int i = 0; i<n/2; i++)
	{
		putchar('+');
		putchar('*');
	}
	
	return 0;
}