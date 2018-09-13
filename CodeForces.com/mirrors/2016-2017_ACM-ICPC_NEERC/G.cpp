#include<iostream>
#include<set>

using namespace std;

const int INF = 2*1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<pair<int,int> > A = {{0,1},{INF, INF}};

    int n;

    cin >> n;

    int s,d;
    for(int i = 0; i<n; i++)
    {
        cin >> s >> d;
        auto it = A.upper_bound({s,0});

        if(it->first>=s+d && (--it)->second<=s)
        {
            cout << s << ' ' << s+d-1 << '\n';
            A.insert({s,s+d});
        }
        else
        {
            bool flag = 1;
            auto it_copy = A.begin();
                it_copy++;
            for(it = A.begin(); flag&&it_copy!=A.end(); ++it)
            if(it_copy->first-it->second>=d)
            {
                A.insert({it->second, it->second+d});
                cout << it->second << ' ' << it->second+d-1 << '\n';
                flag = 0;
            }
            else
                it_copy++;
        }
    }






    return 0;
}

