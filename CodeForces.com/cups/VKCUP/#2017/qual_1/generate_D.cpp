#include<fstream>
#include<random>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n = 100*1000, k = 14;

    string filename = string("D_") + '1' + char('0'+k%10) + ".txt";

    mt19937 generator(k);
    uniform_int_distribution<int> UID(0, 10*1000);

    ofstream cout(filename);
    cout << n << ' ' << k << '\n';
    for(int i = 0; i<n; i++)
        cout << UID(generator) << ' ';


    return 0;
}
