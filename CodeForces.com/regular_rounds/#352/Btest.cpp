#include <iostream>
#include <string>
#include <ctime>

using namespace std;
string s;
int main(){
    ios::sync_with_stdio(false);
    int n, answer = 0;
    char c;
    double be = clock();
    cin >> n;
    cin >> s;
    double en = clock();
    cout << (be-en)/CLOCKS_PER_SEC;
	return 0;
}
