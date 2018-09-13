#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for(int I = 0; I<n; I++)
    {
        string s;
        int k;
        cin >> s >> k;

        for(auto & i : s)
            i = (i == '+');
        vector<char> c(s.size()+1, 0);
        char cur = 0;

        int cnt = 0;
        bool flag = 1;
        for(int i = 0; i < (int)s.size() && flag; i++)
        {
            cur = char(cur ^ c[i]);
            if(i+k <= (int)s.size())
            {
                if((s[i]^cur) == 0)
                {
                    cur ^= 1;
                    c[i+k] ^= 1;
                    cnt++;
                }
            }
            else
            {
                if((s[i]^cur) == 0)
                {
                    cout << "Case #" << I+1 << ": IMPOSSIBLE\n";
                    flag = 0;
                }
            }
        }
        if(flag)
            cout << "Case #" << I+1 << ": " << cnt << '\n';
    }

    return 0;
}
