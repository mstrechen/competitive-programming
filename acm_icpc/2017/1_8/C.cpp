#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s = 0, bag, bag0 = 0;

    cin >> bag;

    int n;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        if(bag0+x<=bag)
        {
            bag0+=x;
        }
        s+=x;
    }

    cout << bag0 << ' ' << s-bag0;



    return 0;
}
