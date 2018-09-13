#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	
	int n,toDivise=9,i,max5 = 0,max2 = 0;
	
	cin >> n;
	
	while(n % 5 == 0 && n > 0)
			{
				n/=5; 
				max5++;
			}
	while(n % 2 == 0 && n > 0)
	{
		n/=2;
		max2++;
	}
	for(i=1;toDivise % n > 0;i++)
	{
		toDivise = toDivise % n; 
		toDivise*= 10;
		toDivise+=9;
	}
	cout << max(max2,max5) << ' ' << i;
	 
return 0;
}