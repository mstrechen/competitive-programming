#include <iostream>

using namespace std;

int A[40500];
int main(){
	ios::sync_with_stdio(false);
    
    int n, a,b,c;
    cin >> n >> a >> b >> c;
    A[0] = 1;
    for(int i = 0; i<n; i++)
    if(A[i])
    {
        int x = min(i+a,n+1);
        A[x] = max(A[x],A[i]+1);
        x = min(i+b,n+1);
        A[x] = max(A[x],A[i]+1);
        x = min(i+c,n+1);
        A[x] = max(A[x],A[i]+1);
    }
    cout << A[n]-1;
    
	return 0;
}