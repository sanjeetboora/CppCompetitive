#include<bits/stdc++.h>
#include<vector>
using namespace std;
class SortEstimate {
public:
    double howMany(int c, int time) {
        double low = 1, high = time, mid,ans=0, cValue = c;
        while(high / low > 1 + 1e-12){
            mid = low+(high-low)/2;
            if( mid * log2(mid) <= time/cValue){
                ans = mid;
                low=mid+ 1e-12;
            } 
            else{
                high=mid;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    SortEstimate s;
    double ans = s.howMany(37, 12392342);
    cout << ans << endl;
    return 0;
}