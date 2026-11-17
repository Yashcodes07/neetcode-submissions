class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m == 0 || n < m) return "";

        int low = 0;
        int high = 0;
        int minlen = INT_MAX;
        int formed = 0;
        int start = 0;

        unordered_map<char,int> need;

        for (high = 0; high < m; high++) {
            need[t[high]]++;
        }

        int required = need.size();

        unordered_map<char,int> window;

        for (high = 0; high < n; high++) {
            window[s[high]]++;

            if (need.find(s[high]) != need.end() &&
                window[s[high]] == need[s[high]]) {
                formed++;
            }

            while (formed == required) {
                int len = high - low + 1;

                if (len < minlen) {
                    minlen = len;
                    start = low;
                }

                window[s[low]]--;

                if (need.find(s[low]) != need.end() &&
                    window[s[low]] < need[s[low]]) {
                    formed--;
                }

                low++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};