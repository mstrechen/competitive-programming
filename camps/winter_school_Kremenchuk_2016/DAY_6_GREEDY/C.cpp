#include<iostream>

using namespace std;

struct Segment
{
    int l, r, c;
    Segment(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c){}
};

istream & operator >> (istream & inStream, Segment & toRead)
{
    inStream >> toRead.l >> toRead.r >> toRead.c;
    return inStream;
}

struct Segments
{
    vector<Segment> _segments;

    Segments(istream & inStream)
    {
        int n;
        inStream >> n;
        _segments.assign(n,{0,0,0});

        for(auto & i : _segments)
            inStream >> i;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int q;
    cin >> q;

    while(q--)
    {
        Segments segments(cin);
        cout << segments.getAns();
    }

    return 0;
}
