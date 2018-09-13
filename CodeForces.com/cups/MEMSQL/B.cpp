#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = sqrt(n);
    cout << (ans + ((n - 1)/ans + 1))*2;

    return 0;
}
