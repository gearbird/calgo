#include "../include/common.hpp"

namespace leetcode {
    using std::string;

    void expand(string &s, int lo, int hi, int &maxLo, int &maxLen) {
        while (lo >= 0 && hi < s.size()) {
            if (s[lo] != s[hi]) return;
            int curLen = hi - lo + 1;
            if (curLen > maxLen) {
                maxLo = lo;
                maxLen = curLen;
            }
            lo--, hi++;
        }
    }

    string longestPalindrome(string s) {
        int maxLo = 0, maxLen = 0, size = s.size();
        for (int i = 0; i < size; i++) {
            if (i > size / 2 && std::min(i + 1, size - i) * 2 <= maxLen) break;
            expand(s, i, i, maxLo, maxLen);
            expand(s, i, i + 1, maxLo, maxLen);
        }
        return s.substr(maxLo, maxLen);
    }

    void test_longestPalindrome() {
        string input = "babad";
        string output = longestPalindrome(input);
        print_inputoutput(input, output);

        // string input = "aabcbefebcde";
        // string output = longestPalindrome(input);
        // print_inputoutput(input, output);
    }

    // Bad solution, time exceeded
    // bool isPalindrome(string s, int lo, int hi) {
    //     while (lo < hi) {
    //         if (s[lo++] != s[hi--]) return false;
    //     }
    //     return true;
    // }

    // string longestPalindrome(string s) {
    //     int len = s.size();
    //     while (len > 0) {
    //         for (int i = 0; i + len <= s.size(); i++) {
    //             if (isPalindrome(s, i, i + len - 1)) return s.substr(i, len);
    //         }
    //         len--;
    //     }
    //     return "";
    // }
}