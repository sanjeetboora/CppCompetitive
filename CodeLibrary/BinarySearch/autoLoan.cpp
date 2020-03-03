#include<bits/stdc++.h>
#include<vector>
using namespace std;
class AutoLoan {
public:
    double interestRate(double price, double monthlyPayment, int loanTerm) {
        double low = 1e-14, high = 100, m;
        while (high / low > 1 + 1e-12) {
            m = low + (high - low) / 2;
            double pr = price;
            bool finish = 0;
            // cout<<m<<endl;
            for (int i = 0; i < loanTerm; ++i)
            {
                pr = pr * (1 + m);
                pr -= monthlyPayment;
                if (pr <= 0) {
                    finish = 1;
                    break;
                }
            }
            if (finish) {
                low  = m;
            }
            else {
                high = m;
            }
        }
        return m * 100 * 12;

    }
};

int main(int argc, char const *argv[])
{
    AutoLoan a;
    cout << a.interestRate(6800, 100, 68) << endl;
    return 0;
}