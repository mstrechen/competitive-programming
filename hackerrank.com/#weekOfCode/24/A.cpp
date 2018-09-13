#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s,t,a,b,m,n;

    int countOfM = 0, countOfN = 0;

    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;

    for(int i = 0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        countOfM+=s<=(a+tmp)&&(a+tmp)<=t;
    }
    for(int i = 0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        countOfN+=s<=(b+tmp)&&(b+tmp)<=t;
    }
    cout << countOfM << '\n' << countOfN;

    return 0;
}
