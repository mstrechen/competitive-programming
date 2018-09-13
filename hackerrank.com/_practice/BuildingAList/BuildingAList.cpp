#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

vector<string> A;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    int q;
    int n;
    cin >> q;
    for(;q; q--)
    {
        A.clear();
        cin >> n;
        cin >> s;
        int tmp = (1<<n);
        string tmpString;
        for(int mask = 0; mask<=tmp; mask++)
        {
            tmpString.clear();
            for(int i = 0; i<n; i++)
            {
                if((mask>>i)&1)
                    tmpString+=s[i];
            }
            if(!tmpString.empty())
                A.push_back(tmpString);
        }
        sort(A.begin(), A.end());
        for(int i = 0; i<A.size(); i++)
            cout << A[i] << '\n';
    }
    return 0;
}
