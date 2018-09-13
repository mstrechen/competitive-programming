#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;


struct PersistentSegmentTree
{
    struct Node
    {
        Node *l, *r;
        int value;

        Node()
        {

        }

        Node(Node * l, Node * r, int value = 0) : l(l), r(r), value(value + getValue(l) + getValue(r))
        {

        }

        static int getValue(Node * nd)
        {
            if(nd == nullptr)
                return 0;
            return nd->value;
        }
    };

    struct MemoryManager
    {
        vector<Node> mem{100*1000*4*20};
        int be{0};

        Node * operator () (Node * l = nullptr, Node * r = nullptr, int value = 0)
        {
            mem[be] = Node(l,r,value);
            return &mem[be++];
        }
    } new_Node;

    vector<Node*> roots{{new_Node()}};
    int L{1}, R{100*1000};


    Node * _set(Node * cur, int pos, int minL, int maxR)
    {
        if(pos<minL || maxR<pos)
            return cur;
        if(minL == maxR)
            if(cur == nullptr)
                return new_Node(nullptr, nullptr, 1);
            else
                return new_Node(nullptr, nullptr, cur->value^1);

        int mid = (minL+maxR)/2;

        if(cur == nullptr)
            return new_Node(_set(nullptr, pos, minL, mid),
                            _set(nullptr, pos, mid+1, maxR));
        return new_Node(_set(cur->l, pos, minL, mid),
                        _set(cur->r, pos, mid+1, maxR));
    }

    void set(int pos, bool createNew = 0)
    {
        pos++;
        if(createNew)
            roots.push_back(_set(roots.back(), pos, L, R));
        else
            roots.back() = _set(roots.back(), pos, L, R);
    }

    int get(int pos, int k)
    {
        pos--;
        if(Node::getValue(roots[pos]) < k)
            return 0;

        int l = L, r = R;

        Node * cur = roots[pos], * next ;
        while(l!=r)
        {
            if(cur == nullptr)
                next = nullptr;
            else
                next = cur->l;
            if(Node::getValue(next) < k)
            {
                k -= Node::getValue(next);
                if(cur != nullptr)
                    cur = cur->r;
                l = (l+r)/2 + 1;

            }
            else
            {
                cur = next;
                r = (r+l)/2;
            }

        }
        return l;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("rollback.in");
    ofstream cout("rollback.out");


    int n, m;
    cin >> n >> m;

    vector<int> a(n), next(n), isFirst(n);

    for(int i = 0; i<n; i++)
        cin >> a[i];

    {
        map<int,int> lastOccurance;

        for(int i = n-1; i>=0; i--)
        {
            if(lastOccurance[a[i]] != 0)
            {
                next[i] = lastOccurance[a[i]];
                isFirst[lastOccurance[a[i]]] = 0;
            }
            else
            {
                next[i] = -1;
            }
            isFirst[i] = 1;
            lastOccurance[a[i]] = i;
        }
    }

    PersistentSegmentTree PST;

    for(int i = 0; i<n; i++)
    if(isFirst[i])
    {

        PST.set(i);
    }

    for(int i = 1; i<n; i++)
    {
        PST.set(i-1, 1);
        PST.set(next[i-1]);
    }

    int q, p = 0;
    cin >> q;

    for(int i = 0; i<q; i++)
    {
        int l, k;
        cin >> l >> k;
        l = (l+p)%n + 1;
        k = (k+p)%m + 1;

        p = PST.get(l,k);
        cout << p << '\n';
    }

    return 0;
}
