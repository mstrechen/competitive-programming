#include <iostream>
#include <fstream>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

struct problem
{
    int maxTime, countOfTests;
    problem(int maxTime = 0, int countOfTests = 0): maxTime(maxTime), countOfTests(countOfTests)
    {}

} problems[10000];

struct submissionToTest
{
    bool rejected;
    int testBegin, testEnd;
    submissionToTest(int testBegin = 0, int testEnd = 0):rejected(false), testBegin(testBegin), testEnd(testEnd)
    {}

    bool empty()
    {
        return rejected||(testBegin==testEnd);
    }
};

int main(){
    ios::sync_with_stdio(false);
    int n;
    int q;
    int countOfSended = 0;

    int maxCountOfSended;

    int tmpProblem, tmpSubmission, tmpTest;
    string tmpVerdict;
    pair<int,int> tmpTask;
    vector<int> problemsOfSubmissions,
                testsInProgress;
    vector<submissionToTest> submissionsToProcess;
    int firstToTest = 0;


    cin >> n >> q;
    maxCountOfSended = sqrt(n+1e-9);

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
                problemsOfSubmissions.push_back(tmpProblem);
                testsInProgress.push_back(0);
                submissionsToProcess.push_back( submissionToTest(0, problems[tmpProblem].countOfTests) );
            }
        }
        while(tmpProblem!=-1);

        do
        {
            cin >> tmpSubmission >> tmpTest;
            if(tmpSubmission!=-1)
            {
                cin >> tmpVerdict;
                if(tmpVerdict=="RJ")
                {
                    submissionsToProcess[tmpSubmission].rejected = true;
                }
                testsInProgress[tmpSubmission]--;
                n++;
            }
        }
        while(tmpSubmission!=-1);

        while(firstToTest!=submissionsToProcess.size()&&submissionsToProcess[firstToTest].empty())
            firstToTest++;

        int j = firstToTest;
        while(n>0&&j!=submissionsToProcess.size())
        {
            if(!submissionsToProcess[j].empty()&&testsInProgress[j]<maxCountOfSended)
            {
                cout << j << ' '<<submissionsToProcess[j].testBegin << endl;
                submissionsToProcess[j].testBegin ++;
                n--;
            }
            else
            {
                j++;
            }
        }
        cout << "-1 -1" << endl;
    }



	return 0;
}
