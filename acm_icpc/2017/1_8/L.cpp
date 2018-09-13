#include<iostream>
#include<vector>

using namespace std;

vector<int> st;

vector<vector<vector<char> > > a(1000, vector<vector<char>>(100, vector<char>(50, 0) ));

bool rec(int n, int d, int h)
{
    if(d <= 0 || d >= 70 || n < 0)
        return false;

    if(h == 0)
    {
        if(n == 0)
        {
            for(auto i : st)
                cout << i << '\n';
            return true;
        }
        return false;
    }
    if(a[n][d][h])
    {
        return false;
    }
    a[n][d][h] = true;

    st.push_back(d);

    if(rec(n - d, d+1, h-1))
    {
        st.pop_back();
        return true;
    }
    else
    {
        bool tmp = rec(n-d, d-1, h-1);
        st.pop_back();
        return tmp;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, h;

    cin >> n >> d >> h;

    st.reserve(h);
    if(!rec(n,d,h))
        cout << "0";

    return 0;
}

