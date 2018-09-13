#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


struct node
{
    long long sum, add;
    node * left, * right;
    node(long long sum = 0, long long add = 0) : sum(sum), add(add){}
    node(node * left, node * right, long long add) :  left(left),
                                                          right(right),
                                                          sum(left->sum + right->sum),
                                                          add(add){}
    node(node * source) : sum(source->sum),
                          add(source->add),
                          left(source->left),
                          right(source->right){}

 };

struct PersistentSegmentTree
{
    vector<node *> roots;
    int _size;
    PersistentSegmentTree(int n, istream & in)
    {
        _size = 1;
        while(_size<n)
            _size*=2;

        vector<node * > nodes(_size);
        for(auto & i : nodes)
            i = new node(0,0);


        for(int i = 0; i<n; i++)
            cin >> nodes[i]->sum;



        for(int curSize = _size/2; curSize; curSize/=2)
            for(int i = 0; i<curSize; i++)
            {
                nodes[i] = new node(nodes[i*2], nodes[i*2+1],0);
            }
        roots.assign(1,nodes[0]);
    }

    long long _get(int l, int r, int minL, int maxR, node * current)
    {
        if(l>r)
            return 0;
        if(l == minL && r == maxR)
            return current->sum + (r-l+1)*current->add;

        int mid = (minL+maxR)/2;
        return (r-l+1)*current->add +
                _get(l, min(r,mid), minL, mid, current->left) +
                _get(max(l,mid+1), r, mid+1, maxR, current->right);

    }
    long long get(int l, int r, int version)
    {
        roots.push_back(roots[version]);
        return _get(l, r, 1, _size, roots[version]);
    }

    node * _update(int l, int r, int minL, int maxR, node * current, long long val)
    {
        if(l>r)
            return current;

        if(l == minL && r == maxR)
        {
            node * res = new node(current);
            res->add += val;
            return res;
        }
        int mid = (minL+maxR)/2;



        node * res = new node(_update(l, min(r,mid), minL, mid, current->left, val),
                              _update(max(l,mid+1),r,  mid+1, maxR, current->right, val));
        res->sum+=(mid-minL + 1)*res->left->add;
        res->sum+=(maxR-mid)*res->right->add;
        return res;
    }

    void update(int l, int r, long long val, int version)
    {
        roots.push_back(_update(l,r,1,_size, roots[version], val));
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    PersistentSegmentTree PST(n,cin);

    int l, r;
    vector<int> versions = {0};
    int current_version = 0;

    for(int i = 0; i<q; i++)
    {
        char qType;
        cin >> qType;
        if(qType == 't')
        {
            int t;
            cin >> current_version;
            current_version--;
        }
        else
        if(qType == '+')
        {
            int l, r, val;
            cin >> l >> r >> val;
            PST.update(l,r,val,current_version);
            current_version = PST.roots.size() - 1;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << PST.get(l,r,current_version) << endl;
            current_version = PST.roots.size() - 1;
        }
    }


    return 0;
}
