#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

const double eps = 1e-6;

double getTimeWithCurrentSetup(vector<pair<double,int> > & bd, vector<pair<double,int> > & fm)
{
    double res = 0;
    for(int i = 0; i<bd.size(); i++)
    if(fm[i].first!=0)
    {
        res = max(res, bd[i].first/fm[i].first);
    }
    else
    if(bd[i].first>eps)
    {
        res = 1e9;
    }
    return res;
}

double getTime(vector<pair<double,int> > bd, vector<pair<double,int> > & fm, double t)
{
    double res = 0;
    double currS = 0;
    double currV = 0;

    for(int i = 0; i<bd.size(); i++)
    {
        bd[i].first-=fm[i].first*t;
    }
    sort(bd.begin(),bd.end(), greater<pair<double, int> >());

    for(int i = 0; i<bd.size(); i++)
    {
        currS+=bd[i].first;
        currV+=fm[i].first;
        res = max(res,currS/currV);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n,k;

    cin >> n;

    vector<pair<double,int> > buildings(n,{0,0} );
    for(int i = 0; i<n; i++)
    {
        cin >> buildings[i].first;
        buildings[i].second = i+1;
    }
    cin >> k;

    vector<pair<double,int> > firms(k, {0,0});
    for(int i = 0; i<k; i++)
    {
        cin >> firms[i].first;
        firms[i].second = i+1;
    }

    sort(buildings.begin(), buildings.end(), greater<pair<int,int > >());
    sort(firms.begin(), firms.end(), greater<pair<int,int > >());
    firms.resize(buildings.size(), {0,0} );

    double minTime = getTime(buildings, firms, 0);


    cout << getTime(buildings, firms,0) << '\n';

    double prevTime = 0;
    while(prevTime+getTimeWithCurrentSetup(buildings, firms)>minTime+0.01)
    {
        for(int i = 0; i<n; i++)
        if(firms[i].second!=0)
        {
            cout << prevTime << ' ' << buildings[i].second << ' ' << firms[i].second << '\n';
        }
        double l = 0;
        double r = 1e9;
        for(int i = 0; i<n; i++)
        if(firms[i].second!=0)
        {
            r = min(r, buildings[i].first/firms[i].first);
        }
        while(l+0.01<r)
        {
            double mid = (l+r)/2;
            if(getTime(buildings,firms, mid)+prevTime+mid>minTime)
                r = mid;
            else
                l = mid;
        }
        l = (l+r)/2;
        for(int i = 0; i<n; i++)
        {
            buildings[i].first-=l*firms[i].first;
        }
        prevTime+=l;
        sort(buildings.begin(), buildings.end(), greater<pair<int,int > >());
    }
    for(int i = 0; i<n; i++)
    if(firms[i].second!=0)
    {
        cout << prevTime << ' ' << buildings[i].second << ' ' << firms[i].second << '\n';
    }




    return 0;
}
