#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

const long long oo = 8*1000000000LL*1000000000LL;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lengh,width,n,m;

    cin >> lengh >> width >> n >> m;

    vector<int> pointsA(n), pointsB(m);


    for(auto &i : pointsA)
        cin >> i;
    for(auto &i : pointsB)
        cin >> i;

    vector<pair<int,int> > ans;

    {
        auto itA = pointsA.begin();
        auto itB = pointsB.begin();
        bool usedA = 0;
        bool usedB = 0;


        do
        {
            if((*itA<*itB || itB == pointsB.end() - 1) && itA != pointsA.end() - 1 )
            {
                if((!usedA)|| abs(*itA - *itB) < abs(*(itA+1) - *itB))
                {
                    ans.push_back({itA - pointsA.begin(), itB - pointsB.begin()});
                    usedB = 1;
                }
                itA++;
                usedA = 0;
            }
            if((*itA>*itB || itA == pointsA.end() - 1) && itB != pointsB.end() - 1 )
            {
                if(!usedB|| abs(*itB - *itA) < abs(*(itB+1) - *itA))
                {
                    ans.push_back({itA - pointsA.begin(), itB - pointsB.begin()});
                    usedA = 1;
                }
                itB++;
                usedB = 0;
            }
            if((*itA==*itB) && itA!=pointsA.end()-1 && itB!=pointsB.end()-1)
            {
                if(!(usedA&&usedB))
                {
                    ans.push_back({itA - pointsA.begin(), itB - pointsB.begin()});
                    usedA = 1;
                    usedB = 1;
                }
                if(*(itA+1) > *(itB+1))
                {
                    itB++;
                    usedB = 0;
                }
                else
                if(*(itA+1) < *(itB+1))
                {
                    itA++;
                    usedA = 0;
                }
                else
                if(*(itA+1) == *(itB+1))
                {
                    itA++;
                    itB++;
                    usedA = 0;
                    usedB = 0;
                }

            }
        }
        while(itA!=pointsA.end()-1 || itB!=pointsB.end()-1);
        if(!(usedA && usedB))
            ans.push_back({itA - pointsA.begin(), itB - pointsB.begin()});

    }

    cout.precision(20);
    cout << (fixed);

    cout << ans.size() << '\n';

    for(auto i : ans)
        cout << i.first+1 << ' ' << i.second+1 << '\n';





    return 0;
}

