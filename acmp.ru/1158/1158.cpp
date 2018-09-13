#include<iostream>
#include<vector>
#include<cassert>

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

    int suffixIdToFind;
    string ans;

    SuffixArray(string & source, int iToFind)
    {
        _s = source;

        vector<suffix> currentState(_s.size());

        vector<int> ranks(_s.size());

        for(int i = 0; i<(int)_s.size(); i++)
            ranks[i] = (int)_s[i];


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
            alphabet = currentRank+1;
            currentPow++;
        }
        while((1<<(currentPow-1) ) < _s.size());


        SuffixArrayValues.assign(_s.size(),0);

        suffixIdToFind = -1;
        for(int i = 0; i<(int)_s.size(); i++)
        {
            SuffixArrayValues[i] = currentState[i].id;
            if(SuffixArrayValues[i] == iToFind && suffixIdToFind == -1)
                suffixIdToFind = i;
            ans.push_back(source[(source.size() + SuffixArrayValues[i] - 1)%source.size()]);
        }

    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin,s);


    SuffixArray mySA(s, 0);
    cout << mySA.suffixIdToFind+1 << '\n' << mySA.ans;

    return 0;
}
