#include <iostream>

using namespace std;
int gcd(int a, int b)
{
	int tmp;
	while(b!=0)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	int n, m,gcdOfNAndM,answer=0;
	cin >> n >> m;
	gcdOfNAndM = gcd(n,m);
	n/=gcdOfNAndM;
	m/=gcdOfNAndM;
	for(int i=2;i*i<=n;)
	{
		
		if(n%i==0)
		{
			n/=i;
			answer++;
		}
		else 
		{
			i++;
		}
	}
	for(int i=2;i*i<=m;)
	{
		if(m%i==0)
		{
			m/=i;
			answer++;
		}
		else 
		{
			i++;
		}
	}
	answer+=(int)(n!=1)+(int)(m!=1);
	cout << answer;
	return 0;
}