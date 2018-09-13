#include <iostream>
//#include <ctime>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long answer = 0;
	int x,y,z,w;
	cin >> x >> y >> z >> w;
	//double be = clock();
	for(int i = w/x; i>=0;i--)
	{
		for(int j = (w-x*i)/y; j>=0; j--)
		{
			for(int k = (w-x*i-y*j)/z; k>=0; k--)
			{
				if(w==x*i+y*j+z*k)
				{
					answer++;
				}
			}
		}
	}
	//double en = clock();
	cout << answer;
	//cout << (en-be)/CLOCKS_PER_SEC;
	return 0;
}