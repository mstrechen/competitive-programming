#include<iostream>

using namespace std;


int grtr(int i)
{
    while(i&(i-1))
        i&=i-1;
    return i;
}


bool get(long long a, long long b)
{
    return !(__builtin_popcountll(a^b) & 1);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    string four = "four\n";
    string seven = "seven\n";
    while(n--)
    {
        long long x,y;
        cin >> x >> y;
        if(get(x,y))
            cout << four;
        else
            cout << seven;
    }

    return 0;
}
