#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
bool isMore(long long a, long long b)
{
	return a>b;	
}


long long spans[2048];

struct someTreeOfSumms{
	long long tree[4096];
	int nLevels;
	someTreeOfSumms (int size)
	{
		size--;
		int i;
		for(i=0; size>0; i++){size/=2;}
		nLevels = i+1;
		for(int i  = 1 << nLevels; i>=0 ; i--)
		{
			tree[i] = 0;
		}	
		
	}
	
	long long operator [](int i){
		long long summ=0;
		for(int j = (1 << (nLevels-1)) + i - 1; j>0; j/=2)
		{
			summ+=tree[j];
		}
		return summ;
		
	}
	void update(int left, int right, int value)
	{
		realUpdate((1 << (nLevels-1)) + left - 1,(1 << (nLevels-1)) + right - 1, 1, 1,value);
	}
	void realUpdate(int left, int right, int level, int i,int value)
	{
		int firstChild = i << (nLevels-level);
		int lastChild =  firstChild + (1 << (nLevels-level)) - 1; 
		int mid = (firstChild+lastChild)/2;
		if(left>right){return;}
		if(level == nLevels)
		{
			tree[i]+=value;
			return;
		}
		
		if((left == firstChild) && (right == lastChild))
		{
			tree[i]+=value;
		}
		else
		{
			if(left>mid)
			{
				realUpdate(left, right, level+1, i*2+1, value);
			}
			else if(right<=mid)
			{
				realUpdate(left, right, level+1, i*2, value);
			}
			else 
			{
				realUpdate(left, mid, level+1, i*2, value);
				realUpdate(mid+1, right, level+1, i*2+1, value);
			}
			
		}
	}
	void setArray(long long *array)
	{
		for(int i = 1 << (nLevels-1); i>=0; i--)
		{
			array[i] = 0;
		}
		int countOnThisLevel=1,firstChild,lastChild;
		int delta = 1 << (nLevels-1);
		for(int i = 1; i<=nLevels; i++)
		{
			for(int j = countOnThisLevel; j<countOnThisLevel*2;j++)
			{
				firstChild = j << (nLevels-i);
				lastChild = firstChild + (1 << (nLevels-i));
				for(int k = firstChild; k<lastChild; k++)
				{
					array[k-delta]+=tree[j];
				}
			}
			countOnThisLevel*=2;
			
		}
	}
};
int main(){
	
	int n,m,tmp;
	
	long long summ=0;
	scanf("%d%d",&n,&m);
	someTreeOfSumms treeOfSumms(n-1);
	
	
	
	
	for(int i = 1; i<n; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			scanf("%d",&tmp);
			summ+=tmp;
			treeOfSumms.update(j,i,tmp);
		}
		
	}
	treeOfSumms.setArray(spans);
	sort(spans,spans+n-1,isMore);
	for(int i = 0; i<m-1; i++)
	{
		summ+=spans[i];
	}
	cout << summ;
	return 0;
}