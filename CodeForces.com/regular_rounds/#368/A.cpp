#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    char c;
    bool isColored = 0;
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
    {
        cin >> c;
        if((c=='C')||(c=='M')||(c=='Y'))
            isColored = 1;
    }
    if(isColored)
        cout << "#Color";
    else
        cout << "#Black&White";

    return 0;
}
