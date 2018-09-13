#include <iostream>
#include <string>

using namespace std;


const int sizeOfRange = 200;
const int maxSize = 40000;

int plused[maxSize/sizeOfRange];
int updates[maxSize/sizeOfRange];
int mins[maxSize/sizeOfRange];
int summs[maxSize/sizeOfRange];

bool wasAdded[maxSize/sizeOfRange];

int arr[maxSize];

int main(){
	ios::sync_with_stdio(false);
	
	int n, m;
	
	cin >> n;
	for(int i = 0; i<n; i++)
		cin >> a[i];
	
	int rangesCount = n/sizeOfRange;
	
	for(int i = 0; i<rangesCount; i++)
	{
		int currMin = 100500;
		int currSumm = 0;
		for(int j = 0; j<sizeOfRange; j++)
		{
			currMin  = min(currMin, a[i*sizeOfRange+j]);
			currSumm += a[i*sizeOfRange+j];
		}
		mins[i] = currMin;
		summs[i] = currSumm;
	}
	
	cin >> m;
	
	string s;
	int x,y,a;
	
	for(int i = 0; i<m;i++)
	{
		cin >> s;
		if(s[0]=='g')
		{
			cin >> x;
			x--;
			if(wasUpdated[x/sizeOfRange])
				cout << updates[x/sizeOfRange]+plused[x/sizeOfRange];
			else
				cout << a[x]+plused[x/sizeOfRange];
		}
		else
		if(s[0]=='a')
		{
			
		}
	}
	
	
	return 0;
}