#include<iostream>
using namespace std;

int main()
{
 long long x,n, a[100000],b[100000], a1[100001]={0}, b1[100001]={0}, i;
 cin>>n>>x;
 for (i=0;i<n;i++)
 {
  cin>>a[i];
 
 }
 
 
  for (i=0; i<n; i++)
  {
   b[i]=a[i]&x;
  }
  for (i=0;i<n;i++)
  {
   a1[a[i]]++;
   b1[b[i]]++;
  }
 i=0;
  while(i<100001)
  {
   if (a1[i]>1) 
   {
    cout<<"0";
    i=100000;
    return 0;
   }
   i++;
  }
   for(int i =0; i <= 100000; i++)
    if(a1[i] > 0 && b1[i] > 0 && b1[i] > a1[i]){
        cout << 1;
        return 0;
    }
     i=0;
  while(i<100001)
  {
   if (b1[i]>1) 
   {
    cout<<"2";
    i=100000;
    return 0;
   }
   i++;
  }
  cout<<"-1";
}