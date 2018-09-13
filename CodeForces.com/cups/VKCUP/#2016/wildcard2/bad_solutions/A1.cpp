#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct problem
{
    int maxTime, countOfTests;
    problem(int maxTime = 0, int countOfTests = 0): maxTime(maxTime), countOfTests(countOfTests)
    {}

} problems[10000];

set<int> rejected;
set< pair<int,int> > queueOfProblems;

int main(){
	ios::sync_with_stdio(false);
    int n;
    int q;
    int countOfSended = 0;

    int tmpProblem, tmpSubmission, tmpTest;
    string tmpVerdict;
    pair<int,int> tmpTask;

    cin >> n >> q;
    for(int i = 0; i<q; i++)
    {
        cin >> problems[i].maxTime >> problems[i].countOfTests;
    }
    while(!cin.eof())
    {
        do
        {
            cin >> tmpProblem;
            if(tmpProblem!=-1)
            {
                for(int i = 0; i<problems[tmpProblem].countOfTests; i++)
                {
                    queueOfProblems.insert({countOfSended, i});
                }
                countOfSended++;
            }
        }
        while(tmpProblem!=-1);

        do
        {
            cin >> tmpSubmission >> tmpTest;
            if(tmpSubmission!=-1)
            {
                cin >> tmpVerdict;
                queueOfProblems.erase({tmpSubmission, tmpTest});
                n++;
            }
        }
        while(tmpSubmission!=-1);

        for(auto i: queueOfProblems)
        {
            cout << i.first << ' '<<i.second<<'\n';
        }
        cout << "-1 -1" << endl;
    }



	return 0;
}

