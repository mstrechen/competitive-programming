#include<iostream>
#include<vector>


using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sA, sB;
    cin >> sA >> sB;

    vector<vector<int16_t> > lcssPrefix(sA.size() + 1, vector<int16_t>(sB.size()+1, 0) ),
                         lcssSuffix(sA.size() + 1, vector<int16_t>(sB.size()+1, 0) );
    vector<vector<pair<int16_t,int16_t> > > maxLcssPrefix(sA.size() + 1, vector<pair<int16_t,int16_t> >(sB.size()+1, {0,0}) ),
                                    maxLcssSuffix(sA.size() + 1, vector<pair<int16_t,int16_t> >(sB.size()+1, {0,0}) );

    for(int aPos = 0; aPos<(int)sA.size(); aPos++)
        for(int bPos = 0; bPos<(int)sB.size(); bPos++)
        {
            if(sA[aPos]==sB[bPos])
                lcssPrefix[aPos+1][bPos+1] = int16_t(lcssPrefix[aPos][bPos] + 1);
            else
                lcssPrefix[aPos+1][bPos+1] = 0;

            maxLcssPrefix[aPos+1][bPos+1] = max(max(maxLcssPrefix[aPos+1][bPos],maxLcssPrefix[aPos][bPos+1]),
                                                    {lcssPrefix[aPos+1][bPos+1], aPos});
        }

    for(int aPos = (int)sA.size() - 1; aPos>=0; aPos--)
        for(int bPos = (int)sB.size() - 1; bPos>=0; bPos--)
        {
            if(sA[aPos]==sB[bPos])
                lcssSuffix[aPos][bPos] = int16_t(lcssSuffix[aPos+1][bPos+1] + 1);
            else
                lcssSuffix[aPos][bPos] = 0;

             maxLcssSuffix[aPos][bPos] = max(max(maxLcssSuffix[aPos+1][bPos],maxLcssSuffix[aPos][bPos+1]),
                                                    {lcssSuffix[aPos][bPos], aPos});
        }

    int maxval = 0;
    pair<int,int> ansPA = {0,0}, ansPB = {0,0};
    for(int prefixA = 0; prefixA<=(int)sA.size(); prefixA++)
        for(int prefixB = 0; prefixB<=(int)sB.size(); prefixB++)
        {
            if(maxLcssPrefix[prefixA][prefixB].first + maxLcssSuffix[prefixA][prefixB].first > maxval)
            {
                maxval = maxLcssPrefix[prefixA][prefixB].first + maxLcssSuffix[prefixA][prefixB].first;
                ansPA = maxLcssPrefix[prefixA][prefixB];
                ansPB = maxLcssSuffix[prefixA][prefixB];
            }
        }

    cout << string(sA.begin() + ansPA.second - ansPA.first+1, sA.begin() + ansPA.second+1) << '\n';
    cout << string(sA.begin() + ansPB.second, sA.begin() + ansPB.second + ansPB.first );


    return 0;
}
