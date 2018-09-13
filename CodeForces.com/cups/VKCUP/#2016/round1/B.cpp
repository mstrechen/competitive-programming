#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    int n,d,h;
    cin >> n >> d >> h;
    if(d==1||d>h*2)
    {
        if(n==2)
        {
            cout << 1 << ' ' << 2;
        }
        else
        {
            cout << -1;
        }
    }
    else
    {
        if(d==h)
        {
            if(h==n-1)
            for(int i = 1; i<n; i++)
            {
                cout << i << ' ' << i+1 << '\n';
            }
            else
            {
                for(int i = 1; i<=h; i++)
                {
                    cout << i << ' ' << i+1 << '\n';
                }
                for(int i = h+1; i<n; i++)
                {
                    cout << 2 << ' ' << i+1 << '\n';
                }
            }


        }
        else
        {
            for(int i = 2; i<=n; i++)
            {
                if(i<h+2)
                {
                    cout << i-1 << ' ' << i << '\n';
                }
                else
                if(i>h+2&&i<d+2)
                {
                    cout << i-1 << ' ' << i << '\n';
                }
                else
                {
                    cout << 1 << ' ' << i << '\n';
                }
            }
        }
    }
	return 0;
}
