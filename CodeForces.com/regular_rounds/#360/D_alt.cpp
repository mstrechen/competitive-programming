#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>

using namespace std;

const int MAXN = 1000500;
//
set<int> A;


bool resheto[MAXN];

vector<int> prime;

int NOD[MAXN];

bool makeNOD(int n)
{
  vector<int> currentDividers;
  vector<int> countOfDividers;
  for(int i = 0; prime[i]*prime[i]<=n; i++)
  {
    if(n%prime[i]==0)
    {
      currentDividers.push_back(prime[i]);
      countOfDividers.push_back(0);
    }

    while(n%prime[i]==0)
    {
      n/=prime[i];
      countOfDividers[countOfDividers.size()-1]++;
    }
  }
  if(n!=1)
  {
    currentDividers.push_back(n);
    countOfDividers.push_back(1);
  }
  bool answer = 0;
  for(int i = 0; i<currentDividers.size(); i++)
  {
    if(NOD[currentDividers[i]]<countOfDividers[i])
    {
      answer = 1;
      NOD[currentDividers[i]] = countOfDividers[i];
    }
  }return answer;
}

int main()
{
  int n;
  int k,tmp;
  for(int i = 2; i*i<MAXN; i++)
  {
    if(!resheto[i])
    {
      for(int j = 2; j*i<MAXN; j++)
        resheto[j*i] = 1;
    }
  }
  for(int i = 2; i<MAXN; i++)
  {
    if(!resheto[i])
      prime.push_back(i);
  }
  scanf("%d", &n);
  scanf("%d", &k);

  for(int i = 0; i<n; i++)
  {
    scanf("%d", &tmp);
    if(tmp!=1)
      makeNOD(tmp);
  }

  if(makeNOD(k))
  {
    cout << "No";
  }
  else
  {
    cout << "Yes";
  }

  return 0;
}
