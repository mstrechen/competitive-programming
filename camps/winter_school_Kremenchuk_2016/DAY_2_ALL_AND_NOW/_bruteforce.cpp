#include<iostream>

using namespace std;

vector<int> st;

vector<pair<int,int> > pairs;

void check()
{
    int x = 0, y = 0;

    for(int i = 0; i<st.size(); i++)


}


void rec(int _i,int max)
{
    if(_i==max)
        check();
    else
    {
        for(int i = 0; i<4; i++)
            st[_i] = i;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    return 0;
}

