#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;
    vector<vector<int> > e(n);

    for(int i = 0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        e[x-1].push_back(y-1);
        e[y-1].push_back(x-1);
    }

    int maxAns = 0;

    for(int i = 0; i<n; i++)
    {
        if(e[i].size() == 1)
        {
            int curans = 0;
            int prev = -1;
            int j = i;

            do
            {
                if(e[j][0]!=prev)
                {
                    prev = j;
                    j = e[j][0];
                }
                else
                {
                    prev = j;
                    j = e[j][1];
                }
                curans++;
                if(e[j].size() == 1)
                    curans++;
            }
            while(e[j].size() == 2);
            maxAns = max(maxAns, curans);
        }

    }

    cout << maxAns;
    return 0;
}
