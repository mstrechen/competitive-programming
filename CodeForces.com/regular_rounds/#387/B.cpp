#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	int n;

	cin >> n;

	cin >> s;


	vector<pair<int,char> > nuks = {{0,'A'}, {0,'C'},{0,'G'}, {0,'T'}};

	for(int i = 0; i<n; i++)
    {
        if(s[i]=='A')
            nuks[0].first++;
        if(s[i]=='C')
            nuks[1].first++;
        if(s[i]=='G')
            nuks[2].first++;
        if(s[i]=='T')
            nuks[3].first++;
    }

    if(n%4!=0 || nuks[0].first>n/4 || nuks[1].first>n/4 || nuks[2].first>n/4 || nuks[3].first>n/4)
    {
        cout << "===";
        return 0;
    }

    for(int i = 0; i<n; i++)
    {
        if(s[i]=='?')
        {
            sort(nuks.begin(), nuks.end());
            cout << nuks.begin()->second;
            nuks.begin()->first++;
        }
        else
            cout << s[i];
    }
	return 0;
}
