#include<iostream>
#include<vector>

using namespace std;

int max(int  a, int  b)
{
    return a>b?a:b;
}

const int stepsX[4] = {0,0,1,-1};
const int stepsY[4] = {1,-1,0,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sizeOfField, maxLength;

    cin >> sizeOfField >> maxLength;

    vector<vector<int> > field(sizeOfField+2, vector<int>(sizeOfField+2, 0));
    vector<vector<int> > current = field, next = field;

    for(int i = 1; i<=sizeOfField; i++)
        for(int j = 1; j<=sizeOfField; j++)
            cin >> field[i][j];

    while(maxLength--)
    {
        for(int i = 1; i<=sizeOfField; i++)
            for(int j = 1; j<=sizeOfField; j++)
            {
                next[i][j] = 0;
                for(int k = 0; k<4; k++)
                    next[i][j] = max(next[i][j], current[i+stepsX[k]][j+stepsY[k]]);
                next[i][j]+=field[i][j];
            }

        next.swap(current);
    }
    cout << current[1][1];



    return 0;
}
