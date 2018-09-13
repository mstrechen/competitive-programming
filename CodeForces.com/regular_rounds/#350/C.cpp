#include <iostream>
#include <set>
#include <map>

using namespace std;

map<int,int> languages;
int lan[200000];
int main(){
	ios::sync_with_stdio(false);
    int n, k, ans = 0, ansFull = 0, ansPart = 0;

    int tmp, tmp1,tmp2;

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        languages[tmp]++;
    }
    cin >> k;
    for(int i = 0; i<k; i++)
    {
        cin >> lan[i];
    }
    for(int i = 0; i<k; i++)
    {
        cin >> tmp;
        tmp1 = languages[lan[i]];
        tmp2 = languages[tmp];
        if((tmp1>ansFull)||(tmp1==ansFull&&tmp2>ansPart))
        {
            ans = i;
            ansFull = tmp1;
            ansPart = tmp2;
        }
    }
    cout << ans+1;


	return 0;
}
