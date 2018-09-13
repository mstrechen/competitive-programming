#include<fstream>

using namespace std;

int main()
{
    ofstream cout("out.txt");

    int n = 400;
    cout << n << " "  <<  (n-2)*2<<  endl;
    for(int i = 2; i<n; i++)
        cout << "0 " << i << " 1\n";
    for(int i = 2; i<n-1; i++)
        cout << i << " " << i+1 << " 1000\n";
    cout << n-1 << " 1 1000";
    return 0;
}
