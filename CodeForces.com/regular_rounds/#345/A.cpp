#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a,b,pocket, answer = 0;
    cin >> a >> b;
    for(;a>1||b>1&&a>0&&b>0;)
    {
        if(a<b)
        {
            swap(a,b);
        }
        pocket = (a>3);
        b+=a/2;
        answer+=a/2;
        a = a%2;
        if(pocket)
        {
            b--;
            a+=2;
            answer--;
        }
    }
    cout << answer;
    return 0;
}
