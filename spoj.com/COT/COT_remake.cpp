#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;


struct PersistentSegmentTree
{
    struct Node
    {
        Node *l{}, *r{};
        int value{};

        Node(){}

        Node(Node * l, Node * r, int value) : l(l), r(r), value(value + Node::getValue(l) + Node::getValue(r)) {}

        static int getValue(Node * nd)
        {
            if(nd == nullptr)
                return 0;
            return nd->value;
        }
    };

    struct MemoryManager
    {
        vector<Node> mem{200*1000*20};
        int be{0};

        Node * operator()(Node * l = nullptr, Node * r = nullptr, int value = 0)
        {
            assert(be != (int)mem.size());
            mem[be] = Node(l,r,value);
            return &mem[be++];
        }
    } new_Node{};

    vector<Node*> roots{new_Node()};
    int L{0}, R{200*1000};

    Node * _set(Node * cur, int pos, int minL, int maxR)
    {
        if(pos<minL || maxR<pos)
            return cur;

        if(minL == maxR)
        {
            if(cur == nullptr)
                return new_Node(nullptr, nullptr, 1);
            else
                return new_Node(nullptr, nullptr, Node::getValue(cur) + 1);
        }

        int mid = (minL + maxR)/2;

        if(cur == nullptr)
            return new_Node(_set(nullptr, pos, minL, mid),
                            _set(nullptr, pos, mid+1, maxR));

        return new_Node(_set(cur->l, pos, minL, mid),
                        _set(cur->r, pos, mid+1, maxR));
    }

    int set(int madeFrom, int pos)
    {
        roots.push_back(_set(roots[madeFrom], pos, L, R) );
        return (int)roots.size() - 1;
    }

    int get(vector<Node*> & toFind, int k)
    {
        k = min(Node::getValue(toFind[0]) + Node::getValue(toFind[1]) - Node::getValue(toFind[2]) - Node::getValue(toFind[3]), k);


        int l = L, r = R;

        vector<Node*> tmp(4);

        while(l!=r)
        {
            for(int i = 0; i<4; i++)
                if(toFind[i] == nullptr)
                    tmp[i] = nullptr;
                else
                    tmp[i] = toFind[i]->l;

            int leftVal = Node::getValue(tmp[0]) + Node::getValue(tmp[1]) - Node::getValue(tmp[2]) - Node::getValue(tmp[3]);

            if(leftVal < k)
            {
                k -= leftVal;

                for(int i = 0; i<4; i++)
                if(toFind[i] != nullptr)
                    toFind[i] = toFind[i]->r;

                l = (l+r)/2 + 1;
            }
            else
            {
                toFind = tmp;
                r = (l+r)/2;
            }
        }

        return l;

    }

    int get(vector<int> I, int k)
    {
        vector<Node*> toFind;
        for(auto i : I)
            toFind.push_back(roots.at(i));
        return get(toFind, k);
    }

};

struct LCA
{
    int steps{};
    vector<vector<int> > & e;
    vector<vector<int> > p{e.size()};
    vector<int> tIn{vector<int>(e.size())}, tOut{tIn};

    LCA(vector<vector<int>> & E) : e(E) {}



    int dfs(int v, int parent, int t)
    {
        int teBe = t;
        tIn[v] = t;

        p[v].push_back(parent);

        for(auto i : e[v])
            if(i!=parent)
            {
                t += dfs(i, v, t);
            }

        tOut[v] = t;
        return t-teBe+1;
    }

    void build(int root)
    {
        dfs(root, root, 0);

        steps = 3;
        {
            int tmp = e.size();
            while(tmp/=2)
                steps++;
        }

        for(int _i = 0; _i+1<steps; _i++)
        {
            for(int i = 1; i<(int)e.size(); i++)
            {
                p[i].push_back(p[p[i][_i]][_i]);

            }
        }
    }

    bool isParent(int p, int s)
    {
        return tIn[p] <= tIn[s] && tIn[s] <= tOut[p];
    }

    int getLCA(int x, int y)
    {
        if(isParent(x,y))
            return x;
        if(isParent(y,x))
            return y;
        for(int i = steps-1; i>=0; i--)
        {
            if(!isParent(p[x][i], y))
                x = p[x][i];
        }

        return p[x][0];
    }

};


struct Tree
{
    int size{};

    vector<int> num{vector<int>(size)};
    vector<vector<int> > e{(size_t)size};

    vector<int> p{num};
    vector<int> version{num};
    LCA lca{e};
    PersistentSegmentTree PST{};


    Tree(int sz) : size(sz) {}

    void addEdge(int x, int y)
    {
        e[x].push_back(y);
        e[y].push_back(x);
    }

    void dfs(int v, int parent)
    {
        p[v] = parent;
        version[v] = PST.set(version[parent], num[v]);

        for(auto i : e[v])
        {
            if(i != parent)
                dfs(i, v);
        }
    }

    void build()
    {
        lca.build(1);
        version[0] = 0;
        dfs(1,0);
    }

    int getKthNumber(int x, int y, int k)
    {
        int _lca = lca.getLCA(x,y);
        return PST.get({version[x], version[y], version[_lca], version[p[_lca]]}, k);
    }
};

struct Compressed
{
    vector<long long> a;

    Compressed(const vector<long long> & source) : a(source)
    {
        sort(a.begin(), a.end());
    }

    int operator () (long long x)
    {
        return lower_bound(a.begin(), a.end(), x) - a.begin();
    }

    long long operator [] (int x)
    {
        return a[x];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    Tree T(n+1);
    assert(n < 200*1000);

    vector<long long> numUncompressed(n);

    for(int i = 0; i<n; i++)
    {
        cin >> numUncompressed[i];
    }

    Compressed C(numUncompressed);

    for(int i = 0; i<n; i++)
    {
        T.num[i+1] = C(numUncompressed[i]);
    }

    for(int i = 1; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        T.addEdge(x,y);
    }

    T.build();

    for(int i = 0; i<m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        cout << C[T.getKthNumber(x,y,k)] << '\n';
    }


    return 0;
}
