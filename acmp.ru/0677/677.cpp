#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream fout;
	ifstream fin;
	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out);
	int k,m,n,s,d;
	
	fin >> k >>m>>n>>d;
	if((k*m*n<=m*n+k*n+k*m)||((k*m*n*d)%(k*m*n-m*n-k*n-k*m))){
		fout << -1;
		
	}
	else{
		int ans=(k*m*n*d)/(k*m*n-m*n-k*n-k*m);
		if(ans%k+ans%n+ans%m==0) fout << ans;
		else fout << -1;
	}
	
	return 0;
}
