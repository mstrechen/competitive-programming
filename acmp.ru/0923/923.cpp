#include <iostream>
#include <map>
#include <fstream>

using namespace std;


long long solve(long long n)
{
    long long res = 0;

    map<long long,int> curr,next;
    curr[n] = 1;
    while(!curr.empty())
    {
        next.clear();
        for(auto i : curr)
        if(i.first<=3)
        {
            res+=(i.first==3)*i.second;
        }
        else
        {
            next[i.first/2]+=i.second;
            next[(i.first-1)/2+1]+=i.second;
        }
        curr = next;
    }
    return res;

}



int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;

    //cin >> n;


    ofstream cout("out.txt");
    for(int i = 0; i<1000; i++)
    {
        cout << i << ' ' << solve(i) << '\n';
    }


	return 0;
}
