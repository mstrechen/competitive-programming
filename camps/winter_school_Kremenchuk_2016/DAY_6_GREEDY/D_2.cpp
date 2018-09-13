#include<iostream>
#include<vector>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long ans = 0;
    long long sum = 0;

    int n;
    cin >> n;

    vector<long long> mine;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        sum+=x;
        mine.push_back(x);

        bool flag = 1;
        while(mine.size()>2 && flag)
        {
            int j = mine.size()-2;
            if(mine[j]>=mine[j-1] && mine[j]>=mine[j+1])
            {
                ans+=mine[j];
                mine[j-1]+=mine[j+1]-mine[j];
                mine.pop_back();
                mine.pop_back();
            }
            else
                flag = 0;
        }
    }

    bool isOur = 1;
    for(int l = 0, r = mine.size()-1; l<=r; )
    {
        if(mine[l]>mine[r])
        {
            if(isOur)
                ans+=mine[l];
            l++;
        }
        else
        {
            if(isOur)
                ans+=mine[r];
            r--;
        }
        isOur^=1;
    }

    if(ans*2<sum)
    {
        cout << 2;
    }
    else
    if(ans*2==sum)
    {
        cout << 0;
    }
    else
    {
        cout << 1;
    }



    return 0;
}
