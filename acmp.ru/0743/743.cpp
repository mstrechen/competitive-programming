#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    map<string, vector<string> > react;
    map<string, int> used;
    map<string, int> dist;
    string s1,s2,s3;

    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> s1 >> s2 >> s3;
        react[s1].push_back(s3);
    }

    queue<string> q;
    cin >> s1 >> s3;

    q.push(s1);
    dist[s1] = 1;
    used[s1] = 1;
    while(!q.empty())
    {
        s2 = q.front();
        q.pop();
        for(auto i : react[s2])
        {
            if(!used[i])
            {
                q.push(i);
                dist[i] = dist[s2]+1;
                used[i] = 1;
            }
        }
    }
    cout << dist[s3]-1;
	return 0;
}
