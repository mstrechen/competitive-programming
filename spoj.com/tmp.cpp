#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

const int MAXNUM = 10000;

bool cmp(int a, int b){
    return __builtin_popcount(a) > __builtin_popcount(b);
}

int firstOne(int a){
    if(a == 0)
        return a;
    return 32 - __builtin_clz(a);
}

int bettermask(int * a, int n, int m1, int m2){
    if(__builtin_popcount(m1) != __builtin_popcount(m2))
        return __builtin_popcount(m1) < __builtin_popcount(m2) ? m2 : m1;
    int i1 = 0, i2 = 0;
    for(int i = 0; i < n; i++){
        while(((m1 >> i1)&1) == 0)
            i1++;
        while(((m2 >> i2)&1) == 0)
            i2++;
        if(a[i1] < a[i2])
            return m1;
        if(a[i1] > a[i2])
            return m2;
        i1++;
        i2++;
    }
    return m1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int> > numbers(MAXNUM+1);
    vector<int> masks;
    for(int i = 0; i < 32; i++)
        masks.push_back(i);

    sort(masks.begin(), masks.end(), cmp);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        numbers[tmp].push_back(i);
    }

    int q;
    cin >> q;
    int a[5];
    while(q--){
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> a[j];
        bool flag = 1;
        int maxmask = 0;
        for(int _i = 0; _i < 32; _i++)
            if(firstOne(masks[_i]) <= n)
            {
                if(__builtin_popcount(maxmask) > __builtin_popcount(masks[_i]))
                    break;

                int first = -1;
                int mask = masks[_i];
                for(int i = 0; i < n && first != -3; i++)
                if((mask >> i)&1)
                {
                    auto it = upper_bound(numbers[a[i]].begin(), numbers[a[i]].end(), first);
                    if(it == numbers[a[i]].end())
                        first = -3;
                    else
                        first = *it;
                }
                if(first != -3)
                    maxmask = bettermask(a, __builtin_popcount(mask), maxmask, mask);

            }
        cout << __builtin_popcount(maxmask);
        for(int i = 0; i < n; i++)
            if((maxmask >> i)&1)
                cout << ' ' << a[i];
        cout << '\n';
     }



    return 0;
}
