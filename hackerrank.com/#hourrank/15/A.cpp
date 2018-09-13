#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(abs(x-z)==abs(y-z))
            cout << "Mouse C\n";
        else
            if(abs(x-z)>abs(y-z))
                cout << "Cat B\n";
            else
                cout << "Cat A\n";
    }


    return 0;
}
