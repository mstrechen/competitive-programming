#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    vector<pair<string, int> > pieces;
    
    string lovely_string,tmp;

    cin >> n >> m;
    cin >> lovely_string;

    for(int i = 0; i<m; i++)
    {
        cin >> tmp;
        pieces.push_back({tmp, i+1});
    }

    sort(pieces.begin(), pieces.end());
    n/=m;

    for(int i = 0; i<m; i++)
    {
        auto it = lower_bound(pieces.begin(), pieces.end(),
                            make_pair(string(lovely_string.begin()+i*n,
                                             lovely_string.begin()+(i+1)*n), 0));
        cout << it->second << ' ';
        it->second = -1;
    }



    return 0;
}
