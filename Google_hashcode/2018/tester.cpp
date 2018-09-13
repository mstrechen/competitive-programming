#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;



struct Ride {
	int x1, y1, x2, y2;
	int tl, tr;
	Ride() {}
	Ride(int x1, int y1, int x2, int y2, int tl, int tr) :x1(x1), y1(y1), x2(x2), y2(y2), tl(tl), tr(tr)
	{

	}
	
};

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(int argc, char ** argv)
{
	int n, m;
	int cVehicles, cRides;
	int bonus;
	int t;
	ifstream in(argv[1]);
	ifstream out(argv[2]);
	
	in >> n >> m >> cVehicles >> cRides >> bonus >> t;
	vector<Ride> rides;
	for (int i = 0; i < cRides; ++i)
	{
		int a, b, c, d, e, f;
		in >> a >> b >> c >> d >> e >> f;
		rides.push_back(Ride(a, b, c, d, e, f));
	}

	long long score = 0;

	for (int i = 0; i < cVehicles; ++i)
	{
		int r; out >> r;
		pair<int, int> pos;
		int t = 0;
		for (int j = 0; j < r; ++j)
		{
			int idx; out >> idx;

			int dBetween = dist(make_pair(rides[idx].x2, rides[idx].y2), make_pair(rides[idx].x1, rides[idx].y1));
			int dToStart = dist(pos, make_pair(rides[idx].x1, rides[idx].y1));
			if (dToStart <= rides[idx].tl - t)
				score += bonus;

			int tstart = max(rides[idx].tl, t + dToStart);
			int tend = tstart + dBetween;
			if (tend <= rides[idx].tr)
				score += dBetween;
			t = tend;
			pos = make_pair(rides[idx].x2, rides[idx].y2);
		}
	}

	cout << score;

	return 0;
}