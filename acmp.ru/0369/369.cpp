#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int oo = 1000000000;

struct gangsta
{
    int time, money, size;
};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int countOfGangsters, maxOpenness, timeOfMoving;

    cin >> countOfGangsters >> maxOpenness >> timeOfMoving;

    vector<gangsta> allGangstas(countOfGangsters);

    for(auto& i : allGangstas) cin >> i.time;
    for(auto& i : allGangstas) cin >> i.money;
    for(auto& i : allGangstas) cin >> i.size;

    map<pair<int,int>, int> timeAndSizeToMoney;

    for(auto i : allGangstas)
        timeAndSizeToMoney[{i.time, i.size}]+=i.money;

    vector<int> currentStep(maxOpenness+1,-(oo)), nextStep;
                currentStep[0] = 0;

    for(int i = 1; i<=timeOfMoving; i++)
    {
        nextStep = currentStep;

        for(int j = 1; j<maxOpenness; j++)
        {
            nextStep[j] = max(max(currentStep[j-1], currentStep[j+1]), currentStep[j]);
            if(timeAndSizeToMoney.count({i,j}))
                nextStep[j]+=timeAndSizeToMoney[{i,j}];
        }

        nextStep[maxOpenness] = max(currentStep[maxOpenness-1], currentStep[maxOpenness]);
        if(timeAndSizeToMoney.count({i,maxOpenness}))
                nextStep[maxOpenness]+=timeAndSizeToMoney[{i,maxOpenness}];

        nextStep[0] = max(currentStep[1], currentStep[0]);

        nextStep.swap(currentStep);
    }

    cout << accumulate(currentStep.begin(), currentStep.end(), 0, [](int a, int b){return max(a,b);});


    return 0;
}
