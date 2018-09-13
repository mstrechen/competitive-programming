#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

using namespace std;

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:256000000")

#define endl '\n'
#define MIN(a, b) ((a)<(b)) ? (a) : (b)
#define MAX(a, b) ((a)>(b)) ? (a) : (b)
#define I (int)
#define LL long long
#define LD long double
#define U unsigned
#define X first
#define Y second
#define PB push_back
#define MP make_pair

FILE* stream;

const int INF = 1e9 + 7;
const LL INFL = (LL)1e18;
const int SIZE = 2e7 + 10;
const int TSIZE = 1e3 + 10;
const LD eps = 0.00000001;
const long long MOD = 1e9 + 7;

char POW(char a, char b)
{
	if (b == 0)
		return 1;
	char cur = POW(a, b / 2);
	if (b % 2 == 0)
		return cur * cur;
	else
		return cur * cur * a;
}
string s1, s = "";
void accept()
{
	int m;
	cin >> m;
	set < pair <int, int> > ends;
	cin >> s1;
	int sz = s1.size();
	vector < pair <char, int> > c(sz), ans;
	for (int i = 0; i < sz; i++)
	{
		c[i] = MP(s1[i], i);
	}
	sort(c.begin(), c.end());
	vector <char> used(s1.size());
	for (int i = 0; i < sz; i++)
	{
		int l = max(c[i].second - m + 1, 0);
		int r = min(c[i].second + m - 1, sz - 1);
		set < pair <int, int> >::iterator it1 = lower_bound(ends.begin(), ends.end(), MP(l, r)), it;
		it = it1;
		int p = 0;
		if (it != ends.begin())
		{

			it--;
			if (it != ends.end())
			{
				if (it->second - l >= m - 2)
				{
					l = min(it->first, l);
					r = max(r, it->second);
					if (it->first <= l && it->second >= r)
					{
						if (ends.size() > 1 || (ends.size() > 0 && ends.begin()->first != 0 && ends.begin()->second != s1.size() - 1) )
						{
							used[c[i].second] = 1;
							ans.push_back(c[i]);
						}
						continue;
					}
					p = 1;
					ends.erase(it);
				}
			}
		}
		it = it1;
		if (it != ends.end())
		{
			if (it->first <= l && it->second >= r && !p)
			{
				if (ends.size() > 1 || (ends.size() > 0 && ends.begin()->first != 0 && ends.begin()->second != s1.size() - 1))
				{
					used[c[i].second] = 1;
					ans.push_back(c[i]);
				}
				continue;
			}
			if (r - it->first >= m - 2)
			{
				r = max(r, it->second);
				ends.erase(it);
			}

		}
		ends.insert(MP(l, r));
		ans.push_back(c[i]);
		used[c[i].second] = 1;
	}
	int l = -1, r = 0, cur = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (used[i] == 1 && l != i)
		{
			r = i;
			break;
		}
	}
	used[s1.size()]++;
	for (int i = 0; i < s1.size(); i++)
	{
		if (i >= r)
		{
			r++;
			while (!used[r])
			{
				r++;
			}
		}
		if (s1[i] == ans[ans.size() - 1].first && used[i])
		{
			if (r - l <= m)
			{
				used[i] = 0;
			}
			else
				l = i;
		}
		if (used[i])
			l = i;
	}
	ans.clear();
	for (int i = 0; i < s1.size(); i++)
		if (used[i])
			ans.push_back(MP(s1[i], 0));
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%c", ans[i].first);
}

void solution()
{
	/*long long t;
	cin >> t;
	for (long long i = 0; i < t; i++)
	{
	accept();
	}
	*/

	accept();
	return;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

#ifdef SpOleM98
	//Generation test
	//freopen("input.txt", "w", stdout);

	//Read data from fail
	freopen("input.txt", "r", stdin);

	//Write answer in fail
	//freopen("output.txt", "w", stdout);
	double beg = clock();
#endif
	srand(time(0));
	solution();

	/*
	cout << "65000\n";
	for (int k = 0; k < 9; k++)
	{
	for (int i = 1; i <= 65000; i++)
	{
	cout << i << " ";
	}
	cout << endl;
	}
	*/

#ifdef SpOleM98
	double end = clock();
	fprintf(stderr, "\n*** Total time = %.3f ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
