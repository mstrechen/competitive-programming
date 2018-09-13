#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    n++;
    vector<int> a(n);
    for(auto & i : a)
        cin >> i;


    for(int _i = 1; _i < n; _i++){
        if(a[_i] > 1 && a[_i-1] > 1){
            cout << "ambiguous\n";
            cout << 0;

            vector<int> b(n);
            b[0] = 1;
            for(int i = 1, current = 2; i < n; i++){
                b[i] = current;
                for(int j = 0; j < a[i]; j++){
                    cout << ' ' << b[i-1];
                }
                current += a[i];
            }
            cout << '\n' << 0;
            for(int i = 1, current = 2; i < n; i++){
                b[i] = current;
                if(i == _i){
                    for(int j = 1; j < a[i]; j++){
                        cout << ' ' << b[i-1];
                    }
                    cout << ' ' << b[i-1] + 1;
                } else {
                    for(int j = 0; j < a[i]; j++){
                        cout << ' ' << b[i-1];
                    }
                }
                current += a[i];
            }


            return 0;
        }
    }
    cout << "perfect";

    return 0;
}
