#include <stdio>
#include <algorithm>
using namespace std;
 
pair<int,int> a[300000];
int valueOfAnswer[100000];

void getInt(int & a)
{
	a = 0;
	char c;
	getc
}
int main(){
    int n,m;
    int tmp1, tmp2;
	cin >> n >> m;
	
    int n2 = n*2;
     
    for(int i = 0; i<n2; i++)
    {
        cin >> tmp1 >> tmp2;
        if(tmp1>tmp2) 
            swap(tmp1,tmp2);
        a[i].first = tmp1;
        a[i++].second = -1;
        a[i].first = tmp2;
        a[i].second = 100500;
    }
    for(int i = 0; i<m; i++)
    {
        cin >> a[n2+i].first;
        a[n2+i].second = i;
    }
    int n2m = n2+m;
    sort(a, a+n2m);
    int t = 0;
    for(int i = 0; i<n2m; i++)
    {
        if((a[i].second^100500)&&!(a[i].second&0x8000000))
            valueOfAnswer[a[i].second]  = t;
        else
        {
            if(a[i].second==-1)
                t++;
            else
                t--;
        }
    }
    for(int i = 0; i<m; i++)
        cout << valueOfAnswer[i] << ' ';
     
    return 0;
}