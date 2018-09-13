#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> inp(n);
    
    for(auto& i : inp) cin >> i;
    
    sort(inp.begin(), inp.end());
    
    long long currSumm = 0;
    long long currMinimal = 1;
    for(auto i : inp)
    {
        if(i>currMinimal)
        {
            cout << currMinimal;
            return 0;
        }
        else
        {
            currSumm+=i;
            currMinimal = currSumm+1;
            
        }
    }
    
    cout << currMinimal;
    
    
    
	
	return 0;
}