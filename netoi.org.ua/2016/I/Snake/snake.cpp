#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);

    int x,y;
    cin >> x >> y;
	x = abs(x);
	y = abs(y);

    cout << max(x,y)*2 - ((x&1) ^ (y&1));


    return 0;
}

