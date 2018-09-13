#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	int dividend, divider;
	scanf("%d%*c%d",&dividend, &divider);
	cout << dividend/divider;
	
	dividend = dividend%divider;
	if(dividend>0){
		
		cout<<'.';
		
		int i=2,max5 = 0,max2 = 0, tmp = 1, lengthOf9=1, just9=9;
		while(i<=dividend)
		{
			if(dividend % i == 0 && divider % i == 0){dividend/=i; divider/=i;}
			else i++;
		}
			
		while(divider % 5 == 0)
			{
				divider/= 5; 
				max5++;
				tmp*= 5;
			}
		while(divider % 2 == 0)
		{
			divider/= 2;
			max2++;
			tmp*= 2;
		}
		if(divider>1)
		{	
			while(just9 % divider>0)
			{
				lengthOf9++;
				just9 = just9 % divider; 
				just9*=10;
				just9+=9;
			}
			divider*=tmp;
			for(int i=max(max2,max5); i>0; i--)
			{
				dividend*=10;
				cout<<dividend/divider;
				dividend = dividend % divider;
			}
			cout << '(';
			for(int i = lengthOf9;i>0;i--){
				dividend*=10;
				cout<<dividend/divider;
				dividend = dividend % divider;
			}
			cout << ')';
		}
		else
			for(int i = max(max2,max5);i>0;i--){
				dividend*=10;
				cout<<dividend/tmp;
				dividend = dividend % tmp;
			}
		
	}
	
return 0;
}