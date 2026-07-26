class TimeMap {
    map<string,set<pair<int,string>>>tm;
public:
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=tm.find(key);
        if(it==tm.end())return "";
        std::set<pair<int,string>>&s=it->second;
        auto itt=s.upper_bound({timestamp,"{"});
        if(itt==s.begin())return "";
        itt--;
        
        return itt->second;
    }
};
