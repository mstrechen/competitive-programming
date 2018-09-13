#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, maxDays;

	cin >> n >> maxDays;

    multiset<int> deltaOfDays;

    vector<int> days(n);

    for(auto& i : days)
        cin >> i;


    int prev = -1;

    int countOfDays = 0;
    int lastSize;

    for(int i = 0; i<(int)days.size(); i++)
    {
        if(days[i]<0)
        {
            countOfDays++;
            if(prev!=-1)
                deltaOfDays.insert(i-prev-1);
            prev = i;
        }
    }
    lastSize = n-prev-1;
    if(countOfDays>maxDays)
    {
        cout << -1;
        return 0;
    }

    if(deltaOfDays.size()==0 && lastSize == n)
    {
        cout << 0;
        return 0;
    }

    while(deltaOfDays.size()&&countOfDays+*deltaOfDays.begin() <= maxDays)
    {
        countOfDays+=*deltaOfDays.begin();
        deltaOfDays.erase(deltaOfDays.begin());
    }


    int ans = 2*(int)deltaOfDays.size() + 2;


    if(countOfDays+lastSize<=maxDays)
        ans--;

    cout << ans;




	return 0;
}
