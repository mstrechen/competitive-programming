#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

void rec(vector<vector<char> > & ans, int depth, int l, int r, int n)
{
    if(l>=r)
    {
        return;
    }
    if(depth>=ans.size())
        ans.push_back(ans[depth-1]);

    int mid = (l+r)/2;

    for(int i = l; i<=mid; i++)
        ans[depth][i]^=1;

    rec(ans, depth+1, l, mid, n);
    rec(ans, depth+1, mid+1, r, n);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char> > allPositions(1, vector<char>(n,0));

    rec(allPositions, 1, 0, n-1, n);

    cout << allPositions.size() -1 << '\n';

    set<pair<int,int> > a;
    for(int i = 1; i<(int)allPositions.size(); i++)
    {
        cout << accumulate(allPositions[i].begin(), allPositions[i].end(), 0) << ' ';
        for(int j = 0; j<allPositions[i].size(); j++)
        {
            if(allPositions[i][j])
                cout << j+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
