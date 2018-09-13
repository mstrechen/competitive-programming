#include<stdio.h>
#include<ctime>
#include<vector>
#include<assert.h>

using namespace std;

struct ixy
{
	int i,x,y;
	ixy(int i,int x, int y):i(i),x(x),y(y)
	{}
};
vector<ixy> q[300][300];


int a[300][300], tmp[300][300];

int answers[100500];



void getAnswers(int _i, int _j, int n, int m)
{
	tmp[_i][_j] = a[_i][_j];

	for(int j = _j+1; j<m; j++)
		tmp[_i][j] = min(tmp[_i][j-1], a[_i][j]);

	for(int i = _i+1; i<n; i++)
	{
		tmp[i][_j] = min(tmp[i-1][_j],a[i][_j]);

		for(int j = _j+1; j<m; j++)
			tmp[i][j] = min(min(tmp[i][j-1],tmp[i-1][j]), a[i][j]);
	}
	for(int i = 0; i<q[_i][_j].size(); i++)
	{
		answers[q[_i][_j][i].i] = tmp[q[_i][_j][i].x][q[_i][_j][i].y];
	}
}


int main()
{
    int n, m, k;

	scanf("%d%d%d",&n,&m,&k);


	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			scanf("%d", &a[i][j]);

	int tmpX1,tmpY1,tmpX2,tmpY2;

	for(int i = 0; i<k; i++)
    {
        scanf("%d%d%d%d", &tmpX1,&tmpY1,&tmpX2,&tmpY2);
        q[tmpX1-1][tmpY1-1].push_back(ixy(i,tmpX2-1,tmpY2-1));
    }

    int counter = 0;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
		{
			if(!q[i][j].empty())
			{
				getAnswers(i,j, n, m);
                counter++;
			}

		}
    assert(counter<=4811||(n==100&&m==100));
	for(int i = 0; i<k; i++)
		printf("%d\n",answers[i]);


    return 0;
}
