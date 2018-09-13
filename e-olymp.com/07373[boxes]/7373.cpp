#include <iostream>
#include <algorithm>
using namespace std;

int boxesPack[1000005];
int boxes[102];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> boxes[i];
	}
	sort(boxes,boxes+n);
	return 0;
}