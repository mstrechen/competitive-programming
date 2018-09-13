
#include<iostream>
#include<vector>

using namespace std;

const static int SQRT_CONST = 1000;
struct SQRT
{
    vector<long long> sums;
    vector<int>  elements;

    SQRT(int n,istream & in)
    {
        elements.assign(n,0);

        sums.assign((n-1)/SQRT_CONST + 1, 0);

        for(int i = 0; i<elements.size(); i++)
            sums[i/SQRT_CONST]+=elements[i];
    }

    void add(int i, long long val)
    {
        sums[i/SQRT_CONST]-=elements[i];
        elements[i] = val;
        sums[i/SQRT_CONST]+=elements[i];
    }



    long long get(int l, int r)
    {
        long long ans = 0;
        for(int i = l; i<=r;)
        {
            if(i%SQRT_CONST == 0 && i+SQRT_CONST <= r-1)
            {
                ans+=sums[i/SQRT_CONST];
                i+=SQRT_CONST;
            }
            else
            {
                ans+=elements[i];
                i++;
            }

        }
        return ans;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    SQRT decomp(n,cin);


    while(q--)
    {
        char type;
        cin >> type;
        if(type=='A')
        {
            int i,x;
            cin >> i >> x;
            decomp.add(i-1,x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << decomp.get(l-1,r-1) << '\n';
        }
    }


    return 0;
}
