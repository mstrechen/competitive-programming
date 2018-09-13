#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    if(n<3)
    {
        cout << 0;
        return 0;
    }

    int prev,  prevLessI = -1, current;

    int minAnsI = -1, minAnsJ = 10005000;

    cin >> prev;

    for(int i = 1; i<n; i++)
    {
        cin >> current;

        if(prev<current)
        {
            prevLessI = i-1;
        }
        else
        if(prev>current)
        {
            if(prevLessI!=-1 && minAnsJ-minAnsI > i-prevLessI)
            {
                minAnsJ = i;
                minAnsI = prevLessI;
            }
        }
        prev = current;
    }

    if(minAnsI==-1)
        cout << 0;
    else
        cout << minAnsI + 1 << ' ' << minAnsJ + 1;






    return 0;
}

