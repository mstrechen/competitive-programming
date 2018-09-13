#include<iostream>
#include<vector>


using namespace std;

long long get(int l, int r, vector<int> & A, bool coef)
{
    if(l==r)
        return A[l]*coef;
    if(l+1==r)
        return max(A[l], A[r])*coef + min(A[l], A[r])*(1-coef);

    if(A[l]+min(A[l+1],A[r]) >=  A[r]+min(A[l],A[r-1]))
        return A[l]*coef + get(l+1,r,A,!coef);
    else
        return A[r]*coef + get(l,r-1,A,!coef);
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> A(n);

    for(auto & i : A)
        cin >> i;

    cout << get(0, n-1, A,1);

    return 0;
}
