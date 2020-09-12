//https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    class node {
    public:
        char data;
        map<char, node*> mp;
        bool isTermianted;
        node(char ch) {
            data = ch;
            isTermianted = false;
        }
    };
    class Trie {

    public:
        node* root;
        Trie() {
            root = new node('\0');
        }
        void insert(string word) {
            node* temp = root;
            for (int i = 0; i < word.length(); i++) {
                if (!temp->mp.count(word[i])) {
                    node* child = new node(word[i]);
                    temp->mp[word[i]] = child;
                }
                temp = temp->mp[word[i]];
            }
            temp->isTermianted = true;
        }

        void searchHelper(string partial, vector<string> &partSol, int &count, node* temp) {
            if (count > 2) {
                return;
            }
            if (temp->isTermianted) {
                partSol.push_back(partial);
                count++;

            }

            for (auto ch : temp->mp) {
                partial += ch.first;
                //cout<<ch.first<<endl;
                searchHelper(partial, partSol, count, temp->mp[ch.first]);
                int len = partial.length();
                partial = partial.substr(0, len - 1);
            }
        }

        vector<vector<string> > search(string searchWord) {
            vector<vector<string>> res;
            node* temp = root;
            string partial = "";
            for (int i = 0; i < searchWord.length(); i++) {
                if (!temp->mp.count(searchWord[i])) {
                    while ( i < searchWord.length()) {
                        vector<string> v;
                        res.push_back(v);
                        i++;
                    }
                }
                else {
                    partial += searchWord[i];
                    vector<string> partRes;
                    temp = temp->mp[searchWord[i]];
                    int count = 0;
                    searchHelper(partial, partRes, count, temp);
                    res.push_back(partRes);
                }
            }

            return res;
        }
    };


    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;

        Trie* t = new Trie();
        for (string prod : products) {
            t->insert(prod);
        }
        res = t->search(searchWord);
        return res;

    }
};