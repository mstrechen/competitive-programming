#include<iostream>

using namespace std;

int main(){
    long long i,n, w1,w2,h1,h2, mx;
    bool f=false;
    cin>>n;
    cin>>w1>>h1;
    mx=max(w1,h1);
    long long sum=w1+h1;
    w1=sum-mx;
    h1=sum-w1;
    for (i=1;i<n;i++)
    {
        cin>>w2>>h2;
        
        if (h1>=w2 && f!=true)
        {
            mx=w2;
        }
        else if (h1>=h2 && f!=true)
        {
            if (h2>w2) mx=h2;
                else mx=w2;
        }
        else if (h1<w2 && h1<h2)
        {
            f=true;
            mx=max(w2, h2);
        }
        sum=w2+h2;
        w1=sum-mx;
        h1=sum-w1;
        
        cout << h1 << ' ' << w1 << endl;
    }
    if(f==true) cout<<"NO";
    else cout<<"YES";
    return 0;
 }