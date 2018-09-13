#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,lastPoint,nextPoint, ansBe,ansEn;
	cin >> n;
	cin >> nextPoint;
	ansBe = -300000;
	ansEn = 300000;
	for(int i = 1; i<n;i++)
	{
		lastPoint = nextPoint;
		cin >>nextPoint;
		if(nextPoint-lastPoint<ansEn-ansBe)
		{
			ansBe = lastPoint;
			ansEn = nextPoint;
		}
	}
	cout << ansBe << ' ' << ansEn;
	return 0;
}