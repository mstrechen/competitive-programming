#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

using namespace std;


struct PersistentSegmentTree
{
    struct Node
    {
        Node *l, *r;
        int cnt;
        Node(Node * l = nullptr, Node * r = nullptr, int add = 0) : l(l), r(r), cnt(add + getValue(l) + getValue(r) ) {}

        static int getValue(Node * nd)
        {
            if(nd == nullptr)
                return 0;
            return nd->cnt;
        }
    };

    struct MemoryManager
    {
        vector<Node> mem{100*1000*20};
        int be{0};

        Node * operator () (Node * l = nullptr, Node * r = nullptr, int add = 0)
        {
            assert(be != (int)mem.size());
            mem[be] = Node(l, r, add);
            return &mem[be++];
        }
    } new_Node{};

    vector<Node*> roots{new_Node()};

    int L{0}, R{100*1000};

    Node * _add(Node * cur, int pos, int minL, int maxR)
    {
        if(pos < minL || maxR < pos)
            return cur;

        if(minL == maxR)
            return new_Node(nullptr, nullptr, Node::getValue(cur) + 1);

        int mid = (minL + maxR)/2;
        if(cur == nullptr)
            return new_Node(_add(nullptr, pos, minL, mid),
                            _add(nullptr, pos, mid+1, maxR));
        return new_Node(_add(cur->l, pos, minL, mid),
                        _add(cur->r, pos, mid+1, maxR));
    }

    void add(int value)
    {
        roots.push_back(_add(roots.back(), value, L, R));
    }

    int _getKthNumber(Node * lRoot, Node * rRoot, int k)
    {
        int l = L, r = R;
        while(l!=r)
        {
            Node * lPart = nullptr, * rPart = nullptr;
            if(lRoot != nullptr)
                lPart = lRoot->l;
            if(rRoot != nullptr)
                rPart = rRoot->l;

            int cntOnPart = Node::getValue(rPart) - Node::getValue(lPart);
            if(cntOnPart < k)
            {
                k-=cntOnPart;
                if(lRoot != nullptr)
                    lRoot = lRoot->r;
                if(rRoot != nullptr)
                    rRoot = rRoot->r;
                l = (l+r)/2 + 1;
            }
            else
            {
                lRoot = lPart;
                rRoot = rPart;
                r = (l+r)/2;
            }
        }

        return l;
    }

    int getKthNumber(int l, int r, int k)
    {
        return _getKthNumber(roots[l-1], roots[r], k);
    }
};

struct Compressed
{
    vector<int> a;

    Compressed(const vector<int> & source) : a(source)
    {
        sort(a.begin(), a.end());
    }

    int operator [](int i)
    {
        return a[i];
    }

    int operator ()(int val)
    {
        return lower_bound(a.begin(), a.end(), val) - a.begin();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<int> values(n);

    for(int i = 0; i<n; i++)
    {
        cin >> values[i];
    }

    PersistentSegmentTree PST;
    Compressed compressed(values);

    for(auto i : values)
    {
        PST.add(compressed(i));
    }

    for(int i = 0; i<m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << compressed[PST.getKthNumber(l, r, k)] << '\n';
    }

    return 0;
}
