#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<fstream>

using namespace std;

struct suffix
{
    int leftRank, rightRank, id;
    suffix(int lRank = 0, int rRank = 0, int id = 0) : leftRank(lRank), rightRank(rRank), id(id){}
};

void SuffixSort(vector<suffix> & toSort, int sizeOfAlphabet)
{
    vector<suffix> tmp(toSort.size());
    vector<int> offsets(sizeOfAlphabet+1, 0);

    for(auto & i : toSort)
        offsets[i.rightRank+1]++;

    for(int i = 1; i<=sizeOfAlphabet; i++)
        offsets[i]+=offsets[i-1];

    for(auto & i : toSort)
    {
        tmp[offsets[i.rightRank]] = i;
        offsets[i.rightRank]++;
    }

    offsets.assign(sizeOfAlphabet+1, 0);

    for(auto & i : tmp)
        offsets[i.leftRank+1]++;

    for(int i = 1; i<=sizeOfAlphabet; i++)
        offsets[i]+=offsets[i-1];

    for(auto & i : tmp)
    {
        toSort[offsets[i.leftRank]] = i;
        offsets[i.leftRank]++;
    }
}

struct SuffixArray
{
    string _s;

    vector<vector<int> > steps;

    vector<int> SuffixArrayValues;

    vector<int> lcp;

    SuffixArray(string & source)
    {
        _s = source + char(1);

        vector<suffix> currentState(_s.size());

        vector<int> ranks(_s.size());

        for(int i = 0; i<(int)_s.size(); i++)
            ranks[i] = (int)_s[i];

        steps.push_back(ranks);


        int currentPow = 0,
            alphabet = 255;


        do
        {
            for(int i = 0; i<(int)_s.size(); i++)
            {
                currentState[i] = suffix(ranks[i], ranks[(i+(1<<currentPow))%_s.size()], i);
            }

            SuffixSort(currentState, alphabet);


            int currentRank = 0;

            for(int i = 0; i<(int)_s.size(); i++)
            {
                if(i!=0 && (currentState[i].leftRank != currentState[i-1].leftRank ||
                           currentState[i].rightRank != currentState[i-1].rightRank))
                    currentRank++;

                ranks[currentState[i].id] = currentRank;
            }

            steps.push_back(ranks);

            alphabet = currentRank+1;
            currentPow++;
        }
        while(alphabet!=_s.size());


        SuffixArrayValues.assign(_s.size(),0);

        for(int i = 0; i<(int)_s.size(); i++)
            SuffixArrayValues[i] = currentState[i].id;
    }

    bool isEqual(int fst, int scnd, int size)
    {
        assert(fst+size<(int)_s.size() && scnd+size<(int)_s.size());

        if(size==0)
            return 1;

        int newSize = min(31 - __builtin_clz(size), (int)steps.size()-1);

        return (steps[newSize][fst] == steps[newSize][scnd])&&
               (steps[newSize][fst + size - (1<<newSize)] == steps[newSize][scnd + size - (1<<newSize)]);
    }

    void BuildLcp()
    {
        lcp.assign((int)SuffixArrayValues.size() - 1, 0);

        for(int i = 0; i<(int)lcp.size(); i++)
        {
            int l = 0, r = min(SuffixArrayValues.size() - SuffixArrayValues[i],
                               SuffixArrayValues.size() - SuffixArrayValues[i+1]);

            while(l+1<r)
            {
                int mid = (l+r)/2;
                if(isEqual(SuffixArrayValues[i],SuffixArrayValues[i+1], mid))
                    l = mid;
                else
                    r = mid;
            }
            lcp[i] = l;
        }
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;
    getline(cin,s);

    SuffixArray mySA(s);

    mySA.BuildLcp();

    cout << s.size()*(s.size()+1)/2 - accumulate(mySA.lcp.begin(), mySA.lcp.end(),0);

    return 0;
}
