//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> fwd;
        unordered_set<string> bck;
        if (words.find(endWord) == words.end()) return 0;

        fwd.insert(beginWord);
        bck.insert(endWord);

        int ladder = 2;
        while (!fwd.empty() and !bck.empty()) {
            if (bck.size() > fwd.size()) {
                swap(bck, fwd);
            }

            unordered_set<string> temp;
            for (string x : fwd) {

                for (int i = 0; i < x.size(); i++) {
                    char ac = x[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        x[i] = ch;
                        if (bck.find(x) != bck.end()) {
                            return ladder;
                        }

                        if (words.find(x) != words.end()) {
                            temp.insert(x);
                            words.erase(x);
                        }
                    }
                    x[i] = ac;
                }
            }
            fwd = temp;
            ladder++;
        }

        return 0;
    }
};