#include<iostream>
#include<algorithm>
#include<set>
#include<map>

using namespace std;
const int MAXN = 100500;

map<int, int> M;
map<int, int> S;
int Msize = 0;
int maxM = 0;
long long currentSumm = 0, summOfStandings = 0;

void makeLessInM(int a)
{
  M[a]--;
  if(M[a]==0)
    M.erase(a);
}
void makeLessInS(int a)
{
  S[a]--;
  if(S[a]==0)
    S.erase(a);
}

void insertInM(int a)
{
  if(a<0)
    return;

  if(Msize==maxM)
  {
    pair<int,int>tmp = *M.begin();
    if(tmp.first>a)
    {
      S[a]++;
      return;
    }

    currentSumm+=a-tmp.first;
    makeLessInM(tmp.first);
    S[tmp.first]++;
    M[a]++;
  }
  else
  {
    currentSumm+=a;
    M[a]++;
    Msize++;
  }

}
void eraseFromM(int a)
{
  if(a<0)
    return;
  currentSumm-=a;
  makeLessInM(a);
  Msize--;
  if(!S.empty())
  {
      pair<int,int>tmp = *S.rbegin();
      M[tmp.first]++;
      Msize++;
      currentSumm+=tmp.first;
      makeLessInS(tmp.first);
  }
}

pair<pair<int,bool>,pair<int,int> >  A[MAXN*2];

int main()
{
  ios::sync_with_stdio(false);
  int n,p;
  cin >> n >> maxM >> p;
  int tmp1,tmp2, tmp3, tmp4;
  long long answer = 0;

  for(int i = 0; i<n; i++)
  {
    cin >> tmp1 >> tmp2 >> tmp3 >> tmp4;
    tmp1-=tmp2;
    A[i*2] = make_pair(make_pair(tmp3,1),make_pair(tmp2,tmp1));
    A[i*2+1] = make_pair(make_pair(tmp4,0),make_pair(tmp2,tmp1));
  }
  n*=2;
  sort(A, A+n);
  int currentStop = 0;
  for(int i = 0; i<n; i++)
  {
    if(A[i].first.first!=currentStop)
    {
      answer+=(currentSumm+summOfStandings)*(A[i].first.first-currentStop);
      currentStop = A[i].first.first;
    }
    if(A[i].first.second)
    {
      summOfStandings+=A[i].second.first;
      insertInM(A[i].second.second);
    }
    else
    {
      summOfStandings-=A[i].second.first;
      eraseFromM(A[i].second.second);
    }
  }
  answer+=(currentSumm+summOfStandings)*(p-A[n-1].first.first);
  cout << answer;
  return 0;
}

