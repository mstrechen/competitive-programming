#include <iostream>
#include <fstream>
#include <set>
#include <bitset>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <map>


using namespace std;

const unsigned int OFFSET = 16;          // for faster separating the program uses bit operation
const unsigned int GETID =  0x0FFFF;     //  x<<OFFSET  except  x*65536, x>>OFFSET  except  x div 65536
                                //  and x&GETID except x mod 65536

struct problem
{
	int maxTime, countOfTests;
	long long rank;
    int countOfBlocks;
    int blocks[30];

	void set(int maxTime = 0, int countOfTests = 0)
	{
	    this->maxTime = maxTime;
	    this->countOfTests = countOfTests;
        this->rank = pow(maxTime,0.8)*countOfTests/10;
        int summ = 0;
        this->blocks[0] = 0;
        this->countOfBlocks = 1;
        double q = pow(maxTime,0.41)/3.0;
        for(int i = 2; summ<countOfTests; i++)
        {
            summ+=(pow(i,2.7)-1)/q;
            this->blocks[this->countOfBlocks++] = min(countOfTests, summ);
        }
        countOfBlocks--;
	}

};
problem problems[10000];


bool rejected[30000];
int testsInQueue[30000];

//set< taskToCheck, compareTuples> queueOfProblems;

map< unsigned long long, pair<int, int> > queueOfProblems; // {RANK, {BLOCK_BEGIN, BLOCK_END}}
map< unsigned long long, pair<int, int> >::iterator it;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);


	int n;
	int q;
	int countOfSended = 0;

	int tmpMaxTime, tmpCountOfTests;
	int tmpProblem, tmpSubmission, tmpTest;

	char firstLetter, secondLetter;
	int maxCountInSameTime;
	int maxCountOfTest = 0;

	long long summTime = 0;
    long long currentRank;
    int minTest, maxTest;
    int currentId;

    int moment = 0;

	cin >> n >> q;
	int beginN = n;

	maxCountInSameTime = (3*n-1)/4+1;

	for (int i = 0; i<q; i++)
	{

		cin >> tmpMaxTime >> tmpCountOfTests;
        problems[i].set(tmpMaxTime, tmpCountOfTests);
		maxCountOfTest = max(maxCountOfTest, tmpCountOfTests);
		summTime += problems[i].maxTime + problems[i].countOfTests;
	}
	summTime /= q;

//	for (int i = 0; i<q; i++)
//	{
//		problems[i].rank = (problems[i].maxTime + sqrt(summTime))*(problems[i].countOfTests + 2*sqrt(maxCountOfTest));
//	}

	while (!cin.eof())
	{
	  moment+=10;
		do
		{
			cin >> tmpProblem;
			if (tmpProblem != -1)
			{
			    for(int i = 0; i<problems[tmpProblem].countOfBlocks; i++)
                {
                    currentRank = countOfSended*155+i*1200 + problems[tmpProblem].rank;
                    queueOfProblems.insert({ ((currentRank << OFFSET )|countOfSended),  {problems[tmpProblem].blocks[i] , problems[tmpProblem].blocks[i+1]} });
                }

				countOfSended++;
			}
		} while (tmpProblem != -1);

		do
		{
			cin >> tmpSubmission >> tmpTest;
			if (tmpSubmission != -1)
			{
				cin >> firstLetter >> secondLetter;
                n++;
                testsInQueue[tmpSubmission]--;
                if(firstLetter == 'R')
                {
                    rejected[tmpSubmission] = 1;
                }
			}
		} while (tmpSubmission != -1);

        it = queueOfProblems.begin();

		while (n>0 && it!=queueOfProblems.end())
		{
            currentRank = it->first;
            minTest = it->second.first;
            maxTest = it->second.second;
            currentId = currentRank&GETID;
            if(minTest >= maxTest||rejected[currentId])
            {
                queueOfProblems.erase(currentRank);
                it = queueOfProblems.upper_bound(currentRank);
            }
            else
            if(testsInQueue[currentId]>maxCountInSameTime)
            {
                it = queueOfProblems.upper_bound(currentRank);
            }
            else
            {
                cout << currentId <<' '<< minTest << endl;
                testsInQueue[currentId]++;
                it->second.first++;
                n--;
            }
        }
        cout << "-1 -1" << endl;
	}



	return 0;
}
