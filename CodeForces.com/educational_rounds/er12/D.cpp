#include <iostream>
#include <vector>

using namespace std;

bool field[2000001];

vector<int> a;
int p[1000];

int main(){
	ios::sync_with_stdio(false);
	
	field[1] = 1;
	for(int i = 2; i<2001; i++)
	{
		if(!field[i])
		{
			for(int j = 2; i*j<1000001; j++)field[i*j] = 1;
		}
	}
	
	int n,tmp;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	int maxP;
	do
	{
		p[0] = 0;
		maxP = 0;
		for(int i = 0; i<a.size();i++)
		{
			tmp = 0;
			for(int j = 0; j<a.size(); j++)
			{
				if(i!=j)tmp+=field[a[j]+a[i]];
			}
			p[i] = tmp;
			if(p[maxP]<p[i]) i  = maxP;
		}
		if(p[maxP]!=0)
		{
			a.erase(a.begin()+maxP);
		}
	}
	while(p[maxP]!=0&&a.size()>0);
	cout << a.size() << '\n';
	for(int i = 0; i<a.size(); i++) cout << a[i] << ' ';
	return 0;
}