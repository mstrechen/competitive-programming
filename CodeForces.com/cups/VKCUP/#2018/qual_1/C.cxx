#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
//beautiful
//mountain



using namespace std;

const int IMPOSSIBLE_VERSION = 1000*1000*1000;

struct relations{
    int size;

    map<pair<string, int>, int> name_to_index;
    vector<pair<string, int> > index_to_name{};

    vector<vector<int> > dependencies; 
    

    relations(int n) 
        : size(n),
          dependencies(n)
        {}
    
    void add_name (const string & project, int version) {
        if(name_to_index.count({project, version}) == 0)
            name_to_index[{project, version}] = index_to_name.size(),
            index_to_name.emplace_back(project, version);
    }

    int get_handle(const string & name, int version) const {
        return name_to_index.at({name, version});
    }
    
    void add_dependencies(istream & in){
        string name;
        int version;
        cin >> name >> version;

        add_name(name, version);
        int handle = get_handle(name, version);
        
        int count;
        cin >> count;

        for(int i = 0; i < count; i++){
            cin >> name >> version;
            add_name(name, version);
            dependencies[handle].push_back(get_handle(name, version));       
        }
    }

    vector<pair<string, int> > get_dependencies(){
        vector<pair<string, int> > result;
        vector<char> visited(size);

        function<void(string)> make_used = [&](const string & name){
            auto it_end = name_to_index.upper_bound({name, IMPOSSIBLE_VERSION});
            for(auto it = name_to_index.lower_bound({name, 0}); 
                it != it_end;
                it++)
                visited[get_handle(it->first.first,
                                   it->first.second)] = 1;
        };
        
        make_used(index_to_name[0].first);

        vector<pair<string, int> > current_layer = {index_to_name[0]},
                    next_layer;
        


        while(current_layer.size() != 0){
            for(auto current : current_layer)
                for(auto next : dependencies[get_handle(current.first, current.second)])
                    if(!visited[next])
                        next_layer.push_back(index_to_name[next]);
            
            sort(next_layer.begin(), next_layer.end(), 
                 [](const pair<string, int> & l, const pair<string, int>  & r){
                    return l.first < r.first || 
                           (l.first == l.first && l.second > r.second);
                 });

            current_layer.clear();

            for(int i = 0; i < (int)next_layer.size(); ){
                result.push_back(next_layer[i]);
                current_layer.push_back(next_layer[i]);

                int j = i;
                
                while(j < (int)next_layer.size() &&
                      next_layer[i].first == next_layer[j].first)
                        j++;
                

                make_used(next_layer[i].first);

                i = j;
            }
            
            next_layer.clear();           
        }
        return result;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    relations r(n);
    for(int i = 0; i < n; i++)
        r.add_dependencies(cin); 

    auto dependencies = r.get_dependencies();

    cout << dependencies.size() << '\n';
    sort(dependencies.begin(), dependencies.end());

    for(auto & i : dependencies){
        cout<< i.first << ' ' << i.second << '\n';
    }


    return 0;
}