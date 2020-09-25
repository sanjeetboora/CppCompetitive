//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
    unordered_map<int, vector<int> > mp;
    vector<pair<int, int> >v;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        v.reserve(10);
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (!mp.count(val)) {
            mp[val].push_back(v.size());
            v.push_back({val, mp[val].size() - 1});
            return true;
        }
        mp[val].push_back(v.size());
        v.push_back({val, mp[val].size() - 1});
        return false;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;

        pair<int, int>p = v.back();
        int lastIdx = mp[val].back();
        v[lastIdx] = p;
        mp[p.first][p.second] = lastIdx;
        mp[val].pop_back();

        if (mp[val].empty()) mp.erase(val);
        v.pop_back();

        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int ele = v[rand() % v.size()].first;
        return ele;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


