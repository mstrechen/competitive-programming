#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    bool ans = 0;

    int be, af;
    string s;
    int n;
    cin >> n;
    for(int i = 0; i<n;i++)
    {
        cin >> s >> be >> af;
        if(be>=2400&&be<af)
            ans = 1;
    }
    cout << (ans?"YES":"NO");
    return 0;
}
