#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int get1(int a)
{
    if(a<9000)
        return a+1000;
    return a;
}
int get2(int a)
{
    if(a%10>1)
        return a-1;
    return a;
}
int get3(int a)
{
    return a/10 + 1000*(a%10);
}
int get4(int a)
{
    return (a%1000)*10 + a/1000;
}
    int used[10000];

int main(){
	ios::sync_with_stdio(false);
    int a, b;

    cin >> a >> b;

    vector<int> res;


    queue<int> q;

    q.push(a);
    used[a] = a;

    while(!q.empty())
    {

        int tmp = q.front();
        q.pop();
        if(!used[get1(tmp)])
        {
            used[get1(tmp)] = tmp;
            q.push(get1(tmp));
        }
        if(!used[get2(tmp)])
        {
            used[get2(tmp)] = tmp;
            q.push(get2(tmp));
        }
        if(!used[get3(tmp)])
        {
            used[get3(tmp)] = tmp;
            q.push(get3(tmp));
        }
        if(!used[get4(tmp)])
        {
            used[get4(tmp)] = tmp;
            q.push(get4(tmp));
        }
    }
    for(int i = b; i!=a; i= used[i])
    {
        res.push_back(i);
    }

    res.push_back(a);
    reverse(res.begin(),res.end());
    for(auto i : res)
        cout << i << '\n';

	return 0;
}
