class UndergroundSystem {
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<double, int>> averages;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string routeName = checkIns[id].first + "=>" + stationName;
        averages[routeName].first += (t - checkIns[id].second);
        averages[routeName].second += 1;
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "=>" + endStation;
        return averages[routeName].first / averages[routeName].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIns(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */