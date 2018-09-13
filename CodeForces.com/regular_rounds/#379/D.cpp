#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, char> >hor,ver, diag1, diag2;
vector<pair<int,char> > tmp;

bool isFighting()
{
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    sort(diag1.begin(), diag1.end());
    sort(diag2.begin(), diag2.end());


    int i = 0;
    while(hor[i].second!='K') i++;
    if(hor[i-1].second=='Q'||hor[i-1].second=='R'||hor[i+1].second=='Q'||hor[i+1].second=='R')
        return 1;

    i = 0;
    while(ver[i].second!='K') i++;
    if(ver[i-1].second=='Q'||ver[i-1].second=='R'||ver[i+1].second=='Q'||ver[i+1].second=='R')
        return 1;
    i = 0;
    while(diag1[i].second!='K') i++;
    if(diag1[i-1].second=='Q'||diag1[i-1].second=='B'||diag1[i+1].second=='Q'||diag1[i+1].second=='B')
        return 1;
    i = 0;
    while(diag2[i].second!='K') i++;
    if(diag2[i-1].second=='Q'||diag2[i-1].second=='B'||diag2[i+1].second=='Q'||diag2[i+1].second=='B')
        return 1;



    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    char c = 'K';
    int x,y;
    int x0, y0;

    cin >> x0 >> y0;
    hor.push_back({y0,c});
    ver.push_back({x0,c});
    diag1.push_back({x0,c});
    diag2.push_back({x0,c});
    c = 'o';
    hor.push_back({-2000000002,c});
    ver.push_back({-2000000002,c});
    diag1.push_back({-2000000002,c});
    diag2.push_back({-2000000002,c});
    hor.push_back({2000000002,c});
    ver.push_back({2000000002,c});
    diag1.push_back({2000000002,c});
    diag2.push_back({2000000002,c});

    for(int i = 0; i<n; i++)
    {
        cin >> c >> x >> y;
        if(x0==x)
        hor.push_back({y,c});
        if(y0==y)
        ver.push_back({x,c});
        if(x0-y0==x-y)
        diag1.push_back({x,c});
        if(x0+y0==x+y)
        diag2.push_back({x,c});
    }

    cout << (isFighting()? "YES" : "NO");

    return 0;
}
