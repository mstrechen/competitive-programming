#include<iostream>
#include<vector>

using namespace std;

const static int SQRT_CONST = 316;
struct SQRT
{
    vector<long long> elements, promises, sums;

    SQRT(istream & in)
    {
        int n;
        in >> n;
        elements.assign(n,0);

        for(auto & i  : elements)
            in >> i;

        promises.assign((n-1)/SQRT_CONST + 1, 0);
        sums.assign((n-1)/SQRT_CONST + 1, 0);

        for(int i = 0; i<elements.size(); i++)
            sums[i/SQRT_CONST]+=elements[i];
    }

    void add(int l, int r, long long val)
    {
        for(int i = l; i<=r;)
        {
            if(i%SQRT_CONST == 0 && i+SQRT_CONST <= r-1)
            {
                sums[i/SQRT_CONST]+=val*SQRT_CONST;
                promises[i/SQRT_CONST]+=val;
                i+=SQRT_CONST;
            }
            else
            {
                sums[i/SQRT_CONST]+=val;
                elements[i]+= val;
                i++;
            }
        }
    }
    void push(int i)
    {
        if(promises[i]!=0)
        {
            for(int j = i*SQRT_CONST; j<(i+1)*SQRT_CONST; j++)
                elements[j] += promises[i];
            promises[i] = 0;
        }
    }



    long long get(int l, int r)
    {
        push(l/SQRT_CONST);
        push(r/SQRT_CONST);
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

    SQRT decomp(cin);

    int q;
    cin >> q;

    vector<long long> add(SQRT_CONST, 0);

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int l, r, c;
            cin >> l >> r >> c;
            decomp.add(l-1,r-1,c);
        }
        else
        if(type == 2)
        {
            int d,c;
            cin >> d >> c;
            if(d<SQRT_CONST)
            {
                add[d]+=c;
            }
            else
            {
                for(int i = d-1; i<decomp.elements.size(); i+=d)
                {
                    decomp.add(i,i,c);
                }
            }
        }
        else
        {
            int l,r;
            cin >> l >> r;

            long long ans = decomp.get(l-1,r-1);

            for(int i = 1; i<SQRT_CONST ; i++)
                ans+=add[i]*(r/i - (l-1)/i);

            cout << ans << '\n';
        }
    }


    return 0;
}
