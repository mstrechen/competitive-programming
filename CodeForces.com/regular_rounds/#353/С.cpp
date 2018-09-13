#include <iostream>
#include <map>

using namespace std;

map<long long, int> pref_s;

int a[100500];

int main(){
	ios::sync_with_stdio(false);

    int n;
    long long summ = 0;

    cin >>n;
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        summ+=a[i];
        pref_s[summ]++;
    }

    long long current = 0;
    int answer  = pref_s[0];

    for(int i = 0; i<n; i++)
        answer = max(answer, pref_s[current+=a[i]]);

    cout << n-answer;

    return 0;
}
