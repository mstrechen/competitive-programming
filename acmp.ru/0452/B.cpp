#include <iostream>
#include <string>

using namespace std;
int number[1000];
int main(){
	ios::sync_with_stdio(false);
	
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0; i<s1.length(); i++)
	{
		number[s1.length()-i-1]+=s1[i]-'0';
	}
	for(int i = 0; i<s2.length(); i++)
	{
		number[s2.length()-i-1]+=s2[i]-'0';
	}
	
	for(int i = 0; i<400;)
	{
		if(i==0&&number[0]>1)
		{
			number[0]-=2;
			number[1]++;
			continue;
		}
		if(i==1&&number[1]>1)
		{
			number[1]-=2;
			number[0]++;
			number[2]++;
			i--;
			continue;
		}
		if(number[i]>1)
		{
			number[i]-=2;
			number[i-2]++;
			number[i+1]++;
			i-=2;
			continue;
		}
		if(i>0&&number[i-1]&&number[i])
		{
			number[i-1]--;
			number[i]--;
			number[i+1]++;
			continue;
		}
		
		i++;
	}
	
	int wasChanged = 0;
	for(int i = 500; i>=0; i--)
	{
		if(wasChanged) cout << number[i];
		if(!wasChanged&&number[i])
		{
			cout << number[i];
			wasChanged = 1;
		}
	}
	
	return 0;
}