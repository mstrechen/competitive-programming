#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int curX = 0;

    for(int i = 0; i<n; i++)
    {
        string dir;
        int dX;

        cin >> dX >> dir;

        if((curX==0 && dir[0] != 'S') || (curX == 20000 && dir[0] != 'N'))
        {
            cout << "NO";
            return 0;
        }

        if(dir[0]=='S')
        {
            curX+=dX;
            if(curX>20000)
            {
                cout << "NO";
                return 0;
            }
        }
        else
        if(dir[0]=='N')
        {
            curX-=dX;
            if(curX<0)
            {
                cout << "NO";
                return 0;
            }
        }

    }
     if(curX!=0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES";

    return 0;
}
