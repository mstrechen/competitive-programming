#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct point{
    double x, y;

    point(const double & x = 0, const double & y = 0) : x(x), y(y){}

    double len(){
        return sqrt(x * x + y * y);
    }
};

bool OK_EPS(double x){
    return abs(x) < 1e-4;
}
const point ANY_POINT = point(0.0, NAN);
const point NO_POINT = point(NAN, NAN);

bool operator == (const point & a, const point & b){
    if(a.x == 0 && a.y != a.y)
        return 1;
    if(b.x == 0 && b.y != b.y)
        return 1;
    
    return OK_EPS(a.x - b.x) && OK_EPS(a.y - b.y);
}

point operator + (const point & a, const point & b){
    return {a.x + b.x, a.y + b.y};
}
point operator - (const point & a, const point & b){
    return {a.x - b.x, a.y - b.y};
}
point operator * (const point & a, double k){
    return {a.x * k, a.y * k};
}
point operator / (const point & a, double k){
    return {a.x / k, a.y / k};
}


istream & operator >> (istream & in, point & to_read){
    in >> to_read.x >> to_read.y;
    return in;
}
ostream & operator << (ostream & out, point & to_write){
    out << to_write.x << ' ' << to_write.y;
    return out;
} 

struct polygon{
    int size;
    vector<point> points;

    point get_incenter(){
        vector<pair<point, point > > bisectors;
        for(int i = 1; i <= size; i++){
            auto v1 = points[i - 1] - points[i % size],
                 v2 = points[(i + 1) % size] - points[i % size];
            v1 = v1 / v1.len();
            v2 = v2 / v2.len();
            bisectors.emplace_back(points[i % size], points[i % size] +  v1 + v2);
        }
        point res = intersect_point(bisectors[0].first, bisectors[0].second,
                                    bisectors[1].first, bisectors[1].second);
        
        for(int i = 0; i < bisectors.size(); i++)
        for(int j = i + 1; j < bisectors.size(); j++){
            auto candidate = intersect_point(bisectors[i].first, bisectors[i].second,
                                        bisectors[j].first, bisectors[j].second);
            if(!(candidate == res))
                return NO_POINT;
        }
            
        return res;
    }

    point intersect_point(const point & a_1, const point & a_2,
                          const point & b_1, const point & b_2){
        double divisor = (a_1.x - a_2.x) * (b_1.y - b_2.y) - (a_1.y - a_2.y)*(b_1.x - b_2.x);
        point p = {(a_1.x*a_2.y - a_1.y*a_2.x)*(b_1.x - b_2.x) 
                 - (a_1.x - a_2.x)*(b_1.x*b_2.y - b_1.y*b_2.x),

                    (a_1.x*a_2.y - a_1.y*a_2.x)*(b_1.y - b_2.y) 
                 - (a_1.y - a_2.y)*(b_1.x*b_2.y - b_1.y*b_2.x)};
        
        if(divisor == 0){
            if(p.x != 0 && p.y != 0)
                return NO_POINT;
            else
                return ANY_POINT;
        }
        return p/divisor;
    }

    double get_radius(const point & p){
        auto delta = points[1] - points[0];
        swap(delta.x, delta.y);
        delta.x *= -1;
        double ans = (intersect_point(p, p + delta, points[0], points[1]) - p).len();
        
        return ans;
    }
};

istream & operator >> (istream & in, polygon & to_read){
    in >> to_read.size;
    to_read.points.resize(to_read.size);
    for(auto & i : to_read.points)
        in >> i;
    return in;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    polygon P;
    cin >> P;
    auto incenter = P.get_incenter();
    if(incenter.x == incenter.x && 
       incenter.y == incenter.y){
        cout << "YES\n";
        cout.precision(3);
        cout << fixed;
        if(incenter.x == 0)
            incenter.x = 0;
        if(incenter.y == 0)
            incenter.y = 0;
    
        

        cout << incenter.x + 1e-5 << ' ' << incenter.y + 1e-5 << ' ' << P.get_radius(incenter) + 1e-5;
    } else {
        cout << "NO";
    } 

    return 0;
}