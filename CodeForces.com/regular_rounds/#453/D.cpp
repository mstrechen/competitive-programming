#include<iostream>
#include<vector>


using namespace std;

const double eps = 1e-10;

int getEuclidian(vector<double> a, vector<double> b){
    if(a.size() < b.size())
        swap(a, b);

    int n = 0;
    while(b.size()){
        for(auto & i : a)
            cout << i << ' ';
        cout << "| ";
        for(auto & i : b)
            cout << i << ' ';
        cout << endl;
        for(int i = a.size() - 1; i >= b.size(); i--){
            double coef = a[i]/b[0];
            for(int j = 0; j < b.size(); j++)
                a[i - j] -= coef * b[j];
        }
        swap(a, b);
        int cut = 0;
        while(cut < b.size() && b[cut] < eps)
            cut++;
        for(int i = 0; i + cut < b.size(); i++)
            b[i] = b[i + cut];
        b.resize(b.size() - cut);
        n++;
    }

}

int main(){

    cout << getEuclidian({1, 1, 1}, {1, 1});

    return 0;
}
