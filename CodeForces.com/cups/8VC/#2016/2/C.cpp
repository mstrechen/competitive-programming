#include <iostream>

using namespace std;

unsigned long long s,q,count=0,stack=0;

void rec(int i,unsigned long long tmp)
{
	if(i==-1)
	{
		if(stack<s&&stack!=0&&(stack^(s-stack))==q)
		{
			count+=2;
		}
		if(stack==s-stack){count--;}
		cout << stack << ' ';
		return;
	}
	stack<<=1;
	tmp>>=1;
	if(tmp&q)
	{
		rec(i-1,tmp);
	}
	else
	{
		rec(i-1,tmp);
		s-=tmp*2;
		stack+= 1;
		rec(i-1,tmp);
		s+=tmp*2;
	}
	
	stack>>=1;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin >> s >> q;
	int lengthOfNum = 63;
	unsigned long long tmp = 1;
	tmp<<=63;
	for(;(s&tmp)==0;)
	{
		lengthOfNum--;
		tmp>>=1;
	}
	rec(lengthOfNum,tmp);
	cout << count;
	return 0;
}