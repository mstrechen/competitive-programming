#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int a,b,c;
    bool ans;
    cin >> a >> b >> c;
    if(c==0)
        ans = a==b;
    else
        ans = (b-a)/c>=0&&(b-a)%c==0;
    if(ans)
        cout << "YES";
    else
        cout << "NO";
	return 0;
}
