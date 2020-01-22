#include <bits/stdc++.h>
using namespace std;

long long int pairsss(int N){
 //  long long int* m = new long long int[N];
   long long int c0=0;
   long long int c2=0;
    while(N--){
        long long int a;
        cin>>a;
       if(a == 0){
           c0++;
       }
       else if(a==2){
           c2++;
       }
    }
    long long int res1 = (c2 * (c2 - 1))/2;
    long long int res2 = (c0 * (c0 - 1))/2;
    long long int pairs = res1+res2;
  
    return pairs;

}
int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<pairsss(N)<<endl;
    }
    
}
