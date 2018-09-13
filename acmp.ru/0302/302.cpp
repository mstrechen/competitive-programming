#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
	double x,y;
	void readPoint(){
		cin >> x >> y;
	}
	double operator ^ (point p)
	{
		return (this->x - p.x)*(this->x - p.x)+(this->y - p.y)*(this->y - p.y);
	}
} cotages[1000];

struct distance{
	double d;
	int a,b;
	void makeDistance(int i, int j, point p1, point p2)
	{
		d = p1^p2;
		a = i;
		b = j;
	}
	operator <(const distance d1 )
	{
		return this->d < d1.d;
	}
} distances[1000000];

int colors[1000];
int main(){
	ios::sync_with_stdio(false);
	int n,countOfDistances=0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cotages[i].readPoint();
		colors[i] = i;
	}
	for(int i = 0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			distances[countOfDistances].makeDistance(i,j,cotages[i], cotages[j]);
			countOfDistances++;
		}
		
	}
	sort(distances,distances+countOfDistances);
	int countInTree = 0;
	double maxDist = 0;
	int whatColorToReplace;
	for(int i = 0; countInTree<n-1; i++)
	{
		if(colors[distances[i].a]!=colors[distances[i].b])
		{
			countInTree++;
			maxDist = distances[i].d;
			whatColorToReplace = colors[distances[i].a];
			for(int j = 0; j<n; j++)
			{
				if(colors[j]==whatColorToReplace)
				{
					colors[j] = colors[distances[i].b];
				}
			}
		}
		
	}
	cout.precision(2);
	cout << fixed <<sqrt(maxDist+1E-4);
	return 0;
}