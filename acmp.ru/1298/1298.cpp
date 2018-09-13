#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> inputArray(n), answer(n, 0), prev(n, -1);
    answer[0] = 1;
    
    for(auto& i : inputArray) cin >> i;
    
    int maxAnsI = 0;
    
    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
            if(inputArray[i] > inputArray[j] && answer[j]>answer[i])
            {
                answer[i] = answer[j];
                prev[i] = j;
            }
            answer[i]++;
        if(answer[i]>answer[maxAnsI])
            maxAnsI = i;
    }
    
    vector<int> res;
    
    
    for(int i = maxAnsI; i!=-1; i = prev[i])
    {
        res.push_back(inputArray[i]);
    }
    cout << res.size() << '\n';
    
    for(auto it = res.rbegin(); it!=res.rend(); it++)
        cout << *it << ' ';
    
	
	return 0;
}