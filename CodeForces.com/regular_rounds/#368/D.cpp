#include<iostream>
#include<vector>

using namespace std;



struct bookshelf
{
    vector<char> current;
    int inverted;
    int countOfChanges;
    vector<pair<vector<char, bool> > > versions;
    vector<int>

    vector<int> kindOf

    bookshelf(int n)
    {
        current = vector<char>(n,0);
        inverted = 0;
        countOfChanges = 0;
        versions.push_back(current);
    }
};


int main()
{
    ios::sync_with_stdio(false);



    return 0;
}
