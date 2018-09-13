#include<iostream>
#include<vector>
#include<string>
#include<bitset>


using namespace std;

const long long MOD = 1000000007;
int COUNT_OF_COLORS;


vector<vector<long long> > matrixOfChanges;


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



bool _check(int mask, int n, int m, int x, int y)
{
  if(x<0||x>=n||y<0||y>=m)
  {
    return 0;
  }
  int _i  = y*n+x;
  return (((mask>>_i)&1)==0);
}

int _fillMask(int mask, int n, int m, int x, int y)
{
  int _i  = y*n+x;
  return (mask|(1<<_i));
}

bool checkBy(int mask, int n, int m, int x, int y, string a)
{
  bool answer = 1;

  for(int i = 0; i<3; i++)
    for(int j = 0; j<3; j++)
    if(a[j*3+i]=='1')
      answer&=_check(mask,n,m,x+i-1, y+j-1);
  return answer;
}

int fillBy(int mask, int n, int m, int x, int y, string a)
{
  for(int i = 0; i<3; i++)
    for(int j = 0; j<3; j++)
    if(a[j*3+i]!='0')
    {
      mask = _fillMask(mask, n,m,x+i-1, y+j-1);
    }
  return mask;
}



void printMask(int mask, int n, int m)
{
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j<m; j++)
      cout << ((mask>>(j*n+i))&1);
    cout << endl;
  }
}
int O_SHIT_DAT_BOI;
void getN(int n, int m, int _i, int mask1, int mask2)
{
 if(_i==n*m)
  {
    matrixOfChanges[mask2][O_SHIT_DAT_BOI]+=1;
    matrixOfChanges[mask2][O_SHIT_DAT_BOI]%=MOD;
    return;
  }
  int x = _i%n;
  int y = _i/n;
  if((mask1>>_i)&1)
  {
    getN(n,m,_i+1, mask1, mask2);
  }
  else
  {
    // 2x2x2
    if(checkBy(mask1, n,m,x,y,"000011011")&&
       checkBy(mask2, n,m,x,y,"000011011"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011011"),
                       fillBy(mask2, n,m,x,y,"000011011"));
    }

    // 1x1x1
    if(checkBy(mask1, n,m,x,y,"000010000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010000"),mask2);
    }
    //##
    //#
    if(checkBy(mask1, n,m,x,y,"000010000")&&
       checkBy(mask2, n,m,x,y,"010010000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010000"),
                       fillBy(mask2, n,m,x,y,"010010000"));
    }
    if(checkBy(mask1, n,m,x,y,"000010000")&&
       checkBy(mask2, n,m,x,y,"000110000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010000"),
                       fillBy(mask2, n,m,x,y,"000110000"));
    }
    if(checkBy(mask1, n,m,x,y,"000010000")&&
       checkBy(mask2, n,m,x,y,"000011000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010000"),
                       fillBy(mask2, n,m,x,y,"000011000"));
    }
    if(checkBy(mask1, n,m,x,y,"000010000")&&
       checkBy(mask2, n,m,x,y,"000010010"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010000"),
                       fillBy(mask2, n,m,x,y,"000010010"));
    }

    if(checkBy(mask1, n,m,x,y,"000011000")&&
       checkBy(mask2, n,m,x,y,"000010000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011000"),
                       fillBy(mask2, n,m,x,y,"000010000"));
    }
    if(checkBy(mask1, n,m,x,y,"000011000")&&
       checkBy(mask2, n,m,x,y,"000001000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011000"),
                       fillBy(mask2, n,m,x,y,"000001000"));
    }
    if(checkBy(mask1, n,m,x,y,"000010010")&&
       checkBy(mask2, n,m,x,y,"000010000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010010"),
                       fillBy(mask2, n,m,x,y,"000010000"));
    }
    if(checkBy(mask1, n,m,x,y,"000010010")&&
       checkBy(mask2, n,m,x,y,"000000010"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011000"),
                       fillBy(mask2, n,m,x,y,"000001000"));
    }

    //####IN HORIZONTAL
    if(checkBy(mask1, n,m,x,y,"001011000"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"001011000"),mask2);
    }

    if(checkBy(mask1, n,m,x,y,"000011001"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011001"),mask2);
    }
    if(checkBy(mask1, n,m,x,y,"000011010"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000011010"),mask2);
    }
    if(checkBy(mask1, n,m,x,y,"000010011"))
    {
      getN(n, m, _i+1, fillBy(mask1, n,m,x,y,"000010011"),mask2);
    }

  }
}

int main()
{
  int n, m,k;
  cin >> n >> m >> k;



  int countOfMasks = 1<<(n*m);
  matrixOfChanges = vector<vector<long long > >(countOfMasks, vector<long long>(countOfMasks,0));



  for(int i = 0; i<countOfMasks; i++)
  {
    O_SHIT_DAT_BOI = i;
    getN(n, m, 0, i, 0);
  }
  matrixOfChanges = powMatrix(matrixOfChanges, countOfMasks, k);

  long long summ = 0;
  for(int i = 0; i<countOfMasks; i++){
    for(int j = 0; j<countOfMasks; j++)
      cout << matrixOfChanges[j][i] << ' ';
    cout << endl;

  }

  cout << matrixOfChanges[0][0];

  return 0;
}
