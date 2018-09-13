#include <stdio.h>
#include <set>
#include <vector>

using namespace std;



int main(){
	
	int n, k, m;
	int tmpBe, tmpEn;
	
	scanf("%d%d%d", &n,&k,&m);
	
	vector<int> a(n-1, k);
	set<int> zeros;
	
	for(int i = 0; i<m; i++)
	{
		scanf("%d%d", &tmpBe, &tmpEn);
		
		if(zeros.lower_bound(tmpBe)==zeros.end()||*zeros.lower_bound(tmpBe)>=tmpEn)
		{
			printf("Yes\n");
			for(int i = tmpBe; i<tmpEn; i++)
			{
				a[i]--;
				if(!a[i])
					zeros.insert(i);
			}
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}