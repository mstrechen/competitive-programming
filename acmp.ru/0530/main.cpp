#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> m >> n;
    
    vector<string> s1(n), s2(n);
    
    for(auto & i : s1)
	cin >> i;	
    for(auto & i : s2)
	cin >> i;
	
    string mask;
    cin >> mask;
    
    for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
	    s1[i][j] = mask[(s1[i][j] == '1')*2 + (s2[i][j] == '1') ];
    
    for(auto & i : s1)
	cout << i << '\n';
	
    
    return 0;
} 
