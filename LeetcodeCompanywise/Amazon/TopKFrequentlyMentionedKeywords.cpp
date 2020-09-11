//https://leetcode.com/discuss/interview-question/542597/

#include <bits/stdc++.h>
using namespace std;

vector<string> topKFrequent(vector<string>& keyWords, int k, vector<string>& reviews) {

    unordered_map<string, int> mp;
    vector<string> res;
    for (int i = 0; i < keyWords.size(); i++) {
        mp[keyWords[i]]++;
    }

    regex re("[^A-Za-z]"); //non-alphabetical chars
    for (string str : reviews)
    {
        string modified = regex_replace(str, re, " ");
        stringstream s(modified);
        unordered_map<string, int> mpLocal;
        string word;
        while (s >> word) {
            if (!mpLocal.count(word)) {
                mpLocal[word]++;
            }
        }
        for (auto x : mpLocal) {
            if (mp.count(x.first)) {
                mp[x.first]++;
            }
        }
    }

    struct cmp {
        bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
    };

    priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq(mp.begin(), mp.end());

    while (k--) {
        pair<string, int> top = pq.top();
        res.push_back(top.first);
        pq.pop();
    }

    return res;

}

int main(int argc, char const *argv[])
{
    /* code */
    int k = 2;
    vector<string> keywords = {"anacell", "betacellular", "cetracular", "deltacellular", "eurocell"};
    vector<string> reviews = {
        "I love anacell Best services; Best services provided by anacell",
        "betacellular has great services",
        "deltacellular provides much better services than betacellular",
        "cetracular is worse than anacell",
        "Betacellular is better than deltacellular.",
    };

    vector<string> result = topKFrequent(keywords, k, reviews);
    for (string str : result) {
        cout << str << ", ";
    }
    cout << endl;


    return 0;
}





/*

Example 1:

Input:
k = 2
keywords = ["anacell", "cetracular", "betacellular"]
reviews = [
  "Anacell provides the best services in the city",
  "betacellular has awesome services",
  "Best services provided by anacell, everyone should use anacell",
]

Output:
["anacell", "betacellular"]

Explanation:
"anacell" is occuring in 2 different reviews and "betacellular" is only occuring in 1 review.

Example 2:

Input:
k = 2
keywords = ["anacell", "betacellular", "cetracular", "deltacellular", "eurocell"]
reviews = [
  "I love anacell Best services; Best services provided by anacell",
  "betacellular has great services",
  "deltacellular provides much better services than betacellular",
  "cetracular is worse than anacell",
  "Betacellular is better than deltacellular.",
]

Output:
["betacellular", "anacell"]

Explanation:
"betacellular" is occuring in 3 different reviews. "anacell" and "deltacellular" are occuring in 2 reviews, but "anacell" is lexicographically smaller.




*/
