#include<string>
#include<iostream>

using namespace std;

int lps(string s)
{
   int n = s.size();
   int i, j, cl;
   int L[n][n];  // Create a table to store results of subproblems


   for (i = 0; i < n; i++)
      L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (s[i] == s[j] && cl == 2)
               L[i][j] = 2;
            else if (s[i] == s[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    s.~basic_string();
    return L[0][n-1];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tmp = "a";
    string s;
    int q;
    int k;
    cin >> q;
    for(;q;q--)
    {
        int n, k;
        cin >> n >> k;
        cin >> s;
        int count = 0;
        int tt = lps(s);
        for(int i = 0; i<=n; i++)
        {
            for(int j = 0; j<26; j++)
            {
                tmp[0] = 'a'+j;
                count+=k<=lps(string(s.begin(), s.begin()+i)+tmp+string(s.begin()+i, s.end()))-tt;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
