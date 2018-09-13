#include <iostream>
#include <string>

using namespace std;

string s;

void makeIt(int i)
{
    if(i == 0 ) return;

    makeIt(i-1);
    int a[10],l = 0;

    for(int k = i; k>0; k/=10)
    {
        a[l++] = k%10;
    }
    for(int k = l-1; k>=0; k--)
        s+='0'+a[k];
}

int main(){
	ios::sync_with_stdio(false);
    int n;
    s.reserve(2000000);

    cin >> n;
    makeIt(1000);
    cout << s[n-1];
	return 0;
}
