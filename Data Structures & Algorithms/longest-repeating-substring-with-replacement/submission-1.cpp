class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int max_freq = 0;
        int maxi = 0;
        int high = 0;
        unordered_map<char,int> f;

        for(high = 0 ; high<n ; high++){
            f[s[high]]++;
            max_freq = max(max_freq,f[s[high]]);
            while ((high - low + 1) - max_freq > k) {
                f[s[low]]--;
                low++;
            }
            maxi = max(maxi, high - low + 1);

        }
        return maxi;
    }
};
