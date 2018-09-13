#include<iostream>

using namespace std;

struct FieldOfView
{
    unsigned long long a[3][3];
    FieldOfView()
    {
        a[0][0] = 19; a[0][1] = 45; a[0][2] = 115;
        a[1][0] = 45; a[1][1] = 87; a[1][2] = 189;
        a[2][0] = 115; a[2][1] = 189; a[2][2] = 355;
    }
    void moveRight()
    {
        unsigned long long newValues[3];
        for(int i = 0; i<3; i++)
            newValues[i] = a[i][0]*6 - a[i][1]*11 + a[i][2]*6 ;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<2; j++)
            {
                a[i][j] = a[i][j+1];
            }
            a[i][2] = newValues[i];
        }
    }

    void moveDown()
    {
        unsigned long long newValues[3];
        for(int i = 0; i<3; i++)
            newValues[i] = a[0][i]*6 - a[1][i]*11 + a[2][i]*6 ;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<2; j++)
            {
                a[j][i] = a[j+1][i];
            }
            a[2][i] = newValues[i];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, m;
    cin >> n >> m;
    n-=2;
    m-=2;

    FieldOfView fov;
    for(int i = 2; i<n; i++)
        fov.moveDown();
    for(int i = 2; i<m; i++)
        fov.moveRight();

    cout << fov.a[min(n,2)][min(m,2)];


    return 0;
}
