#include<iostream>


using namespace std;

const int ideal =  0x7FFFFFF;
const int alterIdeal = 0xFFFFFFFF;

int getMaskOfDigit(int a)
{
  if(a==0)
    return 0b1111011;
  if(a==1)
    return 0b0001010;
  if(a==2)
    return 0b0110111;
  if(a==3)
    return 0b0011111;
  if(a==4)
    return 0b1001110;
  if(a==5)
    return 0b1011101;
  if(a==6)
    return 0b1111101;
  if(a==7)
    return 0b0001011;
  if(a==8)
    return 0b1111111;
  if(a==9)
    return 0b1011111;
}

int getMask(int h, int m)
{
  return getMaskOfDigit(m%10)+
         (getMaskOfDigit(m/10)<<7)+
         (getMaskOfDigit(h%10)<<14)+
         (h>9?(getMaskOfDigit(h/10)<<21):0);
}

int main()
{
  ios::sync_with_stdio(false);
  int blackMask = 0, whiteMask = 0;
  char c1,c2,c3,c4;
  cin >> c1 >> c2 >> c3 >> c3 >> c4;

  int h = (c1-'0')*10+c2-'0', m = (c3-'0')*10+c4-'0';

  int counter = 0;
  blackMask = getMask(h, m);
  whiteMask = ~getMask(h, m);

  while(whiteMask!=alterIdeal||blackMask!=ideal)
  {
    h+=(++m)/60;
    m%=60;
    h%=24;
    blackMask|=(getMask(h, m));
    whiteMask|=(~getMask(h,m));
    counter++;
  }
  cout << counter;

  return 0;
}
