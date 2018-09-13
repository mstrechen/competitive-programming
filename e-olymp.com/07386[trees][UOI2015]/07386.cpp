#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

const long long INF = 1000000666;

struct point
{
	long long x,y;
	point(long long x=0, long long y=0) : x(x), y(y){}
	bool operator ==(point a)
	{
		if(this->x==a.x&&this->y==a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
    bool operator !=(point a)
    {
        return !(*this == a);
    }
	void printl()
    {
        cout << '(' << this->x << ',' << this->y << ')' << '\n';
    }
};
struct polygon
{
	point a[100500];
	int n;
    point leftChain[100500], rightChain[100500];
    int sizeOfLeftChain, sizeOfRightChain;
	long long minY, minYi, maxY, maxYi;

	point & opearator(int x)
	{
		return a[x];
	}
	void read()
	{
	    sizeOfLeftChain = sizeOfRightChain = 0;
		cin >> this->n;

		cin >> this->a[0].x >> this->a[0].y;

		minY = maxY = this->a[0].y;
		minYi = maxYi = 0;

		for(int i = 1; i<n; i++)
		{
			cin >> this->a[i].x >> this->a[i].y;
			if(this->a[i].y < minY)
			{
				minY = this->a[i].y;
				minYi = i;
			}
			else if(this->a[i].y > maxY)
			{
				maxY = this->a[i].y;
				maxYi = i;
			}
		}
		int i = maxYi+1-n*(n==(maxYi+1));
		if(this->a[i].y!=maxY)
        {
            i = maxYi;
        }
		for(; this->a[i].y!=minY; i = i+1-n*(n==(i+1)))
        {
            leftChain[sizeOfLeftChain++] = point(this->a[i].x, this->a[i].y);
        }
        leftChain[sizeOfLeftChain++] = point(this->a[i].x, this->a[i].y);


		i = maxYi-1+n*(maxYi==0);

		if(this->a[i].y!=maxY)
        {
            i = maxYi;
        }
		for(; this->a[i].y!=minY; i = i-1+n*(i==0))
        {
            rightChain[sizeOfRightChain++] = point(this->a[i].x, this->a[i].y);
        }
        rightChain[sizeOfRightChain++] = point(this->a[i].x, this->a[i].y);

	}

    point cross(long long y)
    {
        int i,j,mid=0;
		double leftCross, rightCross;
        for(i = 0, j = sizeOfLeftChain-2; (y > leftChain[mid].y)||(leftChain[mid+1].y > y);)
        {
            mid = ((i+j)/2);
			
            if(leftChain[mid].y<y)
            {
                j = mid;
            }
            else
            {
                i = mid+1;
            }
        }
		leftCross = leftChain[mid].x+((double)leftChain[mid+1].x-leftChain[mid].x)*((double)leftChain[mid].y-y)/((double)leftChain[mid].y-leftChain[mid+1].y);

		for(i = 0, j = sizeOfRightChain-2; (y > rightChain[mid].y)||(rightChain[mid+1].y > y);)
        {
            mid = ((i+j)/2);
            if(rightChain[mid].y<y)
            {
                j = mid;
            }
            else
            {
                i = mid+1;
            }
        }
		rightCross = rightChain[mid].x+((double)rightChain[mid+1].x-rightChain[mid].x)*((double)rightChain[mid].y-y)/((double)rightChain[mid].y-rightChain[mid+1].y);

		if(leftCross>rightCross)
		{
			swap(leftCross,rightCross);
		}
		return point(ceil(leftCross), floor(rightCross));
    }
} allPoints;

const point BAD_RESULT(-INF,INF);



struct circle
{
	point p;
	long long r;
	circle(long long x=0, long long y=0, long long z=0) : p(x,y), r(z){}
	point cross(long long y)
	{
		if(this->p.y+r < y||y < this->p.y-r)
		{
			return BAD_RESULT;
		}
		else
		{
			long long r = this->r,dy = this->p.y-y;

			long long d = sqrt(r*r-dy*dy);
			return point(this->p.x-d,this->p.x+d);
		}
	}
};


struct allCircles
{
	circle allCirclesInThis[50100];
	int n;

	circle & operator [](int x)
	{
		return this->allCirclesInThis[x];
	}
	void read(set<long long> * h, long long maxY, long long minY)
	{
		cin >> this->n;
		for(int i = 0; i<this->n; i++)
		{
			cin >> this->allCirclesInThis[i].p.x >> this->allCirclesInThis[i].p.y >> this->allCirclesInThis[i].r;
			long long 	firstY  = max(this->allCirclesInThis[i].p.y - allCirclesInThis[i].r, minY),
						secondY = min(this->allCirclesInThis[i].p.y + allCirclesInThis[i].r, maxY);
			for(long long j = firstY; j<=secondY; j++)
			{
				h->insert(j);
			}
		}
	}

} allCircles;

struct cross
{
	long long val;
	bool isBegin;
	cross(long long val1 = 0, bool isBegin1 = 0) : val(val1) , isBegin(isBegin1)
	{
	}

} crosses[100500];

int sizeOfCrosses;

bool isCrossLess(cross a, cross b)
{
	if(a.val == b.val)
	{
		return a.isBegin > b.isBegin;
	}
	else
	{
		return a.val < b.val;
	}
}

int main(){
	ios::sync_with_stdio(false);
	
	freopen("input.txt", "r", stdin);
	
	set<long long> horisontales;
	set<long long>::iterator hIterator;
    long long resultOfCalculation = 0;

	allPoints.read();
	allCircles.read(&horisontales, allPoints.maxY, allPoints.minY);

	for(hIterator = horisontales.begin(); hIterator!=horisontales.end(); hIterator++)
    {
        sizeOfCrosses = 0;
        point crossWithPolygon = allPoints.cross(*hIterator), tmpCrossWithCircle;
        for(int i = 0; i<allCircles.n; i++)
        {
            tmpCrossWithCircle = allCircles[i].cross(*hIterator);
            if(tmpCrossWithCircle != BAD_RESULT)
            {
                tmpCrossWithCircle.x = max(tmpCrossWithCircle.x, crossWithPolygon.x);
                tmpCrossWithCircle.y = min(tmpCrossWithCircle.y, crossWithPolygon.y);
				
                if(tmpCrossWithCircle.x<=tmpCrossWithCircle.y)
                {
                    crosses[sizeOfCrosses++] = cross(tmpCrossWithCircle.x, 1);
                    crosses[sizeOfCrosses++] = cross(tmpCrossWithCircle.y, 0);
                }
            }
        }
        long long countOfOpened = 0, countOfPoints = 0, lastOpeningX = 0;
        sort(crosses,crosses+sizeOfCrosses, isCrossLess);
        for(int i = 0; i<sizeOfCrosses; i++)
        {
            if(crosses[i].isBegin)
            {
                countOfOpened++;
                if(countOfOpened==1)
                {
                    lastOpeningX = crosses[i].val;
                }
            }
            else
            {
                countOfOpened--;
                if(countOfOpened==0)
                {
                    countOfPoints += crosses[i].val - lastOpeningX + 1;
                }
            }
        }
        resultOfCalculation+=countOfPoints;
    }
    cout << resultOfCalculation;
	return 0;
}