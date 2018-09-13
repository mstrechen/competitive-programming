#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

using UInt = unsigned int;

const UInt MOD = 1000*1000*1000 + 7;
long long maxVal = 1e18;



struct PersistentSegmentTree
{
    struct Node
    {
        UInt val;
        Node * l, * r;

        static UInt getVal(Node * a)
        {
            if(a == nullptr)
                return 0;
            return a->val;
        }

        Node(UInt val = 0, Node * L = nullptr, Node * R  = nullptr) : val( (val + getVal(L) + getVal(R))%MOD ), l(L), r(R) {}
    };



    Node * root{new Node()};
    long long L{1}, R{1};


    PersistentSegmentTree(int x) : root(new Node(UInt(x))){}

    void copy()
    {
        if(R > maxVal)
            return;

        R*=2;
        root = new Node(0, root, root);
    }

    UInt _get(Node * cur, long long l, long long r, long long minL, long long maxR)
    {
        if(l>r)
            return 0;

        if(cur == nullptr)
            return 0;
        if(l == minL && r == maxR)
            return Node::getVal(cur);

        long long mid = (minL+maxR)/2;
        return (_get(cur->l, l, min(mid, r), minL, mid) +
                _get(cur->r, max(mid+1, l), r, mid+1, maxR))%MOD;

    }

    UInt get(long long l, long long r)
    {
        return _get(root, l, r, L, R);
    }


    Node * _set(Node * cur,long long pos, UInt val, long long minL, long long maxR)
    {
        if(pos < minL || maxR < pos)
            return cur;
        if(minL == maxR)
            return new Node(val);

        long long mid = (minL+maxR)/2;
        if(cur == nullptr)
            return new Node(0, _set(nullptr, pos, val, minL, mid),
                               _set(nullptr, pos, val, mid+1, maxR));
        return new Node(0, _set(cur->l, pos, val, minL, mid),
                           _set(cur->r, pos, val, mid+1, maxR));
    }

    void set(long long pos, UInt val)
    {
        root = _set(root,pos, val, L, R);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int x;
    cin >> x;

    PersistentSegmentTree PST(x);

    int q;
    cin >> q;

    string query;
    long long X, Y;

    while(q--)
    {
        cin >> query;
        if(query[0] == 'S')
        {
            cin >> X >> Y;
            cout << PST.get(X,Y) << '\n';
        }
        else
        if(query[1] == 'O')
        {
            PST.copy();
        }
        else
        {
            cin >> X >> Y;
            PST.set(X, (UInt)Y);
        }
    }
    return 0;
}
