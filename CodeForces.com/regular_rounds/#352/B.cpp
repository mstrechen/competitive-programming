#include <iostream>

using namespace std;

int a[27];
int main(){
	ios::sync_with_stdio(false);
    int n,answer = 0;
    cin >> n;
    char tmp;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        answer+=a[tmp-'a']>0;
        a[tmp-'a']++;
    }
    if(n>26) cout << -1;
    else cout << answer;
	return 0;
}
