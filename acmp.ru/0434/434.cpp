#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct point{
	int x,y;
} points[100001];
point tmpPoint;

 struct line{
	int x, yBe,yEn;
	
 } linesFBTT[100000], linesFTTB[100000];
 
 //lines where y goes from bottom to the top (FBTT) and from top to the bottom(FTTB)
 
 
 point pointsFBTT[200000],pointsFTTB[200000];
 int pFBTTbe=100000,pFBTTen=100000,pFTTBbe=100000,pFTTBen=100000; 
 
 
int sizeOfFBTT=0, sizeOfFTTB=0;

bool isMore(line A,line B)
{
	return A.x > B.x;
}
bool isLess(line A,line B)
{
	return A.x < B.x;
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	
	
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> points[i].x >> points[i].y;
	}
	points[n] = points[0];
	
	for(int i = 0; i<n; i++)
	{
		if(points[i].x==points[i+1].x)
		{
			if(points[i].y<points[i+1].y){
				linesFBTT[sizeOfFBTT].x =  points[i].x; 
				linesFBTT[sizeOfFBTT].yBe =  points[i].y; 
				linesFBTT[sizeOfFBTT].yEn =  points[i+1].y;
				sizeOfFBTT++;
			}
			else
			{
				linesFTTB[sizeOfFTTB].x =  points[i].x; 
				linesFTTB[sizeOfFTTB].yBe =  points[i+1].y; 
				linesFTTB[sizeOfFTTB].yEn =  points[i].y; 
				sizeOfFTTB++;
			}
		}
	}
	sort(linesFBTT, linesFBTT+sizeOfFBTT, isMore);
	sort(linesFTTB, linesFTTB+sizeOfFTTB, isLess);
	
	int delta = 1; 
	for(int i = 1; i<sizeOfFBTT; i++)
	{
		if(linesFBTT[i].x==linesFBTT[i-delta].x)
		{
			linesFBTT[i-delta].yBe = min(linesFBTT[i-delta].yBe, linesFBTT[i].yBe);
			linesFBTT[i-delta].yEn = max(linesFBTT[i-delta].yEn, linesFBTT[i].yEn);
			delta++;
		}
		else linesFBTT[i-delta+1] = linesFBTT[i];
	}
	sizeOfFBTT-=delta-1;
	delta = 1;
	for(int i = 1; i<sizeOfFTTB; i++)
	{
		if(linesFTTB[i].x==linesFTTB[i-delta].x)
		{
			linesFTTB[i-delta].yBe = min(linesFTTB[i-delta].yBe, linesFTTB[i].yBe);
			linesFTTB[i-delta].yEn = max(linesFTTB[i-delta].yEn, linesFTTB[i].yEn);
			delta++;
		}
		else linesFTTB[i-delta+1] = linesFTTB[i];
	}
	sizeOfFTTB-=delta-1;
	int top, bottom;
	
	tmpPoint.x = linesFBTT[0].x;
	tmpPoint.y = linesFBTT[0].yBe;
	pointsFBTT[pFBTTen]=tmpPoint;
	pFBTTen++;
	tmpPoint.y = linesFBTT[0].yEn;
	pointsFBTT[pFBTTen]=tmpPoint;
	pFBTTen++;
	
	top = linesFBTT[0].yEn;
	bottom = linesFBTT[0].yBe;
	
	for(int i = 1; i<sizeOfFBTT; i++)
	{
		if(linesFBTT[i].yBe<bottom)
		{
			
			tmpPoint.x = linesFBTT[i].x;
			tmpPoint.y = bottom;
			pFBTTbe--;
			pointsFBTT[pFBTTbe] = tmpPoint;
			bottom = linesFBTT[i].yBe;			
			pFBTTbe--;
			tmpPoint.y = bottom;
			pointsFBTT[pFBTTbe] = tmpPoint;
		}
		if(linesFBTT[i].yEn>top)
		{
			tmpPoint.x = linesFBTT[i].x;
			tmpPoint.y = top;
			pointsFBTT[pFBTTen] = tmpPoint;
			pFBTTen++;
			top = linesFBTT[i].yEn;			
			tmpPoint.y = top;
			pointsFBTT[pFBTTen] = tmpPoint;
			pFBTTen++;
		}
	}
	
	
	
	tmpPoint.x = linesFTTB[0].x;
	tmpPoint.y = linesFTTB[0].yBe;
	pointsFTTB[pFTTBen]=tmpPoint;
	pFTTBen++;
	tmpPoint.y = linesFTTB[0].yEn;
	pointsFTTB[pFTTBen]=tmpPoint;
	pFTTBen++;
	
	top = linesFTTB[0].yEn;
	bottom = linesFTTB[0].yBe;
	
	for(int i = 1; i<sizeOfFTTB; i++)
	{
		if(linesFTTB[i].yBe<bottom)
		{
			
			tmpPoint.x = linesFTTB[i].x;
			tmpPoint.y = bottom;
			pFTTBbe--;
			pointsFTTB[pFTTBbe] = tmpPoint;
			bottom = linesFTTB[i].yBe;			
			pFTTBbe--;
			tmpPoint.y = bottom;
			pointsFTTB[pFTTBbe] = tmpPoint;
		}
		if(linesFTTB[i].yEn>top)
		{
			tmpPoint.x = linesFTTB[i].x;
			tmpPoint.y = top;
			pointsFTTB[pFTTBen] = tmpPoint;
			pFTTBen++;
			top = linesFTTB[i].yEn;			
			tmpPoint.y = top;
			pointsFTTB[pFTTBen] = tmpPoint;
			pFTTBen++;
		}
	}
	cout << pFBTTen+pFTTBen - pFBTTbe - pFTTBbe <<'\n';
	for(int i = pFTTBen-1;  i>=pFTTBbe; i--)
	{
		cout <<pointsFTTB[i].x <<' ' << pointsFTTB[i].y << '\n';
	}
	for(int i = pFBTTbe; i<pFBTTen; i++)
	{
		cout <<pointsFBTT[i].x <<' ' << pointsFBTT[i].y << '\n';
	}
	return 0;
}