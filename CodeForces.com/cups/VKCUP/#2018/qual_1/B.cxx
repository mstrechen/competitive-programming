#include <iostream>
#include <vector>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, FOV;
    cin >> n >> FOV;

    vector<int> prev(n + 1),
                last_watched(n + 1),
                answer(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> prev[i];


    last_watched[0] = 0;
    answer[0] = 0;

    for(int i = 1; i <= n; i++){
        last_watched[i] = min(n, i + FOV);
        answer[i] = answer[prev[i]] + min(last_watched[i] - last_watched[prev[i]],
                                          1 + FOV + (last_watched[i] - i));
        cout << answer[i] << ' ';
    }

    return 0;
}           