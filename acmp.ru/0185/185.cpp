#include<iostream>
#include<queue>
using namespace std;

int connected[100][100];
bool reached[101];

queue<int> ways;
int main(){
    ios::sync_with_stdio(false);
    int n, k, tmp1, tmp2;
    bool answer = true;
    cin >> n >> k;
    k--;
    reached[k] = 1;
    for(;;)
    {
        cin >> tmp1;
        if(tmp1)
        {
            cin >> tmp2;
            connected[tmp1-1][tmp2-1] = 1;
        }
        else
        {
            break;
        }
    }
    ways.push(k);
    while(ways.size()>0)
    {
        for(int i = 0; i<n; i++)
        {
            if(connected[ways.front()][i]&&!reached[i])
            {
                ways.push(i);
                reached[i] = true;
            }
        }
        ways.pop();
    }
    for(int i = 0; i<n; i++)
    {
        answer &= reached[i];
    }
    if(answer)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

