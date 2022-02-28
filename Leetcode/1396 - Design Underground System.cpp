class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    unordered_map<string, pair<int,int>> m;
    unordered_map<int, pair<string,int>> checkedIn;
    
    void checkIn(int id, string stationName, int t) {
        checkedIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> in = checkedIn[id];
        checkedIn.erase(id);
        string skey = in.first + "-" + stationName;
        int traveltime = t - in.second;
        if(m.find(skey) == m.end()){
            m[skey] = {traveltime, 1};
        } else {
            pair<int,int> curr = m[skey];
            m[skey] = {curr.first + traveltime, curr.second + 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string skey = startStation + "-" + endStation;
        pair<int,int> curr = m[skey];
        return (1.0*curr.first)/(1.0*curr.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */