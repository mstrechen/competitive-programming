#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    
    int lenght,base;
    
    cin >> lenght >> base;
    
    long long withZero = 0, withoutZero = base-1;
    
    
    for(int i = 1; i<lenght; i++)
    {
        long long withZero_tmp    = withoutZero,
            withoutZero_tmp = (withoutZero + withZero)*(base-1);
        withZero = withZero_tmp;
        withoutZero = withoutZero_tmp;
    }
    
    assert(withZero+withoutZero < 2.1e9);
    
    cout << withZero+withoutZero;
	
	return 0;
}