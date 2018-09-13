#include <iostream>

using namespace std;


int a[6] = {4,5,6,3,2,1};

int main(){
	ios::sync_with_stdio(false);

	long long n;
	long long ans = 0;

	char c;
    cin >> n >> c;


    ans=((n-1)/4)*16;

    n=(n-1)%4;
    if(n%2==1)
        ans+=7;

    int changes[6] = {4,5,6,3,2,1};

    ans+=changes[c-'a'];

    cout << ans;



    return 0;
}
