#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int n, k, tmp, ans;
    cin >> n >> k;
    for(int i = 1; k-i>0; i++)
        k-=i;
    k--;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        if(i==k)
            ans = tmp;
    }
    cout << ans;

	return 0;
}
