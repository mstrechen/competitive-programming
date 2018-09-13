#include <iostream>

using namespace std;


int a[6] = {4,5,6,3,2,1};

int main(){
	ios::sync_with_stdio(false);
	long long n;
	long long ans = 0;

	char c;
    cin >> n >> c;
    n--;
    ans+=(n/4)*16;
    n%=4;
    ans+=(n%2)*7;
    ans+=a[c-'a'];
    cout << ans;



    return 0;
}
