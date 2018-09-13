#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> perm(n);
    vector<char> used(n);
    for(int i = 0; i<n; i++)
    {
        perm[i] = i;
    }

    do
    {
        used.assign(n, 0);
        for(int i = 0; i<n; i++)
        if(!used[i])
        {
            cout << '(';
            int j = i;
            do
            {
                if(i != j)
                    cout << ',' << ' ';
                cout << j + 1;
                used[j] = 1;
                j = perm[j];
            }
            while(j != i);
            cout << ')';
        }
        cout << '\n';
    }
    while(next_permutation(perm.begin(), perm.end()));

    return 0;
}
