#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

bool rec(int toLock, int places, vector<int> & res)
{
    if(toLock<places || places < 1)
        return false;
    if(places==1)
    {
        res.push_back(toLock);
        return true;
    }
    bool resB = rec(toLock/2, places/2, res);
         resB&= rec(toLock - toLock/2, places - places/2, res);

    return  resB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> res;

    if(!rec(n, k, res))
    {
        cout << -1;
        return 0;
    }

    int myXor = 0;

    for(auto i : res)
    {
        myXor^=i;
    }

    if(myXor!=0)
    {
        cout << -1;
        return 0;
    }

    assert(res.size() == k);

    for(auto & i : res)
        cout << i << ' ';



    return 0;
}


