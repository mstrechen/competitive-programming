#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int n, b, d;

    int currSize = 0, tmp, ans = 0;

    cin >> n >> b >> d;

    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        if(tmp<=b)
        {
            currSize+=tmp;
            if(currSize>d)
            {
                currSize = 0;
                ans++;
            }
        }
    }
    cout << ans;


    return 0;
}
