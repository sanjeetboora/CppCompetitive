/*  https://leetcode.com/problems/integer-to-english-words/    */
class Solution {
public:
    string tw[20]  = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand ", "Million ", "Billion "};

    inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }

    string convert(int num) {
        if (num <= 0) {
            return "";
        }
        else if (num < 20) {
            return tw[num] + " ";
        }
        else if (num < 100) {
            return tens[num / 10] + " " + convert(num % 10);
        }
        else {
            return tw[num / 100] + " Hundred " + convert(num % 100);
        }
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string word = "";
        int i = 0;
        while (num != 0) {
            if (num % 1000 != 0) {
                word = convert(num % 1000) + thousands[i] + word;
            }

            num /= 1000;
            i++;
        }
        return rtrim(word);
    }
};