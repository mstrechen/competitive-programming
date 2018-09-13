#include<iostream>
#include<vector>

using namespace std;



void readSt(vector<int> & s)
{
    int tmp;
    cin >> tmp;
    s.assign(tmp,0);
    for(int i = 0; i<tmp; i++)
    {
        cin >> s[i];
        s[i]--;
    }
}

bool compareSts(vector<int> & a, vector<int> & b, int delta, int mod)
{
    int useSize = min(a.size(), b.size());
    for(int i = 0; i<useSize; i++)
    {
        if(((a[i]+delta)%mod) < (b[i]+delta)%mod)
            return 1;
        else
        if(((a[i]+delta)%mod) > (b[i]+delta)%mod)
            return 0;
    }
    if(a.size()<=b.size())
        return 1;
    return 0;

}

void findMinimal(vector<int> & a, vector<int> & b, int & delta, int mod)
{
    int useSize = min(a.size(), b.size());
    int i = 0;
    bool flag = 1;
    while(i<useSize&&flag)
    {
        if(a[i]==b[i])
            i++;
        else
        {
            while((a[i]+delta)%mod>(b[i]+delta)%mod)
                delta++;
            flag  = 0;
        }
    }
}


vector<int> allS[500500];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,c;

    vector<int> prevS, nextS;

    cin >> n >> c;

    for(int i = 0; i<n; i++)
        readSt(allS[i]);

    int answer = 0;

    bool flag = 1;

    int i = 3000000/n;
    do
    {

        for(int i = 0; i+1<n; i++)
        {
            findMinimal(allS[i], allS[i+1], answer,c);
            if(answer>=c)
            {
                cout << -1;
                return 0;
            }

        }
        flag = 1;
        for(int i = 0; i+1<n; i++)
            flag&=compareSts(allS[i], allS[i+1], answer,c);

        i--;
    }
    while(flag==0&&i);



    if(flag)
        cout << answer;
    else
        cout << -1;

    return 0;
}
