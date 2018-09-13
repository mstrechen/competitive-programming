#include <iostream>
#include <vector>



using namespace std;
int powEnds[10][5] = {{1,0,0,0,0},{1,1,0,0,0},{4,2,4,8,6},{4,3,9,7,1},{2,4,6,0,0},{1,5,0,0,0},{1,6,0,0,0},{4,7,9,3,1},{4,8,4,2,6},{2,9,1,0,0}};
int main(){
	ios::sync_with_stdio(false);
	int a,b;
	cin >> a >> b;
	a = a%10;
	b = (b-1)%(powEnds[a][0]) + 1;
	cout << powEnds[a][b];
	return 0;
}