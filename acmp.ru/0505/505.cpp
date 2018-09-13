#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

void vectorOfIntToString(vector<int> & a, wstring & s)
{
    s.clear();
    for(int i = 0; i<a.size(); i++)
    {
        s.push_back(wchar_t(a[i]));
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l,n,m;

    cin >> l >> n >> m;

    map<wstring, int> templates;

    vector<int> tmp(l,0);
    wstring sTmp;
    int tmpN;
    for(int _i = 0; _i<n; _i++)
    {
        cin >> tmpN;
        for(int i = 0; i<l; i++)
            cin >> tmp[i];
        vectorOfIntToString(tmp,sTmp);
        templates[sTmp] = tmpN;
    }
    int ok = 0;
    int bad = 0;
    for(int _i = 0; _i<m; _i++)
    {
        for(int i = 0; i<l; i++)
            cin >> tmp[i];
        vectorOfIntToString(tmp,sTmp);
        if(templates.count(sTmp))
        {
            cout << templates[sTmp] << '\n';
            ok++;
        }
        else
        {
            cout << '-' <<'\n';
            bad++;
        }
    }
    cout << "OK=" << ok << " BAD=" << bad;

    return 0;
}
