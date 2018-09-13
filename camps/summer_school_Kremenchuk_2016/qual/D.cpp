#include<iostream>
#include<map>
#include<fstream>

using namespace std;


map<int,int> a_thisSide,a_anotherSide;
map<int,int>::iterator it;


int startedUsing = 0;
int minSumm;
int a[1337];

int main()
{
    //ifstream cin("olymp.in");
    //ofstream cout("olymp.out");

    int n, tmp,tmp2;
    int summ = 0;
    int onOtherSide = 0;
    int currentSumm;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
        a_thisSide[a[i]]++;
        summ+=a[i];
    }
    if(n==2)
    {
        cout << max(a[0],a[1]) << endl;
        cout << a[0] << ' ' << a[1];
        return 0;
    }
    minSumm = summ + (n-3)*(*a_thisSide.begin()).first;

    currentSumm = 0;
    for(int i = 0; 1+i<n; i++)
    {
        if(onOtherSide == 0)
        {
            tmp2 = (*a_thisSide.begin()).first;
            currentSumm+=tmp2;

            if(a_thisSide[tmp2]>1)
            {
                tmp = tmp2;
            }
            else
            {
                it = a_thisSide.begin();
                ++it;
                tmp = (*it).first;
            }
            a_anotherSide[tmp]++;
            a_thisSide[tmp]--;
            if(a_thisSide[tmp]==0)
                a_thisSide.erase(tmp);
            summ-=tmp;
            currentSumm+=tmp;
            onOtherSide = 1;

            if(minSumm>currentSumm+summ+tmp2*(n-3-i))
            {
                minSumm = currentSumm+summ+tmp2*(n-i-3);
                startedUsing = i+1;
            }
        }
        else
        {
            tmp2 = (*a_thisSide.rbegin()).first;
            a_anotherSide[tmp2]++;
            a_thisSide[tmp2]--;
            if(a_thisSide[tmp2]==0)
                a_thisSide.erase(tmp2);
            summ-=tmp2;
            currentSumm+=tmp2;

            tmp = (*a_thisSide.rbegin()).first;
            a_anotherSide[tmp]++;
            a_thisSide[tmp]--;
            if(a_thisSide[tmp]==0)
                a_thisSide.erase(tmp);
            summ-=tmp;

            tmp = (*a_anotherSide.begin()).first;
            a_anotherSide[tmp]--;
            if(a_anotherSide[tmp]==0)
                a_anotherSide.erase(tmp);
            a_thisSide[tmp]++;
            if(i!=n-2)
                currentSumm+=tmp;
            summ+=tmp;

            cout << summ << ' ' << currentSumm << ' ';
            if(minSumm>currentSumm+summ+tmp*(n-3-i))
            {
                minSumm = currentSumm+summ+tmp*(n-i-3);
                startedUsing = i+1;
            }

            onOtherSide = 0;
        }
    }
    cout << minSumm << '\n';
    a_thisSide.clear();
    a_anotherSide.clear();
    for(int i = 0; i<n; i++)
        a_thisSide[a[i]]++;
    for(int i = 0; i<n; i++)
    {
        if(startedUsing>i)
        {
            tmp = (*a_thisSide.begin()).first;
            cout << tmp << ' ' << (*a_thisSide.rbegin()).first << ' '<<tmp;
            tmp = (*a_thisSide.rbegin()).first;
            a_thisSide[tmp]--;
            if(a_thisSide[tmp]==0)
                a_thisSide.erase(tmp);

        }
        else
        {
            if(onOtherSide == 0)
            {
                tmp2 = (*a_thisSide.begin()).first;
                currentSumm+=tmp2;

                if(a_thisSide[tmp2]>1)
                {
                    tmp = tmp2;
                }
                else
                {
                    it = a_thisSide.begin();
                    ++it;
                    tmp = (*it).first;
                }
                a_anotherSide[tmp]++;
                a_thisSide[tmp]--;
                if(a_thisSide[tmp]==0)
                    a_thisSide.erase(tmp);
                onOtherSide = 1;

                cout << tmp2 << ' '<<tmp << ' '<< tmp2;
            }
            else
            {
                tmp2 = (*a_thisSide.rbegin()).first;
                a_anotherSide[tmp2]++;
                a_thisSide[tmp2]--;
                if(a_thisSide[tmp2]==0)
                    a_thisSide.erase(tmp2);

                tmp = (*a_thisSide.rbegin()).first;
                a_anotherSide[tmp]++;
                a_thisSide[tmp]--;
                if(a_thisSide[tmp]==0)
                    a_thisSide.erase(tmp);
                cout << tmp2 << ' ' << tmp << ' ';

                tmp = (*a_anotherSide.begin()).first;
                a_anotherSide[tmp]--;
                if(a_anotherSide[tmp]==0)
                    a_anotherSide.erase(tmp);
                a_thisSide[tmp]++;
                cout << ' ' << tmp;

                onOtherSide = 0;
            }
        }
        cout << '\n';
    }
    it = a_thisSide.begin();
    cout << (*(it++)).first<< ' ' << (*it).first;

    return 0;
}
