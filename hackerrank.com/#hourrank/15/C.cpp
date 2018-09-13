#include<iostream>
#include<vector>
#include<set>

using namespace std;

const long long MOD = 1000000000+9;

int getAns(int pairs, int unpaired, vector<vector<int>> & mA, vector<vector<int>> & mB, int allowed = 0)
{
    if(pairs==0&&unpaired==0)
        return 1;


    if(unpaired<0||pairs<0)
        return 0;
    if(allowed==0&&mA[pairs][unpaired]!=-1)
        return mA[pairs][unpaired];
    if(allowed==1&&mB[pairs][unpaired]!=-1)
        return mB[pairs][unpaired];

    long long res = 0;

    res+=((unpaired-allowed)*(long long)getAns(pairs, unpaired-1, mA,mB))%MOD;
    if(pairs)
        res+=(pairs*(long long)getAns(pairs-1, unpaired+1, mA, mB, 1))%MOD;
    res%=MOD;

    if(allowed==0)
        return mA[pairs][unpaired] = res;
    else
        return mB[pairs][unpaired] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int q;
    cin >> q;

    while(q--)
    {
        int n;
        cin >> n;

        set<int> usedOnce, usedTwice;
        int tmp;
        for(int i = 0; i<n; i++)
        {
            cin >> tmp;
            if(usedOnce.count(tmp))
            {
                usedOnce.erase(tmp);
                usedTwice.insert(tmp);
            }
            else
            {
                usedOnce.insert(tmp);
            }
        }

        vector<vector<int> > memorizedA(2005, vector<int>(2005,-1));
        vector<vector<int> > memorizedB(2005, vector<int>(2005,-1));

        cout << getAns(usedTwice.size(), usedOnce.size(), memorizedA, memorizedB) << '\n';
    }




    return 0;
}
