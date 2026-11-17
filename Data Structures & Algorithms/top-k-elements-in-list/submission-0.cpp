class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Calculate frequencies
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        // Store elements from map into a vector
        vector<pair<int, int>> arr;

        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }

        // Sort according to frequency (descending)
        sort(arr.begin(), arr.end(),
            [](auto a, auto b) {
                return a.second > b.second;
            });

        // Return top k elements
        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].first);
        }

        return res;
    }
};