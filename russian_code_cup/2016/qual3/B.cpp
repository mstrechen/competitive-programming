#include<iostream>
#include<string>

using namespace std;

string a, b;
int main()
{
    ios::sync_with_stdio(false);
    int n, tmp,answer;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        cin >> a >> b;
        tmp--;
        answer = 0;
        for(int j = 0; j<tmp; j++)
            if(b[j]!=a[j])
            {
                answer++;
                a[j] = a[j]=='0'?'1':'0';
                a[j+1] = a[j+1]=='0'?'1':'0';
            }
        if(b!=a)
            cout << -1 << '\n';
        else
            cout << answer << '\n';

    }
    return 0;
}
