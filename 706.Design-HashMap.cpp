// Naive
class MyHashMap {
    vector<int> tmp;
public:
    MyHashMap() {
        tmp = vector<int>(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        tmp[key] = value;
    }
    
    int get(int key) {
        return tmp[key];
    }
    
    void remove(int key) {
        tmp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap {
public:
    vector<list<pair<int,int>>> tmp;
    int size = 997; // Prime number to avoid collisions
	
	MyHashMap() {
        tmp = vector<list<pair<int,int>>>(size);
    }
	
	int getIdx(int key){
        return key%size;
    }
    
    void put(int key, int value) {
        int ind = getIdx(key);
        auto& list = tmp[ind];
        for(auto &i : list){
            if(i.first == key){
                i.second=value;
                return;
            }
        }
        list.push_back({key,value});
    }
    
    int get(int key) {
       int ind = getIdx(key);
       auto& list = tmp[ind];
       for(auto &i : list){
           if(i.first == key) return i.second;
       }
       return -1;
    }
    
    void remove(int key) {
        int ind = getIdx(key);
        auto& list = tmp[ind];
        for(auto &i : list){
            if(i.first == key){
                list.remove(i);
                return;
            }
        }
    }
};