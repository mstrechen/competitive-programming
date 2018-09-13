#include<fstream>

using namespace std;

int main()
{
	ofstream cout("inp.txt");
	cout << "1000 1000 1000000 1000\n";
	for(int i = 0; i<1000; i++)
		for(int j = 0; j<1000; j++)
			cout << i+1 << ' ' << j+1 << '\n';
	return 0;
}