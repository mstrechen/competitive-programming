#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000*1000*1000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    cin >> x;

    vector<int> lowest_prev(x + 1, INF);
    for(int i = 3; i <= x; i++){
        bool prime = 1;
        for(int j = 2; j * j <= i; j++)
            if(i % j == 0){
                prime = 0;
                break;
            }
        lowest_prev[i] = INF;
        if(prime)
            continue;
        lowest_prev[i] = i;

        int tmp = i;  
        for(int j = 2; j*j <= tmp; j++)
            if(tmp % j == 0){
                lowest_prev[i] = i - j + 1;
                while(tmp % j == 0)
                    tmp /= j;
            }
        if(tmp != 1)
            lowest_prev[i] = i - tmp + 1;
    }   
    int tmp = x;
    int max_prime = 0;
    for(int i = 2; i * i <= x; i++)
        if(tmp % i == 0){
            max_prime = i;
            while(tmp % i == 0)
                tmp /= i;
        }
    if(tmp != 1)
        max_prime = tmp;
    
    cout << *min_element(lowest_prev.begin() + x - max_prime + 1, lowest_prev.end());



    return 0;
}