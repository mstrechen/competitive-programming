#include<iostream>
#include<cmath>

using namespace std;

const int oo = 1000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<int,string> N(+oo,"N"), // північ
                     S(+oo,"S"), // південь
                     W(+oo,"W"), // захід
                     E(+oo,"E"), // схід
                     NW(+oo,"NW"),
                     NE(+oo,"NE"),
                     SW(+oo,"SW"),
                     SE(+oo,"SE");

    int x1, x2,y1, y2, X,Y;

    cin >> x1 >> y1 >> x2 >> y2 >> X >> Y;

    if(x1<=X && X<=x2)
    {
        N.first = y2-Y;
        S.first = y1-Y;
        N.first*=N.first;
        S.first*=S.first;
    }
    if(y1<=Y && Y<=y2)
    {
        W.first = x1-X;
        S.first = x2-X;
        W.first*=W.first;
        S.first*=S.first;
    }

    SW.first = (x1-X)*(x1-X) + (y1-Y)*(y1-Y);

    NE.first = (x2-X)*(x2-X) + (y2-Y)*(y2-Y);

    NW.first = (x1-X)*(x1-X) + (y2-Y)*(y2-Y);

    SE.first = (x2-X)*(x2-X) + (y1-Y)*(y1-Y);



    pair<int, string> ans = min(min(min(N,W),min(E,S)),
                                min(min(NW,NE),min(SW,SE)));

    cout << ans.second;



    return 0;
}

