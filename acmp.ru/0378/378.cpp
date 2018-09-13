#include<iostream>
#include<vector>

using namespace std;

void add(vector<char> &  values, int delta)
{
    for(int i = (int)values.size()-1; i>=0; i--)
        if(values[i])
            values[i+delta] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> currentState(500*100+1,0);
    currentState[0] = 1;
    int lenOfSequence;
    cin >> lenOfSequence;

    for(int i = 0; i<lenOfSequence; i++)
    {
        int currentElement;
        cin >> currentElement;
        add(currentState, currentElement);
    }

    int answer = 0;

    for(auto i : currentState)
        answer+=i;

    cout << answer;
    return 0;
}
