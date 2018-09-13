#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<tuple>

using namespace std;

const int INF = 2000*1000*1000;


struct Ride{
    int x1, y1;
    int x2, y2;
    int l, r;
    int index;

    int getLen(int, int, int) const;
    int getCost(int, int, int) const;
    
};


int Ride::getLen(int x, int y, int t) const{
    int first_len = t + max(abs(x1 - x) + abs(y1 - y), l);
    int second_len = abs(x1 - x2) + abs(y1 - y2);
    if(first_len + second_len >= r)
        return INF;
    
    return first_len + second_len;
}

int Ride::getCost(int x, int y, int t) const {
    int first_len = t + max(abs(x1 - x) + abs(y1 - y), l);
    int second_len = abs(x1 - x2) + abs(y1 - y2);
    if(first_len + second_len >= r)
        return INF;

    return first_len;
}


struct City{
    int R, C, F, N, B, T;

    vector<Ride> rides;

    vector<tuple<int, int, int> > currentPos;
    vector<vector<int> > finalRides;
    void calculateRides();
};

void City::calculateRides(){
    srand(0);
    int max_iterations_cnt = 1000*10;
    while(max_iterations_cnt-- && rides.size()){
        int i = rand() % finalRides.size();

        auto & currentCar = currentPos[i];

        auto get_optimal = [&](const auto & a, const auto & b){
                    int t1 = a.getCost(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar));
                    int t2 = b.getCost(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar));
                    return t1 > t2; };

        auto it = max_element(rides.begin(), rides.end(),
               get_optimal);


        int tmp = 41;
        while(it->getLen(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar)) != INF){
            
            finalRides[i].push_back(it->index);
            currentCar = make_tuple(it->x2, it->y2, it->getLen(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar)));

            rides.erase(it);

            if(rides.size() == 0 || tmp-- == 0)
                break;   

             it = max_element(rides.begin(), rides.end(),
                get_optimal);
        }

    }

    /*
    for(int _i = 0; _i < iterations_count; _i++){
        int i = UID(gen);
        

        auto & currentCar = currentPos[i];
        auto it = max_element(rides.begin(), rides.end(),
                [&](const auto & a, const auto & b){
                    int t1 = a.getCost(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar));
                    int t2 = b.getCost(get<0>(currentCar), get<1>(currentCar), get<2>(currentCar));
                    return t1 < t2;}
                    );


        finalRides[i].push_back(it->index);
        currentCar = {it->y1, it->y2, it->getLen(get<0>(currentCar), 
                                                 get<1>(currentCar), 
                                                 get<2>(currentCar))};
        rides.erase(it);
    }
    */
}

istream & operator >> (istream & in, Ride & toRead){
    in >> toRead.x1 >> toRead.y1
       >> toRead.x2 >> toRead.y2
       >> toRead.l >> toRead.r;
    return in;
}

istream & operator >> (istream & in, City & toRead){
    in >> toRead.R >> toRead.C
        >> toRead.F >> toRead.N
        >> toRead.B >> toRead.T;
    toRead.rides.resize(toRead.N);
    toRead.finalRides.resize(toRead.F);
    toRead.currentPos.assign(toRead.F, tuple<int, int, int>(0, 0, 0));
    
    int j = 0;
    for(auto & i : toRead.rides){
        in >> i;
        i.index = j;
        j++;
    }
    
    return in;
};
ostream & operator << (ostream & out, const City & toWrite){
    for(auto & i : toWrite.finalRides){
        cout << i.size();
        for(auto & j : i)
            cout << ' ' << j;
        cout << '\n';
    }
    return out;
}

int main(int argc, char ** argv){
    int MIA = atoi(argv[1]);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    City city;
    cin >> city;
    
    city.calculateRides();

    cout << city;
    
    return 0;
}