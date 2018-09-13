#include<iostream>
#include<set>
#include<vector>


using namespace std;

struct abc
{
    int a, b, c;
    abc(int a, int b, int c): a(a),b(b), c(c){};

};

int tmpA[1000], tmpB[1000];

vector<abc> getN(int n, int m)
{
    vector<abc> res;
    for(int i = 0; i<m; i++)
    {
        tmpA[i] = i;
        if(i>=m/2)
            tmpB[i] = i-m/2;
        else
            tmpB[i] = i+m/2+1;
    }
    for(int i = 0; i<m; i++)
    {
        if(n-tmpA[i]-tmpB[i]>=0)
            res.push_back(abc(tmpA[i],tmpB[i], n-tmpA[i]-tmpB[i]));
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    vector<abc> ans,tmp;
    cin >> n;
    m = (n*2-1)/3 + 1;
    if(m%2==0)
        m++;;
    ans = getN(n,m);
    cout << ans.size() << '\n';
    for(int i = 0; i<ans.size(); i++)
        cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << '\n';

    return 0;
}
