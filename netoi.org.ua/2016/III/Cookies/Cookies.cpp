#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;

const int MAXN = 105;

const float PI = float(acos(-1));
const float PI2 = 2*PI;

const float EPS = float(1e-7);
const float EPS_CALC = float(1e-4);



inline float sqr(float a)
{
    return a*a;
}

struct arc
{
    float l,r;
    arc(float l = 0, float r = 0) : l(l), r(r){}
};

ostream & operator << (ostream & out, const arc & toWrite)
{
    out << toWrite.l << ' ' << toWrite.r;
    return out;
}

bool operator < (const arc & l, const arc & r)
{
    return l.l < r.l;
}

bool operator != (const arc & l, const arc & r)
{
    return (l.l!=r.l) || (l.r!=r.r);
}
bool operator == (const arc & l, const arc & r)
{
    return (l.l==r.l) && (l.r==r.r);
}

const arc NO_ANSWER = arc(0,0);
const arc ALL_IS_DENIED = arc(0,PI2 + EPS);



struct circle
{
    float r;
    float x,y;

    circle(float r = 0, float x = 0, float y = 0) : r(r), x(x), y(y){}

    arc intersect(float A, float B, float C)
    {
        float x0 = -A*C/(sqr(A)+sqr(B)),  y0 = -B*C/(sqr(A)+sqr(B) );
        float D = r*r - sqr(C)/(sqr(A)+sqr(B));

        float  mult = sqrt (D / (sqr(A)+sqr(B)));
        float  ax,ay,bx,by;
        ax = x0 + B * mult;
        bx = x0 - B * mult;
        ay = y0 - A * mult;
        by = y0 + A * mult;

        float angleA = atan2(ax, ay) + PI;
        float angleB = atan2(bx, by) + PI;

        if(angleA > angleB)
            swap(angleA, angleB);

        return arc(angleA, angleB);
    }

    arc intersect(circle toCross) // returns denied arc if toCross  IS NOT allowed to fill
    {
        toCross.x-=x;
        toCross.y-=y;

        if( sqrt(sqr(toCross.x) + sqr(toCross.y)) - EPS >= toCross.r + r)   //circles dont intesect
            return NO_ANSWER;

        arc tmp = intersect(-2*toCross.x, -2*toCross.y, sqr(toCross.x)+ sqr(toCross.y) + sqr(r) -  sqr(toCross.r));

        float angle = atan2(toCross.x, toCross.y) + PI;

        if(angle < tmp.l || angle > tmp.r)
        {
            tmp.l+=PI2;
            swap(tmp.l, tmp.r);
        }

        return tmp;
    }

    arc intersectHull(circle toCross) //returns denied arc if "toCross" IS allowed to fill
    {
        toCross.x-=x;
        toCross.y-=y;

        if(sqrt(sqr(toCross.x) + sqr(toCross.y)) - EPS <= r - toCross.r ||        //circles dont intersect, hull is inside _this_ circle
           sqrt(sqr(toCross.x) + sqr(toCross.y)) + EPS >= r + toCross.r)          // circles dont intersect, hull is beyond _this_ circle
            return ALL_IS_DENIED;

        if(sqrt(sqr(toCross.x) + sqr(toCross.y) + EPS) <= toCross.r - r)    // circles dont intersect, _this_ circle is inside hull
            return NO_ANSWER;

        arc tmp = intersect(-2*toCross.x, -2*toCross.y, sqr(toCross.x) + sqr(toCross.y) + sqr(r) -  sqr(toCross.r));

        float angle = atan2(toCross.x, toCross.y) + PI;

        if( tmp.l < angle && angle < tmp.r)
        {
            tmp.l+=PI2;
            swap(tmp.l, tmp.r);
        }

        return tmp;
    }
};


istream & operator >> (istream & in, circle & toRead)
{
    in >> toRead.x >> toRead.y >> toRead.r;
    return in;
}

arc buffer[MAXN];
circle savedCuted[MAXN], cuted[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    circle mainCircle;
    int n;
    double R;

    cin >> R;
    cin >> n;

    for(int i = 0; i<n; i++)
        cin >> savedCuted[i];

    for(int i = 0; i<n; i++)
        cuted[i] = savedCuted[i];



    float l = 0, r = R;      // for binary search

    int iterations = 100;
    while(l<r-EPS_CALC && iterations-->0)
    {
        float mid = (l+r)/2;

        for(int i = 0; i<n; i++)
            cuted[i].r = savedCuted[i].r + mid;
        mainCircle.r = R - mid;

        bool cantFind = 1;


        for(int i = 0; i<n && cantFind; i++)
        {
            int len = 0;
            arc tmp = cuted[i].intersectHull(mainCircle);

            if(tmp == ALL_IS_DENIED)
            {
                continue;
            }

            if(tmp!=NO_ANSWER)
            {
                buffer[len++] = tmp;
            }

            for(int j = 0; j<n; j++)
                if(j!=i)
                {
                    tmp = cuted[i].intersect(cuted[j]);
                    if(tmp!=NO_ANSWER)
                    {
                        buffer[len++] = tmp;
                    }
                }

            sort(buffer, buffer+len);


            float possibleStart = -EPS;
            for(int j = 0; j<len; j++)
                possibleStart = max(possibleStart, buffer[j].r);
            possibleStart-=PI2;


            if(len==0)
                cantFind = 0;
            else
            {
                float currentR = buffer[0].r;
                for(int j = 1; j<len && cantFind; j++)
                {
                    if(currentR<buffer[j].l && possibleStart<buffer[j].l)
                        cantFind = 0;

                    currentR = max(currentR, buffer[j].r);
                }

                if(cantFind)
                {
                    cantFind = (currentR - PI2 >= buffer[0].l);
                }
            }

        }

        if(cantFind)
            r = mid;
        else
            l = mid;

    }
    cout.precision(10);

    cout << (fixed) << l;

    return 0;
}
