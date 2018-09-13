#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int main(){
	ifstream f;
	ofstream f1;
	int n,summ=0,maximal;
	
	
	f.open("INPUT.TXT", ios::in);
	f1.open("OUTPUT.TXT", ios::out);
	
	f >> n;
	
	int a[n];
	for(int i=0; i<n; i++){
		f >> a[i];
	}
	f >> maximal;
	f.close();
	for(int i=0; i<n; i++){
		summ+=min(a[i],maximal);
	}	
	f1 << summ;
	f1.close();
	return 0;
}
