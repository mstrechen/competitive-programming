#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
    ifstream cin("input.txt");
    string s;
    
    while(!cin.eof())
    {
        if(!(cin >> s))
            break;
            
        stack<char> a;
        
        for(int i = 0; i<s.size()||(!(cout <<(a.empty()?'0':'1'))) ; i++)
        {
            if(s[i]=='['||s[i]=='{'||s[i]=='(')
                a.push(s[i]);
            else
                if(a.size() && ((a.top()=='['&&s[i]==']')||(a.top()=='('&&s[i]==')')||(a.top()=='{'&&s[i]=='}')))
                {
                    a.pop();
                }
                else
                {
                    cout << '1';
                    break;
                }
        }
    }
    
    
	return 0;
}