#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    map<string,vector<int>> pieces;

    string lovely_string,tmp;

    cin >> n >> m;
    cin >> lovely_string;

    for(int i = 0; i<m; i++)
    {
        cin >> tmp;
        pieces[tmp].push_back(i+1);
    }

    n/=m;

    for(int i = 0; i<m; i++)
    {
        auto it = pieces.lower_bound(string(lovely_string.begin()+i*n, lovely_string.begin()+(i+1)*n));
        cout <<  *(it->second).rbegin() << ' ';
        it->second.pop_back();
    }



    return 0;
}
