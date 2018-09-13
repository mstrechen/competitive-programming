#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compInt(int a, int b)
{
	if(a<b) return true;
	return false;
}

struct classcomp {
  bool operator() (const double& lhs, const double& rhs) const
  {return lhs<rhs;}
};
map<double,int,classcomp> setOfAccounts;
map<double,int,classcomp>::iterator it;
pair<double,int> someTmpPair;
int main(){
	ios::sync_with_stdio(false);
	int n;
	double p, tmp;
	cin >> n >> p;
	p = (1-p/100);
	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		setOfAccounts[tmp]++;
	}
	for(int i = 1; i<n; i++)
	{
		it = setOfAccounts.begin();
		someTmpPair= *it;
		tmp = someTmpPair.first;
		if(someTmpPair.second == 1)
		{
			setOfAccounts.erase(it);
		}
		else
		{
			setOfAccounts[tmp]--;
		}
		it = setOfAccounts.begin();
		someTmpPair= *it;		
		if(someTmpPair.second == 1)
		{
			setOfAccounts.erase(it);
		}
		else
		{
			setOfAccounts[someTmpPair.first]--;
		}		
		tmp+= someTmpPair.first;
		tmp*=p;
		setOfAccounts[tmp]++;
		
	}
	
	it = setOfAccounts.begin();
	someTmpPair= *it;
	cout << someTmpPair.first-0.01;
	
	return 0;
}