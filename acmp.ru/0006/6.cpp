#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main(){
	ofstream ofl;
	ifstream ifl;
	string lol;
	
	
	ifl.open("input.txt",ios::in);
	getline(ifl, lol);
	ifl.close();
	ofl.open("output.txt",ios::out);
	
	if(lol[0]>='A'&&lol[0]<='H'&&lol[1]>='1'&&lol[1]<='8'&&lol[3]>='A'&&lol[3]<='H'&&lol[4]>='1'&&lol[4]<='8'&&lol[2]=='-'){
		if(abs(int(lol[0])-int(lol[3]))*abs(int(lol[1])-int(lol[4]))==2&&abs(int(lol[0])-int(lol[3]))+abs(int(lol[1])-int(lol[4])==3)){
			ofl << "YES";
		}
		else{
			ofl << "NO";
		}
	}
	else ofl << "ERROR";
	ofl.close();
	return 0;
}
