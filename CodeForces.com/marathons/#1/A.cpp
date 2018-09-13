#include<iostream>
#include<algorithm>
#include<random>

using namespace std;

const int N = 5000;
const int K = 2000;
const int X = 100;
const int MAGIC = 40;

bool answers[N+1];
bool isFixed[N+1];


void invert(int l, int r, bool * answers, bool * isFixed)
{
    for(int i = l; i<r; i++)
        answers[i]^=(1^isFixed[i]);
}

void setFixed(int l, int r, bool * isFixed, bool value = 1)
{
    for(int i = l; i<r; i++)
        isFixed[i] = value;
}

int counter = 0;
int main()
{
    ios::sync_with_stdio(false);
    int lastBad = 0, prevBad = 0;

    int l_try = 0, r_try = MAGIC;
    invert(0, N, answers, isFixed);

    for(int _i = 0; _i<X&&lastBad<=N; _i++)
    {
        if(lastBad<K*2)
        {
            invert(0, lastBad, answers,isFixed);
            setFixed(lastBad-1, lastBad, isFixed);
        }
        else
        {

            setFixed(prevBad-1, prevBad, isFixed);
            invert(lastBad-1, lastBad, answers,isFixed);
            setFixed(lastBad-1, lastBad, isFixed);
            if(prevBad>lastBad)
            {
                invert(l_try, r_try,answers,isFixed);
                l_try = r_try;
                r_try = l_try+MAGIC;
            }
            else
            {
                l_try = r_try;
                r_try = l_try+MAGIC;

            }

            if(r_try<=N)
                invert(l_try, r_try, answers,isFixed);
        }
        for(int i = 0; i<N; i++)
            cout << answers[i];
        cout << endl;
        prevBad = lastBad;
        cin >> lastBad;
    }


    return 0;
}
