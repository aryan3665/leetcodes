class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>>available;
    map<pair<int,int>,int>price_map;
    multiset<pair<int,pair<int,int>>>rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for (auto entry:entries) {
            int shop=entry[0];
            int movie=entry[1];
            int price=entry[2];
            
            available[movie].insert({price,shop});
            price_map[{shop,movie}]=price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int>result;
        auto& shops=available[movie];
        int count=0;
        for(auto p:shops) {
            if(count==5)break;
            result.push_back(p.second);
            count++;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price=price_map.at({shop,movie});
        
        available[movie].erase({price,shop});
        rented.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price=price_map.at({shop,movie});
        
        auto it=rented.find({price,{shop,movie}});
        if(it!=rented.end()){
            rented.erase(it);
        }
        
        available[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>result;
        int count=0;
        for(auto t:rented) {
            if(count==5)break;
            result.push_back({t.second.first,t.second.second});
            count++;
        }
        return result;
    }
};