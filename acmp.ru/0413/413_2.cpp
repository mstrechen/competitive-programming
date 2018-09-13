#include<iostream>

using namespace std;

char * a = new char[1000], * b = new char[1000];
int main()
{
    int n, m, answer = 0;
    char tmp;
    cin >> n >> m;
    cin >> *a;
    for(int i = 1; i<=n; i++)
    {
        cin >> *b;
        answer+=
        swap(a,b);
    }
    cout << answer;

    return 0;
}
