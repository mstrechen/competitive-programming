#include<iostream>

using namespace std;

const char MOD = 101;

int field[100][100];

int dp1[100][100], 
    dp2[100][100];

	
int main(){
	ios::sync_with_stdio(false);
	int ** prev;
	prev = dp1;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> field[i][j];
	
	dp1[0][0] = field[0][0] == field[n-1][n-1];
	for(int diag = 1; diag < n; diag++){
		if(diag & 1){
			for(int x1 = 0; x1 < n; x1++)
				for(int x2 = 0; x2 < n; x2++){
					dp2[x1][x2] = 0;
					if(diag - x2 >= 0 && 
					   diag - x2 >= 0 && 
					   field[x1][diag - x1] == field[n-x2][n - diag + x2]){
						
					}else{
					}
					
				}
					
		}else{
		
		}
	}
	int res = 0;
	if(n & 1){
	}
	return 0;
}