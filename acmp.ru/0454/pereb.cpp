#include<iostream>
#include<fstream>
#include<vector>
#include<bitset>
using namespace std;

int whatAPower(int a)
{
  int k = 0;
  while(a>1)
  {
    a/=2;
    k++;
  }
  return k;
}
int main()
{
  ofstream cout("hm.txt");
  for(int p1 = 1; p1<2048; p1*=2)
  for(int p2 = 1; p2<2048; p2*=2)
  {

    int answer = 0;
    for(int i = 0; i<p1; i++)
    {
      for(int j = 0; j<p2; j++)
      {
        int xor1 = 0, xor2 = 0;

        for(int k = 0; k<30; k++)
        {
          if(i&(1<<k))
          {
            xor1^=k+1;
          }
          if(j&(1<<k))
          {
            xor2^=k+1;
          }
        }
        if(xor1<xor2&&(i&j)==0)
        {
          answer++;
          //bitset<8> A1(i), B1(j);
          //cout << A1 << ' ' << B1 << '\n';
        }
      }
    }

    int p_1 = 0, p_2 = 0;

    cout << whatAPower(p1) << ' ' << whatAPower(p2) <<':'<< answer << '\n';
  }


  return 0;
}
