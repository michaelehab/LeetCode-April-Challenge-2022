// Naive
class MyHashSet {
    vector<bool> a;
public:
    MyHashSet() {
        a = vector<bool>(1e6 + 1, false);
    }
    
    void add(int key) {
        a[key] = true;
    }
    
    void remove(int key) {
        a[key] = false;
    }
    
    bool contains(int key) {
        return a[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// Optimized

class MyHashSet {
    const int BUCKET_SIZE = 1000;
    vector<int> bucket[1000];
    public:
        MyHashSet() {
        }

        void add(int key) { 
            int index = key % BUCKET_SIZE;
            if(!contains(key))
                bucket[index].push_back(key);
        }

        void remove(int key) {
            int index = key % BUCKET_SIZE;
            for(int i = 0; i < bucket[index].size(); i++)
                if(bucket[index][i] == key) { 
                    bucket[index].erase(bucket[index].begin() + i); 
                    break; 
                }
        }

        bool contains(int key) {
            int index = key % BUCKET_SIZE;
            for(int i = 0; i < bucket[index].size(); i++)
                if(bucket[index][i] == key) return true; 
            return false;
        }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */