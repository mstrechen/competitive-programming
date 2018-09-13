#include<iostream>

using namespace std;
int n,maxx=1000500,cl=-1,cr,lh,h,l,r;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> lh;
    for (int i=1;i<n;i++)
    {
        cin >> h;
        if (h>lh)
        {
            cl=i-1;
        }
        if (h<lh)
        {
            cr=i;
            if (cl!=-1)
            {
                if (cr-cl<maxx)
                {
                    maxx=cr-cl;
                    l=cl;
                    r=cr;
                }
            }
        }
        lh=h;
    }
    if (maxx==1000500)
    {
        cout << "0";
        return 0;
    }
    cout << l+1 << " " << r+1;
    return 0;
}
