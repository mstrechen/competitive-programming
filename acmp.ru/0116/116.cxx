#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int get_max_area(vector<int> & row){
    int n = row.size();

    vector<int> next_left_wall(n),
                next_right_wall(n);
    //      height, index
    stack<pair<int, int> > prev;
    prev.emplace(-1, -1);
    
    for(int i = 0; i < n; i++){
        while(prev.top().first >= row[i])
            prev.pop();
        
        next_left_wall[i] = prev.top().second + 1;
        prev.emplace(row[i], i);
    }
    while(!prev.empty())
        prev.pop();

    prev.emplace(-1, n);
    for(int i = n - 1; i >= 0; i--){
        while(prev.top().first >= row[i])
            prev.pop();
        
        next_right_wall[i] = prev.top().second - 1;
        prev.emplace(row[i], i);
    }

    int max_answer = 0;

    for(int i = 0; i < n; i++){ 
        max_answer = max(max_answer, row[i] * (next_right_wall[i] - next_left_wall[i] + 1) );
    }
    
    return max_answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for(auto & i : field)
        cin >> i;
    
    vector<vector<int> > up_length(n, vector<int>(m));
    for(int j = 0; j < m; j++)
        up_length[0][j] = (field[0][j] == '1'); 

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            up_length[i][j] = (field[i][j] == '1' ? up_length[i - 1][j] + 1 : 0);
    

    int max_answer = 0;

    for(int i = 0; i < n; i++){
        max_answer = max(max_answer, get_max_area(up_length[i]));
    }

    cout << max_answer;


    return 0;
}