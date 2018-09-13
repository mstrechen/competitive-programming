#include <iostream>
#include <stack>

using namespace std;

int connecting[1000000];
bool deleted[1000000];
char a[1000000];

stack<int> st;
int n,m,p;

void move_left()
{
    do
    {
        p--;
        if(deleted[p]&&connecting[p]<p)
            p = connecting[p];
    }
    while(deleted[p]);
}

void move_right()
{

    do
    {
        p++;
        if(deleted[p]&&connecting[p]>p)
            p = connecting[p];
    }
    while(deleted[p]);

}

void delete_brackets()
{
    deleted[p] = 1;
    deleted[connecting[p]] = 1;
    p = max(p, connecting[p]);
    if(p == n-1)
    {
        n = connecting[p];
        p++;
        move_left();
    }
    else
        move_right();
}


int main(){
	ios::sync_with_stdio(false);

    char tmp;
    int tmpInt;
    cin >> n >> m >> p;
    for(int i = 0; i<n; i++)
    {
        cin >> tmp;
        a[i] = tmp;
        if(tmp=='(')
            st.push(i);
        else
        {
            connecting[i] = st.top();
            connecting[st.top()] = i;
            st.pop();
        }
    }
    p--;
    for(int i = 0; i<m; i++)
    {
        cin >> tmp;
        switch(tmp)
        {
        case 'R':
            move_right();break;
        case 'L':
            move_left();break;
        case 'D':
            delete_brackets();break;
        }

    }
    for(int i = 0; i<n; i++)
    {
        if(!deleted[i])
            cout << a[i];
        else
            i = connecting[i];
    }

	return 0;
}

