//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        
        for(int i=0; i<s.length(); i++){
            freq[s[i] - 'a']++;
        }
        
        priority_queue<int> pq;
        
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }
        int prev = INT_MAX;
        int curr = 0;
        int count = 0;
      //O(nlog(26))
        while(!pq.empty()){
            curr = pq.top();
            pq.pop();
            if(curr == prev){
                curr--;
                count++;
                if(curr > 0){ pq.push(curr);}
            }
            else{
                prev = curr;
            }
        }
        return count;
    }
};
