#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int n;
    cin >> n;

    if(n==1)
    {
        cout << "1\n1";
        return 0;
    }
    if(n==2)
    {
        cout << "1\n1 1";
        return 0;
    }

    vector<int> p(n+2,0);
    int pCnt = 0;
    for(int i = 0; i*i<n; i++)
        if(p[i+2]==0)
        {
            for(int j = 2; j*(i+2)<n+2; j++)
                p[j*(i+2)] = 1;
        }

    cout << 2 << '\n';
    for(int i = 0; i<n; i++)
        if(p[i+2]==0) cout << "1 ";
        else cout << "2 ";
    return 0;
}
