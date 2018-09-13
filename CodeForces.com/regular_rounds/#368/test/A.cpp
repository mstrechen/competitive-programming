#include<iostream>

using namespace std;


long long n,m,k,s=2, p[100500], cop, copp, s2=3,ss;
int main()
{
    for(int i = 0; i<100500; i++)
        p[i]=i*i;
    cin>> n;
    copp = n;
    n*=n;
    cop = n;
    for(long long i = 1; i*i<=cop; i++)
    {
        if(n%i==0 &&n/i>1&&(n/i)%2==1)
        {
            cout << i << endl;
            n/=i;
            n--;
            m = n/2;
            k = m+i;
            cout << m << ' ' << k;
            return 0;
        }
        n-=s;
        s+=2;
    }
}
