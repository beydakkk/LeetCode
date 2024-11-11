using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string longest(1, s[0]);

        for (int center = 0; center < s.length(); ++center) {
            expandAroundCenter(s, center, center, longest); // tek uzunluklu palindromlar
            if (center + 1 < s.length() && s[center] == s[center + 1]) 
                expandAroundCenter(s, center, center + 1, longest); // çift uzunluklu palindromlar
        }
        return longest;
    }

private:
    void expandAroundCenter(const string& s, int left, int right, string& longest) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            if (right - left + 1 > longest.length()) {
                longest = s.substr(left, right - left + 1);
            }
            --left;
            ++right;
        }
    }
};
