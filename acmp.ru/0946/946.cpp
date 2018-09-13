#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
    deque<int> shelf;
    int n;
    
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        int x, y;
        cin >> x;
        if(x<3)
        {
            cin >> y;
            if(x==1)
                shelf.push_front(y);
            else
                shelf.push_back(y);
        }
        else
        {
            if(x==3)
            {
                cout << *shelf.begin()<< ' ';
                shelf.pop_front();
            }
            else
            {
                cout << *shelf.rbegin() << ' ';
                shelf.pop_back();
            }
        }
        
    }
	return 0;
}