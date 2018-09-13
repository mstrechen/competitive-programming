#include<iostream>

using namespace std;
int x,y,x1,y1,x2,y2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if (x>=x1)
    {
        if (x<=x2)
        {
            if (y>=y2)
            {
                cout << "N";
            }
            else
            {
                cout << "S";
            }
            return 0;
        }
        if (y<=y2 && y>=y1)
        {
            cout << "E";
            return 0;
        }
        if (y>=y2)
        {
            cout << "NE";
        }
        else
        {
            cout << "SE";
        }
        return 0;
    }
    if (y<=y2 && y>=y1)
    {
        cout << "W";
        return 0;
    }
    if (y>=y2)
    {
        cout << "NW";
    }
    else
    {
        cout << "SW";
    }
    return 0;
}
