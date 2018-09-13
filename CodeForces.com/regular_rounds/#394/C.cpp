#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct MinWork
{
    int letter, digit, sym;

    MinWork(const string & s = "") : letter(100500), digit(100500), sym(100500)
    {

        for(int i = 0; i<(int)s.size(); i++)
            if('a' <= s[i] && s[i] <= 'z')
                letter = min(letter, min(i, (int)s.size() - i));
        else
            if('0' <= s[i] && s[i] <= '9')
                digit = min(digit, min(i, (int)s.size() - i));
        else
            sym = min(sym, min(i, (int)s.size() - i));
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tmp;
    int n;
    cin >> n >> tmp;

    vector<MinWork> a(n);

    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[i] = MinWork(tmp);
    }

    int ans = 100500;

    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            for(int k = 0; k<n; k++)
            if(i!=j && j!=k && k!=i)
                ans = min(ans, a[i].digit + a[j].letter + a[k].sym);

    cout << ans;



    return 0;
}
