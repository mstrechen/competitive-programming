#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int SQRT_N = 316;

struct SmallStep
{
    vector<vector<int> > cnt;

    SmallStep(const vector<int> & A) : cnt(SQRT_N, vector<int>(A.size()))
    {
        int n = (int)A.size();
        for(int k = 1; k < SQRT_N; k++)
        {
            for(int i = n-1; i >= 0; i--)
                if(k + A[i] + i >= n)
                    cnt[k][i] = 1;
                else
                    cnt[k][i] = cnt[k][k + A[i] + i] + 1;
        }
    }

    int get(int p, int k)
    {
        assert(k < SQRT_N);
        return cnt[k][p - 1];
    }
};

struct BigStep
{
    const vector<int> & A;

    BigStep(const vector<int> & S) : A(S)
    {
    }

    int get(int p, int k)
    {
        p--;
        int ans = 0;
        while(p < (int)A.size())
        {
            ans++;
            p += A[p] + k;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto & i : A)
        cin >> i;

    BigStep BS(A);
    SmallStep SS(A);

    int q;
    cin >> q;

    while(q--)
    {
        int p, k;
        cin >> p >> k;
        if(k<SQRT_N)
            cout << SS.get(p,k) << '\n';
        else
            cout << BS.get(p,k) << '\n';
    }


    return 0;
}
