#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n, a[100], maxIndex=0, minIndex=0,multiple=1, summ=0;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin  >> a[i];
		if(a[i]>0) summ+=a[i];
		if(a[maxIndex]<a[i]){
			maxIndex = i;
		}
		if(a[minIndex]>a[i]){
			minIndex = i;
		}
	}
	if(minIndex>maxIndex)
	{
		swap(minIndex,maxIndex);
	}
	for(int i = minIndex+1; i<maxIndex; i++){
		multiple*=a[i];
	}
	cout << summ << ' '<< multiple;
	return 0;
}