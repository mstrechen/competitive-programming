//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//???????????????????????????????
#include <iostream>
#include <string>
using namespace std;

bool nums[10][10] = {};
bool numWas[10] = {};

int main(){
	ios::sync_with_stdio(false);
	string tmpS;
	cin >> tmpS;
	int answer = 0;
	if(tmpS.length()<3)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i<tmpS.length();i++)
	{
		for(int j = 0; j<10; j++)
		{
			nums[j][(int)(tmpS[i]-'0')] = numWas[j];
		}
		numWas[(int)(tmpS[i]-'0')] = true;
	}
	for(int i = 1; i<10;i++)
	{
		for(int j = 0; j<10; j++)
		{
			if(nums[i][j])
			{
				for(int k = 0; k<10; k++)
				{
					answer+=nums[i][k];
				}
			}
		}
	}
	cout << answer;
	return 0;
}