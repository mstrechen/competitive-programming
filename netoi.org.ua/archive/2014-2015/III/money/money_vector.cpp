#include <iostream>

using namespace std;

int A[40500];

int min1(int a, int b)
{
    return a>b?b:a;
}
int max1(int a, int b)
{
    return a<b?b:a;
}

int main(){
	ios::sync_with_stdio(false);
    
    int n, a,b,c;
    cin >> n >> a >> b >> c;
    A[0] = 1;
    for(int i = 0; i<n; i++)
    if(A[i])
    {
        int x = min1(i+a,n+1);
        A[x] = max1(A[x],A[i]+1);
        x = min1(i+b,n+1);
        A[x] = max1(A[x],A[i]+1);
        x = min1(i+c,n+1);
        A[x] = max1(A[x],A[i]+1);
    }
    cout << A[n]-1;
    
	return 0;
}