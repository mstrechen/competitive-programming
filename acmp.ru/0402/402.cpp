#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct point{
	int x,y;
	point(const int x=0, const int y=0)
		:x(x)
		,y(y)
	{}
	operator < (const point p)
	{
		return this->x < p.x; 
	}
} cotage[300];

struct line{
	int x1,y1,x2,y2,length;
	line(const int x1=0, const int y1=0,const int x2=0, const int y2=0,const int length=0)
		:x1(x1)
		,y1(y1)
		,x2(x2)
		,y2(y2)
		,length(length)
	{}
	
	bool isOnLine(int x3,int y3)
	{
		int a = y2-y1;
		int b = x1-x2;
		int c = -(a*x1+b*y1);
		return (a*x3+b*y3+c==0);
	}
	
	bool makeWithPoint(int x3, int y3)
	{
		if(this->isOnLine(x3,y3))
		{
			if((x3<x1)||(x3==x1&&y3<y1))
			{
				x1 = x3;
				y1 = y3;
			}
			else
			if((x3>x2)||(x3==x2&&y3>y2))
			{
				x2 = x3;
				y2 = y3;
			}
			length++;
		}
		return this->isOnLine(x3,y3);
	}
	pair<long long, long long> hash()
	{
		int a = y2-y1;
		int b = x1-x2;
		int c = -(a*x1+b*y1);
		return make_pair((long long)a*1000000+b,(long long)c);
	}
};

set< pair<long long, int> > setOfLines; 
int main(){
	ios::sync_with_stdio(false);
	int n;
	line tmpLine;
	unsigned long long answer = 0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> cotage[i].x >> cotage[i].y;
	}
	sort(cotage,cotage+n);
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			line tmpLine = line(cotage[i].x, cotage[i].y, cotage[j].x, cotage[j].y);
			for(int k = 0; k<n; k++)
			{
				tmpLine.makeWithPoint(cotage[k].x,cotage[k].y);
			}
			if(setOfLines.count(tmpLine.hash())==0)
			{
				setOfLines.insert(tmpLine.hash());
				answer+=tmpLine.length-1;
			}
		}
	}
	
	cout << answer*2;
	return 0;
}