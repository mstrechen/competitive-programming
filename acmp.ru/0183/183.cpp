#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int words, MOD;

	cin >> words >> MOD;

    vector<int> dyn(words*2+2, 0);
    dyn[2] = 1;

    for(int i = 0; i<words; i++)
    {
        dyn[i+1]+=dyn[i];
        dyn[i+1]%=MOD;
        dyn[i*2]+=dyn[i];
        dyn[i*2]%=MOD;
    }
    cout << dyn[words];

	return 0;
}
