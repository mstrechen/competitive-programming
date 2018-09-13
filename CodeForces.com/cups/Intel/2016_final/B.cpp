#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(m, vector<int>(n,0));
    for(int i = 0; i<n; i++)
    {
        int curr = 0;
        for(int j = 0; j<m; j++)
        {
            cin >> a[j][i];
        }
    }

    for(int _i = 0; _i<m; _i++)
        for(int _j = _i; _j<m; _j++)
        {
            swap(a[_i],a[_j]);
            bool res = 1;

            for(int i = 0; i<n; i++)
            {
                int curr = 0;
                for(int j = 0; j<m; j++)
                {
                    curr+=a[j][i]!=j+1;
                }
                if(curr>2)
                    res = 0;
            }
            if(res)
            {
                cout << "YES";
                return 0;
            }
            swap(a[_i],a[_j]);
        }


    cout << "NO";



    return 0;
}
