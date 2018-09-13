#include<iostream>
#include<vector>
#include<set>

using namespace std;

int getCode(int i, int j)
{
    return i*55+j;
}
struct DSU
{
    vector<int> parent, sizes;
    DSU()
    {
        parent.assign(10000,0);
        for(int i = 0; i<10000; i++)
            parent[i] = i;
        sizes.assign(10000,0);
    }
    int get(int i)
    {
        if(parent[i]==i)
            return i;
        return (parent[i] = get(parent[i]));
    }
    pair<int,int> getWithSize(int i)
    {
        i = get(i);
        return {sizes[i],i};
    }
    void unite(int i, int j)
    {
        i = get(i);
        j = get(j);
        if(i!=j)
        {
            sizes[i]+=sizes[j];
            sizes[j] = 0;
            parent[j] = i;
        }
    }
} field;

char A[100][100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i<100; i++)
        for(int j = 0;j<100; j++)
            A[i][j] = '.';

    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
        {
            cin >> A[i][j];
            if(A[i][j]=='.')
                field.sizes[getCode(i,j)] = 1;
        }
    field.sizes[0] = 1000000;

    for(int i = 0; i<=n+1; i++)
    {
        for(int j = 0; j<=m+1; j++)
        {
            if(A[i][j]=='.'&&A[i][j+1]=='.')
                field.unite(getCode(i,j), getCode(i,j+1));
            if(A[i][j]=='.'&&A[i+1][j]=='.')
                field.unite(getCode(i,j), getCode(i+1,j));
        }
    }
    set<pair<int,int> > allSizes;

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            if(A[i][j]=='.')
                allSizes.insert(field.getWithSize(getCode(i,j)));
        }
    }
    set<int> toDelete;
    k = allSizes.size()-k-1;
    int countOfFulled = 0;
    for(int i = 0; i<k; i++)
    {
        toDelete.insert(allSizes.begin()->second);
        countOfFulled+=allSizes.begin()->first;
        allSizes.erase(allSizes.begin());
    }
    cout << countOfFulled << '\n';
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(A[i][j]=='*'||toDelete.count(field.get(getCode(i,j))))
                cout << '*';
            else
                cout << '.';

        }
        cout << '\n';
    }

    return 0;
}
