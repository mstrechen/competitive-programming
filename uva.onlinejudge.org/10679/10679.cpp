#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct SuffixRank
{
    int rankA, rankB;
    int id;
};

bool operator != (const SuffixRank & a, const SuffixRank & b)
{
    return (a.rankA != b.rankA) || (a.rankB != b.rankB);
}
bool operator < (const SuffixRank & a, const SuffixRank & b)
{
    return (a.rankA < b.rankA) || (a.rankA ==  b.rankA && a.rankB < b.rankB);
}


struct SuffixArray
{
    string s;
    vector<int> a;

    SuffixArray(const string & source) : s(source + ' '), a(source.size())
    {
        int n = (int)s.size();

        vector<SuffixRank> currentState(n);
        vector<int> ranks(source.size() + 1);


        int maxRank = 127;
        for(int i = 0; i<n; i++)
            ranks[i] = s[i];

        int step = 0;
        do
        {
            for(int i = 0; i<n; i++)
            {
                currentState[i] = {ranks[i], ranks[ (i + (1<<step) - 1)%n ], i};
            }
            bucketSort(currentState, maxRank);

            maxRank = 0;
            for(int i = 0; i<n; i++)
            {
                if(i!=0 && currentState[i]!=currentState[i-1])
                    maxRank++;
                ranks[currentState[i].id] = maxRank;
            }
            step++;
        }
        while(maxRank+1!=n);


        for(int i = 0; i+1<n; i++)
            a[ranks[i]-1] = i;

    }

    void bucketSort(vector<SuffixRank> & toSort, int maxVal)
    {
        vector<vector<SuffixRank> > tmp(maxVal+1);

        for(auto & i : toSort)
        {
            tmp[i.rankB].push_back(i);
        }
        int pos = 0;
        for(auto & i : tmp)
        {
            for(auto & j : i)
                toSort[pos++] = j;
            i.clear();
        }

        for(auto & i : toSort)
            tmp[i.rankA].push_back(i);

        pos = 0;
        for(auto & i : tmp)
            for(auto & j : i)
                toSort[pos++] = j;
    }

    bool isPrefixOfSuffix(int pos, const string & toFind)
    {
        if(pos+(int)toFind.size() > (int)a.size())
            return 0;

        for(int i = 0; i<(int)toFind.size(); i++)
            if(toFind[i]!=s[pos+i])
                return false;

        return true;
    }

    bool isGreaterThanSuffix(int pos, const string & toCompare)
    {
        int i;
        for(i = 0; i<(int)toCompare.size() && pos+i < (int)a.size(); i++)
            if(s[pos+i] != toCompare[i])
                return toCompare[i] > s[pos+1];

        if(i == (int)toCompare.size())
            return pos+i != (int)a.size();
        return 0;
    }

    bool canFind(const string & toFind)
    {
        int l = 0, r = (int)a.size() - 1;

        while(l!=r)
        {
            int mid = (l+r)/2;

            if(isGreaterThanSuffix(a[mid], toFind))
                l = mid+1;
            else
                r = mid;
        }
        return isPrefixOfSuffix(a[l], toFind) || (l!=0 && isPrefixOfSuffix(a[l-1], toFind));
    }

};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--)
    {
        string s;
        cin >> s;
        SuffixArray SA(s);

        int q1;
        cin >> q1;
        while(q1--)
        {
            cin >> s;
            if(SA.canFind(s))
                cout << 'y' << '\n';
            else
                cout << 'n' << '\n';
        }

    }




    return 0;
}
