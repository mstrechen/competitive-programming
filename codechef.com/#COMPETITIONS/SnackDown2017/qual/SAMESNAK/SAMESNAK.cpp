#include<iostream>

using namespace std;

struct point
{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator < (const point & A, const point & B)
{
    if(A.x == B.x)
        return A.y < B.y;
    else
        return A.x < B.x;
}
bool operator == (const point & A, const point & B)
{
    return A.x == B.x && A.y == B.y;
}

istream & operator >> (istream & in, point & toRead)
{
    in >> toRead.x >> toRead.y;
    return in;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    point A1, A2, B1, B2;

    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> A1 >> A2;
        cin >> B1 >> B2;
        if(A1 == B1 || A1 == B2 ||
           A2 == B1 || A2 == B2)
        {
            cout << "yes\n";
            continue;
        }
        else
        {
            if(A1.x == A2.x && B1.x == B2.x)
            {
                int l = max(min(A1.y, A2.y), min(B1.y, B2.y)),
                    r = min(max(A1.y, A2.y), max(B1.y, B2.y));
                if(l <= r)
                {
                    cout << "yes\n";
                    continue;
                }

            }
            if(A1.y == A2.y && B1.y == B2.y)
            {
                int l = max(min(A1.x, A2.x), min(B1.x, B2.x)),
                    r = min(max(A1.x, A2.x), max(B1.x, B2.x));
                if(l <= r)
                {
                    cout << "yes\n";
                    continue;
                }

            }

        }

        cout << "no\n";
    }



    return 0;
}
