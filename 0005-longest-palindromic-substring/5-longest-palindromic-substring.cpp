using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        string longest(1, s[0]);

        for (int center = 0; center < s.length(); ++center) {
            // Tek uzunluklu palindromları kontrol et
            expandAroundCenter(s, center, center, longest);
            // Çift uzunluklu palindromları kontrol et (örn: "cc")
            if (center + 1 < s.length() && s[center] == s[center + 1]) {
                expandAroundCenter(s, center, center + 1, longest);
            }
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
