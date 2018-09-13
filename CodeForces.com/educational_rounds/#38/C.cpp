#include<iostream>
#include<cmath>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long x;
        cin >> x;
        if(x == 0){
            cout << "1 1\n";
        } else {
            long long b = -1, a = floor(sqrt(x));
            for(; a*a - (a/2)*(a/2) <= x; a++, b = -1){
                
                long long r = a*a - x;
                if(r <= 0 || r != ((long long)sqrt(r))*((long long)sqrt(r)))
                    continue;
                r = sqrt(r);
                b = a/r;
                if(a*a - (a/b)*(a/b) == x){
                    
                    break;
                } else {
                    b = -1;
                }
            }
            if(b == -1)
                cout << -1 << '\n';
            else
                cout << a << ' ' << b << '\n';

        }
    }
    

    return 0;
}