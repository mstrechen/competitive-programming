#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long MOD = 1000*1000*1000 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(26);

    int n;
    cin >> n;

    string s;

    cin >> s;

    s = "_" + s;

    vector<int> dpCount(n+1, 0),
                dpMaxLen(n+1, 0),
                dpMinCnt(n+1,0);

    dpCount[0] = 1;

    for(auto & i : a)
        cin >> i;

    for(int _i = 1; _i<=n; _i++)
    {
        vector<int> tmp = a;

        tmp[s[_i] - 'a']--;
        int i = _i-1;
        do
        {
            dpCount[_i] += dpCount[i];
            if(dpCount[_i]>MOD)
                dpCount[_i]-=MOD;

            dpMaxLen[_i] = max(dpMaxLen[_i], max(_i - i, dpMaxLen[i]));

            dpMinCnt[_i] = min(dpMinCnt[_i], dpMinCnt[i]);

            if(s[i]!='_')
                tmp[s[i] - 'a']--;
            i--;
        }
        while(i>=0 && accumulate(tmp.begin(), tmp.end(), 0, [](int a, int b){return min(a,b);}) >=0 );

        dpMinCnt[_i]++;

        cout << dpCount[_i] << endl;
    }

    cout << dpCount[n] << endl;
    cout << dpMaxLen[n] << endl;
    cout << dpMinCnt[n] << endl;

    return 0;
}
