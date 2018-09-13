#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Event
{
    int pos{0}, be{0};
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int q;
    cin >> q;

    while(q--)
    {
        int n, k, m;
        cin >> n >> k >> m;

        vector<pair<int, int > > x(m*2), y(m*2);

        for(int i = 0; i<m; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 > x2)
                swap(x1, x2);
            if(y1 > y2)
                swap(y1, y2);
            x[i*2].pos = x1;
            x[i*2].be = 1;
            y[i*2].pos = y1;
            y[i*2].be = 1;
            x[i*2+1].pos = x2;
            x[i*2+1].be = -1;
            y[i*2+1].pos = y2;
            y[i*2+1].be = -1;
        }

    }

    return 0;
}
