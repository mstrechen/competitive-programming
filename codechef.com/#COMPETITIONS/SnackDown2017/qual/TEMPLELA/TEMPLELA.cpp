#include<iostream>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--)
    {
        int n;
        cin >> n;

        bool flag = n&1;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            if(x != min(i + 1, n - i))
                flag = false;
        }
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }


    return 0;
}
