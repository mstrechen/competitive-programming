#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cyclelen;
    cin >> n >> cyclelen;
    vector<int> truth(cyclelen);

    for(int i = 0; i < cyclelen; i++){
        cout << i + 1 << endl;
        int ans;
        cin >> ans;
        if(ans == -2)
            return 12;
        if(ans == 0)
            return 0;
        truth[i] = ans;
    }

    int l = cyclelen + 1, r = n + 1, i = 0;
    while(l + 1 < r){
        int mid = (l + r)/2;
        int ans;
        cout << mid << endl;
        cin >> ans;
        if(ans == -2)
            return 12;
        ans *= truth[i];

        if(ans == 0)
            return 0;
         

        if(ans < 0)
            r = mid;
        else 
            l = mid;
        i++;
        i %= cyclelen;
    }
    cout << l << endl;
    return 0;
}