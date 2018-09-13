#include<iostream>
#include<string>

using namespace std;
const int MOD = 1000*1000 + 7;
int dp[1000][1000];


int main(){
	string s;
	cin >> s;
	dp[0][0] = 1;
	
	for(int i = 1; i <= (int) s.size(); i++){
		for(int j = 0; j <= i; j++)
			dp[i][j] = dp[i-1][j];
		if(s[i-1] == '('){
			for(int j = 0; j <= i; j++){
				dp[i][j+1] += dp[i-1][j];
				dp[i][j+1] %= MOD;
			}
		}
		else if(s[i-1] == ')'){
			for(int j = 0; j <= i; j++){
				dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
		}
		else{
			for(int j = 1; j <= i; j++){
				dp[i][0] += dp[i-1][j];
				dp[i][0] %= MOD;
			}
		}
	}
	cout << dp[s.size()][0];
	return 0;
}