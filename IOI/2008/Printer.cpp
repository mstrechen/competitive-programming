#include<iostream>
#include<fstream>
#include<memory>


using namespace std;

const int alphabet = 'z' - 'a' + 1;

struct Node
{
    unique_ptr<Node*[]> sons{new Node*[alphabet]};
    bool isTheEnd{0};
    int maxDepth{0}, num{-1};

    Node()
    {
        for(int i = 0; i<alphabet; i++)
            sons[i] = nullptr;
    }
};

struct Trie
{
    Node * root{new Node};

    mutable string _res{};

    void insert(const string & s)
    {
        Node * current = root;

        for(int _i = 0; _i<(int)s.size(); _i++)
        {
            int i = s[_i] - 'a';
            int pos = (int)s.size() - _i;
            if(current->sons[i] == nullptr)
                current->sons[i] = new Node;

            if(current->maxDepth < pos)
            {
                current->maxDepth = pos;
                current->num = s[_i] - 'a';
            }

            current = current->sons[i];
        }
        current->isTheEnd = 1;
    }

    void dfs(Node * current) const
    {
        if(current->isTheEnd)
            _res.push_back('P');
        for(int i = 0; i<alphabet; i++)
            if(current->sons[i] != nullptr && i != current->num)
            {
                _res.push_back(char('a' + i));
                dfs(current->sons[i]);
            }

        if(current->num!=-1)
        {
            _res.push_back(char('a' + current->num));
            dfs(current->sons[current->num]);
        }


        _res.push_back('-');
    }

    string && getPrinted() const
    {
        _res.clear();
        dfs(root);
        while(_res.size() && _res.back() == '-')
            _res.pop_back();

        return move(_res);
    }

};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string tmp;
    Trie Tr;

    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        Tr.insert(tmp);
    }

    tmp = Tr.getPrinted();

    cout << tmp.size() << '\n';
    for(auto i : tmp)
        cout << i << '\n';

    return 0;
}
