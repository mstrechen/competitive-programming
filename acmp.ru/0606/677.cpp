#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream fout;
	ifstream fin;
	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out);
	int x,y,z;
	
	fin >> x >>y>>z;
	if(x+y<z||x+z<y||y+z<x){
		fout<< "NO";
	}
	else {
		fout << "YES";
	}
	return 0;
}
