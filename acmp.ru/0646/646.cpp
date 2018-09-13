#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, k;
    cin >> n >> k;

    vector<int> boxes(n);

    for(auto & i : boxes)
        cin >> i;

    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    int sizeBe = n/2,
        sizeEn = (n-1)/2 + 1;

    vector<long long> sumBe(1 << sizeBe), sumEn(1 << sizeEn);


    for(int mask = (1 << sizeBe) - 1; mask>=0; mask--)
    {
        long long sum = 0;
        for(int i = 0; i<sizeBe; i++)
            if((mask >> i)&1)
                sum+=boxes[i];
        sumBe[mask] = sum;
    }
    for(int mask = (1 << sizeEn) - 1; mask>=0; mask--)
    {
        long long sum = 0;
        for(int i = 0; i<sizeEn; i++)
            if((mask >> i)&1)
                sum+=boxes[i+sizeBe];
        sumEn[mask] = sum;
    }

    sort(sumEn.begin(), sumEn.end());

    long long ans = 0;
    long long sum = accumulate(boxes.begin(), boxes.end(), 0LL);

    for(auto i : sumBe)
    {
        ans += max(0, upper_bound(sumEn.begin(), sumEn.end(), sum - k - i) - lower_bound(sumEn.begin(), sumEn.end(), k-i));
    }

    cout << ans;



    return 0;
}
