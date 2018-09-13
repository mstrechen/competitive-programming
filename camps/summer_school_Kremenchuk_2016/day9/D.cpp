#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long long max(long long a, long long b)
{
  return a>b?a:b;
}
long long min(long long a, long long b)
{
  return a<b?a:b;
}

long long getDoubleArea(long long xBe,long long yBe,
                        long long xEn,long long yEn,
                        long long x,long long y)
{
  return (xBe-x)*(yEn-y)-(xEn-x)*(yBe-y);
}

int getSign(long long a)
{
  if(a>0)
    return 1;
  if(a<0)
    return -1;
  return 0;

}

struct multigon
{
  vector<pair<long long, long long> > sides;
  long long maxX, minX, maxY, minY;
  multigon()
  {
    sides.clear();
  }
  bool read()
  {
    int n;
    cin >> n;
    if(n==0)
      return 0;
    sides.clear();
    sides.reserve(n);
    sides.push_back(make_pair(0,0));
    cin >> sides[0].first >> sides[0].second;
    maxX = sides[0].first;
    minX = sides[0].first;
    maxY = sides[0].second;
    minY = sides[0].second;
    for(int i = 1; i<n; i++)
    {
      sides.push_back(make_pair(0,0));
      cin >> sides[i].first >> sides[i].second;
      maxX = max(maxX, sides[i].first);
      maxY = max(maxY, sides[i].second);
      minX = min(minX, sides[i].first);
      minY = min(minY, sides[i].second);
    }
    sides.push_back(sides[0]);
    return 1;
  }
  bool isOnSides(long long x, long long y)
  {
    for(int i = 1; i<sides.size(); i++)
    {
      long long xBe = sides[i-1].first,
                xEn = sides[i].first,
                yBe = sides[i-1].second,
                yEn = sides[i].second;
      if(min(xBe, xEn)<=x&&x<=max(xBe,xEn)&&min(yBe, yEn)<=y&&y<=max(yBe,yEn))
      {
        if(!getDoubleArea(xBe, yBe, xEn, yEn, x, y))
        {
          return 1;
        }
      }
    }
    return 0;
  }
  bool isInside(long long x, long long y)
  {
    long long datInfX = 2000000007,datInfY = 200000008;
    int countOfIntersections = 0;
    for(int i = 1; i<sides.size(); i++)
    {
      long long xBe = sides[i-1].first,  xEn = sides[i].first,
                yBe = sides[i-1].second, yEn = sides[i].second;
      if(getSign(getDoubleArea(xBe, yBe, datInfX, datInfY, x, y))!=
         getSign(getDoubleArea(xEn, yEn, datInfX, datInfY, x, y))&&
         getSign(getDoubleArea(xBe, yBe, x,y, xEn, yEn))!=
         getSign(getDoubleArea(xBe, yBe, datInfX, datInfY, xEn, yEn)))
      {
        countOfIntersections++;
      }

    }
    return (countOfIntersections&1);
  }
  void solveWithTriangulate()
  {

  }
} myMultigon;

vector<pair<long long, long long> >answer;
int main()
{
  ios::sync_with_stdio(false);
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);
  while(myMultigon.read())
  {
    answer.clear();
    for(long long  x = myMultigon.minX; x<=myMultigon.maxX; x++)
      for(long long y = myMultigon.minY; y<=myMultigon.maxY; y++)
      {
        if(myMultigon.isOnSides(x,y)||myMultigon.isInside(x,y))
        {
          answer.push_back(make_pair(x,y));
        }
      }
    cout << answer.size() << '\n';
    for(int i  =0; i<answer.size(); i++)
    {
      cout << answer[i].first << ' ' << answer[i].second << '\n';
    }
    cout<< '\n';
  }


  return 0;
}
