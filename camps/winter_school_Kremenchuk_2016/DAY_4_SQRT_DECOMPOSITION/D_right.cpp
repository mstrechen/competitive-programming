#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int SQRT = 316;

struct Orbit
{
    vector<int> answers;
    vector<int> whatWant;
    vector<pair<pair<int,int>, long long> > queries;
    vector<vector<int> > owners;
    vector<int> sectors;
    vector<long long> currSumOnOwners;

    int n, m, q;

    Orbit(istream & in)
    {
        in >> n >> m;
        answers.assign(n,-1);
        whatWant.assign(n,0);
        sectors.assign(m,0);
        owners.assign(n,vector<int>(0,0));
        for(int i = 0; i<m; i++)
        {
            in >> sectors[i];
            owners[--sectors[i]].push_back(i);
        }
        for(auto & i : whatWant)
            in >> i;
        for(auto & i : owners)
            sort(i.begin(), i.end());

        in >> q;
        for(int i = 0; i<q; i++)
        {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;
            queries.push_back({{l,r},c});
        }
    }

    int getCountOnSegment(int owner, int l, int r)
    {
        if(l>r)
            return getCountOnSegment(owner, 0, r) + getCountOnSegment(owner, l, m-1);
        return upper_bound(owners[owner].begin(), owners[owner].end(), r) -
                lower_bound(owners[owner].begin(), owners[owner].end(), l);
    }

    int getShortAns(int owner, int lastQ)
    {
        while(currSumOnOwners[owner]>=whatWant[owner])
        {
            currSumOnOwners[owner]-=queries[lastQ].second * getCountOnSegment(owner, queries[lastQ].first.first,
                                                                                    queries[lastQ].first.second);
            lastQ--;
        }
        return lastQ + 2;
    }

    vector<int> & getAnswer()
    {
        vector<long long> additionals(m+1, 0);
        currSumOnOwners.assign(n,0);
        for(int _i = 0; _i<(int)queries.size(); _i++)
        {
            if(queries[_i].first.first <= queries[_i].first.second)
            {
                additionals[queries[_i].first.first] += queries[_i].second;
                additionals[queries[_i].first.second+1] -= queries[_i].second;
            }
            else
            {
                additionals[0]                          +=queries[_i].second;
                additionals[queries[_i].first.second + 1]-=queries[_i].second;
                additionals[queries[_i].first.first]   +=queries[_i].second;
                additionals[m]                          -=queries[_i].second;
            }
            if((_i+1)%SQRT == 0 || _i==(int)queries.size()-1)
            {
                long long currAdd = 0;
                for(int i = 0; i<m; i++)
                {
                    currAdd+=additionals[i];
                    currSumOnOwners[sectors[i]]+=currAdd;
                }
                additionals.assign(m+1, 0);

                for(int i = 0; i<n; i++)
                if(answers[i]==-1 && currSumOnOwners[i]>=whatWant[i])
                {
                    answers[i] = getShortAns(i, _i);
                }
            }
        }
        return answers;
    }

};

ostream & operator << (ostream & outStream, const vector<int> & toWrite)
{
    for(auto i : toWrite)
        outStream << i << '\n';
    return outStream;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Orbit orbit(cin);

    cout << orbit.getAnswer();



    return 0;
}
