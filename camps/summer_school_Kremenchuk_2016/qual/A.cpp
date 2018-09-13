#include<iostream>
#include<fstream>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ifstream cin("kings.in");
    ofstream cout("kings.out");
    int n,m,k, a,b,c;
    cin >> n >> m >> k >> a >> b >> c;
    pair<int, string> allArmies[3] = {make_pair(n*a, "Joffrey"), make_pair(m*b, "Robb"), make_pair(k*c, "Stannis")};
    sort(allArmies, allArmies+3, greater<pair<int,string> >());

    if(allArmies[0].first==allArmies[2].first)
        cout << allArmies[2].second << ' ';
    if(allArmies[0].first==allArmies[1].first)
        cout << allArmies[1].second << ' ';
    cout << allArmies[0].second;



    return 0;
}
