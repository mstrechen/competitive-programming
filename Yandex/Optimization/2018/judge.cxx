#include "testlib.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <ctime>
#include <iomanip>

const int MAX_SCORE = 10*1000*1000;
const std::string TIMEOUT = "timeout 2s ";


const std::string RUN_TESTS_FLAG = "-R";
const std::string GENERATE_TESTS_FLAG = "-G";
const std::string TEST_PREFIX = "tests/tests_";




const char NORMAL_TEXT[] = "\x1B[0;039m\0";
const char RED_TEXT[] =    "\x1B[1;031m\0";
const char GREEN_TEXT[] =  "\x1B[0;032m\0";
const char YELLOW_TEXT[] = "\x1B[0;033m\0";
const char PURPLE_TEXT[] = "\x1B[0;035m\0";

class point{
public:
    int x, y;

    void operator += (const std::pair<int, int > & a){
        x += a.first;
        y += a.second;
    }
};

std::ostream & operator << (std::ostream & out, const point & p){
    out << '(' << p.x << ',' << p.y <<  ')';
    return out ;
}


bool operator < (const point & lhs, const point & rhs){
    return lhs.x < rhs.x || 
           (lhs.x == rhs.x && lhs.y < rhs.y); 
}

bool operator == (const point & lhs, const point & rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

class car: public point{

};
class user: public point{

};
class zone: public point{

};



class checker{
public:

    static std::pair<int, double> check(int n_tests, char * program_to_check){
        double result = 0;
        int successful_test = 0;

        double execution_time = 0;

        for(int _i = 0; _i < n_tests; _i++){
            std::string current_test = TEST_PREFIX;
            current_test += '0' + _i / 100;
            current_test += '0' + (_i / 10) % 10;
            current_test += '0' + _i % 10;
            current_test += ".test";

            std::string run_program = "./";
                run_program += program_to_check;
                run_program += " < ";
                run_program += current_test;

            auto test = std::ifstream(current_test);
            auto test_result = get_participant_answer(run_program); 
            if(test_result.second >= 0.0){
                auto pans = std::istringstream(test_result.first);
                
                double local_result =  get_score(test, pans);
                
                if(local_result == -1.0){
                    std::cout << RED_TEXT << "TEST #" << std::setw(3) << _i << " FAILED, 2 cars at the same point";
                    std::cout << NORMAL_TEXT;
                } else if(local_result == -1.5){
                    std::cout << RED_TEXT << "TEST #" << std::setw(3) << _i 
                            << " FAILED, some car has coordinate more than 1000";
                    std::cout << NORMAL_TEXT;
                } else if (local_result == -2.0){
                    std::cout << RED_TEXT << "TEST #" << std::setw(3) << _i << " FAILED, not all of passangers are at places";
                    std::cout << NORMAL_TEXT;
                } else if(local_result == -4.0){
                    std::cout << YELLOW_TEXT << "TEST #" << std::setw(3) << _i << " PRESENTATION ERROR (probably EOF)";
                    std::cout << NORMAL_TEXT;
                } else if(local_result == -8.0){
                    std::cout << YELLOW_TEXT << "TEST #" << std::setw(3) << _i << " PRESENTATION ERROR, wrong car index:" 
                              << int(local_result/1000);
                    std::cout << NORMAL_TEXT;
                    
                } else {
                    std::cout << GREEN_TEXT << "TEST #" << std::setw(3) << _i << " OK! " 
                              << PURPLE_TEXT <<  std::setw(7) << local_result 
                              << GREEN_TEXT << " TIME:" 
                              << YELLOW_TEXT <<   std::setw(4) <<   test_result.second << "ms";
                    std::cout << NORMAL_TEXT;
                    result += local_result;
                    successful_test++;
                }
                execution_time += test_result.second;
            } else {
                if(test_result.second == -1.0){
                    std::cout << RED_TEXT << "TEST #" << std::setw(3) << _i << " TL exceeded (> 2s)! " << 
                                PURPLE_TEXT;
                    std::cout << NORMAL_TEXT;
                } else {
                    std::cout << YELLOW_TEXT << "TEST #" << std::setw(3) << _i << " Bad exitcode: " 
                              << int(test_result.second/-1000) << PURPLE_TEXT;
                    std::cout << NORMAL_TEXT;
                }
                execution_time += 2000;
            }
            double estimated_time = (n_tests - _i - 1) * (execution_time / (_i + 1)); 
            
            std::cout << YELLOW_TEXT << " | est. time " << estimated_time/1000
                    << "s" << NORMAL_TEXT << '\n';
            std::cout.flush();
        }
        return {successful_test, result};
    }


    static bool no_cars_at_the_same_point(const std::vector<car> & cars){
        for(size_t i = 0; i < cars.size(); i++)
            for(size_t j = i + 1; j < cars.size(); j++)
                if(cars[i] == cars[j]){
                    std::cout << cars[i] << ' ' << cars[j] << std::endl;
                    return false;
                }
        return true;
    }

    static bool no_cars_out_of_space(const std::vector<car> & cars){
        for(auto & i : cars)
            if(abs(i.x) > 10000 || abs(i.y) > 10000)
                return false;
        return true;
    } 

    static double get_score(std::istream & test, std::istream & pans){
        
        double penalty = 0;
        
        std::vector<car> cars;
        std::vector<user> users;
        std::vector<zone> zones;
        std::vector<int> busy_cars;
        
        int size;
        test >> size;
        cars.resize(size);
        for(int i = 0; i < size; i++)
            test >> cars[i].x >> cars[i].y;
        
        
        test >> size;
        users.resize(size);
        for(int i = 0; i < size; i++)
            test >> users[i].x >> users[i].y;

        test >> size;
        zones.resize(size);
        for(int i = 0; i < size; i++)
            test >> zones[i].x >> zones[i].y;
        
        pans >> size;
        std::string tmp;
        std::vector<int> to_move;
        if(pans.fail())
            return -4.0;
        
        for(int _i = size; _i > 0; _i--){
            if(pans.fail() || pans.eof())
                return -4.0;
        
            pans >> tmp;
            int size;
            std::pair<int, int> delta;
            
            pans >> delta.first >> delta.second >> size ;
            if(pans.fail())
                return -4.0;
            to_move.resize(size);
            
            
            for(int i = 0; i < size; i++){
                pans >> to_move[i];
                --to_move[i];

                if(to_move[i] < 0 || to_move[i] >= cars.size())
                    return -8.0;
            }

            if(pans.fail())
                return -4.0;

            penalty += sqrt(delta.first * delta.first + delta.second * delta.second) * 
                            (1 + size/cars.size());
            

            for(auto i : to_move){
                cars[i] += delta;
            }
            if(!no_cars_at_the_same_point(cars)){
                return -1.0;
            }
            if(!no_cars_out_of_space(cars)){
                return -1.5;
            }

            for(size_t i = 0; i < busy_cars.size(); i++)
                if(zones.end() != std::find(zones.begin(), zones.end(), cars[busy_cars[i]])){
                    std::swap(busy_cars[i], busy_cars.back());
                    busy_cars.pop_back();
                    i--;
                }
            
            for(size_t i = 0; i < cars.size(); i++)
            if(busy_cars.end() == std::find(busy_cars.begin(), busy_cars.end(), i) ){
                auto it = std::find(users.begin(), users.end(), cars[i]);
                if(it != users.end()){
                    busy_cars.push_back(i);
                    std::swap(*it, users.back());
                    users.pop_back();
                }
            }
        }
        
        if(busy_cars.size() + users.size())
            return -2.0;

        
        return MAX_SCORE/penalty;
    }

    static std::pair<std::string, double> get_participant_answer(std::string command) {
        std::string data;
        FILE * stream;
        const int max_buffer = 256;
        char buffer[max_buffer];
        command = TIMEOUT + command;
        command.append(" 2>&1");
        

        std::chrono::high_resolution_clock timer;
        double delta_time;
        auto time_begin = timer.now();
        
        stream = popen(command.c_str(), "r");


        if (stream) {
            while (!feof(stream))
                if (fgets(buffer, max_buffer, stream) != NULL) 
                    data.append(buffer);
            int exit_status = WEXITSTATUS(pclose(stream));
            auto time_end = timer.now();
            delta_time = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_begin ).count();
            if(exit_status != 0){
                if(exit_status == 124)
                    delta_time = -1.0;
                else
                    delta_time = -1000*exit_status;
            }

        } else {
            return {"0", -2};
        }
        
        if(data.size() > 0 && data[0] == 's' && data[1] == 'h' && data[2] == ':'){
            std::cout << RED_TEXT << "FAIL. Something went wrong with program, error: "
                      << YELLOW_TEXT << data << NORMAL_TEXT;
            delta_time = -2.0;
        }

        return {data, delta_time};
    }

};

