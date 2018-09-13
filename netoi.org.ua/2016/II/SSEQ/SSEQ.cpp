#include<iostream>

using namespace std;

int main()
{
    
    cout << int(0.99) << endl;
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	long long tmp;
	int sizeOfSeq[3] = {0,0,0};

	cin >> n >> t;

	for(int i = 0; i<n; i++)
	{
		cin >> tmp;
		if(tmp==t+1)
			sizeOfSeq[2]++;
		if(tmp==t)
		{
			if(sizeOfSeq[2]>0)
				sizeOfSeq[2]--;
			sizeOfSeq[1]++;
		}
		if(tmp==t-1)
		{
			if(sizeOfSeq[1]>0)
			{
				sizeOfSeq[1]--;
			}
			else
			if(sizeOfSeq[2]>0)
			{
				sizeOfSeq[2]--;
			}
			sizeOfSeq[0]++;
		}
	}
	cout << sizeOfSeq[0]+sizeOfSeq[1]+sizeOfSeq[2];
	return 0;
}
