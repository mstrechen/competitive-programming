#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int main(){
    ios::sync_with_stdio(false);

    int n, answer=0,tmp, currentLength;

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    for(;n>0;)
    {
        currentLength = 0;
        for(int i = 1; i<1001; i++)
        {
            if(a[i]!=0)
            {
                a[i]--;
                currentLength++;
            }
        }
        answer+=currentLength-1;
        n-=currentLength;
    }
    cout << answer;
    return 0;
}
