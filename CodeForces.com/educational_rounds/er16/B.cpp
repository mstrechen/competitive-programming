#include<stdio.h>
#include<algorithm>

using namespace std;


int a[300500];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);
    printf("%d", a[(n-1)/2]);

    return 0;
}
