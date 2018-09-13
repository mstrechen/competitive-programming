#include <iostream>
#include <map>

using namespace std;

struct link
{
    int left, right, current;
    link(int c = 0, int a = 0, int b = 0):left(a), right(b), current(c);
} a[100500];

map<int, int> way;
int answer[100500];

int main(){
	ios::sync_with_stdio(false);
    int n,tmp;
    cin >> n;
    cin >> tmp;
    way.insert({0, tmp});

    for(int i = 1; i<n; i++)
    {

    };
    for(int i = 1; i<n; i++)
        cout << answer[i];

	return 0;
}
