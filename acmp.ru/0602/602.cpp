#include <iostream>

using namespace std;
int points[10001];

int main(){
	ios::sync_with_stdio(false);
	int n, ansBe=0,ansEn=1;
	cin >> n;
	for(int i = 0; i<n;i++)
	{
		cin >> points[i];
	}
	for(int i = 0; i+1<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if((ansEn-ansBe)*(points[j]-points[i])<(points[ansEn]-points[ansBe])*(j-i))
			{
				ansBe = i;
				ansEn = j;
			}
		}
	}
	cout << points[ansBe] << ' ' << points[ansEn];
	return 0;
}