#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

long long dist(double dX, double dY)
{
    return dX*dX + dY*dY;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lengh,width,n,m;

    cin >> lengh >> width >> n >> m;

    vector<double> pointsA(n), pointsB(m);


    for(auto &i : pointsA)
        cin >> i;
    for(auto &i : pointsB)
        cin >> i;

    bool wasSwaped = 0;
    if(pointsA.size()>pointsB.size())
    {
        pointsA.swap(pointsB);
        wasSwaped = 1;
    }


    vector<char> used(pointsB.size(),0);

    double ans = 0;
    vector<pair<int,int> > ans_vec;
    {
        auto it = pointsB.begin();
        auto it_used = used.begin();
        int _i = 0;
        for(auto i : pointsA)
        {
            while(it+1!=pointsB.end() && dist(*it - i ,width) > dist(*(it+1) - i ,width))
            {
                it++;
                it_used++;
            }
            *it_used = 1;
            ans+=sqrt(dist(*it - i, width));
            ans_vec.push_back({it - pointsB.begin(), _i});

            _i++;
        }
    }

    {
        auto it_used = used.begin();
        auto it = pointsA.begin();
        int _i = 0;
        for(auto i : pointsB)
        {
            if(*it_used!=1)
            {
                while(it+1!=pointsA.end() && dist(*it-i, width) > dist(*(it+1)-i,width))
                {
                    it++;
                }
                ans+=sqrt(dist(*it - i, width));
                ans_vec.push_back({_i, it - pointsA.begin()});
            }
            it_used++;
            _i++;
        }
    }

    cout.precision(20);
    cout << (fixed);


    cout << ans_vec.size() << '\n';
    for(auto i : ans_vec)
    {
        if(wasSwaped)
            cout << i.first+1 << ' ' << i.second+1<< '\n';
        else
            cout << i.second+1 << ' ' << i.first+1 << '\n';
    }





    return 0;
}

