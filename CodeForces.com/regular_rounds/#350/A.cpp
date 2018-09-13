#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n==1)
    {
        cout << "0 1";
    }
    else
    {
        cout << (n/7)*2 + (n%7==6) << ' ' << ((n-2)/7)*2 + 2+((n-2)%7==6);
    }
	return 0;
}
