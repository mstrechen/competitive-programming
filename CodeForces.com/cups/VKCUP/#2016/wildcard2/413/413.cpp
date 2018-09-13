#include <iostream>
#include <fstream>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct problem
{
	int maxTime, countOfTests, rank;
	problem(int maxTime = 0, int countOfTests = 0) : maxTime(maxTime), countOfTests(countOfTests), rank(maxTime*countOfTests)
	{}

} problems[10000];

struct taskToCheck
{
	int rank, id, test;
	taskToCheck(int rank = 0, int id = 0, int test = 0) :rank(rank), id(id), test(test)
	{}
};

struct compareTuples
{
	bool operator()(taskToCheck a, taskToCheck b)
	{
		if (a.rank != b.rank)
			return a.rank<b.rank;
		else if (a.id != b.id)
			return a.id<b.id;
		else
			return a.test<b.test;
	}
};

set<int> rejected = {};
set< taskToCheck, compareTuples> queueOfProblems;

int main() {
	ios::sync_with_stdio(false);
	int n;
	int q;
	int countOfSended = 0;

	int tmpProblem, tmpSubmission, tmpTest;
	string tmpVerdict;
	taskToCheck tmpTask;
	int maxCountInSameTime;
	int maxCountOfTest = 0;
	long long summTime = 0;

	cin >> n >> q;

	maxCountInSameTime = sqrt(n + 0.001);
	for (int i = 0; i<q; i++)
	{
		cin >> problems[i].maxTime >> problems[i].countOfTests;
		maxCountOfTest = max(maxCountOfTest, problems[i].countOfTests);
		summTime += problems[i].maxTime;
	}
	summTime /= q;
	for (int i = 0; i<q; i++)
	{
		problems[i].rank = (problems[i].maxTime + summTime / (q * 2))*(problems[i].countOfTests + maxCountOfTest / 2);
	}
	while (!cin.eof())
	{
		do
		{
			cin >> tmpProblem;
			if (tmpProblem != -1)
			{
				for (int i = 0; i<problems[tmpProblem].countOfTests&&i<2; i++)
				{
					queueOfProblems.insert(taskToCheck(problems[tmpProblem].rank, countOfSended, i));
				}

				for (int i = 2; i<problems[tmpProblem].countOfTests; i++)
				{
					queueOfProblems.insert(taskToCheck(problems[tmpProblem].rank + ((i - 2) / maxCountInSameTime)*summTime, countOfSended, i));
				}

				countOfSended++;
			}
		} while (tmpProblem != -1);

		do
		{
			cin >> tmpSubmission >> tmpTest;
			if (tmpSubmission != -1)
			{
				cin >> tmpVerdict;
				if (tmpVerdict == "RJ")
				{
					rejected.insert(tmpSubmission);
				}
				n++;
			}
		} while (tmpSubmission != -1);
		while (n>0 && !queueOfProblems.empty())
		{
			tmpTask = *queueOfProblems.begin();
			if (!rejected.count(tmpTask.id))
			{
				cout << tmpTask.id << ' ' << tmpTask.test << endl;
				n--;
			}
			queueOfProblems.erase(tmpTask);
		}
		cout << "-1 -1" << endl;
	}



	return 0;
}
