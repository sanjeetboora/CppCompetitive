
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int N, Q, P;
        scanf("%d %d", &N, &Q);
        int Ai = 0, num = 0;
        for (int i = 0; i < N; i++) {
            cin >> Ai;
            num = num + (__builtin_popcount (Ai) % 2);
        }
        int Anbits =  __builtin_popcount (Ai);

        for (int i = 0; i < Q; i++) {
            scanf("%d", &P);
            bool eq = (__builtin_popcount (P ^ Ai) % 2) == (Anbits % 2);
            int result = eq ? num : N - num;
            printf("%d %d\n",N - result,result);
            
        }

    }
    return 0;
}