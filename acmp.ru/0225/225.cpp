#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;

    cin >> n;

    int a[n][3];

    for(int i = 0; i<n; i++)
        for(int j = 0; j<3; j++)
            cin >> a[i][j];
    int dyn[n+2][3];

    for(int i = n-1; i<n+2; i++)
        for(int  j = 0; j<3; j++)
            dyn[i][j] = 1e9;

    dyn[n-1][0] = a[n-1][0];
    dyn[n][0] = 0;

    for(int i = n-2; i>=0; i--)
        for(int j = 0; j<3; j++)
        {
            dyn[i][j] = a[i][j] + min(dyn[i+j+1][0], min(dyn[i+j+1][1],dyn[i+j+1][2]));
        }



    cout << min(dyn[0][0], min(dyn[0][1], dyn[0][2]));


	return 0;
}
