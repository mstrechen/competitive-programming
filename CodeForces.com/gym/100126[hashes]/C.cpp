#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>

using namespace std;

struct stringWithHashes
{
    const unsigned long long p1 = 31;
	const long long p2 = 41;
    const long long mod2 = 1000*1000*1000+9;

    vector<unsigned long long> hashes1, p1pows;
    vector<long long> hashes2, p2pows;
    string s;

    int size;
    stringWithHashes(string s = ""):s(s)
    {
        size = s.size();
        hashes1.assign(s.size(),0);
        hashes2.assign(s.size(),0);
        p1pows.assign(s.size(),0);
        p2pows.assign(s.size(),0);
        if(s.size())
        {
            hashes1[0] = s[0]-'a'+1;
            hashes2[0] = s[0]-'a'+1;
            p1pows[0] = 1;
            p2pows[0] = 1;
            for(int i = 1; i<s.size(); i++)
            {
                hashes1[i] = hashes1[i-1]*p1+s[i]-'a'+1;
                hashes2[i] = (hashes2[i-1]*p2+s[i]-'a'+1)%mod2;
                p1pows[i] = p1pows[i-1]*p1;
                p2pows[i] = (p2pows[i-1]*p2)%mod2;
            }
        }

    }

    pair<unsigned long long, long long> getHash(int i, int j)
    {
        if(i>j)
            return {-1,-1};
        if(i==0)
            return {hashes1[j],hashes2[j]};

        unsigned long long tmp1 = hashes1[j]-hashes1[i-1]*p1pows[j-i+1];
        long long tmp2 = hashes2[j]-(hashes2[i-1]*p2pows[j-i+1])%mod2;
        if(tmp2<0)
            tmp2+=mod2;
        return {tmp1,tmp2};
    }
};

int main()
{
    ifstream cin("substr.in");
    ofstream cout("substr.out");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, minLen = 100000;
    string s;

    cin >> s;

    stringWithHashes A(s);


    for(int i = 0; i<A.size; i++)
    {
        int l, r;
        for(l = -1, r = min(i+1,A.size-i); l<r+1;)
        {
            if()
        }
    }

    return 0;
}
