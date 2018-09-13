#include <iostream>
using namespace std;
int connections[1001][1001];
bool visited[1001];

int queue[1001];
int be=0,en=0;
int main(){
	for(int i=1;i<=1000;i++) connections[i][0]=0;
	for(int i=1;i<=1000;i++) visited[i]=0;
	ios::sync_with_stdio(false);
	int n,tmp,maxCount=0,currentCount,bestSchoolEver=0;
	
	cin >> n;
	for(int i=1; i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin >> tmp;
			if(tmp==1){
				connections[i][0]++;
				connections[i][connections[i][0]] = j;
			}
		}
	for(int i=1;i<=n&&maxCount<n-i+1;i++)
	{
		if(!visited[i])
		{
			en++;
			queue[be] = i;
			currentCount = 1;
			visited[i] = 1;
			while(en>be){
				for(int j=1; j<=connections[queue[be]][0];j++)
				{
					if(!visited[connections[queue[be]][j]]){
						
						queue[en]= connections[queue[be]][j];
						en++;
						currentCount++;
						visited[connections[queue[be]][j]] = 1;
					}
				}
				be++;
			}
		}
		if(currentCount>maxCount){
			maxCount = currentCount;
			bestSchoolEver = i;
		}
		
	}
	cout << maxCount << ' '<< bestSchoolEver;
	return 0;
}