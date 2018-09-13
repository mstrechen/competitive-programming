#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct point
{
    int a,b,c;
};

int getThird(int a, int b, int c, int _a, int _b)
{
    return a^b^c^_a^_b;
}

void add(map<pair<int,int>,vector<int> > & A,
         vector<point> & P,
         int a, int b, int c, int i)
 {
    pair<int,int> ab = {a,b};

     if(A[ab].size()==2 && A[ab][0]!=i && A[ab][1]!=i)
    {
        int j = A[ab][0];
        if( getThird(P[j].a, P[j].b,P[j].c,a,b) < c )
        {
            A[ab][0] = i;
            i = j;
        }
        j = A[ab][1];

        if(getThird(P[j].a,P[j].b,P[j].c,a,b) < c )
        {
            A[ab][1] = i;
        }

    }
    else
    if(A[ab].size()==0||A[ab][0]!=i)
    {
        A[ab].push_back(i);
    }
 }

int min(int a, int b, int c)
{
    return min(a, min(b,c));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<pair<int,int>,vector<int> > A;
    vector<point> P;

    int n;
    int a,b,c;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> a >> b >> c;
        P.push_back({a,b,c});
        add(A,P,a,b,c, i);
        add(A,P,a,c,b, i);
        add(A,P,b,a,c, i);
        add(A,P,b,c,a, i);
        add(A,P,c,a,b, i);
        add(A,P,c,b,a, i);
    }

    int maxD = 0;
    pair<int,int> ans = {0,-1};
    for(auto i : A)
    {
        int a = i.first.first;
        int b = i.first.second;
        int c;
        if(i.second.size()==1)
        {
            c = i.second[0];
            c = getThird(P[c].a,P[c].b, P[c].c, a,b);
            if(min(a,b,c) > maxD)
            {
                ans = {i.second[0],-1};
                maxD = min(a,b,c);
            }
        }
        else
        {
            int c1 = i.second[0];
                c1 = getThird(P[c1].a,P[c1].b, P[c1].c, a,b);
            int c2 = i.second[1];
                c2 = getThird(P[c2].a,P[c2].b, P[c2].c, a,b);
            c = c1+c2;
            if(min(a,b,c) > maxD)
            {
                ans = {i.second[0], i.second[1]};
                maxD = min(a,b,c);
            }
        }
    }

    cout << 1 + (ans.second!=-1) << '\n';
    cout << ans.first + 1;
    if(ans.second!=-1)
        cout << ' ' << ans.second + 1;


    return 0;
}
