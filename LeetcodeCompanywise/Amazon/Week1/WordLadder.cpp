//https://leetcode.com/problems/word-ladder/

//using bi-directional  | Time: N*(26^(M/2))  | N - number of words |  M - length of a word
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



//using bfs Time: N*(26^M)  | N - number of words |  M - length of a word

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};