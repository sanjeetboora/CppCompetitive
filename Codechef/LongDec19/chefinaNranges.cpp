/* Problem -  */
/* By Sanjeet Boora */
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct temp
{
    int data;
    bool begin;
};
struct tempSmall
{
    inline bool operator() (const temp& t1, const temp& t2)
    {
        if (t1.data != t2.data)
        {
            return t1.data < t2.data;
        }
        else
        {
            if (t1.begin)
            {
                return true;
            }
            return false;
        }
    }
};

temp t[200009];

void compute(int a, int b) {
    int num;
    long long beg;
    long long curr;
    long long next;
    long long prev;
    long long last;
    long long result;
    long long n;
    scanf("%lld", &n);

    for (num = 0; num < n; num++)
    {
        scanf("%lld %lld", &beg, &last);
        t[num * 2].data = beg;
        t[num * 2].begin = true;
        t[num * 2 + 1].data = last;
        t[num * 2 + 1].begin = false;
    }
    sort(t, (t + 2 * n), tempSmall());
    result = 100000000;
    curr = 1;
    next = n - 1;
    prev = 0;
    for (num = 1; num < 2 * n; num++)
    {
        if (t[num].data != t[num - 1].data)
        {
            if (prev > 0 && next > 0)
            {
                if (curr < result)
                {
                    result = curr;
                }
            }
        }

        if (result == 0)
        {
            break;
        }

        if (t[num].begin)
        {
            next--;
            curr++;
        }
        else
        {
            curr--;
            prev++;
        }
    }
    if (result == 100000000)
    {
        result = -1;
    }
    printf("%lld\n", result);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute(0, 10000);
    }
    return 0;
}