class test_generator{
public:
    static void generate(int n_tests, int max_cars_cnt = 20, int max_users = 500, int max_zones = 20){
        for(int _i = 0; _i < n_tests; _i++){
            std::string test_name = TEST_PREFIX;
                test_name += '0' + _i / 100;
                test_name += '0' + (_i / 10) % 10;
                test_name += '0' + _i % 10;
                test_name += ".test";
            std::ofstream current_test(test_name);
            generate_test(current_test, 
                            rnd.next(1, max_cars_cnt), 
                            rnd.next(1, max_users), 
                            rnd.next(1,max_zones), 10000);
            current_test.close();
        }
    } 

    static void generate_test(std::ostream & out, int max_cars_cnt, int max_users, int max_zones, int max_coord){
        int cars_n = max_cars_cnt; 
        std::set<std::pair<int, int> > used;

        out << cars_n << '\n';
        
        while(used.size() != max_cars_cnt){
            int x = rnd.next(-max_coord, max_coord),
                y = rnd.next(-max_coord, max_coord);
            if(!used.count({x, y})){
                out << x << ' ' << y << '\n';
                used.emplace(x, y);
            }   
        }
        out << max_users << '\n';
        while(used.size() != max_cars_cnt + max_users){
            int x = rnd.next(-max_coord, max_coord),
                y = rnd.next(-max_coord, max_coord);
            if(!used.count({x, y})){
                out << x << ' ' << y << '\n';
                used.emplace(x, y);
            }
        }
        out << max_zones << '\n'; 
        while(used.size() != max_cars_cnt + max_users + max_zones){
            int x = rnd.next(-max_coord, max_coord),
                y = rnd.next(-max_coord, max_coord);
            if(!used.count({x, y})){
                out << x << ' ' << y << '\n';
                used.emplace(x, y);
            }
        }
        
        
    }
};

int main(int argc, char ** argv){
    registerGen(argc, argv, 1);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int generate_tests_count = 0,
        run_tests_count = 0;
    char * program_to_check;
    
    for(int i = 1; i < argc; i++){
        if(argv[i] == RUN_TESTS_FLAG){
            run_tests_count = atoi(argv[i + 1]);
            i++;
            program_to_check = argv[argc - 1];
        } else
        if(argv[i] == GENERATE_TESTS_FLAG){
            generate_tests_count = atoi(argv[i + 1]);
            i++;
        }
    }

    if(generate_tests_count != 0)
        test_generator::generate(generate_tests_count);
    
    if(run_tests_count != 0){
        std::pair<int, double> res = checker::check(run_tests_count, program_to_check);
        std::cout << "TOTAL SCORE:  " << YELLOW_TEXT << res.second << '\n' << NORMAL_TEXT;
        std::cout << "TESTS PASSED: " << YELLOW_TEXT << res.first << "/" << run_tests_count << NORMAL_TEXT; 
    }

    return 0;
}