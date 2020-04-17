class Ugly{
    public:
        vector<long long>v;
        Ugly(){
            set<long long int> pq;
            pq.insert(1);
            int count = 1;
            while(count<= 1690){
                
                auto it = pq.begin();
                long long int num=0;
                if (it != pq.end()) num = *it;
               
                 pq.erase(pq.begin()); 
                if (pq.count(num*2) < 1) pq.insert(num*2);
                if (pq.count(num*3) < 1) pq.insert(num*3);
                if (pq.count(num*5) < 1) pq.insert(num*5);

                v.push_back(num);
                count++;
            }
        }
};

class Solution {
public:
    long long int nthUglyNumber(int n) {
        static Ugly u;
        return u.v[n-1];
        
        
    }
};