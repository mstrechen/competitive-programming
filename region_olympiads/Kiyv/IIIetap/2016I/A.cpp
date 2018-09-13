#include <iostream>
using namespace std;

int primeDividers[20], listOfPowers[20];
int placeOfDividers[50000];

bool check(__int64 a, __int64 b, __int64 c)
{
	return (a*b%c==0)&&(a*c%b==0)&&(c*b%a==0)&&(a!=b)&&(b!=c)&&(c!=a);
}
int countOfVariants=0,alterN,alterM;

void bust(__int64 composition, int step, int maxStep)
{
	if(step!=maxStep)
	{
		for(int i = 0; i<=listOfPowers[step]; i++)
		{
			bust(composition, step+1, maxStep);
			composition*=primeDividers[step];
		}
	}
	else
	{
		for(int i = 0; i<=listOfPowers[step]; i++)
		{
			countOfVariants+=check(alterM,alterN,composition);
			composition*=primeDividers[step];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n,m,count=0;
	
	cin >> n >> m;
	alterM = m;
	alterN = n;
	
	for(int i = 2; i<=n;)
	{
		if(n%i==0)
		{
			n/=i;
			if(placeOfDividers[i]==0)
			{
				count++;
				primeDividers[count] = i;
				listOfPowers[count] = 1;
				placeOfDividers[i] = count;
			}
			else
			{
				listOfPowers[placeOfDividers[i]]++;
			}
		}
		else
		{
			i++;
		}
	}
	
	for(int i = 2; i<=m;)
	{
		if(m%i==0)
		{
			m/=i;
			if(placeOfDividers[i]==0)
			{
				count++;
				primeDividers[count] = i;
				listOfPowers[count] = 1;
				placeOfDividers[i] = count;
			}
			else
			{
				listOfPowers[placeOfDividers[i]]++;
			}
		}
		else
		{
			i++;
		}
	}
	bust(1,1,count);
	cout << countOfVariants;
	return 0;
}