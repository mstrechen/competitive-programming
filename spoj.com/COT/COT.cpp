#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

struct Compressed
{
    vector<int> a;

    Compressed(const vector<int> & source = {}) : a(source)
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

    int add(int value, int source)
    {
        roots.push_back(_add(roots[source], value, L, R));
        return (int)roots.size() - 1;
    }

    int _getKthNumber(vector<Node *> nds, int k)
    {
        int l = L, r = R;
        vector<Node *> ndsL(4);
        while(l!=r)
        {
            for(int i = 0; i<4; i++)
            {
                if(nds[i] == nullptr)
                    ndsL[i] = nullptr;
                else
                    ndsL[i] = nds[i]->l;
            }

            int sum = Node::getValue(ndsL[0]) + Node::getValue(ndsL[1]) -
                      Node::getValue(ndsL[2]) - Node::getValue(ndsL[3]);
            if(sum < k)
            {
                k-=sum;
                l = (l+r)/2;
                for(int i = 0; i<4; i++)
                {
                    if(nds[i] != nullptr)
                        nds[i] = nds[i]->r;
                }
            }
            else
            {
                nds = ndsL;
                r = (r+l)/2;
            }

        }

        return l;
    }

    int getKthNumber(int A, int B, int LCA, int LCAP, int k)
    {
        return _getKthNumber({roots[A], roots[B], roots[LCA], roots[LCAP]}, k);
    }
};

struct SegmentTree
{
    pair<int, int> nothing{1000*1000*1000, 0};

    int size;
    vector<pair<int,int> >  values{};

    SegmentTree(const vector<pair<int,int> > & src = {}) : size(src.size())
    {
        while(size&(size-1))
            size&=size-1;
        if(size != (int)src.size())
            size*=2;

        values.assign(size*2, nothing);

        for(int i = 0; i<(int)src.size(); i++)
            values[i+size] = src[i];
        for(int i = size-1; i>0; i--)
            values[i] = min(values[i*2], values[i*2 + 1]);
    }

    pair<int, int> _getMin(int l, int r, int minL, int maxR, int _i)
    {
        if(l>r)
        return nothing;

        if(l == minL && r == maxR)
            return values[_i];

        int mid = (minL+maxR)/2;

        return min(_getMin(l, min(mid, r), minL, mid, _i*2),
                   _getMin(max(mid+1,l), r, mid+1, maxR, _i*2+1));
    }

    int getMin(int l, int r)
    {
        if(l>r)
            swap(l,r);
        return _getMin(l, r, 1, size, 1).second;
    }
};

struct Tree
{
    int size;
    vector<vector<int>> e{(size_t)size};
    vector<int> num{size};
    Compressed compressed{};

    vector<int> parent{size};
    vector<int> timeIn{size};
    vector<int> version{size};
    PersistentSegmentTree PST{};
    vector<int> depth{size};

    vector<pair<int, int> > inOut{};
    SegmentTree inOutST{};

    Tree(int size) : size(size){}

    void addEdge(int x, int y){e[x].push_back(y); e[y].push_back(x); }

    void dfs(int v, int from, int cur_depth)
    {
        depth[v] = cur_depth;
        parent[v] = from;

        inOut.emplace_back(cur_depth, v);
        timeIn[v] = inOut.size();

        cout << "O" << ' ' << v << ' ' << from << ' ';
        version[v] = PST.add(compressed(num[v]), version[from]);
        cout << "K" << endl;

        for(auto i : e[v])
        if(i!=from)
        {
            dfs(i, v, cur_depth+1);
            inOut.emplace_back(cur_depth, v);
        }

    }

    void build()
    {
        num[0] = 0;
        depth[0] = 0;
        version[0] = 0;

        compressed = Compressed(num);

        dfs(1, 0, 1);

        inOutST = SegmentTree(inOut);


    }

    int getKthNumber(int x, int y, int k)
    {
        int LCA = inOutST.getMin(timeIn[x], timeIn[y]);

        if(depth[x] + depth[y] - 2*depth[LCA] + 1 < k)
            return -1;
        return PST.getKthNumber(version[x], version[y], version[LCA], version[parent[LCA]], k);

    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Tree T(n+1);


    for(int i = 1; i<=n; i++)
    {
        cin >> T.num[i];
    }

    for(int i = 1; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        T.addEdge(x, y);
    }

    for(int i = 0; i<=n; i++)
    {
        for(auto j : T.e[i])
            cout << j << ' ';
        cout << endl;
    }
    T.build();

    for(int i = 0; i<m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        cout << T.getKthNumber(x,y,k) << endl;
    }

    return 0;
}
