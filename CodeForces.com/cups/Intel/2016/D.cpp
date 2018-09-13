#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;



map<int, vector<int> > A;

map<int, int> countOfCovers;

set<int, greater<int >> unused;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    int tmp,tmp1;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        unused.insert(tmp);
        tmp1 = tmp;
        countOfCovers[tmp] = 0;
        while(tmp1)
        {
            A[tmp1].push_back(tmp);
            tmp1/=2;
        }
    }
    int taken = A.size();

    map<int, vector<int> >:: iterator it;
    map<int, vector<int> >:: reverse_iterator it1;

    set<int> result;

    vector<int> tmpV;

    bool flag = 1;

    while(flag)
    {
        flag = 0;

        for(auto i = unused.begin(); flag==0&&i!=unused.end();)
        {
            int i1 = *i, i2;
            i2 = i1;
            while(unused.count(i1)&&i1>1)
                i1/=2;
            i++;
            if(unused.count(i1)==0)
            {
                flag = 1;
                unused.erase(i2);
                unused.insert(i1);
            }
        }

    }
    for(auto i : unused)
        cout << i << ' ';

    return 0;
}
