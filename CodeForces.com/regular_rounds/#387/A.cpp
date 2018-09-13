#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int minA = 1;

	for(int i = 2; i*i<=n; i++)
        if(n%i==0)
            minA = i;

    cout << minA << ' ' << n/minA;
	return 0;
}
