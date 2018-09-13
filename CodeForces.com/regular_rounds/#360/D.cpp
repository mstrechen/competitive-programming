#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

const int MAXN = 1000500;

set<int> A;


bool resheto[MAXN];

vector<int> prime;
vector<int> factorized;
vector<int> pows;
bool isOk[100];

bool makeNOD(int n)
{
  vector<int> currentDividers;
  vector<int> countOfDividers;
  if(n!=1)
  {
    currentDividers.push_back(n);
    countOfDividers.push_back(1);
  }
  bool answer = 0;

  factorized = currentDividers;
  pows = countOfDividers;
  return answer;

}

int _pow(int a, int b)
{
  if(b==1)
    return a;
  return a*_pow(a,b-1);
}
int main()
{
  ios::sync_with_stdio(false);
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
  cin >> n >> k;

  makeNOD(k);
  for(int i = 0; i<pows.size(); i++)
  {
    factorized[i] = _pow(factorized[i], pows[i]);
  }

  for(int i = 0; i<n; i++)
  {
    cin >> tmp;
    for(int i = 0; i<factorized.size(); i++)
    {
      isOk[i] |= tmp%factorized[i]==0;
    }
  }
  for(int i = 1; i<pows.size(); i++)
  {
    isOk[0]&=isOk[i];
  }
  if(isOk[0])
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }

  return 0;
}

