#include<iostream>
#include<vector>
#include<iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    vector<pair<int,int> > a;
    
  

    int resSum = 0, prev;
    
    cin >> n;
    
    for(int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        
        if(resSum==0)
            prev = i;
        
        resSum+=x;
        
        if(resSum==0)
            a.push_back({prev,i});
    }
    
    if(resSum!=0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n" << a.size() <<'\n';
        for(auto & i : a)
            cout << i.first+1 << ' ' << i.second+1 << '\n';
    }

    return 0;
}
