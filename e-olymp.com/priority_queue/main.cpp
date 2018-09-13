#include<iostream>
#include<map>
#include<functional>

using namespace std;

template<typename T1, typename T2, typename comp>
struct PriorityQueue{
    map<T2, T1, comp> m1{};
    map<T1, T2> m2{};

    PriorityQueue(){}

    PriorityQueue & operator >> (ostream & out){
        auto it = m1.begin();
        out << it->second << ' ' << it->first << '\n';
        m2.erase(it->second);
        m1.erase(it);
        return *this;
    }
    PriorityQueue & operator << (istream & in){
        T1 a;
        T2 b;
        in >> a >> b;
        m1[b] = a;
        m2[a] = b;
        return *this;
    }

    PriorityQueue & operator || (istream & in){
        T1 id;
        T2 pr, tmpPr;
        in >> id >> pr;
        tmpPr = m2[id];
        m2[id] = pr;
        m1.erase(tmpPr);
        m1.insert(make_pair(pr, id));
        return *this;
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    PriorityQueue<string, int, greater<int> > PQ;
    string instruction;
    while(cin >> instruction){
        switch(instruction[0]){
            case 'A' : PQ << cin; break;
            case 'P' : PQ >> cout; break;
            case 'C' : PQ || cin; break;
            default : while(1){cout << "!!!\n";};
        }
    }

    return 0;
}
