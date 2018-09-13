#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 1000000007;
int COUNT_OF_COLORS;

vector<vector<long long> > matrixOfChanges;

long long matrixOfAnswer[128];

vector<vector<long long> > multMatrix(vector<vector<long long> > a, vector<vector<long long> > b, long long n)
{
  vector<vector<long long> >res(n, vector<long long>(n,0));
  for(int i = 0; i<n; i++)
  for(int j = 0; j<n; j++)
  {
    for(int k  = 0; k<n; k++)
      res[i][j]+=(a[i][k]*b[k][j])%MOD;
    res[i][j]%=MOD;
  }

  return res;
}

vector<vector<long long> > powMatrix(vector<vector<long long> >a, int n, int x)
{
  if(x==1)
    return a;
  if(x&1)
  {
    return multMatrix(a,powMatrix(a, n, x-1), n);
  }
  a = powMatrix(a,n,x/2);
  return multMatrix(a,a,n);
}

long long sqr(long long a)
{
  return a*a;
}
long long pow(long long a, int b)
{
  if(b==0)
    return 1;
  if(b&1)
    return (a*pow(a,b-1))%MOD;
  return sqr(pow(a,b/2))%MOD;
}



void getN(int n, int _i, int mask1, int mask2)
{
  if(_i==n)
  {
    matrixOfChanges[mask2][mask1]+=1;
    matrixOfChanges[mask2][mask1]%=MOD;
    return;
  }
  if(_i!=n-1)
  {
    //##
    //#
    if((!(((mask1>>_i)&1)|(mask1>>(_i+1))&1))&&(!((mask2>>_i)&1)))
    {
      getN(n,_i+2,mask1, mask2|(1<<_i));
    }
    //#
    //##
    if(!(((mask1>>_i)&1)|(mask1>>(_i+1))&1))
    {
      getN(n,_i+2,mask1, mask2|(1<<(_i+1)));
    }

  }
  if(_i!=n-1)
  {
    //##
    // #
    if( (!((mask1>>_i)&1))&&(!(mask2>>_i)&1))
    {
      getN(n,_i+1,mask1, mask2|(1<<(_i+1))|(1<<_i));
    }
  }
  if(_i!=0)
  {
    // #
    //##
    if( (!((mask1>>_i)&1))&&(!(mask2>>(_i-1))&1))
    {
      getN(n,_i+1,mask1, mask2|(1<<(_i-1))|(1<<_i));
    }
  }
  if(((mask1>>_i)&1)==1)
    getN(n,_i+1, mask1, mask2);

}

int main()
{
  int n, m;
  cin >> n >> m >> k;
  int countOfMasks = 1<<n;
  matrixOfChanges = vector<vector<long long > >(countOfMasks, vector<long long>(countOfMasks,0));


  for(int i = 0; i<countOfMasks; i++)
  {
    getN(n, 0, i, 0);
  }

  matrixOfChanges = powMatrix(matrixOfChanges, countOfMasks, m);

  cout << (matrixOfChanges[0][0]*pow(COUNT_OF_COLORS, n*m/3))%MOD;
  return 0;
}
