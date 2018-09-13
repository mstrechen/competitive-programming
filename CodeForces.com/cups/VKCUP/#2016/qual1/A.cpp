#include <iostream>

using namespace std;

int countOfLikes[1000001];

int main(){
	ios::sync_with_stdio(false);
	int mostLiked = 0, currentLike, n;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> currentLike;
		if(++countOfLikes[currentLike]>countOfLikes[mostLiked])
		{
			mostLiked = currentLike;
		}
	}
	cout << mostLiked;
	
	return 0;
}