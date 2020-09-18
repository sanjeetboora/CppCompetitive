//https://leetcode.com/problems/insert-delete-getrandom-o1/

/* using unordered_map and vector  */

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int>mp;
    vector<int> v;
    RandomizedSet() {
        v.reserve(10);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if (mp.count(val) == 0) {
            v.push_back(val);
            mp[val] = v.size() - 1;
            return true;
        }
        return false;

    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val)) {
            int sz = v.size() - 1;
            int x = mp[val];
            mp[v[sz]] = x;
            swap(v[x], v[sz]);
            v.pop_back();
            mp.erase(val);
            return true;
        }
        return false;

    }

    /** Get a random element from the set. */
    int getRandom() {
        int x = rand() % v.size() + 0;
        cout << x << ", " << v[x] << endl;
        if (x == v.size())x--;
        return v[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */