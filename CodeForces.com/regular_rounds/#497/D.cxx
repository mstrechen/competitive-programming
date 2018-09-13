#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Eratosthenes{
    int n;
    vector<int> a;
    Eratosthenes(int n ) : a(n, 0){
        a[0] = 0;
        a[1] = 1;
        for(int i = 2; i * i <= n; i++){
            if(a[i] == 0){
                a[i] = i;
                cout << i << endl;
            }
            
            for(int j = 2; i * j < n; j++)
                if(a[i * j] == 0)
                    a[i * j] = i;
        
        }
        for(int i = 1; i <=20; i++)
         cout << a[i] << ' ';
        for(int i = 2; i < n; i++)
        if(a[i] == 0)
            a[i] = i;
    }

    long long getDivCnt(int x){
        if(x == 1)
            return 1;
        long long ans = 0;
        int prev = -1;
        int cnt = 1;
        while(x != 1){
            cout << x <<  " - ";
            cout << a[x] << endl;
            if(a[x] == prev)
                cnt++,
                x /= prev;
            else{
                ans *= cnt;
                cnt = 1;
                prev = a[x];
                x /= prev;
            }       
        }
        ans *= cnt;
        
        return ans;
    }
    int gcd(int x, int y){
        while(x && y){
            x %= y;
            swap(x, y);
        }
        return x + y;
    }


    long long getCountOfSamePairs(int x, int y){
        int a = gcd(x, y);
        long long ans = getDivCnt(a);
        return (ans * (ans - 1)) / 2;
    }

} E(1000 + 500);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        //int x = a[0], y = a[1], z = a[2];
        long long ans = 0;

        cout << E.getDivCnt(100) << endl;

        cout << ans << endl;
    }

    
    

    return 0;
}