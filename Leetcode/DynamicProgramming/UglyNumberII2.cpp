class Ugly{
    public:
       long long int v[1691] = {0}; 
        Ugly(){
            long long int num;
            int count = 1, i2 =0, i3=0, i5=0;
            v[0] =1;
            while(count<= 1690){
                
                num = min(v[i2]*2,min(v[i3]*3,v[i5]*5));
                v[count] = num;
                if(num == v[i2]*2) i2++;
                if(num == v[i3]*3) i3++;
                if(num == v[i5]*5) i5++;
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