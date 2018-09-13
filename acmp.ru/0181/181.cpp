#include<iostream>


using namespace std;

int memorized[256][101];

string instructions[256];

int dp(int command, int countOfSteps)
{
    if(memorized[command][countOfSteps])
        return memorized[command][countOfSteps];

    if(countOfSteps==1)
        return memorized[command][countOfSteps] = 1;

    int ans = 1;
    for(int i = 0; i<(int)instructions[command].size(); i++)
        ans += dp(instructions[command][i], countOfSteps-1);

    return memorized[command][countOfSteps] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    getline(cin, instructions[(int)'N']);
    getline(cin, instructions[(int)'S']);
    getline(cin, instructions[(int)'W']);
    getline(cin, instructions[(int)'E']);
    getline(cin, instructions[(int)'U']);
    getline(cin, instructions[(int)'D']);

    char command;
    int countOfSteps;

    cin >> command >> countOfSteps;

    cout << dp((int)command, countOfSteps);

    return 0;
}
