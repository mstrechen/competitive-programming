#include <iostream>
#include <string>
using namespace std;
	string a,b;
bool compareStrings(int aP, int bP)
{
	if(aP>=a.size()){return false;}
	else if(bP>=b.size()){return true;}
	else if(a[aP]!=b[bP]){return a[aP]<b[bP];}
	else return compareStrings(aP+1, bP+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int i=0,j=0;
	for(;i<a.size()||j<b.size();)
	{
		if(compareStrings(i,j))
		{
			cout << a[i];
			i++;
			
		}
		else
		{
			cout << b[j];
			j++;
		}
	}
	
	return 0;
}