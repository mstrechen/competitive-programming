#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ifstream cin("bad-hashing.in");
    ofstream cout("bad-hashing.out");
    cout << string(32,'a')<<'\n';
    cout << string(33,'a');
    return 0;
}
