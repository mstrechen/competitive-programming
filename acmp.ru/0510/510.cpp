#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int len;
    cin >> len;

    vector<long long>   dpF(len+1,0),
                        dpG(len+1,0);

    dpF[0] = dpG[0] = 1;

    for(int i = 2; i<=len; i++)
    {
        dpF[i] = dpF[i-2] + 2*dpG[i-2];
        dpG[i] = dpF[i] + dpG[i-2];
    }
    cout << dpF[len];

    return 0;
}
