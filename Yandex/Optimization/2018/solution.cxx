#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
#include <numeric>
#include <cassert>
#include <random>
#include <set>


using namespace std;

int gcd(int x, int y){
    x = abs(x);
    y = abs(y);
    while(x && y)
        x %= y,
        swap(x, y);
    return x + y;
}

class point{
public:
    int x, y;
    point(int x = 0, int y = 0) :
        x(x), y(y) {}
    
    int len_sqr() const {
        return x*x + y*y;
    }
    double len() const {
        return sqrt(len_sqr());
    }
};

ostream & operator << (ostream & out, const point & p){
    out << '(' << p.x << ',' << p.y <<  ')';
    return out ;
}

bool operator == (const point & lhs, const point & rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator < (const point & lhs, const point & rhs){
    return lhs.x < rhs.x ||
           (lhs.x == rhs.x && lhs.y < rhs.y);
}


const point & operator += (point & lhs, const point & rhs){
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return rhs;
}
const point & operator -= (point & lhs, const point & rhs){
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return rhs;
}
point operator + (const point & lhs, const point & rhs){
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

point operator - (const point & lhs, const point & rhs){
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}


istream & operator >> (istream & in, point & to_read){
    in >> to_read.x >> to_read.y;
    return in;
} 

double optimization_possibility (size_t k, const point & a, const point & b){
    point c = a - b;
    return (b.len()/k + c.len()*(1 + 1.0/k)) - a.len() * (1 + 1.0/k); 
}

double solo_move_optimization_possibility(const point & a, const point & b){
    return  b.len() + (b - a).len() - a.len();
}

bool normal_coordinates(const point & a){
    return abs(a.x) <= 10000 && abs(a.y) <= 10000;
}

class car : public point{
};
class zone : public point{
};
class fan : public point{
};


class test{
public:
    vector<car> cars;
    vector<fan> fans;
    vector<zone> zones;

    test(const test & src) 
      : cars(src.cars),
        fans(src.fans),
        zones(src.zones){}  
    
    test() {}
};

istream & operator >> (istream & in, test & to_read){
    int n;
    in >> n;
    to_read.cars.resize(n);
    for(auto & i : to_read.cars)
        in >> i;
    in >> n;
    to_read.fans.resize(n);
    for(auto & i : to_read.fans)
        in >> i;
    in >> n;
    to_read.zones.resize(n);
    for(auto & i : to_read.zones)
        in >> i;
    
    return in;
}

class move_record {
public:
    int x, y;
    vector<int> indexes;
    move_record(int x = 0, int y = 0, const vector<int> & indexes = {}) : 
        x(x), y(y), indexes(indexes) {}
    move_record(int x = 0, int y = 0, const initializer_list<int> & indexes = {}) :
        x(x), y(y), indexes(indexes) {}
};

ostream & operator << (ostream & out, const move_record & to_write){
    out << "MOVE " << to_write.x << ' ' << to_write.y << ' '
        << to_write.indexes.size();
    for(size_t i = 0; i < to_write.indexes.size(); i++)
        out << ' ' << to_write.indexes[i] + 1;
    return out;
} 


class euclid_inserter{
public:
    static void insert(vector<point> & v, const point & to_insert)  {
        v.push_back(to_insert);
    }
    static void insert_to_zone(vector<point> & v, const point & to_insert)  {
        v.push_back(to_insert);
    }
};

class eucldid_divide_inserter{
public:
    static void insert(vector<point> & v, const point & to_insert)  {
        v.push_back(to_insert);
    }
    static void insert_to_zone(vector<point> & v, const point & to_insert)  {
        int g = gcd(to_insert.x, to_insert.y);
        for(int i = 0; i < g; i++)
            v.push_back({to_insert.x/g, to_insert.y/g});
    }
};

class manhattan_move_inserter{
public:
    static void insert(vector<point> & v, const point & to_insert) {
        if(to_insert.x)
            v.push_back({to_insert.x, 0});
        if(to_insert.y)
            v.push_back({0, to_insert.y});
    }
    static void insert_to_zone(vector<point> & v, const point & to_insert) {
        if(to_insert.x)
            v.push_back({to_insert.x, 0});
        if(to_insert.y)
            v.push_back({0, to_insert.y});
    }
};

class manhattan_divide_inserter{
public:
    static void insert(vector<point> & v, const point & to_insert) {
        if(to_insert.x)
            v.push_back({to_insert.x, 0});
        if(to_insert.y)
            v.push_back({0, to_insert.y});
    }
    static void insert_to_zone(vector<point> & v, const point & to_insert) {
        int x = to_insert.x/2;
        if(x)
            v.push_back({x , 0});
        if(to_insert.x - x)
            v.push_back({to_insert.x - x, 0});
        int y = to_insert.y/2;
        if(y)
            v.push_back({0, y});
        if(to_insert.y - y)
            v.push_back({0, to_insert.y - y});
    }
};



class octogone_inserter{
public:
    static void insert(vector<point> & v, const point & to_insert) {
        v.push_back(to_insert);
    }
    static void insert_to_zone(vector<point> & v, const point & to_insert) {
        if(min(abs(to_insert.x), abs(to_insert.y)) * 1.0 
            / max(abs(to_insert.x), abs(to_insert.y)) < 0.41){

            if(to_insert.x)
                v.push_back({to_insert.x, 0});
            if(to_insert.y)
                v.push_back({0, to_insert.y});
        } else {
            v.push_back(to_insert);
        }
    }
    
};



class base_distributor{
public:
    virtual const vector< vector<point> > & distribute (const test & current_test) const{
        exit(0x01);
    }
};

template<typename move_inserter = euclid_inserter>
class distributor : public base_distributor{
protected:
    mutable vector< vector<point> > moves;
public:
    virtual const vector< vector<point> > & distribute(const test & current_test) const {
        if(moves.size() > 0)
            return moves;
        moves.resize(current_test.cars.size());

        auto cars = current_test.cars;
        auto zones = current_test.zones;
        auto fans =  current_test.fans;

        auto get_cost = 
        [&cars, &zones, &fans](int fan, int car, int zone){
            return (fans[fan] - cars[car]).len() + (fans[fan] - zones[zone]).len();
        };

        while(fans.size() > 0){
            int fan_i = 0, car_i = 0, zone_i = 0;
            double cost = get_cost(fan_i, car_i, zone_i);

            for(size_t f = 0; f < fans.size(); f++)
                for(size_t c = 0; c < cars.size(); c++)
                    for(size_t z = 0; z < zones.size(); z++){
                        double new_cost = get_cost(f, c, z);
                        if(new_cost < cost)
                            fan_i = f, car_i = c, zone_i = z,
                            cost = new_cost;
                    }
            

            move_inserter::insert(moves[car_i], fans[fan_i] - cars[car_i]);
            cars[car_i] += fans[fan_i] - cars[car_i];
            
            move_inserter::insert_to_zone(moves[car_i], zones[zone_i] -  cars[car_i]);
            cars[car_i] += zones[zone_i] - cars[car_i];
            
            swap(fans[fan_i], fans.back());
            fans.pop_back();
        }

        for(auto & i : moves)
            reverse(i.begin(), i.end());
        return moves;
    }
};


template<typename move_inserter = euclid_inserter>
class closest_fan_distributor : public distributor<move_inserter> {
protected:
    mutable vector< vector<point> > moves;
public:
    virtual const vector< vector<point> > & distribute(const test & current_test) const {
        if(moves.size() > 0)
            return moves;
        moves.resize(current_test.cars.size());

        auto cars = current_test.cars;
        auto zones = current_test.zones;
        auto fans =  current_test.fans;

        auto get_cost = 
        [&cars, &zones, &fans](int fan, int car, int zone) -> pair<int, int> {
            return {(fans[fan] - cars[car]).len_sqr(),
                    (fans[fan] - zones[zone]).len_sqr()};
        };

        while(fans.size() > 0){
            int fan_i = 0, car_i = 0, zone_i = 0;
            pair<int, int> cost = get_cost(fan_i, car_i, zone_i);

            for(size_t f = 0; f < fans.size(); f++)
                for(size_t c = 0; c < cars.size(); c++)
                    for(size_t z = 0; z < zones.size(); z++){
                        auto new_cost = get_cost(f, c, z);
                        if(new_cost < cost)
                            fan_i = f, car_i = c, zone_i = z,
                            cost = new_cost;
                        
                    }
            

            move_inserter::insert(moves[car_i], fans[fan_i] - cars[car_i]);
            cars[car_i] += fans[fan_i] - cars[car_i];
            
            move_inserter::insert_to_zone(moves[car_i], zones[zone_i] -  cars[car_i]);
            cars[car_i] += zones[zone_i] - cars[car_i];
            
            swap(fans[fan_i], fans.back());
            fans.pop_back();
        }

        for(auto & i : moves)
            reverse(i.begin(), i.end());
        return moves;
    }
};

template<typename move_inserter = euclid_inserter>
class zones_and_cars_distributor : public distributor<move_inserter> {
protected:
    mutable vector< vector<point> > moves;
public:
    virtual const vector< vector<point> > & distribute(const test & current_test) const {
        if(moves.size() > 0)
            return moves;
        moves.resize(current_test.cars.size());

        auto cars = current_test.cars;
        auto zones = current_test.zones;
        auto fans =  current_test.fans;

        vector<int> fans_to_zones(fans.size());
        vector<vector<int> > zones_cnt(zones.size());

        for(size_t f = 0; f < fans.size(); f++){
            int best_z = 0;
            for(int z = 1; z < zones.size(); z++)
                if((fans[f] - zones[z]).len_sqr() < (fans[f] - zones[best_z]).len_sqr())
                    best_z = z;
            fans_to_zones[f] = best_z;
            zones_cnt[best_z].push_back(f);
        }

        auto get_closest_fan = [&](int z, point & c){
            int best_car_dist = 2000*1000*1000;
            for(auto i : zones_cnt[z])
                best_car_dist = min(best_car_dist, (c - fans[i]).len_sqr());
            return best_car_dist;
        };

        auto get_closest_fan_id = [&](int z, point & c, int best_car_dist){
            for(size_t i = 0; i < zones_cnt[z].size(); i++)
                if((c - fans[zones_cnt[z][i]]).len_sqr() == best_car_dist)
                    return zones_cnt[z][i];
            exit(102);
            return -1;
        };

        for(size_t z = 0; z < zones.size(); z++)
        if(zones_cnt[z].size()){
            int best_car = 0;
            int best_car_dist = get_closest_fan(z, cars[0]);
            for(size_t c = 1; c < cars.size(); c++){
                int new_dist = get_closest_fan(z, cars[c]);
                if(new_dist < best_car_dist)
                    best_car_dist = new_dist, 
                    best_car = c;
            }
            int best_fan = get_closest_fan_id(z, cars[best_car], best_car_dist);
            move_inserter::insert(moves[best_car], fans[best_fan] - cars[best_car]);
            cars[best_car] += fans[best_fan] - cars[best_car];
            
            move_inserter::insert_to_zone(moves[best_car], zones[z] - cars[best_car]);
            cars[best_car] += zones[z] - cars[best_car];
            
            zones_cnt[z].erase(find(zones_cnt[z].begin(), zones_cnt[z].end(), best_fan));
            for(auto best_fan : zones_cnt[z]){
                move_inserter::insert(moves[best_car], fans[best_fan] - cars[best_car]);
                cars[best_car] += fans[best_fan] - cars[best_car];
                
                move_inserter::insert_to_zone(moves[best_car], zones[z] - cars[best_car]);
                cars[best_car] += zones[z] - cars[best_car];
            }
        }

        for(auto & i : moves)
            reverse(i.begin(), i.end());
        return moves;
    }
};

class scheduler{
protected:
    mutable vector<car> cars;
    mutable vector<fan> fans;
    mutable vector<zone> zones;
    mutable vector<move_record> res;
    mutable vector<int> zones_usage;
    mutable vector<point> closest_points;
    
    void make_closest_points(int max_delta){
        closest_points.clear();
        for(int x = -max_delta; x <= max_delta; x++)
            for(int y = -max_delta; y <= max_delta; y++)
                if(x || y)
                    closest_points.emplace_back(x, y);
        sort(closest_points.begin(), closest_points.end(), 
        [](const point & lhs, const point & rhs){
            return lhs.len_sqr() < rhs.len_sqr();
        });
    }

    bool no_cars_and_zones (point p) const{
            if(cars.end() != find(cars.begin(), cars.end(), p)
               || find(zones.begin(), zones.end(), p)
                    != zones.end())
                        return false;
            else
                        return true;
    };
    bool no_cars (point p) const {
        return true;
        if(cars.end() != find(cars.begin(), cars.end(), p))
            return false;
        else
            return true;
    }
    bool is_point_clear (point p) const {
            if(cars.end() != find(cars.begin(), cars.end(), p)
               || find(zones.begin(), zones.end(), p)
                    != zones.end()
               || find(fans.begin(), fans.end(), p)
                    != fans.end()
               )
                        return false;
            else
                        return true;
    }

    auto leave_zone(vector<vector<point> > & distr, int car_i) const{
        if(distr[car_i].size() == 0 || !no_cars_and_zones(cars[car_i] + distr[car_i].back())){
                   
            point real_move;
            if(distr[car_i].size() != 0)
                real_move = distr[car_i].back();
            else
                real_move = {0, 0};


            sort(closest_points.begin(), closest_points.end(),
                [&real_move](const point & lhs, const point & rhs){
                    return solo_move_optimization_possibility(real_move, lhs)
                            < solo_move_optimization_possibility(real_move, rhs);
                });

            for(auto & i : closest_points)  
               if(normal_coordinates(cars[car_i] + i) && 
                  is_point_clear(cars[car_i] + i) ){
                        res.push_back({i.x, i.y, {car_i,}});
                        if(distr[car_i].size() > 0)
                            distr[car_i].back() -= i;
                        cars[car_i] += i;
                        return;
                    } 
            throw 0x101;
        } else {
            res.push_back({distr[car_i].back().x,
                           distr[car_i].back().y,
                                {car_i}});

            cars[car_i] += distr[car_i].back();
            distr[car_i].pop_back();
        }
    };

    auto set_move (vector<vector<point> > & distr, int x, int y, const vector<int> & indexes) const {
        res.emplace_back(x, y, indexes);
        for(auto i : indexes){
            cars[i] += {x, y};
        }
        //important! "leave_zone" could take place of some car
        
        for(auto i : indexes){
            point tmp_p = distr[i].back();
            if(tmp_p.x == x && tmp_p.y == y)
                distr[i].pop_back();
            else
                distr[i].back() += {-x, -y};
            auto it = find(zones.begin(), zones.end(), cars[i]);
            
            if(it != zones.end()){
                int zone_id = it - zones.begin();
                if(--zones_usage[zone_id])
                    leave_zone(distr, i);
                if(zones_usage[zone_id] < 0)
                    exit(12);
            }
                
        }
    };
public:
    virtual vector<move_record> && make_shedule(const test & current_test, 
                                             vector< vector<point> > distr) {
        if(res.size() > 0)
            return move(res);
        
        make_closest_points(15);

        cars.assign(current_test.cars.begin(), current_test.cars.end());
        fans.assign(current_test.fans.begin(), current_test.fans.end());
        zones.assign(current_test.zones.begin(), current_test.zones.end());
        
        zones_usage.assign(current_test.zones.size(), 0);

        for(size_t i = 0; i < distr.size(); i++){
            for(auto it = distr[i].rbegin(); it != distr[i].rend(); it++){
                cars[i] += *it;

                for(size_t j = 0; j < current_test.zones.size(); j++){
                    if(cars[i] == current_test.zones[j]){
                        zones_usage[j]++;
                    }
                }
            }
        }   
        cars.assign(current_test.cars.begin(), current_test.cars.end());

        auto moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        while(moves_cnt){
            int car_to_move = -1;
            int move_len = 0;
            for(size_t i = 0; i < distr.size(); i++)
                if(distr[i].size() > 0 && no_cars(cars[i] + distr[i].back()))
                    if(car_to_move == -1 || move_len > distr[i].back().len()){
                        car_to_move = i;
                        move_len = distr[i].back().len();
                    }
                
            assert(distr[car_to_move].size() > 0);
            point current_move = distr[car_to_move].back();
            
            vector<int> will_be_moved = {(int)car_to_move,};

            for(size_t i = 0; i < distr.size(); i++)
            if(i != car_to_move && distr[i].size()){
                if(distr[i].back() == current_move ||
                   (optimization_possibility(distr.size(), distr[i].back(), current_move) < 0 &&
                    is_point_clear(cars[i]+ current_move) &&
                    normal_coordinates(cars[i] + current_move) ) ){
                        will_be_moved.push_back(i);
                    }
            }
            set_move(distr, current_move.x, current_move.y, will_be_moved);


            moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        }

        return move(res);
    }
};


class random_sheduler : public scheduler{
    int scheduler_seed;
public:
    random_sheduler(int scheduler_seed = 13032000) : 
        scheduler_seed(scheduler_seed){}
    virtual vector<move_record> && make_shedule(const test & current_test, 
                                             vector< vector<point> > distr) {
        if(res.size() > 0)
            return move(res);
        
        make_closest_points(15);

        cars.assign(current_test.cars.begin(), current_test.cars.end());
        fans.assign(current_test.fans.begin(), current_test.fans.end());
        zones.assign(current_test.zones.begin(), current_test.zones.end());
        
        zones_usage.assign(current_test.zones.size(), 0);

        for(size_t i = 0; i < distr.size(); i++){
            for(auto it = distr[i].rbegin(); it != distr[i].rend(); it++){
                cars[i] += *it;

                for(size_t j = 0; j < current_test.zones.size(); j++){
                    if(cars[i] == current_test.zones[j]){
                        zones_usage[j]++;
                    }
                }
            }
        }   
        cars.assign(current_test.cars.begin(), current_test.cars.end());

        auto moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        
        mt19937 randomer(scheduler_seed);

        while(moves_cnt){
            vector<int> cars_to_move;
            for(size_t i = 0; i < distr.size(); i++)
                if(distr[i].size() && no_cars(cars[i] + distr[i].back()))
                    cars_to_move.push_back(i);
            
            uniform_int_distribution<int> index_picker(0, (int)cars_to_move.size() - 1);

            int car_to_move = cars_to_move[index_picker(randomer)];


            assert(distr[car_to_move].size() > 0);
            point current_move = distr[car_to_move].back();
            
            vector<int> will_be_moved = {(int)car_to_move,};

            for(size_t i = 0; i < distr.size(); i++)
            if(i != car_to_move && distr[i].size()){
                if(distr[i].back() == current_move ||
                   (optimization_possibility(distr.size(), distr[i].back(), current_move) < 0 &&
                    is_point_clear(cars[i]+ current_move) &&
                    normal_coordinates(cars[i] + current_move) ) ){
                        will_be_moved.push_back(i);
                    }
            }
            set_move(distr, current_move.x, current_move.y, will_be_moved);


            moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        }

        return move(res);
    }
};

class optimal_scheduler : public scheduler{
    virtual vector<move_record> && make_shedule(const test & current_test, 
                                             vector< vector<point> > distr) {
        if(res.size() > 0)
            return move(res);
        
        make_closest_points(15);

        cars.assign(current_test.cars.begin(), current_test.cars.end());
        fans.assign(current_test.fans.begin(), current_test.fans.end());
        zones.assign(current_test.zones.begin(), current_test.zones.end());
        
        zones_usage.assign(current_test.zones.size(), 0);

        for(size_t i = 0; i < distr.size(); i++){
            for(auto it = distr[i].rbegin(); it != distr[i].rend(); it++){
                cars[i] += *it;

                for(size_t j = 0; j < current_test.zones.size(); j++){
                    if(cars[i] == current_test.zones[j]){
                        zones_usage[j]++;
                    }
                }
            }
        }   
        cars.assign(current_test.cars.begin(), current_test.cars.end());

        auto moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        

        while(moves_cnt){
            int car_to_move = 0;
            double best_optimization = 0;
            for(size_t i = 0; i < distr.size(); i++)
            if(distr[i].size() && no_cars(cars[i] + distr[i].back())){
                    car_to_move = i;
                    break;
                }
            for(size_t current_car = 0; current_car < distr.size(); current_car++)
                if(distr[current_car].size() && no_cars(cars[current_car] + distr[current_car].back() ) ){
                    auto current_move = distr[current_car].back();
                    double current_move_opt = 0;

                    for(size_t i = 0; i < distr.size(); i++)
                    if(i != current_car && distr[i].size() && no_cars(cars[i] + distr[i].back())){
                        double opt = optimization_possibility(distr.size(), distr[i].back(), current_move);
                        if(distr[i].back() == current_move ||
                        (opt < 0 &&
                            is_point_clear(cars[i]+ current_move) &&
                            normal_coordinates(cars[i] + current_move) ) ){
                                current_move_opt += opt;
                            }
                    }
                    
                    if(current_move_opt < best_optimization)
                        best_optimization = current_move_opt,
                        car_to_move = current_car;
                }

            assert(distr[car_to_move].size() > 0);
            point current_move = distr[car_to_move].back();
            
            vector<int> will_be_moved = {(int)car_to_move,};

            for(size_t i = 0; i < distr.size(); i++)
            if(i != car_to_move && distr[i].size() && no_cars(cars[i] + distr[i].back() ) ){
                if(distr[i].back() == current_move ||
                   (optimization_possibility(distr.size(), distr[i].back(), current_move) < 0 &&
                    is_point_clear(cars[i] + current_move) &&
                    normal_coordinates(cars[i] + current_move) ) ){
                        will_be_moved.push_back(i);
                    }
            }
            set_move(distr, current_move.x, current_move.y, will_be_moved);


            moves_cnt = accumulate(distr.begin(), distr.end(), 0, 
                            [](int a, const vector<point> & b){
                                return a + b.size();
                            });
        }

        return move(res);
    }
};


class solution{
public:
    shared_ptr<test> t;
    shared_ptr<base_distributor > distr;
    shared_ptr<scheduler> shd;
    mutable vector<move_record> final_moves;

    solution(shared_ptr<test> t_src,
            base_distributor * d_src = nullptr, 
            scheduler * s_src = nullptr) :
                t(t_src), distr(d_src), shd(s_src) {}
    
    solution(shared_ptr<test> t_src,
            shared_ptr<base_distributor> d_src, 
            scheduler * s_src) :
                t(t_src), distr(d_src), shd(s_src) {}

    solution(shared_ptr<test> t_src,
            shared_ptr<base_distributor> d_src, 
            shared_ptr<scheduler> s_src) :
                t(t_src), distr(d_src), shd(s_src) {}

    solution(shared_ptr<test> t_src,
            base_distributor * d_src, 
            shared_ptr<scheduler> s_src) :
                t(t_src), distr(d_src), shd(s_src) {}
    

    const vector<move_record> & get_schedule() const {
        if(!final_moves.empty())
            return final_moves;
        if(t == nullptr || distr == nullptr || shd == nullptr)
            throw 0x100;
        
        final_moves = shd->make_shedule(*t, distr->distribute(*t));

        return final_moves;
    } 
};

class judge{
public:
    static double get_penalty(const test & current_test, const vector<move_record> & moves){
        double penalty = 0;
        for(auto & mv : moves)
            penalty += point(mv.x, mv.y).len() * (1 + mv.indexes.size() * 1.0 / current_test.cars.size());  
        return penalty;
    }     
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    shared_ptr<test> current_test(new test());
    cin >> *current_test;
    
    vector<solution> solutions;
    solutions.emplace_back(
        current_test,
        new distributor<>(),
        new scheduler()
    );
    solutions.emplace_back(
        current_test,
        new distributor<manhattan_move_inserter>(),
        new scheduler()
    );
    // solutions.emplace_back(
    //     current_test,
    //     new distributor<octogone_inserter>(),
    //     new scheduler()
    // );
    solutions.emplace_back(
        current_test,
        new zones_and_cars_distributor<>(),
        new scheduler()
    );
    solutions.emplace_back(current_test,
                        solutions.back().distr,
                        new optimal_scheduler
    );
    solutions.emplace_back(
        current_test,
        new closest_fan_distributor<octogone_inserter>(),
        new scheduler
    );

    solutions.emplace_back(
        current_test,
        new zones_and_cars_distributor<eucldid_divide_inserter>(),
        new scheduler()
    );
    solutions.emplace_back(current_test,
                        solutions.back().distr,
                        new optimal_scheduler
    );
    solutions.emplace_back(
        current_test,
        new zones_and_cars_distributor<manhattan_move_inserter>(),
        new scheduler()
    );
    solutions.emplace_back(
        current_test,
        new closest_fan_distributor<manhattan_move_inserter>(),
        new scheduler()
    );
    solutions.emplace_back(
        current_test,
        new closest_fan_distributor<eucldid_divide_inserter>(),
        new scheduler()
    );
    solutions.emplace_back(current_test,
                        solutions.back().distr,
                        new optimal_scheduler
    );
    solutions.emplace_back(
        current_test,
        new closest_fan_distributor<manhattan_divide_inserter>(),
        new scheduler()
    );
    solutions.emplace_back(
        current_test,
        new distributor<manhattan_divide_inserter>(),
        new scheduler()
    );



    int size_to_insert = solutions.size();
    /*
    for(int seed = 0; seed < 2; seed++){
        for(int i = 0; i < size_to_insert; i++)
            solutions.emplace_back(current_test,
                                solutions[i].distr,
                                new random_sheduler(seed));
    }
    */
    // solutions.emplace_back(
    //     current_test,
    //     new closest_fan_distributor<manhattan_divide_inserter>(),
    //     new optimal_scheduler 
    // );
                            
    
    vector<const vector<move_record> *> schedules;
    vector<double> schedule_scores;
    for(auto & i : solutions)
        schedules.emplace_back(&i.get_schedule());
    for(auto & i : schedules)
        schedule_scores.push_back(judge::get_penalty(*current_test, *i));

    auto best_schedule = min_element(schedule_scores.begin(), schedule_scores.end()) 
                         - schedule_scores.begin();
    

    cout << schedules[best_schedule]->size() << '\n';
    for(auto & i : *schedules[best_schedule])
        cout << i << '\n';

    return 0;
}