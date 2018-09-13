#include <iostream>
#include <set>
using namespace std;

set<int> online;
int a[200000];
int main(){
	ios::sync_with_stdio(false);
	
	int n, k,k1 = 0, q, tmp1,tmp2;
	cin >> n >> k >> q;
	for(int i = 1; i<=n; i++) cin >> a[i];
	for(int i = 0; i<q; i++)
	{
		cin >> tmp1 >> tmp2;
		tmp2 = a[tmp2]; 
		if(tmp1==1) {online.insert(tmp2); k1+=(k1!=k); }
		else
		{
			bool was = 0;
			set<int>::reverse_iterator it = online.rbegin();
			for(int i  = 0; i < k1; i++)
			{
				if(*it==tmp2)
				{
					cout << "YES\n";
					was = 1;
					break;
				}
				it++;
			}
			if(!was)cout << "NO\n";
			
		}
	}
	
	return 0;
}