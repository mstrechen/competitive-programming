#include <iostream>

using namespace std;

long long max(long long a, long long b)
{
    return a>b?a:b;
}
long long make(long long a)
{
    long long maxRes = 0;
    long long curr = a/5;
    for(int i = 0; i<=10&&curr>=0; i++)
    {
        maxRes = max(maxRes, curr*9+((a-curr*5)/3)*5);
        curr--;
    }
    return maxRes;
}

int main(){
	ios::sync_with_stdio(false);
	long long robo3=0, robo2=0,robo1=0,roboNew;
	int k;
	cin >> roboNew >> k;
	for(int i = 1; i<k; i++)
	{
		robo3 = robo2;
		robo2 = robo1;
		robo1 = roboNew;
		roboNew = make(robo1+robo2+robo3);
	}
	cout << robo2+robo1+roboNew;
	return 0;
}
