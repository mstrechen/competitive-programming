#include<iostream>
#include<set>

using namespace std;

string a,b;
set<int> dyn[1005];

char upCase(char c)
{
    return 'A'+(c-'a');
}
bool isUp(char c)
{
    return ('A'<=c&&c<='Z');
}

bool isAtPos(int i, char c)
{
    if(i>b.size()||b[i-1]!=c)
        return 0;

    return 1;
}


int main()
{
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    dyn[0].insert(0);

    for(int _i = 0; _i<q; _i++)
    {
        cin >> a >> b;
        for(int i = 1; i<=a.size(); i++)
        {
            dyn[i].clear();
            if(!isUp(a[i-1]))
            {
                 dyn[i] = dyn[i-1];
                 a[i-1] = upCase(a[i-1]);
            }
            for(auto it = dyn[i-1].begin(); it!=dyn[i-1].end(); ++it)
            {
                if(isAtPos(*it+1, a[i-1]))
                    dyn[i].insert(*it+1);
            }

        }
        cout << (dyn[a.size()].count(b.size())?"YES":"NO");
        cout << '\n';
    }

    return 0;
}
