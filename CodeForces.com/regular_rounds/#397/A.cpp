#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    map<string,int> s;
    string ss,tmp;

    cin >> n;

    cin >> ss;

    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        s[string(tmp.begin(), tmp.begin() + 3)]--;
        s[string(tmp.begin()+5, tmp.begin() + 8)]++;
    }

    if(n%2==0)
    {
        cout << "home";
        return 0;
    }
    cout << "contest";



    return 0;
}
