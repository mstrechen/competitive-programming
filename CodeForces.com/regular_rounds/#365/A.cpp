#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, a = 0, b  = 0, tmp1, tmp2;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp1 >> tmp2;
        if(tmp1>tmp2)
            a++;
        if(tmp1<tmp2)
            b++;
    }
    if(a>b)
        cout << "Mishka";
    if(a==b)
        cout << "Friendship is magic!^^";
    if(a<b)
        cout << "Chris";
    return 0;
}
