#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


struct DSU
{
    vector<int> p, ant;

    DSU(int n) : p(n), ant(n,-1)
    {
        for(int i = 0; i<n; i++)
            p[i] = i;
    }

    int get(int i)
    {
        if(p[i] == i)
            return i;
        return p[i] = get(p[i]);
    }

    bool uniteSyn(int i, int j)
    {
        i = get(i);
        j = get(j);

        if(ant[i] == j)
            return false;

        if(i == j)
            return true;

        if(ant[i] == -1)
            swap(i,j);

        if(ant[i] != -1)
        {
            if(ant[j] != -1)
            {
                p[ant[j]] = ant[i];
            }
        }
        p[j] = i;

        return true;
    }

    bool uniteAnt(int i, int j)
    {
        i = get(i);
        j = get(j);

        if(i == j)
            return false;
        if(ant[i] == j)
            return true;

        if(ant[i] != -1 || ant[j] != -1)
        {
            if(ant[i] != -1)
                uniteSyn(ant[i], j);
            else
                uniteSyn(ant[j], i);
        }
        else
        {
            ant[i] = j;
            ant[j] = i;
        }

        return true;
    }

    int typeOfCon(int i, int j)
    {
        i = get(i);
        j = get(j);

        if(i == j)
            return 1;
        if(i == ant[j])
            return 2;
        return 3;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q1, q2;

    cin >> n >> q1 >> q2;

    string tmpA, tmpB;
    vector<string> dict(n);
    DSU dsu(n);


    for(int i = 0; i<n; i++)
    {
        cin >> dict[i];
    }

    sort(dict.begin(), dict.end());
    for(int i = 0; i<q1; i++)
    {
        int type;
        cin >> type >> tmpA >> tmpB;

        bool res;
        if(type == 1)
        {
            res = dsu.uniteSyn(lower_bound(dict.begin(), dict.end(), tmpA) - dict.begin(), lower_bound(dict.begin(), dict.end(), tmpB) - dict.begin());
        }
        else
        {
            res = dsu.uniteAnt(lower_bound(dict.begin(), dict.end(), tmpA) - dict.begin(), lower_bound(dict.begin(), dict.end(), tmpB) - dict.begin());
        }
        cout << (res?"YES\n" : "NO\n");
    }

    for(int i = 0; i<q2; i++)
    {
        cin >> tmpA >> tmpB;
        cout << dsu.typeOfCon(lower_bound(dict.begin(), dict.end(), tmpA) - dict.begin(), lower_bound(dict.begin(), dict.end(), tmpB) - dict.begin()) << '\n';
    }

    return 0;
}
