#include <iostream>
#include <string>
using namespace std;

int getIntPart(int n)
{
	int twoStepsEarlier = 2, oneStepsEarlier = 2, justNow;
	if(n==0){return 0;}
	if(n==1){return 2;}
	for(int i = 1; i<n; i++)
	{
		justNow = 2*(twoStepsEarlier+oneStepsEarlier)%100000;
		twoStepsEarlier = oneStepsEarlier;
		oneStepsEarlier = justNow;
	}
	
	return justNow-!(n&1);
}
int getRealPart(int n)
{
	if(n>37)
	{
		return 99999*((n-1)&1);
	}
	else
	{
		int a[38] = {0,73205,46410,39230,71281,21023,84609,11266,91752,6037,95580,3235,97631,1733,98730,929,99319,497,99635,266,99804,143,99895,76,99943,41,99969,22,99983,11,99991,6,99995,3,99997,1,99998,0};
		return a[n];
	}
}
string toString(int n)
{
	string s = "     ";
	for(int i = 0; i<5; i++)
	{
		s[4-i] = '0'+n%10;
		n/=10;
	}
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cout <<toString(getIntPart(n))<<'.'<<toString(getRealPart(n))<<'\n';
	
	return 0;
}