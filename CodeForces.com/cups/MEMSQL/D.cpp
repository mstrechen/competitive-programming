#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



struct Fights{
    int n;
    int size;
    vector<vector<double> > pos;

    Fights(int n) : n(n),
                    size(1 << n),
                    pos(size, vector<double>(size, 0)){};

    double getMaxAns(){
        int lvl1, lvl2;
        lvl1 = n/2;
        lvl2 = n - lvl1;

        vector<vector<double> > small(1 << lvl2, vector<double>(1 << lvl1, 0));

        int delta = 1 << lvl1;
        for(int I = 0; I < (1 << lvl2); I++){
            for(int mask = 1 <<(lvl1 * 2 - 1) - 1; mask >= 0; --mask){
                double currVal = 0;
                vector<int> a(1 << lvl1, 0);
                for(int i = 0; i < a.size(); i++)
                    a[i] = i;
                int mmask = mask;
                int offset = 0;

                int lvl = 1;
                while(a.size() != 1){
                    for(int i = 0; i < a.size(); i+=2)
                        if((mmask >> (i/2))&1){
                            currVal += pos[delta * I + a[i + 1]][delta * I + a[i]] * lvl;
                            a[i/2] = a[i + 1];
                        }
                        else{
                            currVal += pos[delta * I + a[i]][delta * I + a[i + 1]] * lvl;
                            a[i/2] = a[i];
                        }
                    lvl *= 2;
                    a.resize(a.size()/2);
                    mmask >>= a.size();
                }

                small[I][a.back()] = max(small[I][a.back()], currVal);
            }
        }



        for(int i = 0; i < small.size(); i++)
            for(int j = 0; j < small[0].size(); j++)
                cout << small[i][j] << ' ';
        cout << endl;

    }


};

int main(){
    int n;
    cin >> n;

    Fights F(n);

    for(auto & i : F.pos)
        for(auto & j : i)
            cin >> j;
    F.getMaxAns();




    return 0;
}
