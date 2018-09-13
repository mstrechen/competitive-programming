#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	 cin >> n;
	 if(n %2 == 1)
	 {
		 cout << 0;
		 return 0;
	 }
	 cout << (n/4) - ( n%4==0 );
	
	return 0;
}