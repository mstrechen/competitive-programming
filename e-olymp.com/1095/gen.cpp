#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int maxCoord = atoi(argv[2]);
    int swaps = atoi(argv[3]);

    cout << n << '\n';
    set<int> a;
    while(a.size() != n){
        a.insert(rnd.next(-maxCoord, maxCoord));
    }

    deque<int> b(a.begin(), a.end());
    for(int i = 0; i < swaps; i++){
        swap(b[rnd.next(n)], b[rnd.next(n)]);
    }
    for(int i = 0; i < n; i++){
        if(i & 1){
            cout << b.back() << '\n';
            b.pop_back();
        } else {
            cout << b.front() << '\n';
            b.pop_front();
        }
    }

    return 0;
}

