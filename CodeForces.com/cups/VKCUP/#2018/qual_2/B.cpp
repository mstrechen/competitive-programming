#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const int oo = 1000*1000*1000;
const int MAX_MASK = 1 << 10;

template<int t> 
int BIT(int n){
    return (n >> t) & 1;
}

template<int t>
char getPlaceChar(int p, int r, int n){
    if(BIT<t>(p))
            return 'S';
        else if(BIT<t>(r))
            return 'P';
        else if(BIT<t>(n))
            return 'x';
        else
            return '.';
}

int POPCOUNT(int n){
    return BIT<0>(n) + BIT<1>(n) + BIT<2>(n) +
           BIT<3>(n) + BIT<4>(n) + BIT<5>(n) +
           BIT<6>(n) + BIT<7>(n) + BIT<8>(n) + BIT<9>(n);
}


vector<pair<int, int> > places = 
{
    {0, 0},
    {1, 1},
    {2, 2},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 9},
    {8, 10},
    {9, 11}
};

struct dp{
    int n;
    vector<int> primes;
    vector<int> regular;

    vector<vector<int> > mem;

    dp(int n) 
        : n(n), 
          primes(n, 0),
          regular(n, 0),
          mem(n, vector<int>(n*10 + 1, -1)){
          }
    
    void readRows(istream & cin){
        string tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            for(auto & p : places)
                switch(tmp[p.second]){
                    case 'S' : primes[i] |= 1 << p.first; break;
                    case 'P' : regular[i] |= 1 << p.first; break; 
                }
        }
    }


    int calcPlaces(int p, int r){
        int ans = 0;
        r |= p;
        ans += (BIT<0>(p) & BIT<1>(r));
        ans += (BIT<1>(p) & BIT<0>(r));
        ans += (BIT<1>(p) & BIT<2>(r));
        ans += (BIT<2>(p) & BIT<1>(r));

        ans += (BIT<3>(p) & BIT<4>(r));
        ans += (BIT<4>(p) & BIT<3>(r));
        ans += (BIT<4>(p) & BIT<5>(r));
        ans += (BIT<5>(p) & BIT<4>(r));
        ans += (BIT<5>(p) & BIT<6>(r));
        ans += (BIT<6>(p) & BIT<5>(r));
        
        ans += (BIT<7>(p) & BIT<8>(r));
        ans += (BIT<8>(p) & BIT<7>(r));
        ans += (BIT<8>(p) & BIT<9>(r));
        ans += (BIT<9>(p) & BIT<8>(r));
        return ans;
    }

    int calc(int row, int passengers){
        if(passengers < 0)
            return +oo;
        if(row == -1){
            if(passengers > 0)
                return +oo;
            else
                return 0;
        }
        if(mem[row][passengers] != -1)
            return mem[row][passengers];

        int minAns = +oo;
        for(int mask = 0; mask < MAX_MASK; mask++)
        if((mask & (primes[row] | regular[row])) == 0){
            minAns = min(minAns, calc(row - 1, passengers - POPCOUNT(mask)) + 
                                 calcPlaces(primes[row], regular[row] | mask) );
            
        }
        
        return mem[row][passengers] = minAns;
    }
    void printRow(int p, int r, int n, ostream & out){
        out << getPlaceChar<0>(p, r, n)
            << getPlaceChar<1>(p, r, n)
            << getPlaceChar<2>(p, r, n)
            << '-'
            << getPlaceChar<3>(p, r, n)
            << getPlaceChar<4>(p, r, n)
            << getPlaceChar<5>(p, r, n)
            << getPlaceChar<6>(p, r, n)
            << '-'
            << getPlaceChar<7>(p, r, n)
            << getPlaceChar<8>(p, r, n)
            << getPlaceChar<9>(p, r, n);
        out << '\n';
    }
    void printAns(int row, int passengers, ostream & out){
        if(row == -1)
            return;

        for(int mask = 0; mask < MAX_MASK; mask++)
        if((mask & (primes[row] | regular[row])) == 0)
        if(calc(row - 1, passengers - POPCOUNT(mask)) + 
           calcPlaces(primes[row], regular[row] | mask)
           == mem[row][passengers]){
               printAns(row - 1, passengers - POPCOUNT(mask), out);
               printRow(primes[row], regular[row], mask, out);
               return;
           }

    }
};

int main(){
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    dp DP(n);
    DP.readRows(cin);

    cout << DP.calc(n - 1, p) << '\n';
    DP.printAns(n - 1, p, cout);

    return 0;
}