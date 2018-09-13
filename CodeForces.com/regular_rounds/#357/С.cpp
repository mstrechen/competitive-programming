#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;


map<int,int> a;
vector<pair<string,int> > answer;

void remove(int n)
{
    a[n]--;
    if(a[n]==0)
        a.erase(n);
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int tmpI;
    string tmpS;
    for(int i = 0; i<n; i++)
    {
        cin >> tmpS;

        if(tmpS[0]=='r')
        {
            if(a.empty())
            {
                answer.push_back({"insert",0});
            }
            else
            {
                remove((*a.begin()).first);
            }
        }
        else
        {
            cin >> tmpI;
            if(tmpS[0]=='i')
            {
                a[tmpI]++;
            }
            if(tmpS[0]=='g')
            {
                if(a.empty())
                {
                    answer.push_back({"insert",tmpI});
                    a[tmpI]++;
                }
                else
                {
                    while((!a.empty())&&(*a.begin()).first<tmpI)
                    {
                        answer.push_back({"removeMin",0});
                        remove((*a.begin()).first);
                    }

                    if(a.empty()||(*a.begin()).first>tmpI)
                    {
                        answer.push_back({"insert", tmpI});
                        a[tmpI]++;
                    }

                }
            }
        }

        answer.push_back(make_pair(tmpS, tmpI));
    }
    cout << answer.size() << '\n';
    for(int i = 0; i<answer.size(); i++)
    {
        cout << answer[i].first;
        if(answer[i].first[0]!='r')
            cout << ' '<<answer[i].second;
        cout << '\n';
    }
    return 0;
}
