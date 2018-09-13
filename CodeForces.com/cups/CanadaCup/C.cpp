#include <iostream>
#include <vector>

using namespace std;

int a[26];
string s;
vector<string> ss(2,string(13,'^'));

void _fill(int y,int x, int pos1, int pos2)
{
    int _i = pos1;
    int i = x;
    while(_i!=pos2)
    {
        ss[y][i] = s[_i];
        _i++;
        if(y)
        {
            if(i==0)
                y = 0;
            else
                i--;
        }
        else
        {
            if(i==12)
                y = 1;
            else
                i++;
        }

    }

}
void _altFill(int y,int x, int pos1, int pos2)
{
    int _i = pos2;
    int i = x;
    while(_i!=pos1)
    {
        ss[y][i] = s[_i];
        _i--;
        if(y)
        {
            if(i==12)
                y = 0;
            else
                i++;
        }
        else
        {
            if(i==0)
                y = 1;
            else
                i--;
        }

    }
}

int main(){
	ios::sync_with_stdio(false);

	cin >> s;

    char doblet = 0;
    for(char i = 'A'; i<='Z'; i++)
        doblet^=i;
    for(auto i : s)
        doblet^=i;

    int pos1 = -1, pos2 = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i]==doblet)
            if(pos1==-1)
                pos1 = i;
        else
            pos2 = i;
    }
    if(pos2-pos1==1)
    {
        cout << "Impossible";
        return 0;
    }

    int sizeOfGap = pos2-pos1-1;

    int lowerFill = sizeOfGap/2;

    _fill(1,lowerFill, pos1, pos2);
    if(lowerFill<12)
        _altFill(1, lowerFill+1, -1, pos1-1);
    else
        _altFill(0, 12, -1, pos1-1);
    _fill(0, (sizeOfGap-1)/2+1, pos2+1,s.size());

    cout << ss[0] << '\n' << ss[1];


	return 0;
}
